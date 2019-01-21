#ifndef _IFD
#define _IFD

#ifndef O_BINARY
    #define O_BINARY 0
#endif

#define MAX_REGIONS 9
#define MAX_REGIONS_OLD 5

typedef struct {
	uint32_t flreg[MAX_REGIONS];
} __attribute__((packed)) frba_t;

// flash descriptor
typedef struct {
	uint32_t flvalsig;
	uint32_t flmap0;
	uint32_t flmap1;
	uint32_t flmap2;
} __attribute__((packed)) fdbar_t;

struct region_name {
	const char *long_name;
	const char *short_name;
};

typedef struct {
	int base, limit, size;
} region_t;

void open_rom_to_memory(char* filename);

void dump_layout();

frba_t *find_frba();

fdbar_t *find_flash_descriptor();

void dump_frba_layout(const frba_t *frba);

region_t get_region(const frba_t *frba, unsigned int region_type);

void dump_region_layout(unsigned int num, const frba_t *frba);

const char *region_name_short(unsigned int region_type);


#endif
