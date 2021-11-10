#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <fstream>
#include"Game_Choice_2.h"

using namespace std;

// Function Declaration 
string findPlayerName(string name[],bool playerTurn);
void userName(string name[]);
int getTheMove(string playerName[], int chipsInPile, bool Player1Turn);

// Variable Declaration
const int Max_Chips = 100;
const float Max_Turn = 0.5;
int chipsInPile = 0 ;
int chipsTaken = 0;
int MaxPerTurn = 0;
int userChoice = 0 ;  
int numberOfMoves = 0;
bool Player1Turn = true;
bool GameOver = false;
string playerName[2];
	
int Chips_In_Pile()
{

	do
	{
		// file to Store Winner name
		ofstream outputFileGame;
		outputFileGame.open("ChipsGameWinner.txt", ios::app);

		// Enter player name
		userName(playerName);

		// see the random number generator
		srand(time(0));

		// start the game with the randome number of chips in the pile
		chipsInPile = (rand() % Max_Chips ) + 1 ;
		cout<< "This round will strat with "<< chipsInPile << " chips in the pile. \n" << endl;
				
		while (GameOver == false)
		{
	
			chipsTaken = getTheMove(playerName, chipsInPile, Player1Turn) ;
			chipsInPile = chipsInPile - chipsTaken;
    
   		 	cout << "There are " << chipsInPile << " left in the pile.\n"<< endl; 
    		numberOfMoves ++ ;
    		
    		if ( chipsInPile == 0 )
    		{
    			GameOver = true;
    			cout<< "Winner of the game is: " << findPlayerName(playerName, !Player1Turn)<< "!" << endl;
    			
    			outputFileGame << "Winner of the Chips Game is: " << findPlayerName(playerName, !Player1Turn) << "." << endl;
    			outputFileGame << "The number of moves, it took to wing the game is: " << numberOfMoves << endl;
	
			}
			else 
			{
				Player1Turn = !Player1Turn;
			}
	
		}
		
		cout << "Do you want to Play again type 1 for yes or 0 for no ";
		cin>> userChoice;
	
		if (userChoice == 1)
		{ 
			GameOver = false;
		}
	} while (userChoice == 1);
	
	return 0;
};

// ** Ask the name of the players.
void userName(string name[])
{
	cout<< "Enter Player 1 Name or Type AI to Play with computer: \n" << endl;
	cin >> name[0];
	cout << "Good Luck! " << name[0] << ". \n"<< endl;
	
	cout<< "Enter Player 2 Name or Type AI to Play with computer: \n" << endl;
	cin >> name[1];
	cout << "Good Luck! " << name[1]<< ". \n" << endl;
}

// ** Find which player's turn it is.
string findPlayerName( string name[], bool playerTurn)
{
	if (playerTurn == true)
	
		return name[0];
	else 
		return name[1];
}


// Determine the number of chips n the bag, ask the player how many chips they want to pick. 
int getTheMove(string playerName[], int chipsInPile, bool Player1Turn)
{
	int MaxPerTurn, chipsTaken;
	char AI;
	do 
	{
		// Maximum number of chips the player can take
		MaxPerTurn = (chipsInPile * Max_Turn);
		
		if (chipsInPile == 1)
		{
			cout << findPlayerName(playerName, Player1Turn) << " How many chips would you like?";
			cout<< "You can pick 1 chip. \n" << endl;
		}
		else
		{
			cout << findPlayerName(playerName, Player1Turn) << ", How many chips would you like? ";
			cout << "You can take upto "<< MaxPerTurn << " chips from pile."<< endl;
		}
		
		if (findPlayerName(playerName, Player1Turn) == "AI")
			{
			if (chipsInPile == 1)
			{
				chipsTaken = 1;
				cout << "Chips taken by Computer is: " << chipsTaken << ". \n" << endl;
			}
			else 
			{
			    chipsTaken = (rand() % MaxPerTurn)+1;
			    cout << "Chips taken by Computer is: " << chipsTaken << ". \n" << endl; 
			}
			}
		else
		{
		 	 cin >> chipsTaken;
		}
    	
   	    	
	}  while ((chipsTaken > MaxPerTurn ) && (chipsInPile > 1));
	
	return chipsTaken;
}

