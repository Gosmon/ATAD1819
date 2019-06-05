#pragma once

typedef unsigned int uInt;

typedef struct date {
	uInt day, month, year;
}Date;

typedef Date* PtDate;

PtDate dateCreate(uInt day, uInt month, uInt year);
Date dateRead();
void datePrint(Date *ptDate);
