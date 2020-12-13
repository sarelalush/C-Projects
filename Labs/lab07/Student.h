#ifndef STUDENT_H
#define STUDENT_H

#define MAX_COURSES 100
#define NO_GRADE -1

typedef unsigned int Course;

typedef unsigned int Grade;

typedef struct{
  char* name;
  char* id;
  Grade grades [MAX_COURSES];
}Student;

Student* StudentCreate(const char* name,const char* id);

Student* StudentDestroy(Student* s);

void StudentAddGrade(Student* s, Course c,Grade g);

Grade StudentGetGrade(Student* s,Course c);

#endif