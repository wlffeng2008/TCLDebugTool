#include "norflash.h"
#include "cJSON.h"
#include "md5.h"


#define DO1(buf) crc = crc_table[((uint32_t)crc ^ (*buf++)) & 0xff] ^ (crc >> 8);
#define DO2(buf)  DO1(buf); DO1(buf);
#define DO4(buf)  DO2(buf); DO2(buf);
#define DO8(buf)  DO4(buf); DO4(buf);

static uint32_t sector_size = 4096;
static uint32_t current_write_offset = 0;
static const uint32_t crc_table[] =
{
	0x00000000L, 0x77073096L, 0xee0e612cL, 0x990951baL, 0x076dc419L,
	0x706af48fL, 0xe963a535L, 0x9e6495a3L, 0x0edb8832L, 0x79dcb8a4L,
	0xe0d5e91eL, 0x97d2d988L, 0x09b64c2bL, 0x7eb17cbdL, 0xe7b82d07L,
	0x90bf1d91L, 0x1db71064L, 0x6ab020f2L, 0xf3b97148L, 0x84be41deL,
	0x1adad47dL, 0x6ddde4ebL, 0xf4d4b551L, 0x83d385c7L, 0x136c9856L,
	0x646ba8c0L, 0xfd62f97aL, 0x8a65c9ecL, 0x14015c4fL, 0x63066cd9L,
	0xfa0f3d63L, 0x8d080df5L, 0x3b6e20c8L, 0x4c69105eL, 0xd56041e4L,
	0xa2677172L, 0x3c03e4d1L, 0x4b04d447L, 0xd20d85fdL, 0xa50ab56bL,
	0x35b5a8faL, 0x42b2986cL, 0xdbbbc9d6L, 0xacbcf940L, 0x32d86ce3L,
	0x45df5c75L, 0xdcd60dcfL, 0xabd13d59L, 0x26d930acL, 0x51de003aL,
	0xc8d75180L, 0xbfd06116L, 0x21b4f4b5L, 0x56b3c423L, 0xcfba9599L,
	0xb8bda50fL, 0x2802b89eL, 0x5f058808L, 0xc60cd9b2L, 0xb10be924L,
	0x2f6f7c87L, 0x58684c11L, 0xc1611dabL, 0xb6662d3dL, 0x76dc4190L,
	0x01db7106L, 0x98d220bcL, 0xefd5102aL, 0x71b18589L, 0x06b6b51fL,
	0x9fbfe4a5L, 0xe8b8d433L, 0x7807c9a2L, 0x0f00f934L, 0x9609a88eL,
	0xe10e9818L, 0x7f6a0dbbL, 0x086d3d2dL, 0x91646c97L, 0xe6635c01L,
	0x6b6b51f4L, 0x1c6c6162L, 0x856530d8L, 0xf262004eL, 0x6c0695edL,
	0x1b01a57bL, 0x8208f4c1L, 0xf50fc457L, 0x65b0d9c6L, 0x12b7e950L,
	0x8bbeb8eaL, 0xfcb9887cL, 0x62dd1ddfL, 0x15da2d49L, 0x8cd37cf3L,
	0xfbd44c65L, 0x4db26158L, 0x3ab551ceL, 0xa3bc0074L, 0xd4bb30e2L,
	0x4adfa541L, 0x3dd895d7L, 0xa4d1c46dL, 0xd3d6f4fbL, 0x4369e96aL,
	0x346ed9fcL, 0xad678846L, 0xda60b8d0L, 0x44042d73L, 0x33031de5L,
	0xaa0a4c5fL, 0xdd0d7cc9L, 0x5005713cL, 0x270241aaL, 0xbe0b1010L,
	0xc90c2086L, 0x5768b525L, 0x206f85b3L, 0xb966d409L, 0xce61e49fL,
	0x5edef90eL, 0x29d9c998L, 0xb0d09822L, 0xc7d7a8b4L, 0x59b33d17L,
	0x2eb40d81L, 0xb7bd5c3bL, 0xc0ba6cadL, 0xedb88320L, 0x9abfb3b6L,
	0x03b6e20cL, 0x74b1d29aL, 0xead54739L, 0x9dd277afL, 0x04db2615L,
	0x73dc1683L, 0xe3630b12L, 0x94643b84L, 0x0d6d6a3eL, 0x7a6a5aa8L,
	0xe40ecf0bL, 0x9309ff9dL, 0x0a00ae27L, 0x7d079eb1L, 0xf00f9344L,
	0x8708a3d2L, 0x1e01f268L, 0x6906c2feL, 0xf762575dL, 0x806567cbL,
	0x196c3671L, 0x6e6b06e7L, 0xfed41b76L, 0x89d32be0L, 0x10da7a5aL,
	0x67dd4accL, 0xf9b9df6fL, 0x8ebeeff9L, 0x17b7be43L, 0x60b08ed5L,
	0xd6d6a3e8L, 0xa1d1937eL, 0x38d8c2c4L, 0x4fdff252L, 0xd1bb67f1L,
	0xa6bc5767L, 0x3fb506ddL, 0x48b2364bL, 0xd80d2bdaL, 0xaf0a1b4cL,
	0x36034af6L, 0x41047a60L, 0xdf60efc3L, 0xa867df55L, 0x316e8eefL,
	0x4669be79L, 0xcb61b38cL, 0xbc66831aL, 0x256fd2a0L, 0x5268e236L,
	0xcc0c7795L, 0xbb0b4703L, 0x220216b9L, 0x5505262fL, 0xc5ba3bbeL,
	0xb2bd0b28L, 0x2bb45a92L, 0x5cb36a04L, 0xc2d7ffa7L, 0xb5d0cf31L,
	0x2cd99e8bL, 0x5bdeae1dL, 0x9b64c2b0L, 0xec63f226L, 0x756aa39cL,
	0x026d930aL, 0x9c0906a9L, 0xeb0e363fL, 0x72076785L, 0x05005713L,
	0x95bf4a82L, 0xe2b87a14L, 0x7bb12baeL, 0x0cb61b38L, 0x92d28e9bL,
	0xe5d5be0dL, 0x7cdcefb7L, 0x0bdbdf21L, 0x86d3d2d4L, 0xf1d4e242L,
	0x68ddb3f8L, 0x1fda836eL, 0x81be16cdL, 0xf6b9265bL, 0x6fb077e1L,
	0x18b74777L, 0x88085ae6L, 0xff0f6a70L, 0x66063bcaL, 0x11010b5cL,
	0x8f659effL, 0xf862ae69L, 0x616bffd3L, 0x166ccf45L, 0xa00ae278L,
	0xd70dd2eeL, 0x4e048354L, 0x3903b3c2L, 0xa7672661L, 0xd06016f7L,
	0x4969474dL, 0x3e6e77dbL, 0xaed16a4aL, 0xd9d65adcL, 0x40df0b66L,
	0x37d83bf0L, 0xa9bcae53L, 0xdebb9ec5L, 0x47b2cf7fL, 0x30b5ffe9L,
	0xbdbdf21cL, 0xcabac28aL, 0x53b39330L, 0x24b4a3a6L, 0xbad03605L,
	0xcdd70693L, 0x54de5729L, 0x23d967bfL, 0xb3667a2eL, 0xc4614ab8L,
	0x5d681b02L, 0x2a6f2b94L, 0xb40bbe37L, 0xc30c8ea1L, 0x5a05df1bL,
	0x2d02ef8dL
};

