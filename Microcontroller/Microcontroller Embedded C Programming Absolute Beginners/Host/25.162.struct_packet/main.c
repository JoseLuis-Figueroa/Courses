/*
 ****************************************************************
 * @file           : Structure and bit fields
 * @author         : Jose Luis Figueroa
 * @Date		   : 31 Mar, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Extract different bits using AND logic
 * 				   : and bitwise right shift.
 ****************************************************************
 */
#include<stdio.h>
#include<stdint.h>


struct packet
{
	uint8_t crc;
	uint8_t status;
	uint16_t payload;
	uint8_t bat;
	uint8_t sensor;
	uint8_t long_addr;
	uint8_t short_addr;
	uint8_t addr_mode;
};


int main(void)
{
	/*User interface*/
	uint32_t packet_value;
	printf("Enter the 32bits packet value: ");
	scanf("%x",&packet_value);

	struct packet pack;

	/*Get the information of the packet*/
	pack.crc = (uint8_t)(packet_value & 0x03);
	pack.status = (uint8_t)((packet_value >> 2) & 0x01);
	pack.payload = (uint16_t)((packet_value >> 3) & 0xFFF);
	pack.bat = (uint8_t)((packet_value >> 15) & 0x07);
	pack.sensor = (uint8_t)((packet_value >> 18) & 0x07);
	pack.long_addr = (uint8_t)((packet_value >> 21) & 0xFF);
	pack.short_addr = (uint8_t)((packet_value >> 29) & 0x03);
	pack.addr_mode = (uint8_t)((packet_value >> 31) & 0x01);

	/*Print packet information*/
	printf("crc:		%#x\n", pack.crc);
	printf("status: 	%#x\n", pack.status);
	printf("payload:	%#x\n", pack.payload);
	printf("bat:		%#x\n", pack.bat);
	printf("sensor: 	%#x\n", pack.sensor);
	printf("long_addr: 	%#x\n", pack.long_addr);
	printf("short_addr: %#x\n", pack.short_addr);
	printf("addr_mode:  %#x\n", pack.addr_mode);

	printf("Size of struct is %I64llu\n", sizeof(pack));

	getchar();
	getchar();

	return 0;
}
