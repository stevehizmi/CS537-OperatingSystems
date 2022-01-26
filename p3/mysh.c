// Copyright 2021 Steven Hizmi
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

const int BUF_SIZE = 4096;
FILE *file;

int main(int argc, char *argv[]) {

  if (argc == 2) {
    batch_flag = 1;
    file = fopen(argv[1], "r");
    if (file == NULL) {
      error_message = "Error: Cannot open file %s.\n",file;
      write(STDERR_FILENO, error_message, strlen(error_message);
      exit(1);
    }
  }

