/*********************************************************
** Program Filename: Inventory.cpp
** Author: Daniel Kim
** Date: 12/03/16
** Description: Inventory class function implementation file.
*********************************************************/

#include "Inventory.hpp"

/*********************************************************************
** Function Name: add(string)
** Description: Add the item's string name to the inventory vector.
** Parameters: String of item's name.
** Returns: N/A
*********************************************************************/
void Inventory::add(std::string iName)
{
    inventory.push_back(iName);
}

/*********************************************************************
** Function Name: remove()
** Description: Remove an item from the inventory vector.
** Parameters: N/A
** Returns: N/A
*********************************************************************/
void Inventory::remove()
{
    inventory.erase(inventory.begin());
}

/*********************************************************************
** Function Name: size()
** Description: Check's size
** Parameters: N/A
** Returns: Number of elements in inventory vector.
*********************************************************************/
int Inventory::size()
{
    return inventory.size();
}

/*********************************************************************
** Function Name: getName()
** Description: Get's the string name of the item in inventory vector.
** Parameters: N/A
** Returns: String name of item.
*********************************************************************/
std::string Inventory::getName()
{
    return inventory[0];        // Always get first item in vector because there is only one item in inventory allowed at a time
}
