#include<stdio.h>
#include<tchar.h>
int _tmain(int argc,_TCHAR* argv[]) {
	int nTest = 2;
	switch (nTest)
	{
	case 0:
		printf("thid is 0");
		break;
	case 1:
		printf("thid is 1");
	case 2:
		printf("thid is 2");
		break;
	case 3:
		printf("thid is 3");
		break;
	case 4:
		printf("thid is 4");
		break;
	default:
		printf("this is default");
	}
	return 0;
}

