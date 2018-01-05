/************************************************************
** Program Filename: Item.hpp
** Author: Daniel Kim
** Date: 12/03/16
** Description: Class declaration header file for class Item.
************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

class Item
{
    private:
        std::string itemName;
        std::string itemDetails;
    public:
        Item(std::string, std::string);
        std::string getItemName();
        std::string getItemDetails();
};

#endif