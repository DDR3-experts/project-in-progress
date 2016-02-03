// must insert utlist.h into the same directory as this file
// to compile "gcc -o readQueue readQueue.c"
// to run "./readQueue <file-name.txt>"


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "utlist.h"


//linear linked list structure for input file data
typedef struct data
{
	int addr;
	char instruction[64];
	int clk;
	struct data * next;
}data;



//main function
int main(int argc, char *argv[])
{
    FILE * fp;
    char line[255];
    char * buf;
    data * inputHead = NULL;
    data * temp;

    //program usage
    if(argc != 2)
    {
    	printf("usage: %s filename", argv[0]);
    	return 0;
    }

    //open file
    fp = fopen(argv[1], "r");

    //go through each line in the input file
    while(fgets(line, 255, (FILE*)fp) != NULL)
    {
    	temp = (data *) malloc(sizeof(data));

    	//get address
    	buf = strtok(line, " ");
    	temp -> addr = strtol(buf, NULL, 16);
    	//printf(".%08x.\n",temp -> addr);

    	//get instruction
    	buf = strtok(NULL, " ");
    	strncpy(temp -> instruction, buf, 64);
    	//printf(".%s.\n",temp -> instruction);

    	//get clock number
    	buf = strtok(NULL, " ");
    	temp -> clk = strtol(buf, NULL, 10);
    	//printf(".%d.\n",temp -> clk);

    	//add to linked list of all the input lines
    	LL_APPEND(inputHead, temp);
    }

    //print input lines
    while(inputHead != NULL)
    {
    	printf("addr = %08x instruction = %s clk = %d\n",inputHead -> addr, inputHead -> instruction, inputHead -> clk);
    	LL_DELETE(inputHead, inputHead);
    }

    //close file pointer
    fclose(fp);



    return 0;
}
