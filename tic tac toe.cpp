#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main() {
	char active = 'X', userInput, winner;
	string checkInput;
	bool isWinner = false;
	int numTurns = 0;
	char board[3][3] =	{
				{'1', '2', '3'},
				{'4', '5', '6'},
				{'7', '8', '9'}
				};
	
	cout << "\t   TIC - TAC - TOE" << endl;					//Shows board at the start of the game before first person makes a move.
	cout << "\n   Player 1 [X]       Player 2 [O]" << endl;			//Board uses numbers 1 - 9 as spots that a player can select.
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
	
	while (!isWinner) {							//Loops until isWinner is assigned "true".
		int player = (active == 'X') ? 1 : 2;				//Player is assigned to 1 or 2 depending on if 'X' or 'O' is the active turn.
		cout << "\n    Player " << player << ", pick a spot: ";
		getline(cin, checkInput);
		if (checkInput.size() > 1 || !isdigit(checkInput.at(0))) {	//Prevents user from entering multiple numbers/letters that would throw off the switch statement.
			cout << "\n    Invalid input, try again." << endl;
			continue;
		}
		else {
			userInput = checkInput.at(0);
		}
		switch(userInput) {						//Matches userInput with spot on board. If the spot is taken already, prompts user to try another input.
		case '1':
			if (board[0][0] == userInput) {				//Checks if spot is taken by comparing the character at spot with userInput. If they don't match, the spot is taken.
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
		default:							//If userInput isn't 1 - 9, goes to default and prompts user to input another choice.
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "\n    Invalid input, try again." << endl;
			continue;
	}
		system("cls");							//Clears screen after every correct input.
		cout << "\t   TIC - TAC - TOE" << endl;				//Shows updated board each time a correct input is entered.
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
		
		for (int i = 0; i < 3; i++) {					//For loop checks if there is a winner by checking straight lines through columns and rows.
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
		}								//Two if statements check diagonals for a winner.
		if (board[0][0] == active && board[1][1] == active && board[2][2] == active) {
			isWinner = true;
			winner = active;
		}
		if (board[0][2] == active && board[1][1] == active && board[2][0] == active) {
			isWinner = true;
			winner = active;
		}
		
		numTurns++;							//Maximum number of turns for a game is 9, so numTurns checks for a draw. If numTurns is reached, game is over.
		if (numTurns >= 9) {						//When numTurns is reached, loop is broken without changing isWinner, so it remains "false".
			break;
		}
		if (isWinner == false){						//If there isn't a winner, the active character switches from 'X' to 'O' and vice versa.
			active = (active == 'X') ? 'O' : 'X';
		}
	}									//End of game loop.
	if (active == 'X' && isWinner) {					//If 'X' was the last move and isWinner is "true", Player 1 must be the winner.
		cout << "\n\t   Player 1 Wins!" << endl;
	}
	else if (active == 'O' && isWinner){					//If 'O' was the last move and isWinner is "true", Player 2 must be the winner.
		cout << "\n\t   Player 2 Wins!" << endl;
	}
	else {									//Otherwise, the loop must have been broken by numTurns, so it must be a tie game.
		cout << "\n\t      Tie Game!" << endl;
	}
	_getch();
}
