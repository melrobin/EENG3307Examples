#include <stdio.h>
#include <stdlib.h>

void allocate_memory(double *buf,long N)
{
   if (N>1000000)
     {
        printf("Tried to hog up too much memory!\n");
        exit(0);
     }
   buf=(double *)malloc(N*sizeof(double));   
   if (buf==NULL)
     {  
        printf("Allocation failed\n");
        exit(0);
     }
     
}
void gen_random_numbers(double *buf,long N)
{
   long i;
   for (i=0;i<N;i++)
      buf[i]=(double)rand()/RAND_MAX; 
}
double compute_average(double *buf,long N)
{
   double sum=0;
   int i;
   for (i=0;i<N;i++)
      sum+=buf[i];

   return(sum/N);
}
int main(int argc, char *argv[])
{
   double *buffer,average;
   long N;
   
   if (argc !=2)
     {
        printf("You didn't give me enough parameters....deuces!\n");
        exit(0);
     }
   N=atoi(argv[1]);
   allocate_memory(buffer,N);
   gen_random_numbers(buffer,N);
   average=compute_average(buffer,N);
   printf("The average we have been waiting on is %f\n",average);
   return(0);
}

