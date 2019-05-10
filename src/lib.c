#include "colorrectdump/lib.h"
#include "colorrectdump/png_util.h"
#include "colorrectdump/common.h"

CRDResult crd_process_and_find_colorrect(const char* image_filepath, int* error)
{
  // read in png image to get its image data pointer
  int rowbytes = 0;
  int width = 0;
  int height = 0;
  // TODO: Currently, no matter the input .png format, it gonna be converted into RGBA png file format
  png_bytepp image_data = crd_read_png_file(image_filepath, &rowbytes, &width, &height);

  // check error
  if (image_data == NULL)
  {
    CRD_ELOG("result image data from reading %s is NULL\n", image_filepath);
    // set error code back
    if (error != NULL)
    {
      *error = 1;
    }
  }

  CRDResult result = { -1, -1, -1, -1 };

  int x_min = width;
  int x_max = 0;
  int y_min = height;
  int y_max = 0;
  
  for (int y=0; y<height; ++y)
  {
    png_bytep row = image_data[y];

    for (int x=0; x<width; ++x)
    {
      png_bytep colorb = &row[x*4];
      
      // check if it is not fully transparent in alpha channel, then take it into consideration
      if (colorb[3] != 0)
      {
        if (x < x_min)
          x_min = x;
        if (x > x_max)
          x_max = x;

        if (y < y_min)
          y_min = y;
        if (y > y_max)
          y_max = y;
      }
    }
  }

  // compute the result
  result.offset_x = x_min - DEFAULT_MARGIN;
  if (result.offset_x < 0)
    result.offset_x = 0;
  result.offset_y = y_min - DEFAULT_MARGIN;
  if (result.offset_y < 0)
    result.offset_y = 0;
  result.width = x_max - x_min + DEFAULT_MARGIN*2;
  if (result.width > width)
    result.width = width;
  result.height = y_max - y_min + DEFAULT_MARGIN*2;
  if (result.height > height)
    result.height = height;

  return result;
}

