#include <stdio.h>
#include <stdlib.h>
#include "Set.h"
#include "Date.h"
#include <stdbool.h>

Element cpyDate(Element d){
  if(!d){return NULL;}
  Date date = create_date(get_day((Date)d),get_month((Date)d),get_year((Date)d));
  return date;
}
void freeDate(Element d){
  if(!d){return NULL;}
  destroy_date((Date)d);
}
bool compareDates(Element d1,Element d2){
   if(!d1 || !d2)
      return false;
   if(d1 == d2)
     return true;
   return (get_day((Date)d1) == get_day((Date)d2) && get_month((Date)d1) == get_month((Date)d2) && get_year((Date)d2) == get_year((Date)d1));
}
int main(int argc , char* argv[]){
  int day=0,month=0,year=0;
  Set s = SetCreate(cpyDate,freeDate,compareDates);
  Date d;
  
  FILE * f = fopen(argv[1],"r");
  if(f == NULL)
    fprintf(stderr,"ERROR File");
  while(fscanf(f,"%d/%d/%d",&day,&month,&year)!=EOF){
    d = create_date(day,month,year);
    SetAdd(s,d);
  }
  
  for(d=SetFirst(s); d != NULL ; d=SetNext(s)){
    printf("%d/%d/%d",get_day(d),get_month(d),get_year(d));
  }
  return 0;
}