static uint32_t _bsp_crc32_(uint32_t crc, const uint8_t*buf, uint32_t len)
{
    crc = crc ^ 0xffffffffL;
    while(len >= 8)
    {
        DO8(buf);
        len -= 8;
    }
    if(len)
    {
        do
        {
            DO1(buf);
        }
        while(--len);
    }

    return crc ^ 0xffffffffL;
}

static uint32_t _update_write_offset_(uint32_t size)
{
	current_write_offset = size;
}

uint32_t get_update_write_offset()
{
	return current_write_offset;
}

static FILE * _prepare_write_flash(uint32_t offset)
{
    /* Open the JSON file */
    FILE * fp = fopen(NOR_FLASH_BIN_FILE_NAME, "r+");
	if(fp)
	{
		fseek(fp, offset, SEEK_SET);
		return fp;
	}
	return NULL;
}

static uint32_t _write_flash_(FILE * fp, uint8_t* buffer, uint32_t size)
{
	if(fp)
	{
	    fwrite(buffer, size,1,fp);
	}	
}

static uint32_t _end_write_flash_(FILE * fp)
{
	if(fp)
	{
	    fclose(fp);
	}
}

uint32_t _write_file_header_(NOR_FLASH_HEADER_INFO* nor_flash_header,int mode)
{
	if(mode==1)
	{
		FILE *file = fopen(NOR_FLASH_BIN_FILE_NAME, "wb");
		if (file != NULL) {
			int i = 0;
			unsigned char data = 0xff;
			for (i = 0; i < 0x80000; i++) {
				fwrite(&data, sizeof(data), 1, file);
			}
			fclose(file);
		}

		file = fopen(NOR_FLASH_BIN_FILE_NAME, "r+b");
		if (file != NULL) {
			fseek(file, 0L, SEEK_SET);
		    fwrite(nor_flash_header, nor_flash_header->size,1,file);
		    fclose(file);
		}
	}
	else
	{
		FILE * file = fopen(NOR_FLASH_BIN_FILE_NAME, "r+b");
		if (file != NULL) {
			fseek(file, 0L, SEEK_SET);
		    fwrite(nor_flash_header, nor_flash_header->size,1,file);
		    fclose(file);
		}		
	}
	
	return 0;
}

