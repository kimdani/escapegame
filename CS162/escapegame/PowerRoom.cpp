/*********************************************************
** Program Filename: PowerRoom.cpp
** Author: Daniel Kim
** Date: 12/03/16
** Description: PowerRoom class function implementation file.
*********************************************************/

#include "PowerRoom.hpp"

/*********************************************************************
** Function Name: playRoom(Player*)
** Description: Performs game logic for current room and allows user to inspect room, change rooms, and manage inventory.
** Parameters: Pointer to current Player object
** Returns: N/A
*********************************************************************/
void PowerRoom::playRoom(Player* p)
{
    std::cout << "You are in the Power room.\n";
        
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
                std::cout << "There are doors to the North and East.\n";
                std::cout << "There is a large generator on the floor. Wires travel from it to other rooms. It is not generating electricity at the moment.\n";
            }
            
            else if (p->getPower() == true)
            {
                std::cout << "There are doors to the North and East.\n";
                std::cout << "There is a large generator on the floor. Wires travel from it to other rooms. It is generating energy.\n";
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
                    if (p->getInventory()->size() == 1 && p->getInventory()->getName() == "Battery Cell")
                    {
                        std::cout << "You insert the battery cell into the generator. The generator slowly hums to life.\n";
                        p->turnOnPower();       // Power is turned on now
                        p->getInventory()->remove();        // Battery Cell removed from inventory vector
                    }
                    
                    else if (p->getInventory()->size() == 1 && p->getInventory()->getName() != "Battery Cell")
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
    while (choice == 1 || choice == 3 || choice == 4 || choice == 6);
}