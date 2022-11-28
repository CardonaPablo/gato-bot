#ifndef _GATO_H
#define _GATO_H

#include <iostream>

using namespace std;

class Gato
{
public:
	char data[3][3] = {
		{'x', 'x', 'o'},
		{'o', 'x', 'x'},
		{' ', 'o', 'o'}
	};
	char turn = 'o';
	bool won = false;

	Gato() {}

	Gato(char _data[3][3] , char _turn)
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				data[i][j] = _data[i][j];
		turn = _turn;
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
		cout << endl;
		
	}

	bool checkWinningCondition() {
		for (int i = 0; i < 3; i++)
		{
			if(data[i][0] == data[i][1] && data[i][0] == data[i][2] && data[i][0] == 'o')
				return true;
			if(data[0][i] == data[1][i] && data[0][i] == data[2][i] && data[0][i] == 'o')
				return true;
		}
		if(data[0][0] == data[1][1] && data[0][0] == data[2][2] && data[0][0] == 'o')
			return true;
		if(data[0][2] == data[1][1] && data[2][0] == data[1][1] && data[1][1] == 'o')
			return true;
		return false;
	}

	bool operator== (Gato g){
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if(data[i][j] != g.data[i][j])
					return false;
		return true;
  	}
};

#endif