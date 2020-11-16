//======================================================================================================
// Name        : SearchAlgorithms(AI).cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : First AI homework, 3x3 board of integers 0-8 (0 is represented by '*'.)
//				 Given a search method and start state, algorithm attempts to return path to goal state.
//======================================================================================================

#include <iostream>
#include <list>
#include <vector>
using namespace std;

int goal[9] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
bool success = false;

struct Node{
public:
	Node* parent;
	int board[9];
	vector<Node*> children;
	int depth;
	bool valid;

	Node(Node* parent, int board[9]){
		this->parent = parent;
		for(int i = 0; i < 9; i++){
				this->board[i] = board[i];
		}
		valid = true;
		depth = 0;
	}
};

bool Equal(int board1[9], int board2[9]){
	bool result = true;
	for(int i = 0; i < 9; i++){
		if(board1[i] != board2[i]){
			result = false;
		}
	}
	return result;
}

void Print(int board[9]){
	for(int i = 0; i < 9; i++){
		if(board[i] == 0){
			cout<<"*";
		}else{
			cout<<board[i];
		}

		if((i + 1) % 3 == 0){
			cout<<"\n";
		}else{
			cout<<" ";
		}
	}
	cout<<"\n";
}

void PrintPath(Node* leaf){
	vector<Node*> path;
	while(leaf != NULL){
		path.push_back(leaf);
		leaf = leaf->parent;
	}
	while(path.size() > 0){
		Print(path.back()->board);
		path.pop_back();
	}
}

