#include <windows.h>

HINSTANCE myHandle;
	
int CALLBACK KeyboardProc(int nCode, DWORD wParam, DWORD lParam)
{
	KBDLLHOOKSTRUCT* p;
	char* text = "[color=Red][������� �����������][/color]'";
	switch(wParam)
	{
		case WM_KEYDOWN:
			p = (KBDLLHOOKSTRUCT*) lParam;
            if(p->vkCode == VK_PAUSE) {
				//MessageBox(NULL,"Press key pause!","Test",MB_OK);

				// �.�. GetFocus �������� ��� ���� ������ �������� ��������
				// ��������� ������� ������� � ������
				HWND fw = GetForegroundWindow();
				DWORD tid = GetCurrentThreadID();
				DWORD ftid = GetWindowThreadProcessId(fw, NULL);
				AttachThreadInput(tid, ftid, 1);
				//{ ������������ ���� ����������� }
				SetForeGroundWindow(myHandle);
				
				//{ ������ ��������� ����� }
				SendMessage(GetFocus(), WM_SETTEXT, 0, (int) text);
				//{ ����������� �������� }
				AttachThreadInput(tid, ftid, 0);
			}
		
			
		break;
	}

	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	myHandle = hInstance;
	SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)&KeyboardProc, GetModuleHandle(NULL), 0);

	MessageBox(NULL,"Hello, World!","Test",MB_OK);
	return 0;
}
