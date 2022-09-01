#include<Windows.h>
#include<tchar.h>
#include<windows.h>
#include<stdio.h>
bool DeleteKey(HKEY hMainKey, LPCWSTR lpSubKey)
{
	HKEY hSubKey;
	//���ؾ����hSubkey
	LONG ReturnValue = ::RegOpenKeyEx(hMainKey, lpSubKey,
		0L, KEY_ENUMERATE_SUB_KEYS, &hSubKey);
	LONG lDelRetValue;
	TCHAR tcNewSubKey[256] = { 0 };
	if (ReturnValue == ERROR_SUCCESS) {
		TCHAR tcKeyName[128];
		DWORD dwKeyNameSize = 128;
		int i = 0, retCode = 0;
		while (1) {
			//������ڴ棬��tckname����256��TCAHR����ġ�
			memset(tcKeyName, 0, 256 * sizeof(TCHAR));
			//�Ƚ�����
			_tcscpy(tcNewSubKey, lpSubKey);
			//����\\
			_tcscat(tcNewSubKey, _T("\\"));

			retCode = RegEnumKeyEx(hSubKey, 0, tcKeyName, &dwKeyNameSize,
				NULL, NULL, NULL, NULL);
			if (retCode == ERROR_NO_MORE_ITEMS) {
				break;
			}
			_tcscat(tcNewSubKey, tcKeyName);
			if (!DeleteKey(hMainKey, tcNewSubKey))
			{
				return FALSE;
			}
			dwKeyNameSize = 128;
		}

	}
	lDelRetValue = RegDeleteKey(hMainKey, lpSubKey);
	return lDelRetValue == ERROR_SUCCESS;
}
int main(int argc, char* argv[])
{
	if (DeleteKey(HKEY_CURRENT_USER, (LPCWSTR)"a"))
	{
		printf("�ɹ�ɾ��");

	}
	else {
		printf("ɾ��ʧ��");
	}
	return 0;

}