bool Branch(Node *parent){

	if(Equal(parent->board, goal)){
		return true;
		success = true;
	}else if(!parent->children.empty()){
		return false;
	}

	int emptySlot = -1;
	for(int i = 0; i < 9; i++){
			if(parent->board[i] == 0){emptySlot = i;}
		}

	switch(emptySlot){
		case 0:{
			int newBoard1[9] = {parent->board[1], parent->board[0], parent->board[2], parent->board[3], parent->board[4], parent->board[5], parent->board[6], parent->board[7], parent->board[8]};
			int newBoard2[9] = {parent->board[3], parent->board[1], parent->board[2], parent->board[0], parent->board[4], parent->board[5], parent->board[6], parent->board[7], parent->board[8]};
			Node* newNode1 = new Node(parent, newBoard1);
			Node* newNode2 = new Node(parent, newBoard2);
			parent->children.push_back(newNode1);
			parent->children.push_back(newNode2);
			break;
		}case 1:{
			int newBoard1[9] = {parent->board[1], parent->board[0], parent->board[2], parent->board[3], parent->board[4], parent->board[5], parent->board[6], parent->board[7], parent->board[8]};
			int newBoard2[9] = {parent->board[0], parent->board[2], parent->board[1], parent->board[3], parent->board[4], parent->board[5], parent->board[6], parent->board[7], parent->board[8]};
			int newBoard3[9] = {parent->board[0], parent->board[4], parent->board[2], parent->board[3], parent->board[1], parent->board[5], parent->board[6], parent->board[7], parent->board[8]};
			Node* newNode1 = new Node(parent, newBoard1);
			Node* newNode2 = new Node(parent, newBoard2);
			Node* newNode3 = new Node(parent, newBoard3);
			parent->children.push_back(newNode1);
			parent->children.push_back(newNode2);
			parent->children.push_back(newNode3);
			break;
		}case 2:{
			int newBoard1[9] = {parent->board[0], parent->board[2], parent->board[1], parent->board[3], parent->board[4], parent->board[5], parent->board[6], parent->board[7], parent->board[8]};
			int newBoard2[9] = {parent->board[0], parent->board[1], parent->board[5], parent->board[3], parent->board[4], parent->board[2], parent->board[6], parent->board[7], parent->board[8]};
			Node* newNode1 = new Node(parent, newBoard1);
			Node* newNode2 = new Node(parent, newBoard2);
			parent->children.push_back(newNode1);
			parent->children.push_back(newNode2);
			break;
		}case 3:{
			int newBoard1[9] = {parent->board[3], parent->board[1], parent->board[2], parent->board[0], parent->board[4], parent->board[5], parent->board[6], parent->board[7], parent->board[8]};
			int newBoard2[9] = {parent->board[0], parent->board[1], parent->board[2], parent->board[4], parent->board[3], parent->board[5], parent->board[6], parent->board[7], parent->board[8]};
			int newBoard3[9] = {parent->board[0], parent->board[1], parent->board[2], parent->board[6], parent->board[4], parent->board[5], parent->board[3], parent->board[7], parent->board[8]};
			Node* newNode1 = new Node(parent, newBoard1);
			Node* newNode2 = new Node(parent, newBoard2);
			Node* newNode3 = new Node(parent, newBoard3);
			parent->children.push_back(newNode1);
			parent->children.push_back(newNode2);
			parent->children.push_back(newNode3);
			break;
		}case 4:{
			int newBoard1[9] = {parent->board[0], parent->board[4], parent->board[2], parent->board[3], parent->board[1], parent->board[5], parent->board[6], parent->board[7], parent->board[8]};
			int newBoard2[9] = {parent->board[0], parent->board[1], parent->board[2], parent->board[4], parent->board[3], parent->board[5], parent->board[6], parent->board[7], parent->board[8]};
			int newBoard3[9] = {parent->board[0], parent->board[1], parent->board[2], parent->board[3], parent->board[5], parent->board[4], parent->board[6], parent->board[7], parent->board[8]};
			int newBoard4[9] = {parent->board[0], parent->board[1], parent->board[2], parent->board[3], parent->board[7], parent->board[5], parent->board[6], parent->board[4], parent->board[8]};
			Node* newNode1 = new Node(parent, newBoard1);
			Node* newNode2 = new Node(parent, newBoard2);
			Node* newNode3 = new Node(parent, newBoard3);
			Node* newNode4 = new Node(parent, newBoard4);
			parent->children.push_back(newNode1);
			parent->children.push_back(newNode2);
			parent->children.push_back(newNode3);
			parent->children.push_back(newNode4);
			break;
		}case 5:{
			int newBoard1[9] = {parent->board[0], parent->board[1], parent->board[5], parent->board[3], parent->board[4], parent->board[2], parent->board[6], parent->board[7], parent->board[8]};
			int newBoard2[9] = {parent->board[0], parent->board[1], parent->board[2], parent->board[3], parent->board[5], parent->board[4], parent->board[6], parent->board[7], parent->board[8]};
			int newBoard3[9] = {parent->board[0], parent->board[1], parent->board[2], parent->board[3], parent->board[4], parent->board[8], parent->board[6], parent->board[7], parent->board[5]};
			Node* newNode1 = new Node(parent, newBoard1);
			Node* newNode2 = new Node(parent, newBoard2);
			Node* newNode3 = new Node(parent, newBoard3);
			parent->children.push_back(newNode1);
			parent->children.push_back(newNode2);
			parent->children.push_back(newNode3);
			break;
		}case 6:{
			int newBoard1[9] = {parent->board[0], parent->board[1], parent->board[2], parent->board[6], parent->board[4], parent->board[5], parent->board[3], parent->board[7], parent->board[8]};
			int newBoard2[9] = {parent->board[0], parent->board[1], parent->board[2], parent->board[3], parent->board[4], parent->board[5], parent->board[7], parent->board[6], parent->board[8]};
			Node* newNode1 = new Node(parent, newBoard1);
			Node* newNode2 = new Node(parent, newBoard2);
			parent->children.push_back(newNode1);
			parent->children.push_back(newNode2);
			break;
		}case 7:{
			int newBoard1[9] = {parent->board[0], parent->board[1], parent->board[2], parent->board[3], parent->board[7], parent->board[5], parent->board[6], parent->board[4], parent->board[8]};
			int newBoard2[9] = {parent->board[0], parent->board[1], parent->board[2], parent->board[3], parent->board[4], parent->board[5], parent->board[7], parent->board[6], parent->board[8]};
			int newBoard3[9] = {parent->board[0], parent->board[1], parent->board[2], parent->board[3], parent->board[4], parent->board[5], parent->board[6], parent->board[8], parent->board[7]};
			Node* newNode1 = new Node(parent, newBoard1);
			Node* newNode2 = new Node(parent, newBoard2);
			Node* newNode3 = new Node(parent, newBoard3);
			parent->children.push_back(newNode1);
			parent->children.push_back(newNode2);
			parent->children.push_back(newNode3);
			break;
		}case 8:{
			int newBoard1[9] = {parent->board[0], parent->board[1], parent->board[2], parent->board[3], parent->board[4], parent->board[8], parent->board[6], parent->board[7], parent->board[5]};
			int newBoard2[9] = {parent->board[0], parent->board[1], parent->board[2], parent->board[3], parent->board[4], parent->board[5], parent->board[6], parent->board[8], parent->board[7]};
			Node* newNode1 = new Node(parent, newBoard1);
			Node* newNode2 = new Node(parent, newBoard2);
			parent->children.push_back(newNode1);
			parent->children.push_back(newNode2);
			break;
		}
	}
	return false;
}

