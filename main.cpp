#include <iostream>
#include <vector>
#include <algorithm>
#include "Gato/Gato.h"
#include "Node/Node.h"

using namespace std;

Gato createResponse(Gato g);
int findSmallestFIndex(vector<Node*> list);
Gato getTopParent(Node* n); 
void printVector(vector<Node*> vector);
bool existsInVector(vector<Node*> vector, Node* target);
int getPositionFromDifference(Gato a, Gato b);

int main()
{
	// Recibir el gato
	Gato g;
	Gato nextState = createResponse(g);
	g.drawBoard();
	nextState.drawBoard();
	// Determinar la diferencia entre el original y la respuesta
	cout << getPositionFromDifference(g, nextState);
}

int getPositionFromDifference(Gato a, Gato b) {
	int i, j, position = 0;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if(a.data[i][j] != b.data[i][j]) {
				cout << "Differs in: " << i << ',' << j << endl;;
				int position = 0;
				position += 3*i;
				position += j;
			}
	return position;
}

Gato createResponse(Gato g) {

	Node start(g);
	vector<Node*> open = { &start };
	vector<Node*> closed;
	Node* current;

	while(!open.empty()) {
		// find smallest F
		int index = findSmallestFIndex(open);
		current = open.at(index);

		// Remove current from open set;
		// Create another vector of size -1
		vector<Node*> filteredArray;
		// Copy all elements except current node
		for(auto i = open.begin(); i != open.end(); ++i)
			if(!((*i)->gato == current->gato))
				filteredArray.push_back(*i);
		// Copy new vector to old one
		open.clear();
		open.assign(filteredArray.begin(), filteredArray.end()); 


		current->createPossibilities();
		for (auto i = current->children.begin(); i != current->children.end(); ++i)  {
			Node* m = *i;
			if(m->gato.won) {
				(*m).parent = current;
				return getTopParent(m);
			}
			if(existsInVector(open, m)) {
				if(current->g + 1 < m->g) {
					// m->parent = current;
					(*m).parent = current;
					m->g = current->g + 1;
					m->f = m->g + m->heuristic();
				}
			} else if(existsInVector(closed, m)) {
				if(current->g + 1 < m->g) {
					(*m).parent = current;
					m->g = current->g + 1;
					m->f = m->g + m->heuristic();
					open.push_back(m);
				}
			} else {
				(*m).parent = current;
				m->g = current->g + 1;
				m->f = m->g + m->heuristic();
				open.push_back(m);
			}
		}
		closed.push_back(current);
	}
	cout << "NO SOLUTION" << endl;
	return Gato();
}

Gato getTopParent(Node* n) {
	// cout << "Calling top parent" << endl;
	// n->gato.drawBoard();
	Node buffer = *n;
	while(buffer.parent->parent != nullptr) 
		buffer = *(buffer.parent);
	return buffer.gato;
}

int findSmallestFIndex(vector<Node*> list) {
	int minValue = list.size() * list.size();
	int minIndex = NULL;

	for (int j = 0; j < list.size(); j++) {
		if(list.at(j)->f < minValue) {
			minValue = list.at(j)->f;
			minIndex = j;
		}
	}
	if(minIndex == NULL && minIndex != 0 && minValue == (list.size() * list.size()))
		return -1;
	return minIndex;
}

bool existsInVector(vector<Node*> vector, Node* target) {
	for (auto i = vector.begin(); i != vector.end(); ++i) 
		if((*i)->gato == target->gato)
			return true;
	return false;
}