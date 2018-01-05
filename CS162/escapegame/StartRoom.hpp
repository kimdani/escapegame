/************************************************************
** Program Filename: StartRoom.hpp
** Author: Daniel Kim
** Date: 12/03/16
** Description: Class declaration header file for class StartRoom.
************************************************************/

#ifndef STARTROOM_HPP
#define STARTROOM_HPP

#include "Room.hpp"
#include "Player.hpp"
#include "Inventory.hpp"

#include <iostream>

class StartRoom : public Room
{
    private:
        void playRoom(Player*);
    public:
        StartRoom() : Room("Start Room")
        {
        }
};

#endif