#include "cd.h"
extern space[50];
extern b[40];
extern n[30];
void color_con(void)
{
	if (!ISDEBUG)		//µ÷ÊÔ½×¶ÎÌø¹ý
	{
		system("color 01");
		printf("%s%sCongratulate!\a\n", n, space);
		Sleep(250);
		system("cls");
		system("color 02");
		printf("%s%sCongratulate!\n", n, space);
		Sleep(250);
		system("cls");
		system("color 03");
		printf("%s%sCongratulate!\n", n, space);
		Sleep(250);
		system("cls");
		system("color 04");
		printf("%s%sCongratulate!\n", n, space);
		Sleep(250);
		system("cls");
		system("color 05");
		printf("%s%sCongratulate!\n", n, space);
		Sleep(250);
		system("cls");
		system("color 06");
		printf("%s%sCongratulate!\n", n, space);
		Sleep(250);
		system("cls");
		system("color 07");
		printf("%s%sCongratulate!\n", n, space);
		Sleep(250);
		system("cls");
		system("color 08");
		printf("%s%sCongratulate!\n", n, space);
		Sleep(250);
		system("cls");
		system("color 09");
		printf("%s%sCongratulate!\n", n, space);
		Sleep(250);
		system("cls");
		system("color 0A");
		printf("%s%sCongratulate!\n", n, space);
		Sleep(250);
		system("cls");
		system("color 0B");
		printf("%s%sCongratulate!\n", n, space);
		Sleep(250);
		system("cls");
		system("color 0C");
		printf("%s%sCongratulate!\n", n, space);
		Sleep(250);
		system("cls");
		system("color 0D");
		printf("%s%sCongratulate!\n", n, space);
		Sleep(250);
		system("cls");
		system("color 0E");
		printf("%s%sCongratulate!\n", n, space);
		Sleep(250);
		system("cls");
		system("color 0F");
	}
	printf("%s%sCongratulate!!!\n\a", n, space);
}