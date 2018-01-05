/*********************************************************
** Program Filename: Room76.cpp
** Author: Daniel Kim
** Date: 12/03/16
** Description: Room76 class function implementation file.
*********************************************************/

#include "Room76.hpp"

/*********************************************************************
** Function Name: playRoom(Player*)
** Description: Performs game logic for current room and allows user to inspect room, change rooms, and manage inventory.
** Parameters: Pointer to current Player object
** Returns: N/A
*********************************************************************/
void Room76::playRoom(Player* p)
{
    std::cout << "You are in the 76 room.\n";
        
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
            if (p->getPower() == false)
            {
                int pickUp;
                
                std::cout << "There are doors to the South and East.\n";
                std::cout << "On the ceiling there is the number '76'.\n";
                std::cout << "There is a pile of rusty battery cells on the floor of this room.\n";
                std::cout << "Pick up a battery cell? Type 1 for yes and 2 for no.\n";
                std::cin >> pickUp;

                while (pickUp < 1 || pickUp > 2)
                {
                    std::cout << "Invalid input. Press 1 to pick up a battery cell or 2 to leave it alone.\n";
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
                        p->getInventory()->add("Battery Cell");
                        std::cout << "You picked up a Battery Cell.\n";
                    }
                }
            }
            
            else if (p->getPower() == true)
            {
                std::cout << "There are doors to the South and East.\n";
                std::cout << "On the ceiling there is the number '76'.\n";
            }
        }
        
        else if (choice == 2)
        {
            std::cout << "You can't go this way. (Hint: Try inspecting the room)\n";
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
    while (choice == 1 || choice == 2 || choice == 4 || choice == 6);
}