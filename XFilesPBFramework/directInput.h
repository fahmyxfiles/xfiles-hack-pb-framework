#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#pragma comment (lib,"dinput8.lib")
#pragma comment (lib,"dxguid.lib")

/////////////////////////////////////////////////////////////////////////////////
LPDIRECTINPUT8 Input;
void InitializeDirectInput();
void UpdateDirectInput();
void DirectInputLoop();
/////////////////////////////////////////////////////////////////////////////////
LPDIRECTINPUTDEVICE8 Keyboard;
void InitializeKeyboard();
void UpdateKeyboard();
char* getKeyboardState();   
bool IsKeyboardKeyDownOnce(int Index);

char KeyboardState[256];
bool KeyPressed[256] = {0};
/////////////////////////////////////////////////////////////////////////////////
LPDIRECTINPUTDEVICE8 Mouse; 
void InitializeMouse();
void UpdateMouse();

typedef struct {
	int x;          //x-location of mouse
	int y;          //y-location of mouse
	bool button[2];  //is button 1 held down?
} MOUSE;
MOUSE mouse;
bool MousePressed[2] = {0};
HANDLE MouseEvent;
#define DIM_LBUTTON 0
#define DIM_RBUTTON 1
#define DIM_MBUTTON 2
/////////////////////////////////////////////////////////////////////////////////
void InitializeDirectInput()
{
	 DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&Input, NULL);
}
void UpdateDirectInput()
{
	if(Keyboard == NULL)InitializeKeyboard();
	else UpdateKeyboard();
	if(Mouse == NULL)InitializeMouse();
	else UpdateMouse();
}
void DirectInputLoop()
{
	if(Input == NULL)InitializeDirectInput();
	else UpdateDirectInput();
}
/////////////////////////////////////////////////////////////////////////////////
void InitializeKeyboard()
{  
    Input->CreateDevice(GUID_SysKeyboard, &Keyboard, NULL);
    Keyboard->SetDataFormat(&c_dfDIKeyboard);
    Keyboard->SetCooperativeLevel(GetForegroundWindow(), DISCL_FOREGROUND|DISCL_NONEXCLUSIVE);
    Keyboard->Acquire();
}
void UpdateKeyboard()
{
	HRESULT res = Keyboard->GetDeviceState(sizeof(KeyboardState),(LPVOID)&KeyboardState); 
	if FAILED(res)
	{ 
		Keyboard->Release();
		Keyboard = NULL;
		return;
	}
}
bool GetKeyboardPressState(int nIndex)
{
    return (KeyboardState[nIndex] && 0x80);
}
bool IsKeyboardKeyDownOnce(int Index){
	if(GetKeyboardPressState(Index)){
		if(KeyPressed[Index] == false){
			KeyPressed[Index] = true;
			return true;
		} else return false;
	} else KeyPressed[Index] = false;
	return false;
}
/////////////////////////////////////////////////////////////////////////////////
void InitializeMouse()
{
	MouseEvent = CreateEvent( NULL, FALSE, FALSE, NULL );

	Input->CreateDevice( GUID_SysMouse, &Mouse, NULL );

	Mouse->SetDataFormat( &c_dfDIMouse );
	Mouse->SetCooperativeLevel( GetForegroundWindow(),	DISCL_EXCLUSIVE | DISCL_FOREGROUND);
	Mouse->SetEventNotification( MouseEvent );

	DIPROPDWORD dipdw;
	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj = 0;
	dipdw.diph.dwHow = DIPH_DEVICE;
	dipdw.dwData = 16;

	Mouse->SetProperty( DIPROP_BUFFERSIZE, &dipdw.diph );
}
void UpdateMouse()
{
	DIDEVICEOBJECTDATA  od;
	DWORD               dwElements;

    dwElements = 1;
    HRESULT res = Mouse->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), &od, &dwElements, 0);

	if FAILED(res)
	{ 
		Mouse->Release();
		Mouse = NULL;
		return;
	}

	if(dwElements == 0)return;

	switch (od.dwOfs) 
    {     
		case DIMOFS_X:	// Mouse horizontal motion 
			mouse.x+=od.dwData;
		break;

		case DIMOFS_Y:	// Mouse vertical motion 
			mouse.y+=od.dwData;
		break;
      
		case DIMOFS_BUTTON0: // Left button pressed or released 
			if ( od.dwData & 0x80 ) mouse.button[0]=TRUE; else mouse.button[0]=FALSE;
		break;
      
		case DIMOFS_BUTTON1: // Right button pressed or released 
			if ( od.dwData & 0x80 ) mouse.button[1]=TRUE; else mouse.button[1]=FALSE;
		break;

		case DIMOFS_BUTTON2: // Middle button pressed or released
			if ( od.dwData & 0x80 ) mouse.button[2]=TRUE; else mouse.button[2]=FALSE;
		break;
    }
}
bool GetMousePressState(int nIndex)
{
    return mouse.button[nIndex];
}
bool IsMouseKeyDownOnce(int Index){
	if(GetMousePressState(Index)){
		if(MousePressed[Index] == false){
			MousePressed[Index] = true;
			return true;
		} else return false;
	} else MousePressed[Index] = false;
	return false;
}