//
// Created by Prateek Agarwal on 25/5/20.
//
//
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern time_t time();

char *word[] = {"hello", "hawaii", "prateek"};

#define NUM_OF_WORDS (sizeof(word) / sizeof(word[0]))
#define MAXLEN 80
#define HANGMAN_TCP_PORT 55555

void play_hangman(int in, int out);

int main(int argc, char *argv[]) {
  int sock, msgsock, client_len;
  struct sockaddr_in server, client;
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("creating stream socket");
    exit(1);
  }

  signal(SIGCHLD, SIG_IGN); // Avoids zombie children

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = htonl(INADDR_ANY);
  server.sin_port = htons(HANGMAN_TCP_PORT);

  if (bind(sock, (const struct sockaddr *) &server, sizeof(server)) < 0) {
    perror("binding socket");
    exit(2);
  }

  listen(sock, 5);

  fprintf(stdout, "hangman server: listening...\n");

  while (1) {
    client_len = sizeof(client);
    msgsock = accept(sock, (struct sockaddr *) &client, (socklen_t *) &client_len);
    if (msgsock < 0) {
      perror("accepting connection");
      exit(3);
    }

    if (fork() == 0) {
      // In child
      close(sock);
      printf("new child (pid %d) using descriptor %d\n", getpid(), msgsock);
      srand(*(unsigned int *) time((long *) 0));// Randomizing the seed
      play_hangman(msgsock, msgsock);
      printf("child (pid %d) exiting\n", getpid());
      exit(0);

    } else
      close(msgsock);
  }
}

void play_hangman(int in, int out){
  // IMPLEMENT LATER
}