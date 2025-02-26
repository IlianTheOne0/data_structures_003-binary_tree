#ifndef TEST_H
#define TEST_H

#include "../View/view.h"

class Test
{
private:
	static const unsigned short testCounter;
public:

	static void startTest()
	{
		switch (testCounter)
		{
			default: { View::Intro0(); }
		}
	}
};

#endif