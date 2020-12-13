#ifndef DATE_H
#define DATE_H

typedef struct Date* Date;

Date create_date(int day, int month, int year);
void destroy_date(Date d);
int get_day(Date dmy);
void set_day(Date dmy, int d);
int get_month(Date dmy);
void set_month(Date dmy, int m);
int get_year(Date dmy);
void set_year(Date dmy, int y);

#endif

