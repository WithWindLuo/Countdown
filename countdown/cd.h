
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <tchar.h>
#define ISDEBUG 0	//是否在调试
typedef struct Time
{
	int hour;
	int min;
	int sec;
}Time;

typedef struct Date
{
	int year;
	int month;
	int day;
}Date;

void _countdown();		//倒计时功能函数
void color_con(void);	//显示祝贺信息的函数
void in(Time *time);	//输入记录函数
void out(void);			//输出记录函数
void time_change(Time *time);	//将大于60的分秒格式化
void out_today(void);		//输出当天的记录
Time time_subtract(Time a, Time b);	//时间相减函数

