#ifndef _IFD
#define _IFD

#ifndef O_BINARY
    #define O_BINARY 0
#endif

#define MAX_REGIONS 9
#define MAX_REGIONS_OLD 5


/*enum ifd_version {
	IFD_VERSION_1,
	IFD_VERSION_2,
};*/

struct region_name {
	const char *long_name;
	const char *short_name;
};

void open_rom_to_memory(char* filename);

#endif 