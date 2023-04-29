#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

char board[3][3]; //character variable board declared globally for tic_tac_toe game
int i, j, ctr = 1, wrongentry = 0, player = 1, option, choice1, win = 0;  // varaibles declared globally for tic_tac_toe game

void createboard(); // Function prototype for the function , createboard()
void display();  // Function prototype for the function , display()
void tic_tac_toe(); // Function prototype for the function , tic_tac_toe()


int main()
{
	int a, count = 0, x = 0;
	char board[3][3];
	const int SIZE = 8;
	string magic_8_ball[8], question;
	char ans;
	do
	{
		cout << "GAMES MENU";
		cout << "\n_________________________";
		cout << "\n1. Hi-Lo Guessing Game";
		cout << "\n2. Magic 8-ball";
		cout << "\n3. Palindrome";
		cout << "\n4. Rock/Paper/Scissors";
		cout << "\n5. Tic-Tac-Toe";
		cout << "\n\nEnter the game of your choice :";
		cin >> a;
		switch (a)
		{
		    case 1:
				int number, guess;
			cout << "\n LET'S PLAY THE HI-LO GUESSING GAME !!!\n";
			srand(time(0));
			number = rand() % 100 + 1;
			
			do
			{
				
				cout << "\nGuess a number between 1 and 100 :";
				cin >> guess;
				count++;
				if (guess < number)
					cout << "\nIt is too low !!";
				else if (guess > number)
					cout << "\nIt is too high !!";
				else
					cout << "\nGood Job !! You have guessed the secret number correctly in " << count << " " << "guesses" << " !";
			} while (guess != number);
			
			
			break;
		case 2:
			
			int num;

			cout << "\nLET'S PLAY THE MAGIC 8-BALL GAME !!!\n";
			
			cout << "\nEnter a yes or no question : ";
			cin.ignore(100, '\n');
			getline(cin, question);

			srand(time(0));
			num = rand() % 8;

		    magic_8_ball[0] = "Absolutely !!";
			magic_8_ball[1] = "There is no way that will happen !!";
			magic_8_ball[2] = "Most probably !";
			magic_8_ball[3] = "I guess so...";
			magic_8_ball[4] = "Cannot predict now !";
			magic_8_ball[5] = "Very doubtful !";
			magic_8_ball[6] = "Outlook is good !";
			magic_8_ball[7] = "Signs point to yes !";

			cout << "\nHere is your answer: " << endl;
			cout << endl << magic_8_ball[num] << endl;
			break;
		case 3:
			char b[20];
			int i;
			cout << "\nLET'S PLAY THE PALINDROME GAME !!!\n";
			cout << "\nEnter the string: ";
			cin >> b;
			for (i = 0; i < strlen(b); i++)
			{
				if (b[i] != b[strlen(b) - 1])
				{
					x = 1;
					cout << "Sorry !! " << b << " " << "is not a palindrome." << endl;
					break;
				}
				  if(x==0)
					cout << "Yayy !! " << b << " " << "is a palindrome." << endl;
				   break;
			}
		  
			break;
		case 4 :
			int choice, computer_guess;
			cout << "\nLET'S PLAY THE ROCK/PAPER/SCISSORS GAME !!!\n";
			cout << "\n1. Rock.";
			cout << "\n2. Paper.";
			cout << "\n3. Scissors.";
			cout << "\nEnter your choice :";
			cin >> choice;
			srand(time(0));
			computer_guess = rand() % 3 + 1;
			switch (choice)
			{
			case 1:
				cout << "\nYou have picked Rock !";
				break;
			case 2:
				cout << "\nYou have picked Paper !";
				break;
			case 3:
				cout << "\nYou have picked Scissors !";
				break;
			default:
				cout << "\nInvalid Choice ! Please try again..";
			}
			cout << "\nYour choice : " << choice;
			cout << "\nComputer's choice : " << computer_guess;
			if (choice == 1)
			{
				if (computer_guess == 2)
					cout << "\nSorry ! The computer has won !!";
			}
			if (choice == 1)
			{
				if (computer_guess == 3)
					cout << "\nGood Job ! You have won !!";
			}
			if (choice == 1)
			{
				if (computer_guess == 1)
					cout << "\nIt's a tie ! Try again..";
			}
			if (choice == 2)
			{
				if (computer_guess == 1)
					cout << "\nGood Job ! You have won !!";
			}
			if(choice == 2)
			{ if(computer_guess == 3)
				cout << "\nSorry ! The computer has won !!";
			}
			if (choice == 2)
			{
				if (computer_guess == 2)
					cout << "\nIt's a tie ! Try again..";
			}
			if (choice == 3)
			{
				if (computer_guess == 1)
					cout << "\nSorry ! The computer has won !!";
			}
			if (choice == 3)
			{
				if (computer_guess == 2)
					cout << "\nGood Job ! You have won !!";
			}
			if (choice == 3)
			{
				if (computer_guess == 3)
					cout << "\nIt's a tie ! Try again..";
			}
			break;
		case 5:
			cout << "\nLET'S PLAY THE TIC-TAC-TOE GAME !!!\n";
			tic_tac_toe();
		default:
			cout << "\nInvalid choice ! Please try again !";
		
        }
		cout << "\nDo you want to continue (y/n) ?  ";
		cin >> ans;
	} while (ans == 'Y' || ans == 'y');
	return 0;
}

