// GetIPConfig.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#pragma comment(lib,"IPHLPAPI.lib")
#include<WinSock2.h>
#include<iphlpapi.h>
#include <stdio.h>

int _tmain()
{
    //指定获取到的网络信息结构体链表的指针
    IP_ADAPTER_INFO* pAdapterInfo;

    ULONG uLOutBufLen;
    DWORD dwRetVal;
    PIP_ADAPTER_INFO pAdapter;

    pAdapterInfo = (IP_ADAPTER_INFO*)malloc(sizeof(IP_ADAPTER_INFO));
    uLOutBufLen =sizeof(IP_ADAPTER_INFO);
    if (GetAdaptersInfo(pAdapterInfo, &uLOutBufLen) != ERROR_SUCCESS)
    {
        free(pAdapterInfo);
        pAdapterInfo=(IP_ADAPTER_INFO*)malloc(uLOutBufLen);

    }
    if (dwRetVal = GetAdaptersInfo(pAdapterInfo, &uLOutBufLen) != ERROR_SUCCESS)
    {
        printf("GetAdaptersInfo Error! %d\n", dwRetVal);
    }
    pAdapter = pAdapterInfo;

    while (pAdapter)
    {
        printf("网络适配名: \t\t%s\n", pAdapter->AdapterName);
        printf("网络适配器描述: \t%s\n\n", pAdapter->Description);
        printf("MAC 地址：\t\t");
        for (unsigned int i=0;i<pAdapter->AddressLength;i++)
        {
            if (i == (pAdapter->AddressLength - 1))
                printf("%.2X\n", (int)pAdapter->Address[i]);
            else
                printf("%.2X-", (int)pAdapter->Address[i]);

        }
        printf("IP 地址: \t\t%s\n", pAdapter->IpAddressList.IpAddress.String);
        printf("子网掩码：\t\t%s\n", pAdapter->IpAddressList.IpMask.String);
        printf("网关：\t\t\t%s\n", pAdapter->GatewayList.IpAddress.String);

        printf("**************************************************8\n");
        if (pAdapter->DhcpEnabled)
        {
            printf("启用DHCP: \t\t 是\n");
            printf("DHCP服务器: \t\t%s\n", pAdapter->DhcpServer.IpAddress.String);

        }
        else {
            printf("启用DHCP: \t\t 否\n");
        }
        pAdapter = pAdapter ->Next;
    }
    if (pAdapterInfo)
        free(pAdapterInfo);
    printf("\n\n");
    system("pause");
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

渗透测试：今日对CMDB_IP进行全端口IP扫描，对扫描端口进行HTTP服务识别，对存在http服务的尝试访问
Server.log文件；利用nmap对端口识别，利用script扫描漏洞；巡检：设备运行正常；