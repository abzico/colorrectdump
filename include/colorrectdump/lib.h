#ifndef CRD_LIB_h
#define CRD_LIB_h

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Safe margin used when return the result after processing.
 */
#define DEFAULT_MARGIN 8

/**
 * Structure to hold result information back from processing.
 */
typedef struct CRDResult_s {
  int offset_x;
  int offset_y;
  int width;
  int height;
} CRDResult;

/**
 * Process input image to find color rectangular area that
 * has all color pixels inside.
 *
 * \param image_filepath Input image filepath to process
 * \param error in case of error, it will return non-zero error code number filled in to this variable and CRDResult will not be useful and will be initialized with -1 for all properties.
 * \return result of operation in CRDResult structure
 */
extern CRDResult crd_process_and_find_colorrect(const char* image_filepath, int* error);

#ifdef __cplusplus
}
#endif

#endif
