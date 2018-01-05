/************************************************************
** Program Filename: PowerRoom.hpp
** Author: Daniel Kim
** Date: 12/03/16
** Description: Class declaration header file for class PowerRoom.
************************************************************/

#ifndef POWERROOM_HPP
#define POWERROOM_HPP

#include "Room.hpp"
#include "Player.hpp"
#include "Inventory.hpp"

#include <iostream>

class PowerRoom : public Room
{
    private:
        void playRoom(Player*);
    public:
        PowerRoom() : Room("Power Room")
        {
        }
};

#endif