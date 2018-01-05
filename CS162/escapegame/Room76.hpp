/************************************************************
** Program Filename: Room76.hpp
** Author: Daniel Kim
** Date: 12/03/16
** Description: Class declaration header file for class Room76.
************************************************************/

#ifndef ROOM76_HPP
#define ROOM76_HPP

#include "Room.hpp"
#include "Player.hpp"
#include "Inventory.hpp"

#include <iostream>

class Room76 : public Room
{
    private:
        void playRoom(Player*);
    public:
        Room76() : Room("76 Room")
        {
        }
};

#endif