static uint32_t _calculate_crc_info(NOR_FLASH_HEADER_INFO* nor_flash_header)
{
	char* pbuffer = (char*)nor_flash_header;
	if(pbuffer)
	{
		return _bsp_crc32_(0, pbuffer+4, nor_flash_header->size-4);
	}
}

static uint32_t _calculate_file_info(uint8_t* filepath,NOR_FLASH_SECTOR_HEADER_INFO* section_header)
{
	MD5_CTX md5;
	uint8_t encrypt[1024];
	uint8_t decrypt[16] = {0};
	uint32_t file_total_length = 0;
	uint32_t checksum = 0;
	uint32_t i = 0;
	
	FILE* fp_config_file = fopen(filepath, "rb");
	if(fp_config_file == NULL) {
		printf("open %s failed \n",filepath);
		return -1;
	}
	
	section_header->offset = (current_write_offset/sector_size+1)*sector_size;
	FILE * fp_flash = _prepare_write_flash(section_header->offset);
	memset(encrypt,0,1024);
	memset(decrypt,0,16);
	MD5Init(&md5);
	while(!feof(fp_config_file)) 
	{
		uint32_t length = fread(encrypt, 1, sizeof(encrypt), fp_config_file);
		for (i = 0; i < length; ++i) {
        	checksum += encrypt[i];
    	}
		MD5Update(&md5, encrypt, length);
		file_total_length += length;
		_write_flash_(fp_flash,encrypt,length);
	}

	_end_write_flash_(fp_flash);
	fclose(fp_config_file);
	MD5Final(&md5, decrypt);
	
#if 0
	uint32_t i = 0;
	printf("FILE: %s MD5: \n",filepath);
	for(i=0; i<16; i++) {
		printf("%02x", decrypt[i]);  //02x前需要加上 %
	}
	printf("\r\n");
#endif
	section_header->reserved[0] =  checksum;
	section_header->size = file_total_length;
	memcpy(&section_header->MD5[0],decrypt,16);
	_update_write_offset_(section_header->offset+section_header->size);
}

