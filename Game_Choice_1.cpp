#include<iostream>
#include<cstdlib>
#include<ctime>
#include"Game_Choice_1.h"

using namespace std;

int Dice_Roll()
{
	
	int dice=0 ;
	int diceGame = 0 ;
	cout << "\n Do you want to roll a dice, please type 1 for yes or 0 for No \n";
	cin >> diceGame;
	
	if (diceGame == 1)
		{
			srand(time(0));
			dice = rand()%6+1;
	
			switch (dice)
			{
				case 1:
					cout << "You rolled a: one \n";
					return (dice);
					break;
		
				case 2:
					cout << "You rolled a: Two \n";
					return (dice);
					break;	
				case 3:
					cout << "You rolled a: Three \n";
					return (dice);
					break;	
		
				case 4:
					cout << "You rolled a: Four \n";
					return (dice);
					break;
			
				case 5:
					cout << "You rolled a: Five \n";
					return (dice);
					break;
			
				case 6:
					cout << "You rolled a: Six \n";
					return (dice);
					break;
			
				default:
					cout << "you are doing something wrong with the code \n";
					break;
	
				}	
		}
	else 
		cout << "What are you afraid of? " ;
    
	
	return(dice);
 } ;
