#include <iostream>
#include "Gato/Gato.h"

using namespace std;

int main()
{
	Gato g;
	g.drawBoard();
	cout << endl << g.checkWinningCondition() << endl;
}