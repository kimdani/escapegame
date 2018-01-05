/*********************************************************
** Program Filename: StartRoom.cpp
** Author: Daniel Kim
** Date: 12/03/16
** Description: StartRoom class function implementation file.
*********************************************************/

#include "StartRoom.hpp"

/*********************************************************************
** Function Name: playRoom(Player*)
** Description: Performs game logic for current room and allows user to inspect room, change rooms, and manage inventory.
** Parameters: Pointer to current Player object
** Returns: N/A
*********************************************************************/
void StartRoom::playRoom(Player* p)
{
    std::cout << "You are in the Starting room.\n";
        
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
                std::cout << "You look around the room and see the word 'RUN' written on the wall in bright red.\n";
                std::cout << "There are doors to the North, South, East, and West.\n";
                std::cout << "There is a keypad by the door to the North.\n";
                std::cout << "The keypad doesn't seem to work. There's no power.\n";
            }
            
            else if (p->getPower() == true)
            {
                std::cout << "You look around the room and see the word 'RUN' written on the wall in bright red.\n";
                std::cout << "There are doors to the North, South, East, and West.\n";
                std::cout << "There is a keypad by the door to the North.\n";
                std::cout << "The keypad is functional.\n";
            }
        }

        else if (choice == 2 && (p->getPower()))        // Allows user to try a password if the power is on
        {
            std::cout << "The door is locked. There is a functioning keypad next to the door.\n";
            
            int passwordChoice;
            std::cout << "Press 1 to try a 4 digit password.\n";
            std::cout << "Press 2 if you don't want to try.\n";
            std::cin >> passwordChoice;
            
            while (passwordChoice < 1 || passwordChoice > 2)
            {
                std::cout << "Invalid input.\n";
                std::cout << "Press 1 to try a 4 digit password.\n";
                std::cout << "Press 2 if you don't want to try.\n";
                std::cin >> passwordChoice;
            }
            
            while (passwordChoice == 1)
            {
                int password;
                std::cout << "Enter a 4 digit number.\n";
                std::cin >> password;
                
                while (password < 1000 || password > 9999)
                {
                    std::cout << "Invalid input. Enter a 4 digit number.\n";
                    std::cin >> password;
                }
                
                if (password == 1824)
                {
                    std::cout << "Correct password! The door opens.\n";
                    passwordChoice = 0;     // Stops the while loop from executing
                    p->setLocation(up);
                }
                
                else
                {
                    std::cout << "Incorrect password. Would you like to try again?\n";
                    std::cout << "Press 1 to try again.\n";
                    std::cout << "Press 2 to quit trying.\n";
                    std::cin >> passwordChoice;
                    
                    while (passwordChoice < 1 || passwordChoice > 2)
                    {
                        std::cout << "Invalid input.\n";
                        std::cout << "Press 1 to try a 4 digit password.\n";
                        std::cout << "Press 2 if you don't want to try.\n";
                        std::cin >> passwordChoice;
                    }
                }
                
                if (passwordChoice == 2)
                {
                    choice = 1;     // Allows outer loop to continue
                }
            }
        }
            
        else if (choice == 2 && !(p->getPower()))
        {
            std::cout << "The door is locked. There is a keypad next to the door but it doesn't have power.\n";
            choice = 1;     // Allows outer loop to continue
        }

        else if (choice == 3)
        {
            p->setLocation(down);
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
    while (choice == 1 || choice == 6);
}
