#include "cd.h"
extern space[50];
extern b[40];
extern n[30];
void _countdown(void)
{
	system("cls");
	char ch = ' ';
	char a;
	Time counttime, temp;		//counttimeΪ�����ʱ�䣬tempΪ����ʱ�ɹ����뵽�ı���ı���
	counttime.hour = counttime.min = counttime.sec = 0;		//��ʼ��
	printf("%s%s%s\b\b\b\b\b\b\b\b\b\b\b\b\bPlease enter hour,min,sec(such as\"2 1 3\",'q' to quit):",n, space, b);
	while (1)
	{
		if (scanf("%d", &counttime.hour) != 1 || counttime.hour <= -1)
			//���������ַ�����С��0ֱ������ѭ�������������ú���
		{
			while (getchar() != '\n')
				continue;
			break;
		}

		scanf("%d", &counttime.min);
		if (counttime.min <= -1)
		{
			while (getchar() != '\n')
				continue;
			break;
		}

		scanf("%d", &counttime.sec);
		if (counttime.sec <= -1)
		{
			while (getchar() != '\n')
				continue;
			break;
		}
		time_change(&counttime);
		temp = counttime;
		system("cls");
		do
		{
			do
			{
				do
				{
					printf("%s\t\t\t\t\t\t\t(Enter '1'to stop,'2'to continue,'q' to end)\n", n);
					printf("%s\b\bStay Focus!!!\n", space);
					printf("%s %02d:%02d:%02d\n", space, counttime.hour, counttime.min, counttime.sec);

					Sleep(1000);
					system("cls");
					counttime.sec--;

					if (_kbhit())		//��;����'q'��ֹ
						if ((ch = getch()) == 'q')		//�˳�����
						{
							goto a;
						}
						else if (ch == '1')		//��ͣ���ܣ�����������ʵ��
						{
							printf("%s%s\b\b\b\b(Enter 'q' to end)\n", n, space);
							printf("%s\b\b\b\b\b\bSucceed in stopping!!!\n%s%02d:%02d:%02d\n", space, space, counttime.hour, counttime.min, ++counttime.sec);
							while (!_kbhit())
							{
								if ((ch = getch()) == '2')		//�ָ����ܣ����ͷ���������ʵ�֣���;���л����˳�����
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

				} while (counttime.sec >= 0);
				counttime.min--;
				counttime.sec = 59;
			} while (counttime.min >= 0);
			counttime.hour--;
			counttime.min = 59;
		} while (counttime.hour >= 0);
		in(&temp);
		color_con();		//ף�غ���
		out_today();		//�������ļ�¼
		//����ʱ�ɹ���д���ı�
		Sleep(2000);
		putchar('\a');
		system("color 0F");
	a:
		if (ch == 'q')
		{
			ch = 'a';
			printf("%s%s\b\b\b\b\b\bSucceed in ending!\n", n, space);
		}
		printf("%s%s\b\b\b\b\b\b\bPlease enter hour,min,sec(such as\"2 1 3\",'q' to quit):", space, b);
	}
	return;
}



