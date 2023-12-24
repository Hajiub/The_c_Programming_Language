/*
 Exercise 5-9. Rewrite the routines day_of_year and month_day with pointers instead of indexing.
*/

#include <stdio.h>


#define IS_LEAP(year) ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
  
static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
	
	int leap, i;
	leap = IS_LEAP(year);
	char *pt = &daytab[leap][1];
	for (i = 1; i < month; i++)	
		day += *pt++;
	
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	leap = IS_LEAP(year);
	char *pt = &daytab[leap][1];
	for (i = 1; yearday > *pt; i++)
		yearday -= *pt++;
		
	*pmonth = i;
	*pday = yearday;
}

int main(void)
{
	int year, month, day, yearday;

	year = 2000;
	month = 3;
	day = 1;
	printf("The date is: %d-%02d-%02d\n", year, month, day);
	printf("day_of_year: %d\n", day_of_year(year, month, day));


	yearday = 61;	/* 2000-03-01 */
	month_day(year, yearday, &month, &day);
	printf("Yearday is %d\n", yearday);
	printf("month_day: %d %d\n", month, day);

	return 0;
}
