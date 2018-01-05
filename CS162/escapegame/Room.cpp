/*********************************************************
** Program Filename: Room.cpp
** Author: Daniel Kim
** Date: 12/03/16
** Description: Room class function implementation file.
*********************************************************/

#include "Room.hpp"

/*********************************************************************
** Function Name: Room(string)
** Description: Room base class constructor
** Parameters: Derived room's string name
** Returns: N/A
*********************************************************************/
Room::Room(std::string rName)
{
    name = rName;
    up = NULL;
    down = NULL;
    left = NULL;
    right = NULL;
}

/*********************************************************************
** Function Name: ~Room()
** Description: Room base class deconstructor
** Parameters: N/A
** Returns: N/A
*********************************************************************/
Room::~Room()
{
    
}

/*********************************************************************
** Function Name: setUp(Room*)
** Description: Set's room above current room.
** Parameters: N/A
** Returns: N/A
*********************************************************************/
void Room::setUp(Room* roomName)
{
    up = roomName;
}

/*********************************************************************
** Function Name: setDown(Room*)
** Description: Set's room below current room.
** Parameters: N/A
** Returns: N/A
*********************************************************************/
void Room::setDown(Room* roomName)
{
    down = roomName;
}

/*********************************************************************
** Function Name: setLeft(Room*)
** Description: Set's room to the left of current room.
** Parameters: N/A
** Returns: N/A
*********************************************************************/
void Room::setLeft(Room* roomName)
{
    left = roomName;
}

/*********************************************************************
** Function Name: setRight(Room*)
** Description: Set's room to the right of current room.
** Parameters: N/A
** Returns: N/A
*********************************************************************/
void Room::setRight(Room* roomName)
{
    right = roomName;
}