#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int c;
  int aflag = 0;
  int bflag = 0;
  int numoption = 0;
  char txtoption[56] = "default";

  opterr = 0;

  while ((c = getopt(argc, argv, "abn:t:")) != EOF) {
    switch (c) {
      case 'a':
        aflag = 1;
        break;
      case 'b':
        bflag = 1;
        break;
      case 'n':
        numoption = atoi(optarg);
        break;
      case 't':
        strcpy(txtoption, optarg);
        break;
      default:
        fprintf(stderr, "Invalid option: -%c\n", optopt);
    }
  }

  if (aflag) printf("Option a is set\n");
  if (bflag) printf("Option b is set\n");
  printf("Numeric option = %d\n", numoption);
  printf("Text option = %s\n", txtoption);

  /* OK, now we have finished dealing with the options.  argv has been
     re-ordered so that all the non-option  arguments come at the end.
     optind is now the index in argv of the first non-option argument.
  */

  argv += optind;
  argc -= optind;

  while (argc--) { printf("arg: %s\n", *argv++); }

  return EXIT_SUCCESS;
}