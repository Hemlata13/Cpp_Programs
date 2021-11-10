#include<iostream>
#include"Game_Choice_1.h"
#include"Game_Choice_2.h"

using namespace std;

int main()
{
    /* code */
    string plan = "Diwali plans" ; int Game_Choice = 1;
    cout << "What is your Diwali plans ";
    cin >> plan;
    cout << "Thats amazing, have a Happy Diwali! \nWhat game you want to play? \n";
    cout << "To Roll a Dice Press 1 \nTo Play Chips in a Pile Press 2" << endl;
    cin >> Game_Choice;

    if (Game_Choice == 1)
    {
        Dice_Roll();
    }
   else if (Game_Choice == 2)
   {
        Chips_In_Pile();
   } 
   else 
   {
       cout << "What are you afraid of! ";
   }
    
    return 0;
};