void createboard()  // Function definition for createboard() function for tic_tac_toe game
{
	board[0][0] = '1';
	board[0][1] = '2';
	board[0][2] = '3';
	board[1][0] = '4';
	board[1][1] = '5';
	board[1][2] = '6';
	board[2][0] = '7';
	board[2][1] = '8';
	board[2][2] = '9';
}

void display()   // Function definition for display() function for tic_tac_toe game
{
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			cout <<  board[i][j] << "\t";
		cout << endl;
	}

}

void checkplayer1win()   // Function definition for checkplayer1win() function for tic_tac_toe game
{
	char ch = 'X';
	if (board[0][0] == ch && board[0][0] == board[0][1] && board[0][1] == board[0][2])
	{
		cout << "\nPlayer 1 has won";
		win = 1;
	}
	else if (board[1][0] == ch && board[1][0] == board[1][1] && board[1][1] == board[1][2])
	{
		cout << "\nPlayer 1 has won";
		win = 1;
	}
	else if (board[2][0] == ch && board[2][0] == board[2][1] && board[2][1] == board[2][2])
	{
		cout << "\nPlayer 1 has won";
		win = 1;
	}
	else if (board[0][0] == ch && board[0][0] == board[1][0] && board[1][0] == board[2][0])
	{
		cout << "\nPlayer 1 has won";
		win = 1;
	}
	else if (board[0][1] == ch && board[0][1] == board[1][1] && board[1][1] == board[2][1])
	{
		cout << "\nPlayer 1 has won";
		win = 1;
	}
	else if (board[0][2] == ch && board[0][2] == board[1][2] && board[1][2] == board[2][2])
	{
		cout << "\nPlayer 1 has won";
		win = 1;
	}
	else if (board[0][0] == ch && board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		cout << "\nPlayer 1 has won";
		win = 1;
	}
	else if (board[2][0] == ch && board[1][1] == board[2][0] && board[1][1] == board[0][2])
	{
		cout << "\nPlayer 1 has won";
		win = 1;
	}
}

