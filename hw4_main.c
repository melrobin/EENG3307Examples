#include <stdio.h>
extern void arr_process(double *,int,int,int,char*); /*This is a function prototype */
int main()
{
    double some_array[10]={-3.2,4.7,3.6,.9,-.9,-.9,-.9,-3.2,0,1,1,1,1,1,1};

    arr_process(some_array,10,2,9,"afile.txt");
    return 0;
}



