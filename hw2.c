#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*This function takes two command line arguments.*/
/*ex: ./hw2 life 42 */
/* First argument "life" names the file that is written.*/
/* Second argument "42" is the number of lines it will eventually fill with randomly generated numbers.*/


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
   if(fp==NULL) /* To check if the file is actually there */
    {
	perror("File not found?");
	return(-1);
    }

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
   strcpy(fname,argv[1]); /* Assigns first argument and assigns it to fname*/
   N=atoi(argv[2]); /* Converts the second argument into an integer, assigns it to N */
   generate_data(fname,N); /* Both arguments are passed to a function that generates an "N" amount of lines of randomly
	generated numbers into a file named by "fname"*/
   average=calculate_average(fname); /* Finds the sum ("average") of all the numbers and divides it by the 		"number_of_lines"*/
   printf("The average of these machinations is %f\n",average);
   return(0);
}
