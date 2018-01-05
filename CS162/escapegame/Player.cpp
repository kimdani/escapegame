/*********************************************************
** Program Filename: Player.cpp
** Author: Daniel Kim
** Date: 12/03/16
** Description: Player class function implementation file.
*********************************************************/

#include "Player.hpp"
#include "Room.hpp"
#include "Inventory.hpp"

/*********************************************************************
** Function Name: Player()
** Description: Player class constructor. Creates a new inventory for the player.
** Parameters: N/A
** Returns: N/A
*********************************************************************/
Player::Player()
{
    inv = new Inventory();
    powerOn = false;
    escaped = false;
}

/*********************************************************************
** Function Name: ~Player()
** Description: Player class destructor. Deletes the created inventory object.
** Parameters: N/A
** Returns: N/A
*********************************************************************/
Player::~Player()
{
    delete inv;
}

/*********************************************************************
** Function Name: getLocation()
** Description: Gets user's location.
** Parameters: N/A
** Returns: User's current location.
*********************************************************************/
Room* Player::getLocation()
{
    return location;
}

/*********************************************************************
** Function Name: setLocation()
** Description: Sets user's location. 
** Parameters: Pointer to a room object.
** Returns: N/A
*********************************************************************/
void Player::setLocation(Room* r)
{
    location = r;
}

/*********************************************************************
** Function Name: getInventory()
** Description: Gets the player's inventory.
** Parameters: N/A
** Returns: Player's inventory
*********************************************************************/
Inventory* Player::getInventory()
{
    return inv;
}

/*********************************************************************
** Function Name: getPower()
** Description: Get whether power is on or off.
** Parameters: N/A
** Returns: powerOn
*********************************************************************/
bool Player::getPower()
{
    return powerOn;
}

/*********************************************************************
** Function Name: turnOnPower()
** Description: Turns the power on by setting powerOn to true.
** Parameters: N/A
** Returns: N/A
*********************************************************************/
void Player::turnOnPower()
{
    powerOn = true;
}

/*********************************************************************
** Function Name: getEscaped()
** Description: Get's user's escape status.
** Parameters: N/A
** Returns: escaped
*********************************************************************/
bool Player::getEscaped()
{
    return escaped;
}

/*********************************************************************
** Function Name: escape()
** Description: Changes user's escape status to true.
** Parameters: N/A
** Returns: N/A
*********************************************************************/
void Player::escape()
{
    escaped = true;
}