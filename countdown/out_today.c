#include "cd.h"
extern space[50];
extern b[40];
extern n[30];
void out_today(void)
{
	FILE *fp;
	Date datex;	//取日期
	Time timex;	//取累计时间
	if ((fp = fopen("time_record", "rb+")) == NULL)
	{
		return;
	}
	fseek(fp, (-1)*sizeof(Date)+(-1)*sizeof(Time), 2);
	fread(&datex, sizeof(Date), 1, fp);
	fread(&timex, sizeof(Time), 1, fp);
	printf("%s", space);
	printf("Today:   %d-%d-%d\n", datex.year, datex.month, datex.day);
	printf("%s", space);
	printf("Already: %02d:%02d:%02d\n",timex.hour,timex.min,timex.sec);
	fclose(fp);
}