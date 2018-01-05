/************************************************************
** Program Filename: Play.hpp
** Author: Daniel Kim
** Date: 12/03/16
** Description: Class declaration header file for class Play.
************************************************************/

#ifndef PLAY_HPP
#define PLAY_HPP

#include "Room.hpp"
#include "StartRoom.hpp"
#include "ExitRoom.hpp"
#include "PowerRoom.hpp"
#include "Room76.hpp"
#include "Room24.hpp"
#include "CardKeyRoom.hpp"
#include "DarkRoom.hpp"
#include "Player.hpp"

class Play
{
    private:
        Room* start;
        Room* exit;
        Room* power;
        Room* seventy6;
        Room* twenty4;
        Room* cardkey;
        Room* dark;
        
        Player* player;
    public:
        Play();
        ~Play();
        void startGame();
};

#endif