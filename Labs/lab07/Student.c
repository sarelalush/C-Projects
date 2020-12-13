#include "Student.h"
#include<stdio.h> 
#include<string.h> 
#include <stdlib.h>

Student* StudentCreate(const char* name,const char* id){
  Student *s = (Student*)calloc(sizeof(Student),1);
  s->name = strdup(name);
  s->id = strdup(name);
  memset(s->grades,NO_GRADE,sizeof(int)*MAX_COURSES);
  return s;
}

Student* StudentDestroy(Student* s){
  free(s->name);
  free(s->id);
  free(s);
}

void StudentAddGrade(Student* s, Course c,Grade g){
  if(!(c<MAX_COURSES && g<=100)){
    fprintf (stderr, "%s, line %d.", __FILE__, __LINE__);
    exit(1);
  }
  s->grades[c] = g;
}

Grade StudentGetGrade(Student* s,Course c){
  if(!(c<MAX_COURSES))
  {
    fprintf (stderr, "%s, line %d.", __FILE__, __LINE__);
    exit(1);
  }
  if(s->grades[c] == NO_GRADE)
    return NO_GRADE;
  return s->grades[c];
}
