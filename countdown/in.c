#include "cd.h"
extern space;
extern b;
extern n;
void in(Time *temp)
{
	bool flag=false;
	FILE *fp;
	Time get_counttime,addcounttime;	//get_counttimeΪ���ļ�ȡ���ĵ���ʱ(���һ�Σ�
										//addcounttimeΪ*temp��get_counttime�ĺ�
	Date date,date_get;		//date_getΪ���ļ���ȡ�������ڣ����һ�Σ�

	time_t timep;		//��ȡϵͳ����
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
		fread(&date_get, sizeof(Date), 1, fp);	//���ļ���ȡ�����һ��������ʱ��
		fread(&get_counttime, sizeof(Time), 1, fp);
		//printf("%d:%d:%d\n", get_counttime.hour, get_counttime.min, get_counttime.sec);
		addcounttime.hour = temp->hour + get_counttime.hour;	//ͬһ�쵹��ʱ�����
		addcounttime.min = temp->min + get_counttime.min;
		addcounttime.sec = temp->sec + get_counttime.sec;
		time_change(&addcounttime);
	} 
	fclose(fp);



	if (flag == false)
	{
		if (date_get.year != date.year || date_get.month != date.month || date_get.day != date.day)
		{	//������µ�һ��
			if ((fp = fopen("time_record", "ab")) == NULL)
			{
				return;
			}
			fwrite(&date, sizeof(Date), 1, fp);
			fwrite(temp, sizeof(Time), 1, fp);
			fclose(fp);
		}
		else
		{	//ͬһ��
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
	{	//��һ��ʹ�ó���û�б��ؼ�¼�ļ�
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