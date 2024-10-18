
#include <iostream>
#include <cstdlib>
using namespace std;

//function to roll a die
int die() {

	return rand() % 6 + 1;  //returns a random number b/w 1 and 6

}

//function to play the game of craps
void playGame(int &balance) {

	int wager;
	cout<< "You have " << balance << " credits. How much do you wager ? ";
	cin >> wager;

	while (wager > balance) { //condition to check the betting amount does not exceed balance
		cout<<"You wager exceeds your balance. Try again. \n";
		cout<< "How much do you wager? ";
		cin >> wager;
	}
    //rolling the die
	int roll1 = die();
	int roll2 = die();
	int sum = roll1 + roll2;

	cout<< "Player rolled "<< roll1<< " + " << roll2 << " = " << sum << endl;

	if(sum == 7|| sum ==11) { //checks result of first roll
		cout << "Player wins\n";
		balance = balance + wager; // adds to the balance
		cout<< "You won " << wager << " credits. Your new balance is " << balance << " credits\n";

	}
	else if (sum == 2 ||sum == 3 || sum ==12) { //also checks result of furst roll
		cout << "Player loses\n" ;
		balance = balance- wager;       //this conditions takes away from balance
		cout<< "You lost " << wager << " credits. Your new balance is " << balance << " credits\n";
	}
	else {
	    
		int point = sum;
		cout<< "Point is " << point << endl;
		bool PointsWon = false;
		while(!PointsWon) {

			roll1 = die();
			roll2 = die();
			sum = roll1 + roll2;
			cout << "Player rolled " << roll1 << " + " << roll2 << " = " << sum <<endl;

			if (sum == point) { //checks if player rolls a 7 or makes a point
				cout << "Player wins\n";
				balance = balance + wager; //if point is made, it is added to balance
				cout<< "You won " << wager << " credits. Your new balance is "<< balance<< " credits\n";
				PointsWon = true;

			}
			else if (sum == 7) {
				cout << "Player loses\n";
				balance = balance - wager; //point not made, balance is deducted
				cout << "You lost "<< wager << " credits. Your new balance is "<< balance << " credits\n";
				PointsWon = true;
			}
		}

	}

}

int main() {


int balance = 100; //initial balance
char ans;
bool done = false;

while (!done) {  
	playGame(balance);
	
	if (balance <=0) { //checks if there aere enough credits
		cout<<"You are out of credits ------ Game Over!\n";
		break;
	}
	cout << "Play again (y/n)? ";
	cin >> ans;

	if(ans == 'n' || ans == 'N') done = true; //checks if players wants a replay
	  else done = false;

}

cout<< "Thanks for playing! Your final balance is " << balance << " credits\n";
   
    return 0;

}