void BreadthFirstSearch(int board[9]){
	int queued = 0;
	list<Node*> queue;
	Node *curNode = new Node(NULL, board);

	while(curNode->depth < 10){
		if(Branch(curNode)){											//Print path if goal found
			PrintPath(curNode);
			cout<<"\nMoves: "<<curNode->depth<<"\nEnqueued: "<<queued;
			break;
		}
		for(unsigned int i = 0; i < curNode->children.size(); i++){		//Add new children to queue
			curNode->children[i]->depth = curNode->depth + 1;
			queue.push_back(curNode->children[i]);
			queued++;
		}
		curNode = queue.front();										//Fetch front node from queue and set it to current
		queue.pop_front();
	}

}
void IterativeDeepeningSearch(int board[9]){
	int queued = 0;
	bool tempValid;
	bool visited;
	Node *curNode = new Node(NULL, board);
	vector<int*> boards;
	int maxDepth = 10;
	bool found = false;
	Node* foundNode = new Node(NULL, board);

	while(curNode->depth <= maxDepth){
		visited = false;
		for(unsigned int j = 0; j < boards.size();j++){
			if(Equal(curNode->board, boards[j])){
				curNode->valid = false;
				curNode = curNode->parent;
			}
		}
		if(Branch(curNode)){
			maxDepth = curNode->depth;
			found = true;
			foundNode = curNode;
			while(curNode->parent != NULL){
				curNode = curNode->parent;
			}
		}else if(curNode->depth > maxDepth){											//Max depth reached: Invalidate and traverse to parent
			curNode->valid = false;
			curNode = curNode->parent;
		}
		if(visited == false){											//Keep track of visited states
			boards.push_back(curNode->board);
			queued += curNode->children.size();
		}
		tempValid = false;
		for(unsigned int i = 0; i < curNode->children.size(); i++){		//Traverse to first valid child
			visited = false;
			curNode->children[i]->depth = curNode->depth + 1;
			for(unsigned int j = 0; j < boards.size();j++){
				if(Equal(curNode->children[i]->board, boards[j])){
					visited = true;
				}
			}
			if(curNode->children[i]->valid == true && visited == false && tempValid == false){
				tempValid = true;
				curNode = curNode->children[i];
			}
		}if(tempValid == false){										//No valid children: Invalidate and traverse to parent
			curNode->valid = false;
			curNode = curNode->parent;
		}if(curNode == NULL){
			break;
		}
	}
	if(found == true){
		PrintPath(foundNode);											//Print path if goal found
		cout<<"\nMoves: "<<curNode->depth<<"\nEnqueued: "<<queued;
	}
}

