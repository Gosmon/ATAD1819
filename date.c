#include <stdlib.h>
#include <string.h>
#include "date.h"
#include <stdio.h>

PtDate dateCreate(uInt day, uInt month, uInt year) {
	
	PtDate date = (PtDate)malloc(sizeof(Date));
	
	date->day = day;
	date->month = month;
	date->year = year;

	return date;
}

void datePrint(PtDate date) {
	printf("%02d/%02d/%4d", date->day, date->month, date->year);
}
