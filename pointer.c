#include <stdio.h>
#include <math.h>
#include <stdlib.h>
const double PI = 3.14159;
double my_function(char *filename)
{
   FILE *fp;
   int index;
   double s,c;
   double x,sum=0;
   fp=fopen(filename,"r");
   printf("The file that I am reading from is %s\n",filename);
   while (!feof(fp))
   {
       fscanf(fp,"%d",&index);
       fscanf(fp,"%lf",&s);
       fscanf(fp,"%lf",&c);
       sum +=c;
       printf("Current value of cosine is %f, but the current value of the sum is %f\n",c,sum);
   }
   fclose(fp);
}
int main()
{
   int *an_int_pointer,loop_counter;
   int some_integer=747;
   FILE *fp,*fp1;
   double *double_pointer;
   fp=fopen("myfile.txt","w"); /*Open the file */
   fp1=fopen("another_myfile","w");
   an_int_pointer=&some_integer;
   printf("The value of the point is %p\n",an_int_pointer);
   printf("And its value is %d\n",*an_int_pointer); /* Note I dereferenced the pointer here */
  /* Net two lines write to the file */
   fprintf(fp,"The value of the point is %p\n",an_int_pointer);
   fprintf(fp,"And its value is %d\n",*an_int_pointer); /* Note I dereferenced the pointer here */
 /*  fprintf(fp1,"This is some random text to show that I can write to multiple files from the same program\n"); */
   fclose(fp);
   for (loop_counter=0;loop_counter<180;loop_counter++)
      fprintf(fp1,"%d\t%f\t%f\n",loop_counter,sin(PI/180*loop_counter),cos(PI/180*loop_counter));
   /*Create an array */
   double_pointer=(double *)malloc(5*sizeof(double));
   fclose(fp1);
   my_function("another_myfile");
   return(0);
}

