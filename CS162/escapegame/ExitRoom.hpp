/************************************************************
** Program Filename: ExitRoom.hpp
** Author: Daniel Kim
** Date: 12/03/16
** Description: Class declaration header file for class ExitRoom.
************************************************************/

#ifndef EXITROOM_HPP
#define EXITROOM_HPP

#include "Room.hpp"
#include "Player.hpp"
#include "Inventory.hpp"

#include <iostream>

class ExitRoom : public Room
{
    private:
        void playRoom(Player*);
    public:
        ExitRoom() : Room("Exit Room")
        {
        }
};

#endif