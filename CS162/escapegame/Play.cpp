/*********************************************************
** Program Filename: Play.cpp
** Author: Daniel Kim
** Date: 12/03/16
** Description: Play class function implementation file.
*********************************************************/

#include "Play.hpp"

/*********************************************************************
** Function Name: Play()
** Description: Play class constructor. Creates the map and instantiates each room.
** Parameters: N/A
** Returns: N/A
*********************************************************************/
Play::Play()
{
    // Create new derived Room objects
    start = new StartRoom();
    exit = new ExitRoom();
    power = new PowerRoom();
    seventy6 = new Room76();
    twenty4 = new Room24();
    cardkey = new CardKeyRoom();
    dark = new DarkRoom();
    
    // Setup the map
    exit->setUp(NULL);
    exit->setDown(start);
    exit->setLeft(NULL);
    exit->setRight(NULL);
    
    start->setUp(exit);
    start->setDown(twenty4);
    start->setLeft(seventy6);
    start->setRight(dark);
    
    seventy6->setUp(NULL);
    seventy6->setDown(power);
    seventy6->setLeft(NULL);
    seventy6->setRight(start);
    
    power->setUp(seventy6);
    power->setDown(NULL);
    power->setLeft(NULL);
    power->setRight(twenty4);
    
    twenty4->setUp(start);
    twenty4->setDown(NULL);
    twenty4->setLeft(power);
    twenty4->setRight(cardkey);
    
    cardkey->setUp(dark);
    cardkey->setDown(NULL);
    cardkey->setLeft(twenty4);
    cardkey->setRight(NULL);
    
    dark->setUp(NULL);
    dark->setDown(cardkey);
    dark->setLeft(start);
    dark->setRight(NULL);
    
    // Create new player object and place player in StartRoom
    player = new Player();
    player->setLocation(start);
}
/*********************************************************************
** Function Name: ~Play()
** Description: Play class destructor. Calls destructors from the derived classes and Player class.
** Parameters: N/A
** Returns: N/A
*********************************************************************/
Play::~Play()
{
    delete start;
    delete exit;
    delete power;
    delete seventy6;
    delete twenty4;
    delete cardkey;
    delete dark;
    delete player;
}

/*********************************************************************
** Function Name: startGame()
** Description: Starts the game and continues looping if user has time left. Each loop checks if the user has escaped yet.
** Parameters: N/A
** Returns: N/A
*********************************************************************/
void Play::startGame()
{
    int count = 20;     // Time limit
    Room* playerLocation;
    
    while (count != 0)
    {
        std::cout << "\nTime left: " << count << " minutes.\n";
        playerLocation = player->getLocation();
        playerLocation->playRoom(player);
        count--;
        
        // Checks if the player's escaped status has changed
        if (player->getEscaped())
        {
            std::cout << "You escaped with " << count << " minutes remaining.\n";
            std::cout << "RUN...\n\nCongratulations you win!\n";
            break;
        }
    }
    
    // If time limit is up: Game over
    if (!player->getEscaped())
    {
        std::cout << "Time's up. You're stuck here FOREVER. GAME OVER...\n";
    }
}