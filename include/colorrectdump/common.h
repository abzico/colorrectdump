#ifndef CRD_COMMON_h
#define CRD_COMMON_h

#ifdef __cplusplus
extern "C" {
#endif

/// ***be careful not to use this macro in statement without { } wrapping around the code
/// as we don't to add empty while loop to project the code section
#ifdef CRD_DEBUG
#define CRD_LOG(f, ...) fprintf(stdout, f, ##__VA_ARGS__);
#define CRD_ELOG(f, ...) fprintf(stderr, f, ##__VA_ARGS__);
#else
#define CRD_LOG(f, ...)
#define CRD_ELOG(f, ...)
#endif

/**
 * Exit with input status number.
 *
 * \param status status number to exit the program with.
 */
extern void crd_exitnow(int status);

/**
 * Exit the program with input status, but print text format to stderr first before exiting.
 *
 * \param status status number to exit the program with
 * \param err_str_format format string to print to stderr first before exiting
 */
extern void crd_exitnow_text(int status, const char* err_str_format, ...);

#ifdef __cplusplus
}
#endif

#endif
