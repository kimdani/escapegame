/************************************************************
** Program Filename: Inventory.hpp
** Author: Daniel Kim
** Date: 12/03/16
** Description: Class declaration header file for class Inventory.
************************************************************/

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include <string>

class Inventory
{
    private:
        std::vector<std::string> inventory;
    public:
        void add(std::string);
        void remove();
        int size();
        std::string getName();
};

#endif