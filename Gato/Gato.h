#ifndef _GATO_H
#define _GATO_H

#include <iostream>

using namespace std;

class Gato
{
private:
	char data[3][3] = {
		{'x', ' ', 'x'},
		{'o', 'o', ' '},
		{'x', 'x', 'x'}
	};
	char turn = 'x';
	bool won = false;
public:

	Gato()
	{
		
	}

	void drawBoard()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << data[i][j];
				if(j < 2)
					cout << "|";
			}
			if(i < 2)
				cout << endl << "-+-+-" << endl;
			
		}
		
	}

	bool checkWinningCondition() {
		bool equal = true;
		for (int i = 0; i < 3; i++)
		{
			if(data[i][0] == data[i][1] && data [i][0] == data[i][2])
				return true;
			if(data[0][i] == data[1][i] && data [0][i] == data[2][i])
				return true;
		}
		if(data[0][0] == data[1][1] && data[0][0] == data[2][2])
			return true;
		if(data[0][2] == data[1][1] && data[2][0] == data[1][1])
			return true;
		return false;
	}
};

#endif