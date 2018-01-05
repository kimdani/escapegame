/*********************************************************
** Program Filename: ExitRoom.cpp
** Author: Daniel Kim
** Date: 12/03/16
** Description: ExitRoom class function implementation file.
*********************************************************/

#include "ExitRoom.hpp"

/*********************************************************************
** Function Name: playRoom(Player*)
** Description: Performs game logic for current room and allows user to inspect room, change rooms, and manage inventory.
** Parameters: Pointer to current Player object
** Returns: N/A
*********************************************************************/
void ExitRoom::playRoom(Player* p)
{
    std::cout << "You are in the Exit room.\n";
    std::cout << "There is a card swiping machine on a small wooden coffee table.\n";
        
    int choice;
    
    do
    {
        std::cout << "\nChoose action:\n";
        std::cout << "1. Inspect the room.\n";
        std::cout << "2. Enter room to the North.\n";
        std::cout << "3. Enter room to the South.\n";
        std::cout << "4. Enter room to the West.\n";
        std::cout << "5. Enter room to the East.\n";
        std::cout << "6. Manage inventory.\n";
        std::cin >> choice;
        
        while (choice < 1 || choice > 6)
        {
            std::cout << "Invalid input.\n";
            std::cout << "\nChoose action:\n";
            std::cout << "1. Inspect the room.\n";
            std::cout << "2. Enter room to the North.\n";
            std::cout << "3. Enter room to the South.\n";
            std::cout << "4. Enter room to the West.\n";
            std::cout << "5. Enter room to the East.\n";
            std::cout << "6. Manage inventory.\n";
            std::cin >> choice;
        }
        
        if (choice == 1)
        {
            std::cout << "The room is empty except a door to the North and South.\n";
            std::cout << "Above the door to the North is a bright neon sign flashing 'EXIT'\n";
            std::cout << "There a card swiping machine on a small wooden coffee table.\n";
        }

        else if (choice == 2)
        {
            if (p->getInventory()->getName() == "Keycard")
            {
                std::cout << "You swipe the keycard and the door to the North opens.\n";
                p->escape();        // Change user's escape status
            }
            
            else if (p->getInventory()->getName() != "Keycard")
            {
                std::cout << "You don't have the keycard.\n";
                choice = 1;     // Allows outer loop to continue
            }
        }
        
        else if (choice == 3)
        {
            p->setLocation(down);
        }

        else if (choice == 4)
        {
            std::cout << "You can't go this way. (Hint: Try inspecting the room)\n";
        }

        else if (choice == 5)
        {
            std::cout << "You can't go this way. (Hint: Try inspecting the room)\n";
        }
        
        else
        {
            int invChoice;
            
            std::cout << "Press 1 to check your current item.\n";
            std::cout << "Press 2 to throw away your current item.\n";
            std::cout << "Press 3 to use your current item.\n";
            std::cout << "Press 4 to do nothing.\n";
            std::cin >> invChoice;
            
            while (invChoice < 1 || invChoice > 4)
            {
                std::cout << "Invalid input.\n";
                std::cout << "Press 1 to check your current item.\n";
                std::cout << "Press 2 to throw away your current item.\n";
                std::cout << "Press 3 to use your current item.\n";
                std::cout << "Press 4 to do nothing.\n";
                std::cin >> invChoice;
            }
            
            switch(invChoice)
            {
                case 1:
                    if (p->getInventory()->size() == 0)
                    {
                        std::cout << "You are not holding an item.\n";
                    }
                    
                    else
                    {
                        std::cout << "Current item: " << p->getInventory()->getName() << "\n";
                    }
                    break;
                
                case 2:
                    if (p->getInventory()->size() == 1)
                    {
                        std::cout << "You threw away the " << p->getInventory()->getName() << ".\n";
                        p->getInventory()->remove();
                    }
                    
                    else
                    {
                        std::cout << "You are not holding an item.\n";
                    }
                    break;
                    
                case 3:
                    if (p->getInventory()->size() == 1 && p->getInventory()->getName() == "Keycard")
                    {
                        std::cout << "You swipe the keycard and the door to the North opens.\n";
                        p->escape();    // Change user's escape status
                        choice = 2;     // Stops the while loop
                    }
                    
                    else if (p->getInventory()->size() == 1 && p->getInventory()->getName() != "Keycard")
                    {
                        std::cout << p->getInventory()->getName() << " has no use in this room.\n";
                    }

                    else if (p->getInventory()->size() == 0)
                    {
                        std::cout << "You are not holding an item.\n";
                    }
                    break;
            }
        }
    }
    while (choice == 1 || choice == 4 || choice == 5 || choice == 6);
}