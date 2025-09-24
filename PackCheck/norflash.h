#ifndef __NOR_FLASH_H__
#define __NOR_FLASH_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_CONFIG_BIN_FILES	30
#define MAX_FILE_PATH_LENGTH	90

#ifdef RUN_ON_PC
#define NOR_FLASH_BIN_FILE_NAME		"output/spi_nor_flash.bin"
#define JASON_CONFIG_FILE_NAME	"pqchip_00_85X11H.json"
#else
#define NOR_FLASH_BIN_FILE_NAME		"/tmp/spi_nor_flash.bin"
#define JASON_CONFIG_FILE_NAME	"/tclconfig/hardware/param/pq/pqchip_00_85X11H.json"
#endif
typedef unsigned char		uint8_t;
typedef unsigned int		uint32_t;
typedef unsigned long long 	uint64_t;

#pragma pack(push, 1)

typedef struct {
	uint32_t maintype;
	uint32_t subtype;
	uint8_t filepath[MAX_FILE_PATH_LENGTH+1];
} CONFIG_FILE_INFO;

typedef struct {
	uint64_t magicnumber;
	uint32_t version;
	uint32_t sectionNum;
	CONFIG_FILE_INFO fileinfo[30];
} JSON_FILE_INFO;


typedef struct {
	uint32_t mainType;
	uint32_t subType;
	uint32_t offset;
	uint32_t size;
	uint8_t	 MD5[16];
	uint32_t reserved[2];
} NOR_FLASH_SECTOR_HEADER_INFO;

typedef struct {
	uint32_t CRC;
	uint64_t magicnumber;
	uint32_t size;
	uint32_t version;
	uint32_t sectionNum;
	uint32_t reserved[2];
	NOR_FLASH_SECTOR_HEADER_INFO section_header[MAX_CONFIG_BIN_FILES];
} NOR_FLASH_HEADER_INFO;

typedef struct {
	uint32_t mainType;
	uint32_t offset;
	uint32_t size;
	uint8_t	 MD5[16];
	uint32_t reserved[2];
} UPDATE_PACKAGE_SECTOR_HEADER_INFO;

typedef struct {
	uint32_t CRC;
	uint64_t magicnumber;
	uint32_t size;
	uint32_t version;
	uint32_t sectionNum;
	uint32_t reserved[2];
	UPDATE_PACKAGE_SECTOR_HEADER_INFO section_header[2];
} UPDATE_PACKAGE_HEADER_INFO;

#pragma pack(pop)


uint32_t nor_flash_update_init(uint32_t flash_sector_size);

JSON_FILE_INFO* nor_flash_parser_jason_file(char* filename, char* version);

NOR_FLASH_HEADER_INFO* nor_flash_write_config_data(JSON_FILE_INFO* json);

uint32_t get_update_write_offset();

uint32_t calculate_crc_update_header(UPDATE_PACKAGE_HEADER_INFO* updatepackage_header);
uint32_t calculate_file_md5(uint8_t* filepath,int size, UPDATE_PACKAGE_SECTOR_HEADER_INFO* section_header);

#ifdef __cplusplus
}
#endif

#endif