uint32_t nor_flash_update_init(uint32_t flash_sector_size)
{	
	current_write_offset = 0;
	sector_size = flash_sector_size;
}

JSON_FILE_INFO* nor_flash_parser_jason_file(char* filename, char* version)
{
    FILE *fp;
    char buffer[4096] = {0};
    struct cJSON *json, *item;
	JSON_FILE_INFO* json_info = NULL;

    /* Open the JSON file */
    fp = fopen(filename, "r");
	if(fp)
	{
	    fread(buffer, 4096, 1, fp);
	    fclose(fp);

	    /* Parse the JSON file */
	    json = cJSON_Parse(buffer);
	    /* Print each item in the JSON file */

		json_info = malloc(sizeof(JSON_FILE_INFO));
		memset(json_info,0,sizeof(JSON_FILE_INFO));
	    cJSON_ArrayForEach(item, json) {
	        if (cJSON_IsNumber(item))
	        {
	            //printf("Element cJSON_IsNumber name:(%s), value: (%d)\n", item->string, item->valueint);
				if(!memcmp(item->string,"version",sizeof("version")))
				{
					json_info->version = item->valueint;
					//printf("version: %d \n",item->valueint);
				}

				if(!memcmp(item->string,"sectionNumber",sizeof("sectionNumber")))
				{
					json_info->sectionNum= item->valueint;
					//printf("sectionNumber: %d \n",item->valueint);
				}
	        }
	        else if (cJSON_IsString(item))
	        {
	            //printf("Element cJSON_IsString name: %s, value: %s\n", item->string, item->valuestring);
				if(!memcmp(item->string,"magicNumber",sizeof("magicNumber")))
				{
					//printf("magicNumber: %s \n",item->valuestring);
					json_info->magicnumber = strtoull(item->valuestring, NULL, 0);
				}

	        }
			uint32_t counter = 0;
	        if (cJSON_IsArray(item))
	        {
	            cJSON *sub_element = NULL;
	            cJSON_ArrayForEach(sub_element, item)
	            {
	            	cJSON *sub_element2 = NULL;
					cJSON_ArrayForEach(sub_element2, sub_element)
					{
						//printf("Array element name: %s, value: %s\n", sub_element2->string, cJSON_Print(sub_element2));
				        if (cJSON_IsNumber(sub_element2))
				        {
				            //printf("Element cJSON_IsNumber name:(%s), value: (%d)\n", item->string, item->valueint);
							if(!memcmp(sub_element2->string,"maintype",sizeof("maintype")))
							{
								//printf("maintype: %d \n",sub_element2->valueint);
								json_info->fileinfo[counter].maintype = sub_element2->valueint;
							}

							if(!memcmp(sub_element2->string,"subtype",sizeof("subtype")))
							{
								json_info->fileinfo[counter].subtype = sub_element2->valueint;
								//printf("subtype: %d \n",sub_element2->valueint);
							}
				        }
				        else if (cJSON_IsString(sub_element2))
				        {
				            //printf("Element cJSON_IsString name: %s, value: %s\n", item->string, item->valuestring);
							if(!memcmp(sub_element2->string,"filepath",sizeof("filepath")))
							{
								if(strlen(sub_element2->valuestring)>MAX_FILE_PATH_LENGTH)
								{
									printf("ERROR, file path is too long,%d > %d \n",strlen(sub_element2->valuestring),MAX_FILE_PATH_LENGTH);
								}
								else
								{
									//printf("filepath: %s \n",sub_element2->valuestring);
									strcpy(json_info->fileinfo[counter].filepath,sub_element2->valuestring);
									if(version && strstr(json_info->fileinfo[counter].filepath,"version.bin"))
									{
									    FILE *file;
									    file = fopen(json_info->fileinfo[counter].filepath, "wb+");
									    if (file == NULL) {
									        printf("Error open file: %s\n",json_info->fileinfo[counter].filepath);
									    }
										else
										{
									    	if (fwrite(version, 1, strlen(version), file)!= strlen(version))
											{
									        	printf("Error write file: %s\n",json_info->fileinfo[counter].filepath);										
									    	}
									    	fclose(file);
										}
									}
								}
							}

				        }
					}
					counter ++;
	            }
	        }
	    }
    }
	else
	{
		printf("open %s failed \n",JASON_CONFIG_FILE_NAME);
	}
	
    /* Free the JSON object */
    cJSON_Delete(json);

    return json_info;
}

