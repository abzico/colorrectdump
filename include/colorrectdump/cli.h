#ifndef CRD_CLI_h
#define CRD_CLI_h

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Print help text message.
 * Usually this function is used when user enters in '--help' parameter, or malformed parameter.
 *
 * \param fd it can be 1 or 2, if it's 1 print into standard output, otherwise will print into stadard error.
 */
extern void crd_print_help(int fd);

/**
 * Print version information text.
 *
 * \param fd it can be 1 or 2, if it's 1 print into standard output, otherwise will print into stadard error.
 */
extern void crd_print_version(int fd);

#ifdef __cplusplus
}
#endif

#endif
