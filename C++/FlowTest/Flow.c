// FlowTest.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include<stdio.h>
int read_it=1;
int write_it;
int ref_it=1;
void callfow() {
    printf("hello this is callfow\n");
}
int main()
{
    int* p = &ref_it;
    *p = read_it;
    write_it = *p;
    callfow();  
    if (read_it == 3) {
        write_it = 2;
    }
    else {
        write_it = 1;
    }
    printf("our have the number : %d \n", write_it);
    callfow();

}

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
