/*********************************************************
** Program Filename: main.cpp
** Author: Daniel Kim
** Date: 12/03/16
*********************************************************/

#include <iostream>

#include "Play.hpp"
#include "Room.hpp"

int main()
{
    int choice;
    Play game;
    for (int i = 0; i < 50; i++)    // Clear the console
    {
        std::cout << "\n";
    }
    
    std::cout << "You wake up in an all white room lying on the floor with no recollection as to how you got there.\n";
    std::cout << "As you stand up you notice a metal band around your arm with a screen that reads,\n";
    std::cout << "********************************\n";
    std::cout << "*        'Subject #13'         *\n";
    std::cout << "*   'Time left: 20 minutes'    *\n";
    std::cout << "********************************\n";
    std::cout << "You attempt to take the band off but it is securely fitted to your wrist.\n\n";

    std::cout << "Press 1 to play the Escape game.\n";
    std::cout << "Press 2 to see the goal of the game.\n";
    std::cout << "Press 3 to see a walkthrough to complete the game.\n";
    std::cout << "Press 4 to exit.\n";
    std::cin >> choice;
    
    while (choice < 1 || choice > 4)
    {
        std::cout << "Invalid choice.\n";
        std::cout << "Press 1 to play the Escape game.\n";
        std::cout << "Press 2 to see the goal of the game.\n";
        std::cout << "Press 3 to see a walkthrough to complete the game.\n";
        std::cout << "Press 4 to exit.\n";
        std::cin >> choice;
    }
    
    if (choice == 1)
    {
        game.startGame();
    }
    
    else if (choice == 2)
    {
        std::cout << "\nThe goal of the game is to escape within 20 minutes. Moving to an adjacent room will count as one minute.\nThe other rules must be found out by playing the game. Good luck!\n";
        
        std::cout << "\nPress 1 to play the Escape game.\n";
        std::cout << "Press 2 to see a walkthrough to complete the game.\n";
        std::cout << "Press 3 to exit.\n";
        std::cin >> choice;
        
        while (choice < 1 || choice > 3)
        {
            std::cout << "Invalid choice.\n";
            std::cout << "Press 1 to play the Escape game.\n";
            std::cout << "Press 2 to see a walkthrough to complete the game.\n";
            std::cout << "Press 3 to exit.\n";
            std::cin >> choice;
        }
        
        if (choice == 1)
        {
            game.startGame();
        }
        
        else if (choice == 2)
        {
            std::cout << "\n1. Go West to the 76 room. Inspect the '76' on the wall. Pick up the battery cell.\n2. Go South to the power room and use the battery cell with the generator to turn on the power.\n3. Go East to the 24 room and pick up the paper to inspect it. You can drop the paper after seeing the number.\n4. Go East to the card key room and turn on the lights. Inspect the room and pick up the card key.\n5. Go North to the dark room and turn on the lights. Inspect the 'x or *' written on the wall.\n6. Return to the start room by going West and use the keypad to enter the cardkey room.\nThe password is '1824' from 24*76 (hints found in Room76, DarkRoom, and Room24).\n7. Use the cardkey in the cardkey room to escape.\n";
            std::cout << "\nPress 1 to play the Escape game.\n";
            std::cout << "Press 2 to exit.\n";
            std::cin >> choice;

            while (choice < 1 || choice > 2)
            {
                std::cout << "Invalid choice.\n";
                std::cout << "Press 1 to play the Escape game.\n";
                std::cout << "Press 2 to exit.\n";
                std::cin >> choice;
            }
            
            if (choice == 1)
            {
                game.startGame();
            }
        }
    }
        
    else if (choice ==3)
    {
        std::cout << "\n1. Go West to the 76 room. Inspect the '76' on the wall. Pick up the battery cell.\n2. Go South to the power room and use the battery cell with the generator to turn on the power.\n3. Go East to the 24 room and pick up the paper to inspect it. You can drop the paper after seeing the number.\n4. Go East to the card key room and turn on the lights. Inspect the room and pick up the card key.\n5. Go North to the dark room and turn on the lights. Inspect the 'x or *' written on the wall.\n6. Return to the start room by going West and use the keypad to enter the cardkey room.\nThe password is '1824' from 24*76 (hints found in Room76, DarkRoom, and Room24).\n7. Use the cardkey in the cardkey room to escape.\n";
        std::cout << "\nPress 1 to play the Escape game.\n";
        std::cout << "Press 2 to exit.\n";
        std::cin >> choice;
        
        while (choice < 1 || choice > 2)
        {
            std::cout << "Invalid choice.\n";
            std::cout << "Press 1 to play the Escape game.\n";
            std::cout << "Press 2 to exit.\n";
            std::cin >> choice;
        }
        
        if (choice == 1)
        {
            game.startGame();
        }
    }
}