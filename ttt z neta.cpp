#include <iostream>
using namespace std;

void displayBoard(char board[]);
bool rangeCorrect(int cell);
bool cellIsEmpty(int cell, char board[]);
void changeTurn(char &turn);
bool three(char turn, char board[]);
bool threeInARow(char turn, char board[]);
bool threeInAColumn(char turn, char board[]);
bool threeInADiagonal(char turn, char board[]);

struct Node {
   int moveNumber;
   char board[9];
   Node *nextPtr;
};

void displayList( Node *head);


int main() {
	char board[9];
	//initializing board
	for(int i = 0; i < 9; i++)
		board[i] = ' ';
	
	Node *head = NULL;   // head of linked list 
    Node *tempPtr;

	int moveNumber = 0;
	char turn = 'X';
	int cell = 0;
	displayBoard(board);//displays the empty board
	while(moveNumber < 9) {
		displayList(head);
		cout<<"*****************************"<<endl;
		cout<<"Move number: "<<moveNumber<<endl;
		cout << "TURN: "<< turn << " make your move: ";
		cin >> cell; //this is the simple version. only input numbers here. does not check non-numeric characters..
		//is input correct?
		if(rangeCorrect(cell)) { //checking if inside the range 1-9
			if(cellIsEmpty(cell-1, board)){ //checking if cell is empty. subtracting 1, because array starts from 0.
				board[cell-1] = turn;//storing the move in the array
				if(three(turn, board)) {//checking if there are three in a row or column or diagonal
					displayBoard(board);
					cout << "Congratulations player "<<turn<< " You win!!";
					cin >> cell; //to stop execution on windows 
					return 1;
				}
				
				//creating a new Node, filling its fields and adding to the list.
				tempPtr = new Node;
				// Insert at head of list 
				tempPtr->moveNumber = moveNumber; //copying moveNumber inside the node
				for(int i=0;i<9;i++) { //copying the elements of the board inside the board in the node
					tempPtr->board[i]=board[i];
				}
				tempPtr->nextPtr = head; //the pointer of the node points to the first element of the list
				head = tempPtr; //the head points to the new node just created
				moveNumber++; //preparing for next move.
				changeTurn(turn);//changing the turn to the next player.
				
			}
			else { //cell was full
				cout << "Sorry...cell "<< cell << " has already been used, try again: " << endl;
			}
		}
		else {
			cout << "Sorry...cell "<< cell << " is outside the range 1-9, try again: " << endl;
		}
	}
	cout<<"Game Ended: No Winners";
	cin >>cell;
	return 1;
}

void displayList( Node *head)
{
   Node *tempPtr = head;  // Used to traverse list without destroying head
   cout << "\n List contains: "<<endl;
   while( tempPtr != NULL) {
      displayBoard(tempPtr->board);
	  cout<<"Move Numer: "<<tempPtr->moveNumber<<endl<<endl;
      tempPtr = tempPtr->nextPtr;
   }
   cout << "\n\n";
}

void displayBoard(char board[]) {
	cout << " ___   ___   ___ "<<endl;
	cout << "| "<<board[0]<<" |"<<" "<< "| "<< board[1]<<" |"<<" "<< "| "<< board[2]<<" |"<<endl;
	cout << "|___| |___| |___| "<<endl;
	cout << " ___   ___   ___ "<<endl;
	cout << "| "<<board[3]<<" |"<<" "<< "| "<< board[4]<<" |"<<" "<< "| "<< board[5]<<" |"<<endl;
	cout << "|___| |___| |___| "<<endl;
	cout << " ___   ___   ___ "<<endl;
	cout << "| "<<board[6]<<" |"<<" "<< "| "<< board[7]<<" |"<<" "<< "| "<< board[8]<<" |"<<endl;
	cout << "|___| |___| |___| "<<endl;
	/*cout << "|"<<board[3]<<"|"<<board[4]<<"|"<<board[5]<<"|"<<endl;
	cout << "_______"<<endl;
	cout << "|"<<board[6]<<"|"<<board[7]<<"|"<<board[8]<<"|"<<endl;
	cout << "_______"<<endl;*/

}

//returns true if cell is between 1 and 9
bool rangeCorrect(int cell) {
	//checking if cell is outside the range 1 to 9.
	if(cell >= 1 && cell <= 9)
		return true;
	else 
		return false;
}

//returns true if the cell has already been used
bool cellIsEmpty(int cell, char  board[]) {
	if(board[cell]!=' ')
		return false;
	else 
		return true;
}

void changeTurn(char &turn) {
	if(turn == 'X')
		turn = 'O';
	else
		turn = 'X';
}

bool three(char turn, char board[]) {
	if(threeInARow(turn, board) || threeInAColumn(turn,board) || threeInADiagonal(turn,board))
		return true;
	else
		return false;
}

bool threeInARow(char turn, char board[]) {
	if((board[0] == turn && board[1] == turn && board[2] == turn) ||
	   (board[3] == turn && board[4] == turn && board[5] == turn) ||
	   (board[6] == turn && board[7] == turn && board[8] == turn))
	   return true;
	else 
		return false;
}

bool threeInAColumn(char turn, char board[]) {
	if((board[0] == turn && board[3] == turn && board[6] == turn) ||
	   (board[1] == turn && board[4] == turn && board[7] == turn) ||
	   (board[2] == turn && board[5] == turn && board[8] == turn))
	   return true;
	else 
		return false;
}

bool threeInADiagonal(char turn, char board[]) {
	if((board[0] == turn && board[4] == turn && board[8] == turn) ||
	   (board[2] == turn && board[4] == turn && board[6] == turn))
	   return true;
	else 
		return false;
}