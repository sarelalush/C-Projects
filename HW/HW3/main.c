#include <stdio.h>
#include <stdlib.h>
#include "ProtStats.h"

/*
Sarel Alush 316373851
Shai Dahan  209462712
*/

int main(int argc , char* argv[]){
  unsigned int n =0 ;
  int i=0;
  ProtStats *p = file_fasta_read(argv [1],&n);
  printf("N\tName\tLength\tHydro\tCharged\tPolar\n");
  for(i =0 ; i < n ;i++)
  {
    printf("%d\t%s\t%d\t%.1lf\t%.1lf\t%.1lf\n",i+1,p[i].name,p[i].length,p[i].freq_aa[0],p[i].freq_aa[1],p[i].freq_aa[2]);
  }
  
  for(i =0 ; i < n ;i++) // free all the string in array of ProtStats
  {
    free(p[i].name);
  }
  free(p);
}