#pragma once
#include <string>
#include <iostream>
#include <vector>


class Screen
{
public:
	friend class Window_mgr;

	typedef std::string::size_type pos;

	Screen() = default;
	Screen(pos height, pos width, char c) : height(height), width(width), contents(width* height, c) {};

	char get() const { return contents[cursor]; }
	char get(pos r, pos c) const
	{
		pos row = r * width;
		return contents[row + c];
	}

	inline Screen& set(char c)
	{
		contents[cursor] = c;
		return *this;
	}
	inline Screen& set(pos row, pos col, char ch)
	{
		contents[row * width + col] = ch;
		return *this;
	}

	Screen& display(std::ostream& os)
	{
		do_display(os);
		return *this;
	}
	const Screen& display(std::ostream& os) const
	{
		do_display(os);
		return *this;
	}

	void draw()
	{
		int counter = 0;
		std::cout << std::endl;
		for (size_t i = 0; i < height; i++)
		{
			for (size_t j = 0; j < width; j++)
			{
				std::cout << contents[counter];
				counter++;
			}
			std::cout << std::endl;
		}
	}

	Screen& move(pos r, pos c)
	{
		pos row = r * width;
		cursor = row + c;
		return *this;
	}
private:
	void do_display(std::ostream& os) const
	{
		os << contents;
	}
	pos width = 0, height = 0;
	pos cursor = 0;
	std::string contents;
};

class Window_mgr
{
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex i)
	{
		Screen& s = screens[i];
		s.contents = std::string(s.height * s.width, '0');
	}
	ScreenIndex addScreen(const Screen& s)
	{
		screens.push_back(s);
		return screens.size() - 1;
	}

private:
	std::vector<Screen> screens{ Screen(24,80,'1') };
};

