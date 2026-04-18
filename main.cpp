#include <iostream>
#include <random>
#include <string>

using namespace std;

int main() {
    // Gens a num using random lib
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1, 100);
    int rn = distr(gen);

    int chosen = 0;
    int tries = 0;
    bool won = false;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl;

    // restart here 
    start:
    cout << "\nPlease select the difficulty level:" << endl;
    cout << "1. Easy (10 chances)\n2. Medium (5 chances)\n3. Hard (3 chances)" << endl;
    cout << "Enter your choice: ";
    cin >> chosen;

    switch (chosen) {
        case 1: tries = 10; break;
        case 2: tries = 5; break;
        case 3: tries = 3; break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            goto start;
    }

    cout << "Great! You have " << tries << " chances. Let's start!" << endl;

    for (int i = 1; i <= tries; i++) {
        cout << "Enter your guess: ";
        cin >> chosen;

        if (chosen == rn) {
            cout << "Congratulations! You guessed the correct number in " << i << " attempts." << endl;
            won = true;
            break;
        } else {
            cout << "Incorrect! The number is " << (chosen > rn ? "less" : "greater") << " than " << chosen << "." << endl;
        }
    }

    if (!won) {
        cout << "\nYou ran out of chances! The number was: " << rn << ". Better luck next time!" << endl;
    }

    return 0;
}