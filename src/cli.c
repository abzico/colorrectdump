#include "colorrectdump/cli.h"
#include <stdio.h>

void crd_print_help(int fd)
{
  const char* help_text = "Usage: colorrectdump image-filepath|--help|--version";

  if (fd == 1)
  {
    fprintf(stdout, "%s\n", help_text);
  }
  else
  {
    fprintf(stderr, "%s\n", help_text);
  }
}

void crd_print_version(int fd)
{
  const char* version_text = "colorrectdump v0.1 by Angry Baozi";

  if (fd == 1)
  {
    fprintf(stdout, "%s\n", version_text);
  }
  else
  {
    fprintf(stderr, "%s\n", version_text);
  }
}
