#include "cd.h"
extern space;
extern b;
extern n;
void in(Time *temp)
{
	bool flag=false;
	FILE *fp;
	Time get_counttime,addcounttime;	//get_counttime为从文件取出的倒计时(最后一次）
										//addcounttime为*temp与get_counttime的和
	Date date,date_get;		//date_get为从文件里取出的日期（最后一次）

	time_t timep;		//获取系统日期
	struct tm *p;
	time(&timep);
	p = localtime(&timep);
	date.year = p->tm_year + 1900;
	date.month = p->tm_mon + 1;
	date.day = p->tm_mday ;
	//printf("%d-%d-%d\n", date.year, date.month, date.day);

	if ((fp = fopen("time_record", "rb")) == NULL)
	{
		flag = true;
		if ((fp = fopen("time_record", "wb+")) == NULL)
		{
			return;
		} 
	}
	if (flag == false)
	{
		fseek(fp, (-1L)*sizeof(Time)+(-1L)*sizeof(Date), SEEK_END);
		fread(&date_get, sizeof(Date), 1, fp);	//从文件读取出最后一个日期与时间
		fread(&get_counttime, sizeof(Time), 1, fp);
		//printf("%d:%d:%d\n", get_counttime.hour, get_counttime.min, get_counttime.sec);
		addcounttime.hour = temp->hour + get_counttime.hour;	//同一天倒计时则相加
		addcounttime.min = temp->min + get_counttime.min;
		addcounttime.sec = temp->sec + get_counttime.sec;
		time_change(&addcounttime);
	} 
	fclose(fp);



	if (flag == false)
	{
		if (date_get.year != date.year || date_get.month != date.month || date_get.day != date.day)
		{	//如果是新的一天
			if ((fp = fopen("time_record", "ab")) == NULL)
			{
				return;
			}
			fwrite(&date, sizeof(Date), 1, fp);
			fwrite(temp, sizeof(Time), 1, fp);
			fclose(fp);
		}
		else
		{	//同一天
			if ((fp = fopen("time_record", "rb+")) == NULL)
			{
				return;
			}
			fseek(fp, (-1)*sizeof(Time), 2);
			fwrite(&addcounttime, sizeof(Time), 1, fp);
			fclose(fp);
		}
	}			
	else
	{	//第一次使用程序，没有本地记录文件
		if ((fp = fopen("time_record", "wb")) == NULL)
		{
			return;
		}
		fwrite(&date, sizeof(Date), 1, fp);
		fwrite(temp, sizeof(Time), 1, fp);
		fclose(fp);
	}
	return;
}