// Rus.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


#include <iostream>
#include <Windows.h>
using namespace std;

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

struct RGBfloat
{
	float R;
	float G;
	float B;
};

struct RGB16bit
{
	unsigned char R : 5;
	unsigned char G : 6;
	unsigned char B : 5;
};

struct chararecters
{
	RGBfloat C;
	RGB16bit A;
	unsigned int color;
	chararecters(unsigned int c)
	{
		color = c;
		switch (c)
		{
		case 0: A.R = 0; A.G = 0; A.B = 0; //black
			break;
		case 1: A.R = 0; A.G = 0; A.B = 31; //blue
			break;
		case 2: A.R = 0; A.G = 63; A.B = 0; //green
			break;
		case 3: A.R = 0; A.G = 63; A.B = 31; //cyan
			break;
		case 4: A.R = 31; A.G = 0; A.B = 0; //red
			break;
		case 5: A.R = 31; A.G = 0; A.B = 31; //magenta
			break;
		case 6: A.R = 15; A.G = 0; A.B = 0; //brown
			break;
		case 7: A.R = 23; A.G = 47; A.B = 23; //lightgray
			break;
		case 8: A.R = 15; A.G = 31; A.B = 15; //darkgray
			break;
		case 9: A.R = 15; A.G = 47; A.B = 31; //lightblue
			break;
		case 10: A.R = 15; A.G = 63; A.B = 15; //lightgreen
			break;
		case 11: A.R = 31; A.G = 63; A.B = 15; //lightcyan
			break;
		case 12: A.R = 31; A.G = 31; A.B = 15; //lightred
			break;
		case 13: A.R = 31; A.G = 31; A.B = 31; //lightmagenta
			break;
		case 14: A.R = 31; A.G = 63; A.B = 0; //yellow
			break;
		case 15: A.R = 31; A.G = 63; A.B = 31; //white
			break;
		default:
			color = 0;
			c = 0;
			A.R = 0; A.G = 0; A.B = 0;
			break;
		}
		C.R = A.R / 31.0;
		C.G = A.G / 63.0;
		C.B = A.B / 31.0;
		SetColor((c + 3) % 16, c);
		system("cls");
	}
};
int main()
{
	unsigned int c = 0;
	while (c <= 15)
	{
		cout << "Enter color:";
		cin >> c;
		chararecters Color = chararecters(c);
		cout << "Background color number:" << Color.color << "\n";
		cout << "16 bit representation:" << (int)Color.A.R << " " << (int)Color.A.G << " " << (int)Color.A.B << "\n";
		printf("Float representation:%5.3f %5.3f %5.3f\n", Color.C.R, Color.C.G, Color.C.B);
	}
	return 0;
}
