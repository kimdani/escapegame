/************************************************************
** Program Filename: CardKeyRoom.hpp
** Author: Daniel Kim
** Date: 12/03/16
** Description: Class declaration header file for class CardKeyRoom.
************************************************************/

#ifndef CARDKEYROOM_HPP
#define CARDKEYROOM_HPP

#include "Room.hpp"
#include "Player.hpp"
#include "Inventory.hpp"

#include <iostream>

class CardKeyRoom : public Room
{
    private:
        bool cardkeyRoomLightOn;
        void playRoom(Player*);
    public:
        CardKeyRoom() : Room("Cardkey Room")
        {
            cardkeyRoomLightOn = false;
        }
};

#endif