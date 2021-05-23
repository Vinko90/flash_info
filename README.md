[![GPLv3 license](https://img.shields.io/badge/License-GPLv3-blue.svg)](http://perso.crans.org/besson/LICENSE.html) [![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://GitHub.com/Naereen/StrapDown.js/graphs/commit-activity)

# Flash_Info

The following tool is used to display on screen the partition schema and relative addresses of a BIOS binary image file.

## Compile

Any GNU C++ compile which support C++17 will be sufficient. Run the "make" command to compile the executable.

## Usage

After compiling the tool, run the application as follow: 

```
flash_info [-rhv] <filename.rom>

            -r | --rom <filename.rom>        Print the layout of the rom file
            -v | --version                   Print the app version
            -h | --help                      Print this help
```
