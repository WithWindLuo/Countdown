#include "cd.h"
char space[50] = "\t\t\t\t\t\t\t\t\t  ";		//向前缩进所用的空格
char n[30] = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";	//换行至中间所需的换行符
char b[40] = "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";		//向后缩进所用的退格符

int main(void)
{
	system("color 0F");	char option;
	SetConsoleTitleA("保持专注——倒计时V1.5");
	printf("%s%s\b\bEnter your option:\n",n,space);
	printf("%s\b\b1.Countdown\n",space);
	printf("%s\b\b2.Output the record\n",space);
	printf("%s\b\bq.Quit\n",space);
	while((option = getch()) != 'q')
	{
		switch (option)
		{
		case '1':
			_countdown();
			system("cls");
			printf("%s%s\b\bEnter your option:\n", n, space);
			break;
		case '2':
			out();		//清屏函数内置在out()里
			printf("%s\b\bEnter your option:\n",space);
			break;
		default:
			system("cls");
			printf("%s%s\b\b'%c' not found. Please enter right option.\n\n", n, space,option);
			printf("%s\b\bEnter your option:\n", space);
			break;
		}
		printf("%s\b\b1.Countdown\n", space);
		printf("%s\b\b2.Output the record\n", space);
		printf("%s\b\bq.Quit\n", space);
	}
	return 0;
}



