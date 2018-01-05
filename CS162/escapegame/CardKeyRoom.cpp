/*********************************************************
** Program Filename: CardKeyRoom.cpp
** Author: Daniel Kim
** Date: 12/03/16
** Description: CardKeyRoom class function implementation file.
*********************************************************/

#include "CardKeyRoom.hpp"

/*********************************************************************
** Function Name: playRoom(Player*)
** Description: Performs game logic for current room and allows user to inspect room, change rooms, and manage inventory.
** Parameters: Pointer to current Player object
** Returns: N/A
*********************************************************************/
void CardKeyRoom::playRoom(Player* p)
{
    std::cout << "You are in the Card Key room.\n";
        
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
            // If lights are off the user cannot inspect the room properly
            if (cardkeyRoomLightOn == false)
            {
                int lightChoice;
                
                std::cout << "The room is too dark to see much.\n";
                std::cout << "You can distinguish a door to the North and West.\n";
                std::cout << "There is also an illuminated light switch on the wall.\n";
                std::cout << "Press 1 to flip the light switch to on. Press 2 to do nothing.\n";
                std::cin >> lightChoice;
                
                while (lightChoice < 1 || lightChoice > 2)
                {
                    std::cout << "Invalid input.\n";
                    std::cout << "Press 1 to flip the light switch to on. Press 2 to do nothing.\n";
                    std::cin >> lightChoice;
                }
                
                if (lightChoice == 1)
                {
                    // If the power is off the lights will not turn on
                    if (p->getPower() == false)
                    {
                        std::cout << "Flipping the switch has no effect. There doesn't seem to be any power.\n";
                    }
                    
                    else if (p->getPower() == true)
                    {
                        std::cout << "The lights turn on in the room.\n";
                        cardkeyRoomLightOn = true;  // Turn lights on
                    }
                }
            }

            else
            {
                std::cout << "The lights are on in this room.\n";
                std::cout << "There are doors to the North and West.\n";
                
                int pickUp;

                std::cout << "There is a shelf on the wall with keycards hanging on hooks.\n";
                std::cout << "Pick up a keycard? Type 1 for yes and 2 for no.\n";
                std::cin >> pickUp;

                while (pickUp < 1 || pickUp > 2)
                {
                    std::cout << "Invalid input. Press 1 to pick up a keycard or 2 to leave it alone.\n";
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
                        p->getInventory()->add("Keycard");
                    }
                }
                
                int lightChoice;
                
                std::cout << "There is also an illuminated light switch on the wall.\n";
                std::cout << "Press 1 to flip the light switch to off. Press 2 to do nothing.\n";
                std::cin >> lightChoice;
                
                while (lightChoice < 1 || lightChoice > 2)
                {
                    std::cout << "Invalid input.\n";
                    std::cout << "Press 1 to flip the light switch to on. Press 2 to do nothing.\n";
                    std::cin >> lightChoice;
                }
                
                if (lightChoice == 1)
                {
                    std::cout << "You turn the lights off.\n";
                    cardkeyRoomLightOn = false;
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
    while (choice == 1 || choice == 3 || choice == 5 || choice == 6);
}