#include <iostream>
#include <getopt.h>
#include "ifd.h"

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

int main(int argc, char *argv[]) {

    int opt = 0;
    int option_index = 0;
    
    static const struct option long_options[] = {
		{"rom", 1, NULL, 'r'},
		{"version", 0, NULL, 'v'},
		{"help", 0, NULL, 'h'},
		{0, 0, 0, 0}
	};

	while ((opt = getopt_long(argc, argv, "r:vh?", long_options, &option_index)) != EOF) {
		
        switch (opt) {		
            case 'r':
                open_rom_to_memory(argv[2]);
                return 0;
            case 'v':
                print_version();
                break;
            case 'h':
                print_help();
                break;
            case '?':
            default:
                print_help();
                break;
        }
    }

    if (argc == 1 || argv[2] == NULL) 
    {
        print_help();
        exit(EXIT_FAILURE);
    }

	return 0;
}