void checkplayer2win()   // Function definition for checkplayer2win() function for tic_tac_toe game
{
	char ch = 'O';
	if (board[0][0] == ch && board[0][0] == board[0][1] && board[0][1] == board[0][2])
	{
		cout << "\nPlayer 2 has won";
		win = 1;
	}
	else if (board[1][0] == ch && board[1][0] == board[1][1] && board[1][1] == board[1][2])
	{
		cout << "\nPlayer 2 has won";
		win = 1;
	}
	else if (board[2][0] == ch && board[2][0] == board[2][1] && board[2][1] == board[2][2])
	{
		cout << "\nPlayer 2 has won";
		win = 1;
	}
	else if (board[0][0] == ch && board[0][0] == board[1][0] && board[1][0] == board[2][0])
	{
		cout << "\nPlayer 2 has won";
		win = 1;
	}
	else if (board[0][1] == ch && board[0][1] == board[1][1] && board[1][1] == board[2][1])
	{
		cout << "\nPlayer 2 has won";
		win = 1;
	}
	else if (board[0][2] == ch && board[0][2] == board[1][2] && board[1][2] == board[2][2])
	{
		cout << "\nPlayer 2 has won";
		win = 1;
	}
	else if (board[0][0] == ch && board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		cout << "\nPlayer 2 has won";
		win = 1;
	}
	else if (board[2][0] == ch && board[1][1] == board[2][0] && board[1][1] == board[0][2])
	{
		cout << "\nPlayer 2 has won";
		win = 1;
	}
}

void tic_tac_toe()  // Function definition for tic_tac_toe()
{
	createboard();
	display();
	do
	{
		if (player == 1)
		{
			wrongentry = 0;
			cout << "\nPlayer 1's Turn !\n";
			cout << "\nEnter the location where you wish to make your move : ";
			cin >> choice1;
			switch (choice1)
			{
			case 1:
				board[0][0] = 'X';
				break;
			case 2:
				board[0][1] = 'X';
				break;
			case 3:
				board[0][2] = 'X';
				break;
			case 4:
				board[1][0] = 'X';
				break;
			case 5:
				board[1][1] = 'X';
				break;
			case 6:
				board[1][2] = 'X';
				break;
			case 7:
				board[2][0] = 'X';
				break;
			case 8:
				board[2][1] = 'X';
				break;
			case 9:
				board[2][2] = 'X';
				break;
			default:
				cout << "\nWrongchoice";
				wrongentry = 1;
				break;
			}
			if (wrongentry == 0)
			{
				player = 2;
			}
			display();
			checkplayer1win();
		}
		else if (player == 2)
		{
			wrongentry = 0;
			cout << "\nPlayer 2's Turn !\n";
			cout << "\nnEnter the location where you wish to make your move : ";
			cin >> choice1;
			switch (choice1)
			{
			case 1:
				board[0][0] = 'O';
				break;
			case 2:
				board[0][1] = 'O';
				break;
			case 3:
				board[0][2] = 'O';
				break;
			case 4:
				board[1][0] = 'O';
				break;
			case 5:
				board[1][1] = 'O';
				break;
			case 6:
				board[1][2] = 'O';
				break;
			case 7:
				board[2][0] = 'O';
				break;
			case 8:
				board[2][1] = 'O';
				break;
			case 9:
				board[2][2] = 'O';
				break;
			default:
				cout << "\nWrongchoice";
				wrongentry = 1;
				break;
			}
			if (wrongentry == 0)
			{
				player = 1;
			}
			display();
			checkplayer2win();
		}
		if ((board[0][0] == 'X' || board[0][0] == 'O') && (board[0][1] == 'X' || board[0][1] == 'O') &&
			(board[0][2] == 'X' || board[0][2] == 'O') && (board[1][0] == 'X' || board[1][0] == 'O') &&
			(board[1][1] == 'X' || board[1][1] == 'O') && (board[1][2] == 'X' || board[1][2] == 'O') &&
			(board[2][0] == 'X' || board[2][0] == 'O') && (board[2][1] == 'X' || board[2][1] == 'O') &&
			(board[2][2] == 'X' || board[2][2] == 'O') && win == 0)
		{
			cout << "\nIt's a draw !!";
			win = 1;
		}
		cout << "\nDo you want to continue\nEnter your choice(0/1): ";
		cin >> option;
	} while (option == 1 && win == 0);
}





