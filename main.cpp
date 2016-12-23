//This program is the equivalent of the Master Mind.
//The commented code was a first effort to print all answers and their evaluation every turn.
#include <iostream>
#include <vector>
#include <cstring>

int main() {

    std::vector<int> fact = {1, 2, 3, 4};
    std::vector<int> guess;
    //std::vector<int> trackGuesses;
    //std::vector<std::string> trackValidation;
    int bullCount = 0;
    int cowCount = 0;

    while (bullCount != 4) {
        //Collect guess from user.
        std::cout << "Please enter 4 integers separated by a space. Terminate with a pipe (|): " << std::endl;
        for (int i = 0; std::cin >> i;) {
            guess.push_back(i);
            //trackGuesses.push_back(i);
        }

        //Compares number to be guessed, vector fact, against user submitted guess, vector guess
        for (unsigned int i = 0; i < fact.size(); i++) {
            for (unsigned int j = 0; j < guess.size(); ++j) {
                if ( i == j && fact[i] == guess[j]) {  //Checks if guess and fact are the same and are in the same place
                    bullCount += 1;
                    std::cout << "Bull ";
                    //trackValidation.push_back("Bull");
                }
                else if (i != j && fact[i] == guess[j]) { //Checks if guess and fact are the same but in different places
                    cowCount += 1;
                    std::cout << "Cow ";
                    //trackValidation.push_back("Cow");
                }
            }
        }

        //Checks if guess is correct. If not, it tells you how close and cleans up counters and guess vector.
        if (bullCount == 4) {
            std::cout << "You have won!";
        } else {
            //std::cout << bullCount << " bull and " << cowCount << " cow." << std::endl;
/*
            for (int i = 0; i < trackGuesses.size(); ++i) {
                std::cout << trackGuesses[i] << '\t'; //<< trackValidation[j]  << std::endl;
            }
            for (int i = 0; i < trackValidation.size(); ++i) {
                std::cout << trackValidation[i] << '\t'; //<< trackValidation[j]  << std::endl;
            }
*/
            std::cout << std::endl;
            bullCount = 0;
            cowCount = 0;
            std::cin.clear();
            std::cin.ignore();
            guess.clear();
        }
    }

    return 0;
}