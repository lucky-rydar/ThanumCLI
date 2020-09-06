#pragma once
#include <string>
#include <Windows.h>

using namespace std;

enum class Color
{
	Blue = 1,
	Green,
	Aqua,
	Red,
	Purple,
	Yellow,
	White,
	Gray,
	LightBlue,
	Black = 0,
	LightGreen = 10,
	LightAqua,
	LightRed,
	LightPurple,
	LightYellow,
	BrightWhite
};

class ColoredPrinter
{
public:
	ColoredPrinter(Color background = Color::Black, Color text = Color::White)
	{
		default_background = background;
		default_text = text;
	}
	
	void print(string text, Color back_ground_color, Color text_color)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hConsole, int((int(back_ground_color) + 1) * (int(text_color) + 1)) - 1);
		printf(text.c_str());
		SetConsoleTextAttribute(hConsole, int((int(default_background) + 1) * (int(default_text) + 1)) - 1);
	}
	
	void setDefaultColor(Color background = Color::Black, Color text = Color::White)
	{
		default_background = background;
		default_text = text;
	}
	
private:
	Color default_background;
	Color default_text;
};


