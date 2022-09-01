#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
void error_handling(char* message);


//struct sockaddr_in{

//}
int main(int argc, char* argv[])
{
	int serv_sock;
	int clnt_sock;

	//服务结构和客户端结构
	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size;

	char message[] = "hello world";
	if (argc != 2)
	{
		printf("Usage:%s<port>\n", argv[0]);
		exit(1);
	}
	//配置一个套接字，等于电话机
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (serv_sock == -1)
		error_handling("socket() error");
	//分配堆内存
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));
	//绑定套接字，为套接字分配serv_addr,
	if (bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
		error_handling("bind() error");
	//端口开放成连接状态。
	if (listen(serv_sock, 5) == -1)
		error_handling("listen error");
	clnt_addr_size = sizeof(clnt_addr);
	//来人了就获取请求，套接字，客户端地址，客户端地址结构长度
	clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
	if (clnt_sock == -1)
		error_handling("accept() error");
	//向套接字写入地址。
	write(clnt_sock, message, sizeof(message));
	close(clnt_sock);
	close(serv_sock);
	return 0;
}
void error_handling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

