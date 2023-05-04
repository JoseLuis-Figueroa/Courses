/*
 ****************************************************************
 * @file           : Applicability union
 * @author         : Jose Luis Figueroa
 * @Date		   : 31 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : One of the uses of union is bit extraction
 * 				   : to get better access to bits of a variable.
 * 				   : The code 25.163 implements a bit extraction,
 * 				   : but unions are cleaner and faster to do this
 ****************************************************************
 */
#include<stdio.h>
#include<stdint.h>


union packet
{
	uint32_t packet_value;
	struct
	{
		uint32_t crc		:2;
		uint32_t status		:1;
		uint32_t payload	:12;
		uint32_t bat		:3;
		uint32_t sensor		:3;
		uint32_t long_addr	:8;
		uint32_t short_addr	:2;
		uint32_t addr_mode	:1;
	}packet_fields;
};


int main(void)
{
	union packet pack;
	/*User interface*/
	printf("Enter the 32bits packet value: ");
	scanf("%x",&pack.packet_value);

	/*Print packet information*/
	printf("crc:		%#x\n", pack.packet_fields.crc);
	printf("status: 	%#x\n", pack.packet_fields.status);
	printf("payload:	%#x\n", pack.packet_fields.payload);
	printf("bat:		%#x\n", pack.packet_fields.bat);
	printf("sensor: 	%#x\n", pack.packet_fields.sensor);
	printf("long_addr: 	%#x\n", pack.packet_fields.long_addr);
	printf("short_addr: %#x\n", pack.packet_fields.short_addr);
	printf("addr_mode:  %#x\n", pack.packet_fields.addr_mode);

	printf("Size of struct is %I64llu\n", sizeof(pack));

	getchar();
	getchar();

	return 0;
}
