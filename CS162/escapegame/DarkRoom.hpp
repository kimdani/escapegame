/************************************************************
** Program Filename: DarkRoom.hpp
** Author: Daniel Kim
** Date: 12/03/16
** Description: Class declaration header file for class DarkRoom.
************************************************************/

#ifndef DARKROOM_HPP
#define DARKROOM_HPP

#include "Room.hpp"
#include "Player.hpp"
#include "Inventory.hpp"

#include <iostream>

class DarkRoom : public Room
{
    private:
        bool darkRoomLightOn;
        void playRoom(Player*);
    public:
        DarkRoom() : Room("Dark Room")
        {
            darkRoomLightOn = false;
        }
};

#endif