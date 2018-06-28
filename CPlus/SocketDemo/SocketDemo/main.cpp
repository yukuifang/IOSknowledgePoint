//
//  main.cpp
//  SocketDemo
//
//  Created by fangyukui on 2018/6/28.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>

#include <stdlib.h>

#include <sys/socket.h>

#import <netinet/in.h>

#import <arpa/inet.h>

#import <unistd.h>

#define SERV_IP    "127.0.0.1"
#define SERV_PORT  6666

int main(int argc, const char * argv[]) {
    
    int lfd,cfd;
    
    struct sockaddr_in serv_addr,client_addr;
    
    socklen_t client_addr_len;
    
    char buf[BUFSIZ];
    
    int size;
    
    int i  ;
    
    lfd = socket(AF_INET, SOCK_STREAM, 0);
    
    serv_addr.sin_family = AF_INET;
    
    serv_addr.sin_port = htons(SERV_PORT);
    
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    bind(lfd, (sockaddr *)&serv_addr, sizeof(serv_addr));
    
    listen(lfd, 32);
    
    client_addr_len = sizeof(client_addr);
    
    cfd = accept(lfd, (sockaddr *)&client_addr,&client_addr_len);
    
    while(1){
        size = (int)read(cfd, buf, sizeof(buf));
        
        for (i=0; i< 5; i++) {
            buf[i] = toupper(buf[i]);
        }
        
        write(cfd, buf, sizeof(buf));
    }
    
    close(cfd);
    
    close(lfd);
    
    

    return 0;
    
}
