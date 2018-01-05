/************************************************************
** Program Filename: Room.hpp
** Author: Daniel Kim
** Date: 12/03/16
** Description: Class declaration header file for class Room.
************************************************************/

#ifndef ROOM_HPP
#define ROOM_HPP

#include "Player.hpp"

#include <string>

class Room
{
    protected:
        std::string name;
        Room *up;
        Room *down;
        Room *left;
        Room *right;
    public:
        Room(std::string);
        virtual ~Room();
        virtual void playRoom(Player*) = 0;
        void setUp(Room*);
        void setDown(Room*);
        void setLeft(Room*);
        void setRight(Room*);
};

#endif