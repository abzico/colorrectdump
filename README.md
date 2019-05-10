# colorrectdump

A tool to find rectangular area for color pixels that live in the input .png image.

# Build

Depends on [libpng](http://www.libpng.org/pub/png/libpng.html), so install it first.

* `./autogen.sh`
* `./configure`
* `make -j4`
* `sudo make install`

# Usage

`colorrectdump input-image-filepath|--help|--version`

Example:

`colorrectdump /path/to/my/image.png`

it will print out result with 4 numbers onto starndard output in format `offset-x offset-y width height` in which offset x/y is the top left corner of the rectangular area. You can further use batch/bash script to do batch process with this output later on.

# NOTE

Currently it works only with RGBA .png file format that has transparent pixels. If you input opaque image like grayscale, or RGB format, the output is not defined as well as its behavior. This feature will be considered to add later.

# LICENSE

[MIT](https://github.com/abzico/colorrectdump/blob/master/LICENSE), [Angry Baozi](https://abzi.co)
