#include "colorrectdump/common.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void crd_exitnow(int status)
{
  exit(status);
}

void crd_exitnow_text(int status, const char* err_str_format, ...)
{
  va_list arg_list;
  va_start(arg_list, err_str_format);
  vfprintf(stderr, err_str_format, arg_list);
  va_end(arg_list);

  exit(status);
}

