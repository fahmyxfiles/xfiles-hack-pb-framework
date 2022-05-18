#define BUFFERSIZE 256
#include <urlmon.h> //"urlmon.h: No such file or directory found"
#pragma comment(lib, "urlmon.lib")
class CNetHTTP
{
private:
	string Method;
	string Url;
	string Host;
	string Path;

	vector<string> Headers;
	vector<string> Parameters;
	vector<string> Files;
public:
	string Request;
	string AdditionalParameter;
	string AdditionalRequest;

	void* Response;
	string ResponseHeaders;
	void* ResponseBody;
	double ResponseLength;
	string ResponseBodyString;

	int ResponseCode;
	double ContentLength;

	CNetHTTP::CNetHTTP(string Method, string Url)
	{
		this->Method = Method;
		this->Url = Url;
		this->Host = "";
		this->Path = "";

		this->Headers.clear();
		this->Parameters.clear();
		this->Files.clear();

		this->Request = "";
		this->AdditionalParameter = "";
		this->AdditionalRequest = "";

		this->Response = NULL;
		this->ResponseHeaders = "";
		this->ResponseBody = NULL;
		this->ResponseLength = 0;
		this->ResponseBodyString = "";

		this->ResponseCode = -1;
		this->ContentLength = 0;
	}
	void CNetHTTP::Cleanup()
	{
		this->Method.clear();
		this->Url.clear();
		this->Host.clear();
		this->Path.clear();

		if(this->Headers.size())
			this->Headers.clear();
		if(this->Parameters.size())
			this->Parameters.clear();
		if(this->Files.size())
			this->Files.clear();

		this->Request.clear();
		this->AdditionalParameter.clear();
		this->AdditionalRequest.clear();;

		if(this->Response)
			free(this->Response);
		this->ResponseHeaders.clear();
		if(this->ResponseBody)
			free(this->ResponseBody);
		this->ResponseLength = 0;
		this->ResponseBodyString.clear();

		this->ResponseCode = -1;
		this->ContentLength = 0;
	}
	bool CNetHTTP::Run()
	{
		string temp = this->Url;
		if(this->Url.find("http://") != -1)
			temp = this->Url.substr(this->Url.find("http://") + 7);

		// Split host and file location //
		int dm = temp.find("/");
		this->Path = temp.substr(dm);
		this->Host = temp.substr(0, dm);

		this->Request = this->Method + " " + this->Url + " HTTP/1.0\r\n";
		this->AddHeaders("Host", this->Host);
		this->AddHeaders("Connection", "close");
		this->AddHeaders("User-Agent", "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36");

		if(this->Method == "GET")
		{
			if(this->Parameters.size() > 0){
				this->AdditionalParameter = "?";

				for(unsigned int i = 0; i < this->Parameters.size(); i++)
					this->AdditionalParameter += this->Parameters[i] + "&";
			}
		}
		else if(this->Method == "POST")
		{
			if(this->Files.size() > 0 || this->Parameters.size() > 0){
				if(this->Files.size() > 0)
				{
					for(unsigned int i = 0; i < this->Files.size(); i++)
						this->AdditionalRequest += "------WebKitFormBoundaryXFilesHack\r\n" + this->Files[i] + "\r\n";
				}
				if(this->Parameters.size() > 0){
					for(unsigned int i = 0; i < this->Parameters.size(); i++)
						this->AdditionalRequest += "------WebKitFormBoundaryXFilesHack\r\n" + this->Parameters[i] + "\r\n";
				}
				this->AdditionalRequest += "------WebKitFormBoundaryXFilesHack--\r\n";
				this->AddHeaders("Content-Type", "multipart/form-data; boundary=----WebKitFormBoundaryXFilesHack");
				this->AddHeaders("Content-Length", std::to_string((long double)this->AdditionalRequest.length()));
			}
		}


		this->Request = this->Method + " " + this->Url + this->AdditionalParameter + " HTTP/1.0\r\n";

		// BUILD REQUEST HEADERS
		for(unsigned int i = 0; i < this->Headers.size(); i++)
			this->Request += this->Headers[i] + "\r\n";

		this->Request += "\r\n";
		this->Request += this->AdditionalRequest;

		char buffer[BUFFERSIZE];

		struct sockaddr_in serveraddr;
		int sock;
		WSADATA wsaData;
		int port = 80;

		if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
			return FALSE;

		if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
			return FALSE;

		memset(&serveraddr, 0, sizeof(serveraddr));

		hostent *record = gethostbyname(this->Host.c_str());
		in_addr *address = (in_addr * )record->h_addr;
		string ipd = inet_ntoa(* address);
		const char *ipaddr = ipd.c_str();

		serveraddr.sin_family = AF_INET;
		serveraddr.sin_addr.s_addr = inet_addr(ipaddr);
		serveraddr.sin_port = htons(port);

		if (connect(sock, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0)
			return FALSE;
		if (send(sock, this->Request.c_str(), this->Request.length(), 0) != this->Request.length())
			return FALSE; 

		int nRecv = BUFFERSIZE;
		bool bSuccess = true;

		double currentPos = 0;
		int tmpSize = BUFFERSIZE * 4;
		this->Response = malloc(tmpSize);

		while(nRecv == BUFFERSIZE)
		{
			memset(buffer, 0, BUFFERSIZE);
			nRecv = recv(sock, (char*)&buffer, BUFFERSIZE, 0);
			if(nRecv > 0)
			{
				if(currentPos + nRecv > tmpSize)
				{
					void* newTmp = malloc(tmpSize * 4);
					tmpSize = tmpSize*4;
					memcpy((void*)(newTmp), (void*)(this->Response), currentPos);
					free(this->Response);
					this->Response = newTmp;
				}
				memcpy((void*)((int)this->Response + (int)currentPos), (void*)(buffer), nRecv);
				currentPos += nRecv;

				string Response = string((char*)this->Response);

				if(this->ResponseCode == -1 && Response.find("HTTP/") != string::npos)
					this->ResponseCode = atoi(Response.substr(Response.find("HTTP/") + 9).substr(0,3).c_str());	

				if(this->ContentLength == 0 && Response.find("Content-Length") != string::npos)
					this->ContentLength = atof(Response.substr(Response.find("Content-Length") + 16).substr(0, Response.find("\r\n", Response.find("Content-Length"))).c_str());	
			}
			else 
			{
				bSuccess = false;
				break;
			}
		}
		string Response = string((char*)this->Response);
		if(bSuccess){
			this->ResponseHeaders = Response.substr(0, Response.find("\r\n\r\n"));

			this->ResponseLength = currentPos - this->ResponseHeaders.size() - 4;
			this->ResponseBody = malloc(ResponseLength);

			memcpy((void*)(this->ResponseBody), (void*)((int)this->Response + Response.find("\r\n\r\n") + 4), ResponseLength);

			this->ResponseBodyString = string((char*)(ResponseBody)).substr(0, this->ResponseLength);
		}
		closesocket(sock);
		WSACleanup();

		return TRUE;
	} 

	bool SaveToFile(string Path)
	{
		if(this->Run() == true)
		{
			FILE* fp = fopen(Path.c_str(), "wb");
			fwrite((void*)(this->ResponseBody), this->ResponseLength, 1, fp);
			fclose(fp);
			return TRUE;
		}
		return FALSE;
	}
	void CNetHTTP::AddHeaders(string Key, string Value)
	{
		string NewHeaders = Key + ": " + Value;
		this->Headers.push_back(NewHeaders);
	}
	void CNetHTTP::AddParameter(string Key, string Value)
	{
		string NewParams;
		if(this->Method == "GET")
		{
			NewParams = Key + "=" + Value;
		}
		else if(this->Method == "POST")
		{
			NewParams = "Content-Disposition: form-data; name=\"" + Key +"\"\r\n\r\n" + Value;
		}
		this->Parameters.push_back(NewParams);
	}
	void CNetHTTP::AddFiles(string FieldName, string Filename, string ContentType, string Path )
	{
		FILE* fp = fopen(Path.c_str(), "rb");
		fseek(fp,0,SEEK_END);
		long Size = ftell(fp);
		void* Buffer = malloc(Size);
		fseek(fp,0,SEEK_SET);
		fread(Buffer, Size, 1, fp);
		fclose(fp);

		string NewFiles = "Content-Disposition: form-data; name=\"" + FieldName + "\"; filename=\"" + Filename + "\"\r\nContent-Type: " + ContentType + "\r\n\r\n";
		for(long i = 0; i < Size; i++)
			NewFiles += *(char*)((long)Buffer + i);

		free(Buffer);

		this->Files.push_back(NewFiles);
	}
	void CNetHTTP::AddFiles(string FieldName, string Filename, string ContentType, void* Buffer, long Size)
	{
		string NewFiles = "Content-Disposition: form-data; name=\"" + FieldName + "\"; filename=\"" + Filename + "\"\r\nContent-Type: " + ContentType + "\r\n\r\n";
		for(long i = 0; i < Size; i++)
			NewFiles += *(char*)((long)Buffer + i);
		this->Files.push_back(NewFiles);
	}
};