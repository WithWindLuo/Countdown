#include "cd.h"
Time time_subtract(Time a, Time b)
{
	int sec_a;
	int sec_b;
	sec_a = a.hour * 3600 + a.min * 60 + a.sec -1;			//由于按提前结束功能延迟，需要-1s
	sec_b = b.hour * 3600 + b.min * 60 + b.sec;
	sec_a -= sec_b;
	a.sec = sec_a % 60;
	sec_a = sec_a / 60;
	a.min = sec_a % 60;
	sec_a = sec_a / 60;
	a.hour = sec_a % 60;
	return a;
}