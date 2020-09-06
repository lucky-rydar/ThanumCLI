#pragma once
#include <string>
#include <iostream>

using namespace std;

enum class Color
{
	Black = 30, // this + 10 equals foreground color
	Red,
	Green,
	Yellow,
	Blue,
	Magenta,
	Cyan,
	White,
	BrightBlack = 90,
	BrightRed,
	BrightGreen,
	BrightYellow,
	BrightBlue,
	BrightMagenta,
	BrightCyan,
	BrightWhite
};

class TextConvertor
{
public:
	static string coloredBy(string text, Color text_color, Color back_ground_color = Color::Black)
	{
		return ("\033[" + to_string(int(back_ground_color) + 10) + ";" + to_string(int(text_color)) + "m" + text + "\033[0m");
	}
	
private:
	
};