NOR_FLASH_HEADER_INFO* nor_flash_write_config_data(JSON_FILE_INFO* json)
{	
	if(json->sectionNum >= MAX_CONFIG_BIN_FILES)
	{
		printf("ERROR, too much file to support,%d>%d \n",json->sectionNum,MAX_CONFIG_BIN_FILES);
		return NULL;
	}


	NOR_FLASH_HEADER_INFO* nor_flash_header = malloc(sizeof(NOR_FLASH_HEADER_INFO));
	if(nor_flash_header)
	{
		uint32_t i = 0;
		memset(nor_flash_header,0,sizeof(NOR_FLASH_HEADER_INFO));
		uint32_t raw_header_size = (int)&(nor_flash_header->section_header[0]) - (int)&(nor_flash_header->CRC);
		printf("raw_header_size: %d \n",raw_header_size);
		printf("NOR_FLASH_SECTOR_HEADER_INFO: %d \n",sizeof(NOR_FLASH_SECTOR_HEADER_INFO));

		nor_flash_header->CRC = 0;
		nor_flash_header->magicnumber = json->magicnumber;
		nor_flash_header->sectionNum= json->sectionNum;
		nor_flash_header->version = json->version;
		nor_flash_header->size = raw_header_size + sizeof(NOR_FLASH_SECTOR_HEADER_INFO)*json->sectionNum;
		_update_write_offset_(nor_flash_header->size);

		_write_file_header_(nor_flash_header,1);
		for(i=0; i<nor_flash_header->sectionNum; i++)
		{
			nor_flash_header->section_header[i].mainType = json->fileinfo[i].maintype;
			nor_flash_header->section_header[i].subType = json->fileinfo[i].subtype;
			_calculate_file_info(json->fileinfo[i].filepath,&(nor_flash_header->section_header[i]));
		}		
		nor_flash_header->CRC = _calculate_crc_info(nor_flash_header);
		_write_file_header_(nor_flash_header,0);
		
	}
	return nor_flash_header;
}

uint32_t calculate_crc_update_header(UPDATE_PACKAGE_HEADER_INFO* updatepackage_header)
{
	char* pbuffer = (char*)updatepackage_header;
	if(pbuffer)
	{
		return _bsp_crc32_(0, pbuffer+4, updatepackage_header->size-4);
	}
}

uint32_t calculate_file_md5(uint8_t* filepath, int size, UPDATE_PACKAGE_SECTOR_HEADER_INFO* section_header)
{
	MD5_CTX md5;
	uint8_t encrypt[1024];
	uint8_t decrypt[16] = {0};
	uint32_t left_length = size;
	
	FILE* fp_config_file = fopen(filepath, "rb");
	if(fp_config_file == NULL) {
		printf("open %s failed \n",filepath);
		return -1;
	}
	
	memset(encrypt,0,1024);
	memset(decrypt,0,16);
	MD5Init(&md5);
	while(!feof(fp_config_file)) 
	{
		uint32_t length = fread(encrypt, 1, sizeof(encrypt), fp_config_file);
		if(left_length >= length)
		{
			MD5Update(&md5, encrypt, length);
			left_length = left_length - length;
		}
		else
		{
			MD5Update(&md5, encrypt, left_length);
			break;
		}
	}

	fclose(fp_config_file);
	MD5Final(&md5, decrypt);
	
	memcpy(&section_header->MD5[0],decrypt,16);
}
