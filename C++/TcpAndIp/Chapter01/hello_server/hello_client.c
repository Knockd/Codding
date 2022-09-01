#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
void error_handling(char* message);

int main(int argc,char * argv[]) {
	int sock;
	//连接结构
	struct sockaddr_in serv_addr;
	char message[30];
	int str_len;

	if (argc != 3)
	{
		printf("Usage: %s<port>\n", argv[0]);
	}
	//发起连接，获取句柄。
	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock == -1)
		error_handling("socket() error");
	//为sev_addr分配堆内存
	memset(&serv_addr, 0, sizeof(serv_addr));
	//设置serv_addr结构的IP和端口，和通信协议。 
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	//连接到套接字。
	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
		error_handling("connect() error");
	//
	str_len = read(sock, message, sizeof(message) - 1);
	if (str_len == -1)
		error_handling("read() error!");
	printf("Message from server:%s \n", message);
	close(sock);
	return 0;
}
void error_handling(char* message)
{
	fputs(message, stderr);
	fputc('c', stderr);
	exit(1);
}