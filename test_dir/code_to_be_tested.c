#include <stdio.h>
unsigned char MB_count_LRC(unsigned char *mb_data, unsigned char mb_l)
{
    unsigned char lrc=0,i=0,value;

    for (i=1; i<mb_l; i++)
    {   
    	printf("%c\n", (*(mb_data+i)-'0')*16);
    	printf("%c\n", *(mb_data+i+1)-'0');
        value=(*(mb_data+i)-'0')*16 +*(mb_data+i+1)-'0';
        lrc+=value;
       }

    lrc=~(lrc+1);

    return lrc;
}

