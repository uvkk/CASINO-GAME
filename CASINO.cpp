#include <iostream>
#include<windows.h>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
using namespace std;
void display();
void rules();
int main()
{
    display();
    string playerName;
    int balance; // stores player's balance
    int bettingAmount;
    int guess;
    int dice; // stores the random number
    char choice;
    srand(time(0)); // "Seed" the random generator
    system ("Color 2F"); //CLI color changer
    cout << "\n\nWhat's your Name :: ";
    getline(cin, playerName);
    cout<<"thanks for telling us your name";
    system ("Color 1"); //CLI color changer
    cout << "\n\nEnter the total balance to play game : $ ";
    cin >> balance;
    do
    {
        system("cls");
        rules();
	    system ("Color 2"); //CLI color changer
        cout << "\n\nYour current balance is : $" << balance << "\n";
// Get player's betting balance
        do
        {
		system ("Color 3"); //CLI color changer
            cout << "Hey, " << playerName<<", Enter how much amount you want to bet : $";
            cin >> bettingAmount;
            if(bettingAmount > balance)
                cout << "Betting balance can't be more than current balance!\n"
                       <<"\nRe-enter balance\n ";
        }while(bettingAmount > balance);
// Get player's numbers
        do
        {
		system ("Color 6"); //CLI color changer
            cout << "Guess any betting number from 1 to 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "\nYour number should be between 1 to 10\n";
                 cout<<"Re-enter number:\n ";
        }while(guess <= 0 || guess > 10);
        dice = rand()%10 + 1;
        if(dice == guess)
        {
		system ("Color 5"); //CLI color changer
            cout << "\n\nCongratulation!! You have won : $" << bettingAmount * 15;
            balance = balance + bettingAmount * 15;
        }
        else
        {
            cout << "Better luck next time !! You have lost : $"<< bettingAmount <<"\n";
            balance = balance - bettingAmount;
        }
        cout << "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<<playerName<<", You have balance of : $" << balance << "\n";
        if(balance == 0)
        {
		system ("Color 4"); //CLI color changer
            cout << " Sorry! You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your balance is : $" << balance << "\n\n";
    return 0;
}
void display()
{
		system ("Color 7"); //CLI color changer
string var="\n=========================================================================================="
 "\n   CCCCC      A        SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO     "
 "\n CC          A  A      SS             III     NN N   NN   OO      OO    "
 "\nCC          A    A     SSSSSSSSS      III     NN  N  NN   OO      OO    "
 "\n CC        AAAAAAAA           SS      III     NN   N NN   OO      OO   " 
 "\n   CCCCC  A        A   SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO   "  
 "\n===============================================================================================\n";
 for(int i=0;i<var.size();i++)
 {
 	Sleep(10);
 	cout<<var[i];
 }
}
void rules()
{
	system ("Color C"); //CLI color changer
    system("cls");
    cout << "\t\t======CASINO NUMBER GUESSING RULES!======\n";
    cout << "\t1. You have to choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 15 times of the money bet\n";
    cout << "\t3. If you choose wrong betting number then you lose the amount you bet!!\n\n";
}
