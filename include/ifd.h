#ifndef _IFD
#define _IFD

enum ifd_version {
	IFD_VERSION_1,
	IFD_VERSION_2,
};

struct size{
	unsigned int byte_size;
	float Kb_size;
	float Mb_size;
};

void read_rom_file();

#endif 