#include<stdio.h>    
#include<stdlib.h>    
#include<netinet/in.h>    
#include<sys/socket.h>    
#include<arpa/inet.h>    
#include<string.h>    
#include<unistd.h>    
#define BACKLOG 5      
#define CONCURRENT_MAX 8    
#define SERVER_PORT 11332    
#define BUFFER_SIZE 1024    
#define QUIT_CMD ".quit"    
int client_fds[CONCURRENT_MAX];    
int main(int argc, const char * argv[])    
{    
    int i;
    char input_msg[BUFFER_SIZE];    
    char recv_msg[BUFFER_SIZE];    
    //���ص�ַ    
    struct sockaddr_in server_addr;    
    server_addr.sin_family = AF_INET;    
    server_addr.sin_port = htons(SERVER_PORT);    
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");    
    bzero(&(server_addr.sin_zero), 8);    
    //����socket    
    int server_sock_fd = socket(AF_INET, SOCK_STREAM, 0);    
    if(server_sock_fd == -1)    
    {    
        perror("socket error");    
        return 1;    
    }    
    //��socket    
    int bind_result = bind(server_sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));    
    if(bind_result == -1)    
    {    
        perror("bind error");    
        return 1;    
    }    
    //listen    
    if(listen(server_sock_fd, BACKLOG) == -1)    
    {    
        perror("listen error");    
        return 1;    
    }    
    //fd_set    
    fd_set server_fd_set;    
    int max_fd = -1;    
    struct timeval tv;  //��ʱʱ������    
    while(1)    
    {    
        tv.tv_sec = 20;    
        tv.tv_usec = 0;    
        FD_ZERO(&server_fd_set);    
        FD_SET(STDIN_FILENO, &server_fd_set);    
        if(max_fd <STDIN_FILENO)    
        {    
            max_fd = STDIN_FILENO;    
        }    
        //printf("STDIN_FILENO=%d\n", STDIN_FILENO);    
    //��������socket    
        FD_SET(server_sock_fd, &server_fd_set);    
       // printf("server_sock_fd=%d\n", server_sock_fd);    
        if(max_fd < server_sock_fd)    
        {    
            max_fd = server_sock_fd;    
        }    
    //�ͻ�������    
        for(i=0; i < CONCURRENT_MAX; i++)    
        {    
            //printf("client_fds[%d]=%d\n", i, client_fds[i]);    
            if(client_fds[i] != 0)    
            {    
                FD_SET(client_fds[i], &server_fd_set);    
                if(max_fd < client_fds[i])    
                {    
                    max_fd = client_fds[i];    
                }    
            }    
        }    
        int ret = select(max_fd + 1, &server_fd_set, NULL, NULL, &tv);    
        if(ret < 0)    
        {    
            perror("select ����\n");    
            continue;    
        }    
        else if(ret == 0)    
        {    
            printf("select ��ʱ\n");    
            continue;    
        }    
        else    
        {    
            //ret Ϊδ״̬�����仯���ļ��������ĸ���    
            if(FD_ISSET(STDIN_FILENO, &server_fd_set))    
            {    
                printf("������Ϣ��\n");    
                bzero(input_msg, BUFFER_SIZE);    
                fgets(input_msg, BUFFER_SIZE, stdin);    
                //���롰.quit"���˳�������    
                if(strcmp(input_msg, QUIT_CMD) == 0)    
                {    
                    exit(0);    
                }    
                for(i = 0; i < CONCURRENT_MAX; i++)    
                {    
                    if(client_fds[i] != 0)    
                    {    
                        printf("client_fds[%d]=%d\n", i, client_fds[i]);    
                        send(client_fds[i], input_msg, BUFFER_SIZE, 0);    
                    }    
                }    
            }    
            if(FD_ISSET(server_sock_fd, &server_fd_set))    
            {    
                //���µ���������    
                struct sockaddr_in client_address;    
                socklen_t address_len;    
                int client_sock_fd = accept(server_sock_fd, (struct sockaddr *)&client_address, &address_len);    
                printf("new connection client_sock_fd = %d\n", client_sock_fd);    
                if(client_sock_fd > 0)    
                {    
                    int index = -1;    
                    for(i = 0; i < CONCURRENT_MAX; i++)    
                    {    
                        if(client_fds[i] == 0)    
                        {    
                            index = i;    
                            client_fds[i] = client_sock_fd;    
                            break;    
                        }    
                    }    
                    if(index >= 0)    
                    {    
                        printf("�¿ͻ���(%d)����ɹ� %s:%d\n", index, inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));    
                    }    
                    else    
                    {    
                        bzero(input_msg, BUFFER_SIZE);    
                        strcpy(input_msg, "����������Ŀͻ������ﵽ���ֵ,�޷�����!\n");    
                        send(client_sock_fd, input_msg, BUFFER_SIZE, 0);    
                        printf("�ͻ����������ﵽ���ֵ���¿ͻ��˼���ʧ�� %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));    
                    }    
                }    
            }    
            for(i =0; i < CONCURRENT_MAX; i++)    
            {    
                if(client_fds[i] !=0)    
                {    
                    if(FD_ISSET(client_fds[i], &server_fd_set))    
                    {    
                        //����ĳ���ͻ��˹�������Ϣ    
                        bzero(recv_msg, BUFFER_SIZE);    
                        long byte_num = recv(client_fds[i], recv_msg, BUFFER_SIZE, 0);    
                        if (byte_num > 0)    
                        {    
                            if(byte_num > BUFFER_SIZE)    
                            {    
                                byte_num = BUFFER_SIZE;    
                            }    
                            recv_msg[byte_num] = '\0';    
                            printf("�ͻ���(%d):%s\n", i, recv_msg);    
                        }    
                        else if(byte_num < 0)    
                        {    
                            printf("�ӿͻ���(%d)������Ϣ����.\n", i);    
                        }    
                        else    
                        {    
                            FD_CLR(client_fds[i], &server_fd_set);    
                            client_fds[i] = 0;    
                            printf("�ͻ���(%d)�˳���\n", i);    
                        }    
                    }    
                }    
            }    
        }    
    }    
    return 0;    
}   
