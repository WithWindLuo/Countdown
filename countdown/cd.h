
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <tchar.h>
#define ISDEBUG 0	//�Ƿ��ڵ���
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

void _countdown();		//����ʱ���ܺ���
void color_con(void);	//��ʾף����Ϣ�ĺ���
void in(Time *time);	//�����¼����
void out(void);			//�����¼����
void time_change(Time *time);	//������60�ķ����ʽ��
void out_today(void);		//�������ļ�¼
Time time_subtract(Time a, Time b);	//ʱ���������

