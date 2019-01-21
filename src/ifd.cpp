#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <fcntl.h>
//#include <fstream>
#include <unistd.h>
//#include <sys/types.h>
#include <sys/stat.h>
#include "ifd.h"

using namespace std;

/*static void convert_bytes(int size)
{
    cout << "Bytes: " << size << endl;
    cout << "Kb: " << size/1024 << endl;
    cout << "Mb " << size/1024/1024 << endl;
}*/




/*static const struct region_name region_names[MAX_REGIONS] = {
	{ "Flash Descriptor", "fd"},
	{ "BIOS", 			"bios"}, 
	{ "Intel ME", 		  "me"},
	{ "GbE", 			 "gbe"}, 
	{ "Platform Data",    "pd"}, 
	{ "Reserved_1",     "res1"}, 
	{ "Reserved_2",     "res2"}, 
	{ "Reserved_3",     "res3"}, 
	{ "EC",               "ec"}, 
};
*/
static char *bios_image;
static int  bios_size = -1;

void open_rom_to_memory(char* filename)
{
    int file_descriptor = -1;
    struct stat bios_buffer;
    
    cout << "Preparing to opening the rom: " << filename << endl;
	
    file_descriptor = open(filename, O_RDONLY | O_BINARY);
    if (file_descriptor == -1)
    {
       cout << "Could not open the rom file" << endl;
       exit(EXIT_FAILURE);
    }
	
	if (fstat(file_descriptor, &bios_buffer) == -1) {
		cout << "Could not stat the rom file" << endl;
		exit(EXIT_FAILURE);
	}
	
    bios_size = bios_buffer.st_size;
	cout << "Your ROM is " << bios_size/1024/1024 << "MB" << endl;
    
	bios_image = new char[bios_size];
    if (!bios_image) {
		cout << "Out of memory" << endl;
		exit(EXIT_FAILURE);
	}

	if (read(file_descriptor, bios_image, bios_size) != bios_size) {
		cout << "Could not read file" << endl; 
		exit(EXIT_FAILURE);
	}

	close(file_descriptor);

	//TBD
    //check_ifd_version();

    delete[] bios_image;
}

static void check_ifd_version(char *image, int size)
{
	if (is_platform_ifd_2())
		ifd_version = IFD_VERSION_2;
	else
		ifd_version = get_ifd_version_from_fcba(image, size);

	if (ifd_version == IFD_VERSION_1)
		max_regions = MAX_REGIONS_OLD;
	else
		max_regions = MAX_REGIONS;
}