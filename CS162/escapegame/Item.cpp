/*********************************************************
** Program Filename: Item.cpp
** Author: Daniel Kim
** Date: 12/03/16
** Description: Item class function implementation file.
*********************************************************/

#include "Item.hpp"

Item::Item(std::string iN, iD)
{
    itemName = iN;
    itemDetails = iD;
}

std::string Item::getItemName()
{
    return itemName;
}

std::string Item::getItemDetails()
{
    return itemDetails;
}
