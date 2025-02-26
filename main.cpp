#include "cfg.h"
#include "lib.h"
#include "Core/core.h"
#include "Presentation/presentation.h"

int main()
{
	INFO("The program is started");

	(Logger::getLoggerState()) ? Test::startTest() : View::Intro0();
	INFO("The program is closed");

	return 0;
}