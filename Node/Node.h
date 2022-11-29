#ifndef _NODE_H
#define _NODE_H

#include <iostream>
#include <vector>
#include "../Gato/Gato.h" 

using namespace std;
class Node
{
public:
	vector<Node*> children;
	int maxDimension = 9;
	int f;
	int g = 0;

	Node* parent = nullptr;
	Gato gato;
	Node() {}

	Node(Gato _data, int dimension)
	{
		gato = _data;
		maxDimension = dimension;
	}

	Node(Gato _data)
	{
		gato = _data;
		int spaces = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if(_data.data[i][j] == ' ') 
					spaces++;
		maxDimension = spaces;
	}

	void createPossibilities()
	{
		vector<pair<int, int>> spaces;
		// Count spaces
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if(gato.data[i][j] == ' ')
					spaces.push_back(pair(i, j));
			}
			
		}
		
		// Create n possibilities based on turn and change turn
		for (auto i = spaces.begin(); i != spaces.end(); ++i) {
			Gato buffer(gato.data, gato.turn == 'x' ? 'o':'x');
			buffer.data[(*i).first][(*i).second] = buffer.turn;
			buffer.won = buffer.checkWinningCondition();
			// if(buffer.won)
				// buffer.drawBoard(); 
			Node* child = new Node(buffer, maxDimension-1);
			children.push_back(child);
		}
	}
	
	int heuristic() {
		// cout << "HEURISTICA DE: " << endl;
		// gato.drawBoard();
		int AIScore = gato.getCloseToWinningScore('o');
		int userScore = gato.getCloseToWinningScore('x');
		// cout << endl << endl;
		// cout << "USER SCORE: " << userScore << endl;
		// cout << "AI SCORE: " << AIScore << endl;
		// cout << userScore - AIScore << endl;
		return userScore - AIScore;
	}
};

#endif