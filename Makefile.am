ACLOCAL_AMFLAGS = -I m4

# cli program
bin_PROGRAMS = colorrectdump
colorrectdump_CFLAGS = -Wall \
											 -std=c99 \
											 -O2 \
											 -pedantic \
											 -I./include
colorrectdump_LDFLAGS = -lpng \
												-lz
colorrectdump_SOURCES = src/cli.c \
												src/common.c \
												src/lib.c \
												src/png_util.c \
												src/main.c

EXTRA_DIST = README.md LICENSE autogen.sh
