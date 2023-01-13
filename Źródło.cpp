#include <iostream>
#include <stdlib.h>
#include <dos.h> //delay()
#include <windows.h> //sleep()
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <conio.h>   //color
#include "color.hpp"
using namespace std;

string player1 = "Player 1";
string player2 = "Player 2";
char playernames, mark;
char num_board[10] = { 'o','1','2','3','4','5','6','7','8','9'};
string choice;
int  who, i, turn;

void intro() {
	system("color 3");
	cout << dye::light_blue("		==============================================================================\n");
	cout << dye::light_blue("		==============	   "); cout << dye::yellow("TicTacToe GAME by Jan Skulimowski s27144"); cout << dye::light_blue("	==============\n");
	cout << dye::light_blue("		==============================================================================\n") << endl;

}

void set_names() {
	cout << dye::light_blue("Enter the name of the first player : ");
	cin >> player1;
	cout << dye::light_blue("Enter the name of the second player: ");
	cin >> player2;
	system("CLS");
	intro();
	cout << dye::light_blue("Player 1: ") << dye::aqua(player1) << dye::aqua(" (X)") << dye::light_blue("\nPlayer 2: ") << dye::yellow(player2) << dye::yellow(" (Y)") << endl;
	system("pause");
	system("cls");
	intro();
	return;
}

void ask_set_names() {

	cout << dye::light_blue("Do you want to enter player names? "); cout << dye::yellow("[Y/N] : ");
	cin >> playernames;
	if (playernames == 'y' || playernames == 'Y')
	{
		set_names();
		return;

	}
	else if (playernames == 'n' || playernames == 'N')
	{
		return;
	}
	else
	{
		cout << dye::light_blue("Wrong answer, try again.");
		Sleep(2200);
		system("cls");
		intro();
		return(ask_set_names());
	}
}

void who_starts() {
	srand(time(NULL));
	who = rand() % 2 + 1;
	if (who == 1) {
		turn = true;
	}
	else {
		turn = false;
	}
}

void board() {
	system("cls");
	intro();
	cout << "	       			       	   " << dye::aqua(player1) << dye::aqua(" (X)") << dye::light_blue(" vs ") << dye::yellow(player2) << dye::yellow(" (Y)") << endl;
	cout << endl;

	cout << "	       					" << "     |     |" << endl;
	cout << "	    	    				" << "  " << num_board[1] << "  |  " << num_board[2] << "  |  " << num_board[3] << endl;
	cout << "	       					" << "_____|_____|_____" << endl;
	cout << "	       					" << "     |     |     " << endl;
	cout << "	       					" << "  " << num_board[4] << "  |  " << num_board[5] << "  |  " << num_board[6] << endl;
	cout << "	       					" << "_____|_____|_____" << endl;
	cout << "	       					" << "     |     |     " << endl;
	cout << "	       					" << "  " << num_board[7] << "  |  " << num_board[8] << "  |  " << num_board[9] << endl;
	cout << "	       					" << "     |     |" << endl;
	
}

int check_win() {
	if (num_board[1] == num_board[2] && num_board[2] == num_board[3])

		return 1;
	else if (num_board[4] == num_board[5] && num_board[5] == num_board[6])

		return 1;
	else if (num_board[7] == num_board[8] && num_board[8] == num_board[9])

		return 1;
	else if (num_board[1] == num_board[4] && num_board[4] == num_board[7])

		return 1;
	else if (num_board[2] == num_board[5] && num_board[5] == num_board[8])

		return 1;
	else if (num_board[3] == num_board[6] && num_board[6] == num_board[9])

		return 1;
	else if (num_board[1] == num_board[5] && num_board[5] == num_board[9])

		return 1;
	else if (num_board[3] == num_board[5] && num_board[5] == num_board[7])

		return 1;
	else if (num_board[1] != '1' && num_board[2] != '2' && num_board[3] != '3'
		&& num_board[4] != '4' && num_board[5] != '5' && num_board[6] != '6'
		&& num_board[7] != '7' && num_board[8] != '8' && num_board[9] != '9')

		return 0;
	else
		return -1;
}

int main() {
	intro();
	ask_set_names();
	who_starts();

	do {
		board();

		if (turn == true) { mark = 'X'; dye::aqua(mark); cout << dye::aqua("Player ") << dye::aqua(player1) << dye::aqua(" (X), enter a number : "); }
		else { mark = 'Y'; dye::light_red(mark); cout << dye::yellow("Player ") << dye::yellow(player2) << dye::yellow(" (Y), enter a number:  "); }
		cin >> choice;


		if (choice == "1" && num_board[1] == '1') { num_board[1] = mark;}
		else if (choice == "2" && num_board[2] == '2') { num_board[2] = mark;}


		else if (choice == "3" && num_board[3] == '3') { num_board[3] = mark;}


		else if (choice == "4" && num_board[4] == '4') { num_board[4] = mark;}


		else if (choice == "5" && num_board[5] == '5') { num_board[5] = mark;}


		else if (choice == "6" && num_board[6] == '6') { num_board[6] = mark;}


		else if (choice == "7" && num_board[7] == '7') { num_board[7] = mark;}


		else if (choice == "8" && num_board[8] == '8') { num_board[8] = mark;}


		else if (choice == "9" && num_board[9] == '9') { num_board[9] = mark;}

		else {
			cout << "Invalid move ";
			cin.ignore();
			cin.clear();
			choice = "";
		}

		i = check_win();
		turn = !turn;
	} while (i == -1);

	board();


	if (i == 1) {
		if (turn != true) {
			
			cout << dye::aqua("Player (X) ") << dye::yellow(player1) << dye::aqua(" win. Thanks for playing!\n");
			system("pause");
		}
		else {
			
			cout << dye::yellow("Player (Y) ") << dye::aqua(player2) << dye::yellow(" win. Thanks for playing!\n");
			system("pause");
		}
	}
	else {
		cout << dye::aqua("Game draw!") << dye::yellow("Thanks for playing!\n");
		system("pause");
	}

	return 0;
}





