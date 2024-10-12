#include "AdventureGame.h"
#include <iostream>

void showMenu() {
    std::cout << "\n1. Go to the kitchen" << std::endl;
    std::cout << "2. Go to the bedroom" << std::endl;
    std::cout << "3. Go to the garden" << std::endl;
    std::cout << "4. Exit the game" << std::endl;
}

void kitchen() {
    std::cout << "\nYou are in the kitchen. There are some delicious smells here!" << std::endl;
}

void bedroom() {
    std::cout << "\nYou are in the bedroom. It's cozy and warm here." << std::endl;
}

void garden() {
    std::cout << "\nYou are in the garden. It's fresh and green here." << std::endl;
}

void playAdventureGame() {
    int choice;
    while (true) {
        showMenu();
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            kitchen();
            break;
        case 2:
            bedroom();
            break;
        case 3:
            garden();
            break;
        case 4:
            std::cout << "Thanks for playing!" << std::endl;
            return;
        default:
            std::cout << "Invalid choice, please try again." << std::endl;
        }
    }
}
