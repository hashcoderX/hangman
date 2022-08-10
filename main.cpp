#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
using namespace std;

int NUM_OF_TRY=3;
int checkGuess (char, string, string&);
void main_menu();
string message = "Play!";


int main(int argc, char *argv[])
{
	string name;
	char letter;
	string month;


    string months[] =
	{
		"january",
		"february",
		"march",
		"april",
		"may",
		"june",
		"july",
		"august",
		"september",
		"october",
		"november",
		"december"
	};

	srand(time(NULL));
	int n=rand()% 12;
	month=months[n];


	string hide_m(month.length(),'X');




	while (NUM_OF_TRY!=0)
	{
		main_menu();
		cout << "\n\n\t\t\t\t" << hide_m;
		cout << "\n\n\t\t\t\tGuess a letter: ";
		cin >> letter;

		if (checkGuess(letter, month, hide_m)==0)
		{
			message = "Incorrect letter.";
			NUM_OF_TRY = NUM_OF_TRY - 1;
		}
		else
		{
			message = "NICE! You guess a letter";
		}



		if (month==hide_m)
		{
			message = "Congratulations! You got it!";
			main_menu();
			cout << "\n\t\t\t\tThe month is : " << month << endl;
			break;
		}
	}
	if(NUM_OF_TRY == 0)
	{
		message = " SHITS!you've been hanged.";
		main_menu();
		cout << "\n\t\t\t\tThe month was : " << month << endl;
	}
	cin.ignore();
	cin.get();
	return 0;
}


int checkGuess (char guess, string secretmonth, string &guessmonth)
{
	int c;
	int matches=0;
	int len=secretmonth.length();
	for (c = 0; c< len; c++)
	{

		if (guess == guessmonth[c])
			return 0;

		if (guess == secretmonth[c])
		{
			guessmonth[c] = guess;
			matches++;
		}
	}
	return matches;
}

void main_menu()
{
	 system("color 05");
                system("cls");
                 cout<<"\t\t\t\t*\t*";

  cout<<"\t\t\t\t**\t**";
   cout<<"\t\t\t\t***\t***";
   cout<<"\t\t\t\t****\t****";
   cout<<"\t\t\t\t*****\t*****";
    cout<<"\t\t\t\t******\t******";
   cout<<"\t\t\t\t*******\t*******";
   cout<<"\t\t\t\t*******\t*******";
   cout<<"\t\t\t\t******\t******";
   cout<<"\t\t\t\t*****\t*****";
   cout<<"\t\t\t\t****\t****";
   cout<<"\t\t\t\t***\t***";
   cout<<"\t\t\t\t**\t**";
   cout<<"\t\t\t\t*\t*";

 cout<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
                cout<<"\n\t\t\t\tHangman Game!";
				cout << "\n\t\tYou have " << NUM_OF_TRY << " tries to try and guess the month.";
				cout<<"\n\n\t\t\t\t"+message;
 cout<<"\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

}
