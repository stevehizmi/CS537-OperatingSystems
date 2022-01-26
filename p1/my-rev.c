// Copyright 2021 Steven Hizmi
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

const int BUF_SIZE = 4096;

int main(int argc, char **argv) {
  opterr = 0;
  int option;
  FILE *file = NULL;
  char buf[BUF_SIZE];
  int flag = 0;

  while ((option = getopt(argc, argv, "Vhf:")) != -1) {
    switch (option) {
      case 'V':
        printf("my-rev from CS537 Spring 2021\n");
        exit(0);
      case 'h':
        printf("\n********** Help Page **********\n");
        printf("For version, type './my-rev -V'\n");
        printf("For help, type './my-rev -h\n");
        printf("To read from a file, type './my-rev -f <filename>\n");
        printf("If error is printed, command used incorrectly\n\n");
        exit(0);
      case 'f':
        file = fopen(optarg, "r");
        if (file == NULL) {
          printf("my-rev: cannot open file\n");
        exit(1); }
        flag = 1;
        break;

      default:
        printf("my-rev: invalid command line\n");
        exit(1);
    }
  }
  if (optind < argc) {
    printf("my-rev: invalid command line\n");
    exit(1);
  }
  if (flag == 0)
    file = stdin;
  int start;
  int end;
  int temp;
  while (fgets(buf, BUF_SIZE, file) != NULL) {
    if (buf[strlen(buf)-1] == '\n')
      end = strlen(buf) - 2;
    else
      end = strlen(buf) - 1;
  start = 0;
  while (start < end) {
      temp = buf[start];
      buf[start] = buf[end];
      buf[end] = temp;
      start++;
      end--;
    }
  printf("%s", buf); }
  if (flag == 1)
    fclose(file);
  return 0; }
