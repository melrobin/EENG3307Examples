#include <stdio.h>
#include <stdlib.h>

int bounds_check(int start,int end,int size)
{
   return(0);
}
void arr_process(double *in_array,int max_index,int start_index,int end_index,char *fname)
{
   FILE *fp;
   int i; 

   if ((start_index > max_index)|| (start_index > end_index) || (end_index > max_index))
     {
        printf("ERROR: something is wrong with your indices!\n");
        exit(0);
     }
/* Bounds are OK.  Feel free to proceed */
   fp=fopen(fname,"w");
/* File is open */
   for (i=start_index;i<end_index;i++)
      fprintf(fp,"%f\n",in_array[i]);
   
}
