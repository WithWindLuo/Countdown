#include "cd.h"
void time_change(Time *time)
{
	Time a;
	int sec;
	a = *time;
	sec = a.hour * 60 * 60 + a.min * 60 + a.sec;
	time->sec = sec % 60;
	sec = sec / 60;
	time->min = sec % 60;
	sec = sec / 60;
	time->hour = sec % 60;
	return;
}