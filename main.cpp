//This program is the equivalent of the Master Mind.
//It only works if numbers are not repeated.
#include <iostream>
#include <vector>
#include <cstring>
#include <random>

//Numbers generated are not random at all!! Same two ints submitted to function produce same results.
inline int randint(int min, int max) { static std::default_random_engine ran; return std::uniform_int_distribution<>{min, max}(ran); }

//inline int randint(int max) { return randint(0, max); }


int main() {

    //std::vector<int> fact = {1, 2, 3, 4}; //Used for testing.
    std::vector<int> fact;
    std::vector<int> guess;
    std::vector<int> trackGuesses;
    std::vector<std::string> trackValidation;
    int bullCount = 0;
    int cowCount = 0;
    //int seed1, seed2;

/*
    std::cout << "Please enter two integers (0 - 9) to generate your puzzle: ";
    std::cin >> seed1 >> seed2;
    for (int k = 0; k < 4; ++k) {
        fact.push_back(randint(seed1, seed2));
    }
*/

    std::cout << "Please enter 4 non-repeating integers in any order (0 - 9) for your puzzle: ";
    for (int i = 0; std::cin >> i;) {
        fact.push_back(i);
    }
    std::cin.clear();
    std::cin.ignore();

    while (bullCount != 4) {
        //Collect guess from user.

        std::cout << "Please enter 4 integers separated by a space. Terminate with a pipe (|): " << std::endl;
        for (int i = 0; std::cin >> i;) {
            guess.push_back(i);
            //trackGuesses.push_back(i);
        }

        //Compares number to be guessed, vector fact, against user submitted guess, vector guess
        //TODO: Logic does not work where fact has numbers that repeat.
        for (unsigned int i = 0; i < fact.size(); i++) {
            for (unsigned int j = 0; j < guess.size(); ++j) {
                if ( i == j && fact[i] == guess[j]) {  //Checks if guess and fact are the same and are in the same place
                    bullCount += 1;
                    //std::cout << "Bull ";
                    //trackValidation.push_back("Bull");
                }
                else if (i != j && fact[i] == guess[j]) { //Checks if guess and fact are the same but in different places
                    cowCount += 1;
                    //std::cout << "Cow ";
                    //trackValidation.push_back("Cow");
                }
            }
        }

        //Checks if guess is correct. If not, it tells you how close and cleans up counters and guess vector.
        if (bullCount == 4) {
            std::cout << "You have won!";
        } else {
            std::cout << bullCount << " bull and " << cowCount << " cow." << std::endl;

/*          //Goal was to produce to cout a line of guesses and whether they were cow or bulls.
            //Did not figure out how to track does that are neither.
            //Need to use a class.
            for (unsigned int i = 0; i < trackGuesses.size(); ++i) {
                std::cout << trackGuesses[i] << '\t'; //<< trackValidation[j]  << std::endl;
            }
            for (unsigned int i = 0; i < trackValidation.size(); ++i) {
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