#include "cd.h"
extern space;
extern b;
extern n;
void in(Time *temp)
{
	bool flag=false;
	FILE *fp;
	Time counttime;
	Date date,date_get;		//date_get为从文件里取出的日期

	time_t timep;		//获取系统日期
	struct tm *p;
	time(&timep);
	p = localtime(&timep);
	date.year = p->tm_year + 1900;
	date.month = p->tm_mon +1;
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
		fread(&date_get, sizeof(Date), 1, fp);
		fread(&counttime, sizeof(Time), 1, fp);
		//printf("%d:%d:%d\n", counttime.hour, counttime.min, counttime.sec);
		temp->hour += counttime.hour;
		temp->min += counttime.min;
		temp->sec += counttime.sec;
		time_change(temp);
	} 
	fclose(fp);



	if (flag == false)
	{
		if (date_get.year != date.year || date_get.month != date.month || date_get.day != date.day)
		{
			if ((fp = fopen("time_record", "ab")) == NULL)
			{
				return;
			}
			fwrite(&date, sizeof(Date), 1, fp);
			fwrite(temp, sizeof(Time), 1, fp);
			fclose(fp);
		}
		else
		{
			if ((fp = fopen("time_record", "rb+")) == NULL)
			{
				return;
			}
			fseek(fp, (-1)*sizeof(Time), 2);
			fwrite(temp, sizeof(Time), 1, fp);
			fclose(fp);
		}
	}			
	else
	{
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