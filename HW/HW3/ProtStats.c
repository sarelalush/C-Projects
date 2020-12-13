#include "ProtStats.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_ARRAY_FREQ 3

int num_prots(const char * filename){
    size_t bufsize = 0;
    char* buf = NULL;
    int number_of_times = 0;
    FILE *fp = fopen(filename,"r");
    if(!fp){
        fprintf(stderr, "Cannot Open This File [FILE NAME : %s]\n",filename); 
        exit(1);
    }
    while(getline(&buf,&bufsize,fp) != EOF){
        if(buf[0] == '>') 
          number_of_times += 1;
    }
    free(buf);
    fclose(fp);
    return number_of_times; 
}

ProtStats* ProtStatsCreate(char* name_giveing,char* freq){
    ProtStats* proton = (ProtStats*)malloc(sizeof(ProtStats));
    if(!proton){
        fprintf(stderr, "info: %s:%d: Fail to allocate %lu bytes\n", __FILE__, __LINE__,sizeof(ProtStats)); 
        exit(1);
    }
    
    ProtStatsInit(name_giveing,freq,proton);
    return proton;
}

void ProtStatsInit(char* name, char* freq, ProtStats* prot_to_change){
    int i =0;
    prot_to_change->name = strdup(name);
    prot_to_change->length = strlen(freq);
    
    for(i=0;i<strlen(freq);i++) // run all string freq prot 
    {
      if(find_type(freq[i]) == Hydrophobic) // if the char is Hydrophobic ..
        prot_to_change->freq_aa[Hydrophobic]++; 
      else if(find_type(freq[i]) == Polar)  // if the char is Polar ..
        prot_to_change->freq_aa[Polar]++;
      else if(find_type(freq[i]) == Charged)  // if the char is Charged ..
        prot_to_change->freq_aa[Charged]++;
    }
    prot_to_change->freq_aa[Hydrophobic]= (prot_to_change->freq_aa[Hydrophobic] / prot_to_change->length)*100; // number of Hydrophobic chars / length * 100
    prot_to_change->freq_aa[Polar]= (prot_to_change->freq_aa[Polar] / prot_to_change->length)*100;   // number of Polar chars / length * 100
    prot_to_change->freq_aa[Charged]= (prot_to_change->freq_aa[Charged] / prot_to_change->length)*100;  // number of Charged chars / length * 100
}

void ProtStatsCopy(ProtStats* p1,ProtStats* p2)
{
  strcpy(p1->name,p2->name);
     
  p1->length = p2->length;
  
  p1->freq_aa[Hydrophobic] = p2->freq_aa[Hydrophobic];
  p1->freq_aa[Polar] = p2->freq_aa[Polar];
  p1->freq_aa[Charged] = p2->freq_aa[Charged];
}

void ProtStatsSwap(ProtStats* p1,ProtStats* p2)
{
  int i = 0 ,tmp_len =0 ;
  float tmp_freq =0;
  char* tmp_name = 0;
  
  tmp_name = strdup(p1->name);
  free(p1->name);
  p1->name = strdup(p2->name);
  free(p2->name);
  p2->name = strdup(tmp_name);
  free(tmp_name);
  
  tmp_len = p1->length;
  p1->length = p2->length;
  p2->length = tmp_len;
  
  for(i=0;i<SIZE_ARRAY_FREQ;i++)
  {
    tmp_freq = p1->freq_aa[i];
    p1->freq_aa[i] = p2->freq_aa[i];
    p2->freq_aa[i] = tmp_freq;
  }
  
}


ProtStats* file_fasta_read(char* file_name, unsigned int* n)
{
  FILE * fp = fopen(file_name,"r");
  char* line = NULL;
  size_t len = 0;
  ProtStats * arr_prot = 0;
  int i =0 ,j=0;
  *n  = num_prots(file_name);

  arr_prot = (ProtStats*)calloc(sizeof(ProtStats),(*n)); //malloc for array of ProtStats
  if(!fp){
    fprintf(stderr, "Cannot Open This File [FILE NAME : %s]\n",file_name); 
  }
  if (!arr_prot)
  {
    fprintf(stderr, "info: %s:%d: Fail to allocate %lu bytes\n", __FILE__, __LINE__,sizeof(ProtStats)*(*n)); 
    exit(1);
  }
  for (i=0;i<(*n);i++)
  {
    if(getline(&line,&len,fp) != EOF) 
    {
      char *name = strdup(line); // line 1 (the name)
      name[strlen(name)-1] = '\0'; //delete the \n (break line in the file)
      
      if(getline(&line,&len,fp) != EOF)// line 2 (the freq string)
      {
        line[strlen(line)-1] = '\0'; //delete the \n (break line in the file)
        ProtStatsInit(name+1,line,arr_prot+i);
        free(name);
      }
    }
    
  }
  free(line);
  fclose(fp);
  return arr_prot;
}

aa_type find_type(char ch){
  aa_type t = 0;
  if(strchr("LIAFVPG",ch)) // (strchar) function to check if the char in string
    t = Hydrophobic;
  else if (strchr("EDKR",ch))
    t = Polar;
  else if(strchr("CYTSHNQMW",ch))
    t = Charged;
  return t;
}

