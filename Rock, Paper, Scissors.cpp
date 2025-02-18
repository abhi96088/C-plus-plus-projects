#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

void showChoice(int choice) {
    switch (choice) {
        case 1: cout << "Rock"; break;
        case 2: cout << "Paper"; break;
        case 3: cout << "Scissors"; break;
        default: cout << "Invalid"; break;
    }
}

int main() {
    srand(time(0));  // Seed random number generator

    int playerChoice, computerChoice;
    
    cout << "Rock, Paper, Scissors Game!" << endl;
    cout << "1. Rock\n2. Paper\n3. Scissors\n";
    cout << "Enter your choice (1-3): ";
    cin >> playerChoice;

    if (playerChoice < 1 || playerChoice > 3) {
        cout << "Invalid choice! Please select 1, 2, or 3." << endl;
        return 1;
    }

    computerChoice = rand() % 3 + 1;  // Random number between 1 and 3

    cout << "\nYou chose: ";
    showChoice(playerChoice);
    cout << "\nComputer chose: ";
    showChoice(computerChoice);
    cout << "\n";

    // Determine winner
    if (playerChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if ((playerChoice == 1 && computerChoice == 3) || 
               (playerChoice == 2 && computerChoice == 1) || 
               (playerChoice == 3 && computerChoice == 2)) {
        cout << "You win!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }

    return 0;
}

