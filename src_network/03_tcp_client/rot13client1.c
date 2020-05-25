//
// Created by Prateek Agarwal on 25/5/20.
//

#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BSIZE 1024

int main(int argc, char **argv) {
  struct hostent *host_info;
  struct sockaddr_in server;
  int sock, count;
  char buf[BSIZE];
  char *server_name;

  server_name = (argc > 1) ? argv[1] : "localhost";

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("creating stream socket");
    exit(1);
  }

  host_info = gethostbyname(server_name);
  if (host_info == NULL) {
    fprintf(stderr, "%s: unknown host: %s\n", argv[0], server_name);
    exit(2);
  }

  server.sin_family = AF_INET;
  memcpy((char *) &server.sin_addr, host_info->h_addr, host_info->h_length);
  server.sin_port = htons(1067);

  if (connect(sock, (struct sockaddr *) &server, sizeof server) < 0) {
    perror("connecting to server");
    exit(4);
  }

  printf("connected to server %s\n", server_name);
  while ((count = read(0, buf, BSIZE)) > 0) {
    write(sock, buf, count);
    read(sock, buf, count);
    write(1, buf, count);
  }
}