int Heuristic1(int board[9]){
	//Heuristic: How many tiles are out of place
	int score = 8;
	for(int i = 0; i < 9; i++){
		if(board[i] == goal[i] && board[i] != 0){score--;}
	}
	return score;
}

int Heuristic2(int board[9]){
	//Heuristic: Manhattan distance
	int score = 0;
	switch(board[0]){
	case 1:
		break;
	case 2: score+=1;
		break;
	case 3: score+=2;
		break;
	case 4: score+=1;
		break;
	case 5: score+=2;
		break;
	case 6: score+=3;
		break;
	case 7: score+=2;
		break;
	case 8: score+=4;
		break;
	}switch(board[1]){
	case 1: score+=1;
		break;
	case 2:
		break;
	case 3: score+=1;
		break;
	case 4: score+=2;
		break;
	case 5: score+=1;
		break;
	case 6: score+=2;
		break;
	case 7: score+=3;
		break;
	case 8: score+=2;
		break;
	}switch(board[2]){
	case 1: score+=2;
		break;
	case 2: score+=1;
		break;
	case 3:
		break;
	case 4: score+=3;
		break;
	case 5: score+=2;
		break;
	case 6: score+=1;
		break;
	case 7: score+=4;
		break;
	case 8: score+=3;
		break;
	}switch(board[3]){
	case 1: score+=1;
		break;
	case 2: score+=2;
		break;
	case 3: score+=3;
		break;
	case 4:
		break;
	case 5: score+=1;
		break;
	case 6: score+=2;
		break;
	case 7: score+=1;
		break;
	case 8:	score+=2;
		break;
	}switch(board[4]){
	case 1: score+=2;
		break;
	case 2: score+=1;
		break;
	case 3: score+=2;
		break;
	case 4: score+=1;
		break;
	case 5:
		break;
	case 6: score+=1;
		break;
	case 7: score+=2;
		break;
	case 8: score+=1;
		break;
	}switch(board[5]){
	case 1: score+=3;
		break;
	case 2: score+=2;
		break;
	case 3: score+=1;
		break;
	case 4: score+=2;
		break;
	case 5: score+=1;
		break;
	case 6:
		break;
	case 7: score+=3;
		break;
	case 8: score+=2;
		break;
	}switch(board[6]){
	case 1: score+=2;
		break;
	case 2: score+=3;
		break;
	case 3: score+=4;
		break;
	case 4: score+=1;
		break;
	case 5: score+=2;
		break;
	case 6: score+=3;
		break;
	case 7:
		break;
	case 8: score+=1;
		break;
	}switch(board[7]){
	case 1: score+=3;
		break;
	case 2: score+=2;
		break;
	case 3: score+=3;
		break;
	case 4: score+=2;
		break;
	case 5: score+=1;
		break;
	case 6: score+=2;
		break;
	case 7: score+=1;
		break;
	case 8:
		break;
	}switch(board[8]){
	case 1: score+=4;
		break;
	case 2: score+=3;
		break;
	case 3: score+=2;
		break;
	case 4: score+=3;
		break;
	case 5: score+=2;
		break;
	case 6: score+=1;
		break;
	case 7: score+=2;
		break;
	case 8: score+=1;
		break;
	}

	return score;
}

