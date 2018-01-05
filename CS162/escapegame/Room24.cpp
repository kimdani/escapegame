/*********************************************************
** Program Filename: Room24.cpp
** Author: Daniel Kim
** Date: 12/03/16
** Description: Room24 class function implementation file.
*********************************************************/

#include "Room24.hpp"

/*********************************************************************
** Function Name: playRoom(Player*)
** Description: Performs game logic for current room and allows user to inspect room, change rooms, and manage inventory.
** Parameters: Pointer to current Player object
** Returns: N/A
*********************************************************************/
void Room24::playRoom(Player* p)
{
    std::cout << "You are in the 24 room.\n";
        
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
            int pickUp;
            std::cout << "There are doors to the North, West, and East.\n";
            std::cout << "Hanging from the ceiling are multiple sheets of paper.\n";
            std::cout << "Would you like to grab a sheet of paper? Press 1 if yes. Press 2 if no.\n";
            std::cin >> pickUp;
            
            while (pickUp < 1 || pickUp > 2)
            {
                std::cout << "Invalid input.\n";
                std::cout << "Would you like to grab a sheet of paper? Press 1 if yes. Press 2 if no.\n";
                std::cin >> pickUp;
            }
            
            if (pickUp == 1)
            {
                if (p->getInventory()->size() == 1)
                {
                    std::cout << "Ouch! The metal band zapped you. The screen displays, 'Don't get greedy. Only one item at a time!'\n";
                }
                
                else
                {
                    p->getInventory()->add("Twenty-Four Paper");
                    std::cout << "You grab a sheet of paper and inspect it. On it is written 'Twenty-Four'.\n";
                }
            }
        }
        
        else if (choice == 2)
        {
            p->setLocation(up);
        }

        else if (choice == 3)
        {
            std::cout << "You can't go this way. (Hint: Try inspecting the room)\n";
        }

        else if (choice == 4)
        {
            p->setLocation(left);
        }

        else if (choice == 5)
        {
            p->setLocation(right);
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
                    if (p->getInventory()->size() == 1)
                    {
                        std::cout << p->getInventory()->getName() << " has no use in this room.\n";
                    }
                    
                    else
                    {
                        std::cout << "You are not holding an item.\n";
                    }
                    break;
            }
        }
    }
    while (choice == 1 || choice == 3 || choice == 6);
}