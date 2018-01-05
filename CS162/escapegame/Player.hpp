/************************************************************
** Program Filename: Player.hpp
** Author: Daniel Kim
** Date: 12/03/16
** Description: Class declaration header file for class Player.
************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Room;
class Inventory;

class Player
{
    private:
        Room* location;
        Inventory* inv;
        bool powerOn;
        bool escaped;
    public:
        Player();
        ~Player();
        Room* getLocation();
        void setLocation(Room*);
        Inventory* getInventory();
        void turnOnPower();
        bool getPower();
        bool getEscaped();
        void escape();
};

#endif