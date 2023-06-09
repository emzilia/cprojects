#ifndef GTIME_H
#define GTIME_H

#include <stdlib.h>

typedef struct {
	size_t hour;
	size_t day;
	size_t week;
	size_t month;
} Time;

extern Time gtime;

void advance_hour(int value);
void advance_day(int value);
void advance_week(int value);
void advance_month(int value);

#endif
