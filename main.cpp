// Name: Ryan Khieu
// Program Name: Loop Lab
// Date: 11/5/24
// Extra: Box PIN is random

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

// Create arrays for days and quotes
std::string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
std::string quotes[7];

// Variables for energy, supplies, and option
int energy = 5;
int supplies = 0;
int opt = 0;

// Variable for option
char enter;

int main() {
    // Ask for quotes for each day
    for (int i = 0; i < 7; i++) {
        std::cout << "Enter your quote for " << days[i] << ":" << std::endl;
        std::getline(std::cin, quotes[i]);
    }

    std::cout << std::endl;

    // Display the quotes for each day
    for (int i = 0; i < 7; i++) {
        std::cout << days[i] << ": " << quotes[i] << std::endl;
    }

    std::cout << std::endl;

    std::cout << "You are in a zombie apocalypse. You need to get 10 supplies to survive. Each day, you can get supplies or rest. Resting replenishes 2 energy, while getting supplies uses 1 energy." << std::endl;
    // Loop until energy is 0 or supplies is 10
    while (energy > 0 && supplies < 10) {
        std::cout << "You have " << energy << " energy and " << supplies << " supplies." << std::endl;
        std::cout << "1. Get supplies" << std::endl;
        std::cout << "2. Rest" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> opt;
        if (opt == 1) {
            supplies++;
            energy--;
        } else if (opt == 2) {
            energy += 2;
        }
    }

    if (supplies >= 10) {
        std::cout << "You have survived the zombie apocalypse!" << std::endl;
    } else {
        std::cout << "You have died in the zombie apocalypse." << std::endl;
    }

    std::cout << std::endl;

    std::srand(std::time(0));
    int pin = std::rand() % 900 + 100;
    // Loop until the pin is correct
    do {
        std::cout << "Enter the 3-digit pin: ";
        std::cin >> opt;
        if (opt != pin) {
            std::cout << "Incorrect pin. Would you like to try again? (Y/N)" << std::endl;
            std::cin >> enter;
            if (std::tolower(enter) == 'n') {
                std::cout << "The box remains locked." << std::endl;
                break;
            }
        }
    } while (opt != pin);

    std::cout << "The box has been unlocked." << std::endl;

    return 0;
}