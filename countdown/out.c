#include "cd.h"
extern space[50];
extern b[40];
extern n[30];
void out(void)
{
	system("cls");
	FILE *fp;
	Time time;		//用以存放取出的时间
	Date date;		//用以存放取出的日期
	if ((fp = fopen("time_record", "rb")) == NULL)
	{
		printf("%s%s", n, space);
		puts("\b\bRecord not fonud.\n\n");
		return;
	}
	fread(&date, sizeof(Date), 1, fp);
	fread(&time, sizeof(Time), 1, fp);
	while (!feof(fp))
	{
		printf("%d-%d-%d\n", date.year, date.month, date.day);
		printf("%02d:%02d:%02d\n", time.hour, time.min, time.sec);
		fread(&date, sizeof(Date), 1, fp);
		fread(&time, sizeof(Time), 1, fp);
	}
	fclose(fp);
	printf("Enter 'q' to quit!");
	while (getch() != 'q')
		continue;
	system("cls");
	printf("%s", n);
}