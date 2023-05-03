/*
 ****************************************************************
 * @file           : String exercise
 * @author         : Jose Luis Figueroa
 * @Date		   : 20 Apr, 2022
 * @board		   : CPU (Standard C)
 * @brief          : Implement a student data base used structs.
 * 				   : I follow all the rules of MISRA-C
 ****************************************************************
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*******************  Definitions  *****************************/
/*Definition of a student record*/
typedef struct
{
	uint32_t roll_number;
	char name [30];
	char branch[50];
	char dob[15];
	uint32_t semester;
}STUDENT_INFO_t;

STUDENT_INFO_t students[10];

/*Global variables*/
uint16_t const MAX_REC = 10;


/*******************  Functions  *******************************/
static void display_records(STUDENT_INFO_t *ptr_records, uint8_t MAX_REC);
static uint8_t add_record(STUDENT_INFO_t *ptr_record, uint8_t MAX_REC);
static uint8_t exist_record(STUDENT_INFO_t *ptr_record, uint8_t MAX_REC,
		uint32_t roll_number);
static uint8_t delete_record(STUDENT_INFO_t *ptr_record, uint8_t MAX_REC);

int main(void)
{
	uint32_t option;
	uint8_t add_flag, delete_flag;
	uint8_t cycle = 1;

	while(cycle)
	{
		printf("\nStudent record management program\n");
		printf("Display all records	==> 1\n");
		printf("Add new record		==> 2\n");
		printf("Delete a record 	==> 3\n");
		printf("Exit application	==> 0\n");

		printf("Enter your option here: ");
		fflush(stdout);
		scanf("%d", &option);

		/*Conditions to perform the tasks*/
		if (option == 0)
		{
			cycle = 0;
		}
		else if (option == 1)
		{
			display_records(students, MAX_REC);
		}
		else if (option == 2)
		{
			add_flag = add_record(students, MAX_REC);
			if (add_flag)
			{
				printf("Record add successfully\n");
			}
			else
			{
				printf("Record add unsuccessful\n");
			}
		}
		else if (option == 3)
		{
			delete_flag = delete_record(students, MAX_REC);
			if(delete_flag)
			{
				printf("Record delete successfully\n");
			}
			else
			{
				printf("Record not found\n");
			}
		}
		else
		{
			printf("Invalid Input\n");
		}
	}
	return 0;
}


/**************  Functions implementation  *********************/
static void display_records(STUDENT_INFO_t *ptr_records, uint8_t MAX_REC)
{
/* This function displays all the records entered by the user
* so far.
* Param[1]=STUDENT_INFO_t: base address of the record.
* Param[2]=MAX_REC: Maximum record number maintained by this
* program.
* */
	uint8_t exist_record = 0;
	printf("\nDisplaying all students record\n");
	for(uint8_t i=0; i<MAX_REC; i++)
	{
		/*If roll number contains a number, then enters*/
		if(ptr_records[i].roll_number)
		{
			exist_record = 1;
			printf("Roll number[%d] = %d\n",i, ptr_records[i].roll_number);
			printf("Name [%d] = %s\n", i, ptr_records[i].name);
			printf("Branch [%d] = %s\n", i, ptr_records[i].branch);
			printf("Dob [%d] = %s\n", i, ptr_records[i].dob);
			printf("Semester [%d] = %d\n", i, ptr_records[i].semester);
		}
	}

	if(!exist_record)
	{
		printf("No record found it\n\n");
	}



}


static uint8_t add_record(STUDENT_INFO_t *ptr_record, uint8_t MAX_REC)
{
	/*Add records entered by the user.
	 * Param[1]=STUDENT_INFO_t: base address of the record.
	 * Param[2]=MAX_REC: Maximum record number maintained by this
	 * program.
	 * */
	uint32_t roll_number;
	uint8_t exist_flag = 0;
	uint8_t status = 0;

	for(uint8_t i=0; i<MAX_REC; i++)
	{
		if(!ptr_record[i].roll_number)
		{
			printf("\nAdd a new record\n");
			printf("Enter the roll number: ");
			fflush(stdout);
			scanf("%d", &roll_number);
			exist_flag = exist_record(ptr_record, MAX_REC, roll_number);

			if(!exist_flag)
			{
				status = 1;
				ptr_record[i].roll_number = roll_number;
				printf("Enter the student semester: ");
				fflush(stdout);
				scanf("%s", ptr_record[i].name);
				printf("Enter the branch: ");
				fflush(stdout);
				scanf("%s", ptr_record[i].branch);
				printf("Enter the Dob(mm/dd/yyyy): ");
				fflush(stdout);
				scanf("%s", ptr_record[i].dob);
				printf("Enter the semester: ");
				fflush(stdout);
				scanf("%d", &ptr_record[i].semester);
			}
			else
			{
				printf("Roll number already exist\n");
			}
			break;
		}

	}
	return status;
}


static uint8_t exist_record(STUDENT_INFO_t *ptr_record, uint8_t MAX_REC,
		uint32_t roll_number)
{
	/*Find if a roll number is equal.
	 * Param[1]=STUDENT_INFO_t: base address of the record.
	 * Param[2]=MAX_REC: Maximum record number maintained by this
	 * program.
	 * */
	uint8_t flag = 0;
	for(int i=0; i<MAX_REC; i++)
	{
		if (roll_number == ptr_record[i].roll_number)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}


static uint8_t delete_record(STUDENT_INFO_t *ptr_record, uint8_t MAX_REC)
{
	/*Delete a record according to the selected roll number
	 * Param[1]=STUDENT_INFO_t: base address of the record.
	 * Param[2]=MAX_REC: Maximum record number maintained by this
	 * program.
	 * */
	uint32_t roll_number;
	uint8_t delete_flag;

	printf("\nDelete a record\n");
	printf("Enter the roll number of the student\n");
	scanf("%d", &roll_number);

	for(int i=0; i<MAX_REC; i++)
	{
		if(roll_number == ptr_record[i].roll_number)
		{
			delete_flag = 1;
			memset(&ptr_record[i], 0, sizeof(STUDENT_INFO_t));
			break;
		}
	}
	return delete_flag;
}

