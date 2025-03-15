#include "header.h"
#include "PauseSymbol.h"
#include "BaseEngine.h"

void PauseSymbol::virtDraw()
{
	if (getEngine()->isPaused())
	{
		getEngine()->drawForegroundRectangle(
			500, 200, 600, 500,0x808080);

		getEngine()->drawForegroundRectangle(
			700, 200, 800, 500, 0x808080);

		getEngine()->drawForegroundString(470, 550, "press ENTER to continue", 0);
	}
}