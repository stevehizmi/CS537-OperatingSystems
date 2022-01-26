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

  if (argc < 2) {
    printf("my-look: invalid command line\n");
    exit(1);
  }
  while ((option = getopt(argc, argv, "Vhf:")) != -1) {
    switch (option) {
      case 'V':
        printf("my-look from CS537 Spring 2021\n");
        exit(0);
      case 'h':
        printf("\n********** Help Page **********\n");
        printf("For version, type './my-look -V'\n");
        printf("For help, type './my-look -h\n");
        printf("To read from a file, type './my-look -f <filename>\n");
        printf("If error is printed, command used incorrectly\n\n");
        exit(0);
      case 'f':
        file = fopen(optarg, "r");
        if (file == NULL) {
          printf("my-look: cannot open file\n");
          exit(1);
         }
        flag = 1;
        break;
      default:
        printf("my-look: invalid command line\n");
        exit(1);
    }
  }
  if (optind < argc-1) {
    printf("my-look: invalid command line\n");
    exit(1);
  }
  char *prefix = argv[optind];
  if (flag == 0)
    file = stdin;
  while (fgets(buf, BUF_SIZE, file) != NULL) {
    if (strncasecmp(buf, prefix, strlen(prefix)) == 0)
      printf("%s", buf);
  }
fclose(file);
  return 0;
}