void AStarHeuristic1(int board[9]){
	int queued = 0;
	vector<Node*> queue;
	Node *curNode = new Node(NULL, board);
	curNode->valid = false;
	vector<int*> boards;
	boards.push_back(curNode->board);									//Initial state is visited

	while(curNode->depth <= 10){
		if(Branch(curNode)){											//Expand
			PrintPath(curNode);											//Print path if goal found
			cout<<"\nMoves: "<<curNode->depth<<"\nEnqueued: "<<queued;
			break;
		}

		for(unsigned int i = 0; i < curNode->children.size(); i++){		//Add new children to queue
			for(unsigned int j = 0; j < boards.size();j++){
				if(Equal(curNode->children[i]->board, boards[j])){
					curNode->children[i]->valid = false;
				}
			}if(curNode->children[i]->valid == true){
				curNode->children[i]->depth = curNode->depth + 1;
				queue.push_back(curNode->children[i]);
				queued++;
			}
		}
		int min = INT_MAX;
		for(unsigned int i = 0; i < queue.size(); i++){					//Traverse to best move in queue
			if((Heuristic1(queue[i]->board) + queue[i]->depth) < min){
				min = Heuristic1(queue[i]->board) + queue[i]->depth;
				curNode = queue[i];
				queue.erase(queue.begin()+i);
			}
		}
	}
}

void AStarHeuristic2(int board[9]){
	int queued = 0;
	vector<Node*> queue;
	Node *curNode = new Node(NULL, board);
	curNode->valid = false;
	vector<int*> boards;
	boards.push_back(curNode->board);									//Initial state is visited

	while(curNode->depth <= 10){
		if(Branch(curNode)){											//Expand
			PrintPath(curNode);											//Print path if goal found
			cout<<"\nMoves: "<<curNode->depth<<"\nEnqueued: "<<queued;
			break;
		}
		for(unsigned int i = 0; i < curNode->children.size(); i++){		//Add new children to queue
			for(unsigned int j = 0; j < boards.size();j++){
				if(Equal(curNode->children[i]->board, boards[j])){
					curNode->children[i]->valid = false;
				}
			}if(curNode->children[i]->valid == true){
				curNode->children[i]->depth = curNode->depth + 1;
				queue.push_back(curNode->children[i]);
				queued++;
			}
		}
		int min = INT_MAX;
		for(unsigned int i = 0; i < queue.size(); i++){					//Traverse to best move in queue
			if((Heuristic2(queue[i]->board) + queue[i]->depth) < min){
				min = Heuristic2(queue[i]->board) + queue[i]->depth;
				curNode = queue[i];
				queue.erase(queue.begin()+i);
			}
		}
	}
}

int main(int argc, char **argv) {
	if(argc > 15 || argc < 11){
		cout<<"Incorrect number of arguments entered.\n";
		cout<<argc;
		for(int i = 0; i < argc; i++){
			cout<<argv[i]<<"\n";
		}
		return -1;
	}

	string alg = argv[1];
	enum Algorithm {bfs, ids, astar1, astar2};
	Algorithm choice;

	if(alg == "bfs"){
		choice = bfs;
	}else if(alg == "ids"){
		choice = ids;
	}else if (alg == "astar1"){
		choice = astar1;
	}else if(alg == "astar2"){
		choice = astar2;
	}else{
		cout<<"Incorrect algorithm input. Please enter:\n 'bfs' for breadth first search\n 'ids' for iterative deepening search\n 'astar1' for running the A* algorithm with heuristic 1\n 'astar2' for running the A* algorithm with heuristic 2";
		cout<<"\n"<<alg;
		return -1;
	}
	int board[9];
	int x = 0;
	for(int i = 2; i < argc; i++){
		string input = argv[i];
		if(input == "HW1.cpp"){
			board[x] = 0;
			i += 2;
		}else if(input == ".cproject"){	//'*' can be processed as 4 arguments, the first being .cproject, so if .cproject pops up, skip the other arguments and count it as 0.
			board[x] = 0;
			i += 4;
		}else if(input == "*"){
			board[x] = 0;
		}else{
			board[x] = (int)*argv[i]-48;
		}
		x++;
	}

	switch(choice){
	case 0: BreadthFirstSearch(board);break;
	case 1: IterativeDeepeningSearch(board);break;
	case 2: AStarHeuristic1(board);break;
	case 3: AStarHeuristic2(board);break;
	default: return -1;
	}
	if(success == false){
		cout<<"\nThe path could not be found within 10 moves.";
	}
	cout.flush();
	return 0;
}


