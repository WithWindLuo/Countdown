#include "cd.h"
extern space[50];
extern b[40];
extern n[30];
void _countdown(void)
{
	system("cls");
	char ch = ' ';
	char a;
	bool isminu = false;		//是否输入为负数的标志
	Time counttime, temp,ahead_time;		//counttime为输入的时间，temp为倒计时成功输入到文本里的变量,等于初始输入值
											//ahead_time为提前结束时所走过的时间										
	counttime.hour = counttime.min = counttime.sec = 0;		//初始化
	printf("%s%s%s\b\b\b\b\b\b\b\b\b\b\b\b\bPlease enter hour,min,sec(such as\"2 1 3\",'q' to quit):",n, space, b);
	while (1)
	{
		if (scanf("%d", &counttime.hour) != 1)
			//输入其他字符直接跳出循环，即可跳出该函数
		{
			while (getchar() != '\n')
				continue;
			break;
		}


		if (scanf("%d", &counttime.min) != 1)
		{
			while (getchar() != '\n')
				continue;
			break;
		}

		if (scanf("%d", &counttime.sec) != 1)
		{
			while (getchar() != '\n')
				continue;
			break;
		}

		if (counttime.hour <= -1)		//如果是负数，则变为正数，且改变标志，不输进入文件
		{
			isminu = true;
			counttime.hour *= -1;
		}
		if (counttime.min <= -1)
		{
			isminu = true;
			counttime.min *= -1;
		}
		if (counttime.sec <= -1)
		{
			isminu = true;
			counttime.sec *= -1;
		}


		time_change(&counttime);
		ahead_time=temp = counttime;
		system("cls");
		do
		{
			do
			{
				do
				{
					printf("%s\t\t\t\t\t(Enter '1'to stop,'2'to continue,'3' to accomplish ahead of schedule,'q' to end)\n", n);
					printf("%s\bStay Focus!!!\n", space);
					printf("%s %02d:%02d:%02d\n", space, counttime.hour, counttime.min, counttime.sec);

					Sleep(1000);
					system("cls");
					counttime.sec--;

					if (_kbhit())		//中途键入'q'终止
						if ((ch = getch()) == 'q')		//退出功能
						{
							goto a;
						}
						else if (ch == '1')		//暂停功能，用阻塞函数实现
						{
							printf("%s%s\b\b\b\b(Enter 'q' to end)\n", n, space);
							printf("%s\b\b\b\b\b\bSucceed in stopping!!!\n%s%02d:%02d:%02d\n", space, space, counttime.hour, counttime.min, ++counttime.sec);
							while (!_kbhit())
							{
								if ((ch = getch()) == '2')		//恢复功能，用释放阻塞函数实现，中途可切换至退出功能
								{
									system("cls");
									break;
								}
								else if (ch == 'q')
								{
									system("cls");
									goto a;
								}

							}
						}
						else if (ch == '3')
						{
							ahead_time=time_subtract(ahead_time, counttime);
							counttime.hour = counttime.min = counttime.sec = -1;	//提前结束 跳出循环
						}

				} while (counttime.sec >= 0);
				counttime.min--;
				counttime.sec = 59;
			} while (counttime.min >= 0);
			counttime.hour--;
			counttime.min = 59;
		} while (counttime.hour >= 0);
		if (ch == '3')			//如果提前结束
		{
			ch == ' ';
			in(&ahead_time);
		}
		else if(isminu == false)		//若负数，不输入文件
			in(&temp);
		color_con();		//祝贺函数
		out_today();		//输出当天的记录
		//倒计时成功，写入文本
		if(!ISDEBUG)
			Sleep(2000);
		putchar('\a');
		system("color 0F");
	a:
		if (ch == 'q')
		{
			ch = ' ';
			printf("%s%s\b\b\b\b\b\bSucceed in ending!\n", n, space);
		}
		printf("%s%s\b\b\b\b\b\b\bPlease enter hour,min,sec(such as\"2 1 3\",'q' to quit):", space, b);
	}
	return;
}
