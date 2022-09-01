#include<Windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {
	int nRet=MessageBox(NULL, TEXT("Hello world!"), TEXT("Caption"),
		MB_OKCANCEL | MB_ICONINFORMATION | MB_DEFBUTTON2);
	switch (nRet) {
	case IDOK:
		MessageBox(NULL, TEXT("用户单击了确定按钮"), TEXT("Caption"), MB_OK);
		break;
	case IDCANCEL:
		MessageBox(NULL, TEXT("用户点击了取消安妮"),TEXT("Caption"),MB_OK);
		break;
	}
	return 0;
}