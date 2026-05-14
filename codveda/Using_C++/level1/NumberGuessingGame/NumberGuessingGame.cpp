#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
	srand(time(0));
	int numberToGuess = rand() % 101;
	int userGuess = 0;
	int attempts = 5;
	cout << "Welcome to the Number Guessing Game!" << endl;
	cout << "I have selected a number between 1 and 100. Can you guess it?" << endl;
	cout << "You have 5 attempts to guess the number." << endl;
	while (userGuess != numberToGuess && attempts > 0) {
		cout << "\nEnter your guess: ";
		cin >> userGuess;
		if (userGuess < numberToGuess) {
			cout << "Too low! Try again." << endl;
			cout << "Attempts left: " << attempts-1 << endl;	
		} 
		else if (userGuess > numberToGuess) {
			cout << "Too high! Try again." << endl;
			cout << "Attempts left: " << attempts-1 << endl;
		} 
		else {
			cout << "Congratulations! You've guessed the number!" << endl;
		}
		attempts--;
	}
	if (attempts == 0 && userGuess != numberToGuess) {
		cout << "\nSorry, you've run out of attempts. The number was " << numberToGuess << "." << endl;
	}
	return 0;
}