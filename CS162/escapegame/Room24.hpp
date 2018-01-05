/************************************************************
** Program Filename: Room24.hpp
** Author: Daniel Kim
** Date: 12/03/16
** Description: Class declaration header file for class Room24.
************************************************************/

#ifndef ROOM24_HPP
#define ROOM24_HPP

#include "Room.hpp"
#include "Player.hpp"
#include "Inventory.hpp"

#include <iostream>

class Room24 : public Room
{
    private:
        void playRoom(Player*);
    public:
        Room24() : Room("24 Room")
        {
        }
};

#endif