#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_data(char *filename,int number_to_write)
/*This function is all good */
{
  int i;
  FILE *fp;
  fp=fopen(filename,"w"); /*Open our output file */
  for (i=0;i<number_to_write;i++)
        fprintf(fp,"%f\n",(double)rand()/RAND_MAX);
  fclose(fp);
}

double calculate_average(char *filename)
{
   double average,x;
   int number_of_lines=0;
   FILE *fp;
   fp=fopen(filename,"r");
   while (!feof(fp))
    {
      fscanf(fp,"%lf",&x);
      average+=x;
      number_of_lines++;
    }
   fclose(fp);
   
   return(average/number_of_lines);
}
int main(int argc, char *argv[])
{
   int N;
   char fname[15];
   double average;
   if (argc !=3)
     {
        printf("Not enough arguments\n");
        exit(0); /*We're out of here! */
     }
   strcpy(fname,argv[1]);
   N=atoi(argv[2]);
   generate_data(fname,N);
   average=calculate_average(fname);
   printf("The average of these machinations is %f\n",average);
   return(0);
}


