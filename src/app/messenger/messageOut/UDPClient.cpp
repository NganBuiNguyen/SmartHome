#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc,char **argv)
{
    int z = 0;
    int x = 0;
    char srvr_addr[256];
    struct sockaddr_in adr_srvr;
    struct sockaddr_in adr;
    int len_inet = 0;
    int fd = 0;
    char dgram[512];


    memset(&adr_srvr, 0, sizeof(adr_srvr));
    strcpy(srvr_addr, "192.168.1.177");

    adr_srvr.sin_family = AF_INET;
    adr_srvr.sin_port = htons(8789);
    adr_srvr.sin_addr.s_addr =  inet_addr(srvr_addr);

    if ( adr_srvr.sin_addr.s_addr == INADDR_NONE )
    {
        printf("bad address.");
    }

    len_inet = sizeof(adr_srvr);

    fd = socket(AF_INET, SOCK_DGRAM, 0);

    if ( fd == -1 )
    {
        printf("socket()"); 
    }
  
    strcpy(dgram, "EMB");
    
//    for (;;)
  //  {
        z = sendto(fd,
                   dgram,
                   strlen(dgram),
                   0,
                   (struct sockaddr *)&adr_srvr,
                   len_inet);

   // }

    close(fd);

    return 0;
}
