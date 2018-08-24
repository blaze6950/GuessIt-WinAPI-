
#include <windows.h>
#include <tchar.h>
#include <iostream>
#include <stdio.h>
#include <wchar.h>

int standart_message(int number)
{
	size_t i;
	char buffer[50];
	sprintf_s(buffer, "Ваше число : %d", number);
	wchar_t str[50];
	MultiByteToWideChar(CP_ACP, 0, buffer, -1, str, strlen(buffer) + 1);
	return MessageBox(
		0,
		str,
		TEXT("Угадай число"),
		MB_YESNO | MB_ICONINFORMATION);
}
void win_message()
{
	MessageBox(
		0,
		TEXT("УРА УРА УРА"),
		TEXT("Угадай число"),
		MB_OK | MB_ICONINFORMATION);
}
int more_or_less()
{
	return MessageBox(
		0,
		TEXT("Если больше, нажжми \"Да\", если меньше, нажми \"Нет\""),
		TEXT("Угадай число"),
		MB_YESNO | MB_ICONINFORMATION);
}

INT WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrevInst,
	LPTSTR lpszCmdLine, int nCmdShow)
{
	int more_less = 0;
	int number = 500;
	int MAX_NUM = 1000;
	int MIN_NUM = 0;
	while (true)
	{
		if (standart_message(number) == 6)
		{
			win_message();
			break;
		}
		else{
			more_less = more_or_less() - 6;
		}
		if (more_less == 0)//если 0, то больше, 1 = меньше
		{
			MIN_NUM = number;
			number = (MAX_NUM - MIN_NUM) / 2 + MIN_NUM;
		}
		else{
			MAX_NUM = number;
			number = (MAX_NUM - MIN_NUM) / 2 + MIN_NUM;
		}



	}
	





	return 0;
}