#ifndef _GATO_H
#define _GATO_H

#include <iostream>

using namespace std;

class Gato
{
public:
	char data[3][3] = {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
	};
	char turn = 'x';
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

	bool checkWinningCondition(char icon = 'o') {
		for (int i = 0; i < 3; i++)
		{
			if(data[i][0] == data[i][1] && data[i][0] == data[i][2] && data[i][0] == icon)
				return true;
			if(data[0][i] == data[1][i] && data[0][i] == data[2][i] && data[0][i] == icon)
				return true;
		}
		if(data[0][0] == data[1][1] && data[0][0] == data[2][2] && data[0][0] == icon)
			return true;
		if(data[0][2] == data[1][1] && data[2][0] == data[1][1] && data[1][1] == icon)
			return true;
		return false;
	}
	
	int getCloseToWinningScore(char icon = 'o') {
		int score = 0;

		// Horizontal
		// | |o|o|
		// |o| |o|
		// |o|o| |
		for (int i = 0; i < 3; i++) {
			if(data[i][0] == data[i][1] && data[i][0] == icon && data[i][2] == ' ')
				score += 10;
			if (data[i][1] == data[i][2] && data[i][1] == icon && data[i][0] == ' ')
				score += 10;
			if (data[i][0] == data[i][2] && data[i][0] == icon && data[i][1] == ' ')
				score += 10;
		}

		// Vertical 
		// |o| |o|
		// |o|o| |
		// | |o|o|
		for (int j = 0; j < 3; j++) {
			if(data[0][j] == data[1][j] && data[0][j] == icon && data[2][j] == ' ')
				score += 10;
			if (data[1][j] == data[2][j] && data[1][j] == icon && data[0][j] == ' ')
				score += 10;
			if (data[0][j] == data[2][j] && data[0][j] == icon && data[1][j] == ' ')
				score += 10;
		}

		// Diagonal

		// | | | |
		// | |o| |
		// | | |o|
		if(data[1][1] == data[2][2] && data[0][0] == ' ' && data[1][1] == icon)
			score += 15;

		// |o| | |
		// | |o| |
		// | | | |
		if(data[0][0] == data[1][1] && data[2][2] == ' ' && data[0][0] == icon)
			score += 15;
		// |o| | |
		// | | | |
		// | | |o|

		if(data[0][0] == data[2][2] && data[1][1] == ' ' && data[0][0] == icon)
			score += 15;

		// | | | |
		// | |o| |
		// |o| | |

		if(data[2][0] == data[1][1] && data[0][2] == ' ' && data[1][1] == icon)
			score += 15;
		// | | |o|
		// | |o| |
		// | | | |
		if(data[0][2] == data[1][1] && data[2][0] == ' ' && data[1][1] == icon)
			score += 15;

		// | | |o|
		// | | | |
		// |o| | |
		if(data[2][0] == data[0][2] && data[1][1] == ' ' && data[2][0] == icon)
			score += 15;

		bool winning = checkWinningCondition(icon);
		if(winning)
			score += 50;
		return score;
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