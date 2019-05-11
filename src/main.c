#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colorrectdump/colorrectdump.h"

int main(int argc, char** argv)
{
  // possible arguments would be
  // * input-image-filepath
  // * --help
  // * --version
  if (argc < 2)
  {
    fprintf(stderr, "Not enough parameters!\n");
    crd_print_help(2);
    crd_exitnow(1);
  }
  else
  {
    // in case of --help parameter
    if (strcmp(argv[1], "--help") == 0)
    {
      crd_print_help(1);
      crd_exitnow(0);
    }
    else if (strcmp(argv[1], "--version") == 0)
    {
      crd_print_version(1);
      crd_exitnow(0);
    }
    // this means the first parameter is actually our filepath
    else
    {
      int error = 0;
      CRDResult result = crd_process_and_find_colorrect(argv[1], &error);
      if (error > 0)
      {
        // error actually happens
        crd_exitnow(1);
      }

      // print result out
      printf("%d %d %d %d", result.x_min, result.y_min, result.x_max, result.y_max);
    }
  }

  return 0;
}
