#include "Controller.h"
#include "set.h"
#include "UI.h"
//#include "TESTE.h"

int main()
{
	//testAll();
	Set s;
	Controller ctrl{ s };
	UI ui{ ctrl };
	ui.run();
	return 0;
}