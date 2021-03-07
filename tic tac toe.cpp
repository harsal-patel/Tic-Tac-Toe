#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main() {
	char active = 'X', userInput, winner;
	bool isWinner = false;
	int numTurns = 0;
	char board[3][3] = {
							{'1', '2', '3'},
							{'4', '5', '6'},
							{'7', '8', '9'}
						};
	
	cout << "\t   TIC - TAC - TOE" << endl;
	cout << "\n   Player 1 [X]       Player 2 [O]" << endl;
	cout << endl;
	cout << "\t      |       |" << endl;
	cout << "\t  " << board[0][0] << "   |   " << board[0][1] << "   |   " << board [0][2] << endl;
	cout << "\t______|_______|_______" << endl;
	cout << "\t      |       |" << endl;
	cout << "\t  " << board[1][0] << "   |   " << board[1][1] << "   |   " << board [1][2] << endl;
	cout << "\t______|_______|_______" << endl;
	cout << "\t      |       |" << endl;
	cout << "\t  " << board[2][0] << "   |   " << board[2][1] << "   |   " << board [2][2] << endl;
	cout << "\t      |       |" << endl;
	
	while (!isWinner) {
		int player = (active == 'X') ? 1 : 2;
		cout << "\n    Player " << player << ", pick a spot: ";
		cin >> userInput;
		switch(userInput) {
		case '1':
			if (board[0][0] == userInput) {
				board[0][0] = active;
			}
			else {
				cout << "\n    Invalid input, try again." << endl;
				continue;
			}
			break;
		case '2':
			if (board[0][1] == userInput) {
				board[0][1] = active;
			}
			else {
				cout << "\n    Invalid input, try again." << endl;
				continue;
			}
			break;
		case '3':
			if (board[0][2] == userInput) {
				board[0][2] = active;
			}
			else {
				cout << "\n    Invalid input, try again." << endl;
				continue;
			}
			break;
		case '4':
			if (board[1][0] == userInput) {
				board[1][0] = active;
			}
			else {
				cout << "\n    Invalid input, try again." << endl;
				continue;
			}
			break;
		case '5':
			if (board[1][1] == userInput) {
				board[1][1] = active;
			}
			else {
				cout << "\n    Invalid input, try again." << endl;
				continue;
			}
			break;
		case '6':
			if (board[1][2] == userInput) {
				board[1][2] = active;
			}
			else {
				cout << "\n    Invalid input, try again." << endl;
				continue;
			}
			break;
		case '7':
			if (board[2][0] == userInput) {
				board[2][0] = active;
			}
			else {
				cout << "\n    Invalid input, try again." << endl;
				continue;
			}
			break;
		case '8':
			if (board[2][1] == userInput) {
				board[2][1] = active;
			}
			else {
				cout << "\n    Invalid input, try again." << endl;
				continue;
			}
			break;
		case '9':
			if (board[2][2] == userInput) {
				board[2][2] = active;
			}
			else {
				cout << "\n    Invalid input, try again." << endl;
				continue;
			}
			break;
		default:
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "\n    Invalid input, try again." << endl;
			continue;
	}
		system("cls");
		cout << "\t   TIC - TAC - TOE" << endl;
	cout << "\n   Player 1 <X>        Player 2 <O>" << endl;
	cout << endl;
	cout << "\t      |       |" << endl;
	cout << "\t  " << board[0][0] << "   |   " << board[0][1] << "   |   " << board [0][2] << endl;
	cout << "\t______|_______|_______" << endl;
	cout << "\t      |       |" << endl;
	cout << "\t  " << board[1][0] << "   |   " << board[1][1] << "   |   " << board [1][2] << endl;
	cout << "\t______|_______|_______" << endl;
	cout << "\t      |       |" << endl;
	cout << "\t  " << board[2][0] << "   |   " << board[2][1] << "   |   " << board [2][2] << endl;
	cout << "\t      |       |" << endl;
		
		for (int i = 0; i < 3; i++) {
			if (board[i][0] == active && board[i][1] == active && board[i][2] == active) {
			isWinner = true;
			winner = active;
			break;
			}
			if (board[0][i] == active && board[1][i] == active && board[2][i] == active) {
			isWinner = true;
			winner = active;
			break;
			}
		}
		if (board[0][0] == active && board[1][1] == active && board[2][2] == active) {
			isWinner = true;
			winner = active;
		}
		if (board[0][2] == active && board[1][1] == active && board[2][0] == active) {
			isWinner = true;
			winner = active;
		}
		
		numTurns++;
		if (numTurns >= 9) {
			break;
		}
		if (isWinner == false){	
			active = (active == 'X') ? 'O' : 'X';
		}
	}
	if (active == 'X' && isWinner) {
		cout << "\n\t   Player 1 Wins!" << endl;
	}
	else if (active == 'O' && isWinner){
		cout << "\n\t   Player 2 Wins!" << endl;
	}
	else {
		cout << "\n\t      Tie Game!" << endl;
	}
}
