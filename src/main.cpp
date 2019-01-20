#include <iostream>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include "ifd.h"

#ifndef O_BINARY
    #define O_BINARY 0
#endif

using namespace std;

static void print_version()
{
    cout << "flash_info version: v1.0" << endl;
    cout << "by WarOfDevil" << endl;
}

static void print_help()
{
    cout << "Usage: flash_info [-rhv] <filename.rom>" << endl << endl
         << "   -r | --rom <filename.rom>        Print the layout of the rom file" << endl
         << "   -v | --version                   Print the app version" << endl
         << "   -h | --help                      Print this help" << endl;
}

static void convert_bytes(int size)
{
    cout << "Bytes: " << size << endl;
    cout << "Kb: " << size/1024 << endl;
    cout << "Mb " << size/1024/1024 << endl;
}

int main(int argc, char *argv[]) {

    int opt = 0;
    int option_index = 0;
    
    char *rom_file;
    int bios_descriptor = -1;
    int bios_size = -1;
    struct stat bios_buffer;

    static const struct option long_options[] = {
		{"rom", 1, NULL, 'r'},
		{"version", 0, NULL, 'v'},
		{"help", 0, NULL, 'h'},
		{0, 0, 0, 0}
	};

	while ((opt = getopt_long(argc, argv, "r:vh?", long_options, &option_index)) != EOF) {
		
        switch (opt) {		
            case 'r':
                rom_file = argv[2];
                break;
            case 'v':
                print_version();
                exit(EXIT_SUCCESS);
                break;
            case 'h':
                print_help();
                exit(EXIT_SUCCESS);
                break;
            case '?':
            default:
                print_help();
                exit(EXIT_SUCCESS);
                break;
        }
	}

    cout << "Preparing to opening the rom: " << rom_file << endl;
	
    bios_descriptor = open(rom_file, O_RDONLY | O_BINARY);
    if (bios_descriptor == -1)
    {
       cout << "Could not open the rom file" << endl;
       exit(EXIT_FAILURE);
    }
	
	if (fstat(bios_descriptor, &bios_buffer) == -1) {
		perror("Could not stat the rom file");
		exit(EXIT_FAILURE);
	}
	
    bios_size = bios_buffer.st_size;

	cout << "File " << rom_file << " is ";
    convert_bytes(bios_size);

	char *image = malloc(bios_size);
	if (!image) {
		printf("Out of memory.\n");
		exit(EXIT_FAILURE);
	}

	if (read(bios_descriptor, image, bios_size) != bios_size) {
		perror("Could not read file");
		exit(EXIT_FAILURE);
	}

	close(bios_descriptor);

	//check_ifd_version(image, size);

	free(image);

	return 0;

}

