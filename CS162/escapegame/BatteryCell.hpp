/************************************************************
** Program Filename: BatteryCell.hpp
** Author: Daniel Kim
** Date: 12/03/16
** Description: Class declaration header file for class BatteryCell.
************************************************************/

#ifndef BATTERYCELL_HPP
#define BATTERYCELL_HPP

#include "Item.hpp"

class BatteryCell : public Item
{
    private:
    
    public:
        BatteryCell() : Item("Battery Cell", "A heavy battery. Hopefully it still works");
}