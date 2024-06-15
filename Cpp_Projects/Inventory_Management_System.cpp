#include <iostream>
#include <string>
#include <limits>

struct item{
    std :: string name;
    std :: string description;
    float price;
    int quantity;
};

//the n variable is used to keep track of how  many items are in the inventory.
int n = 0;
bool run = true;
bool item_exist = false;
std :: string command;
std :: string update_item;
std :: string update_info;
std :: string remove_item;
std :: string srch_type;
std :: string srch_item;

item inventory[3] ;

void add();
void update(item &inv);
void search();
void display_item(item inv);
void display_all();
void remove();
void remove_all();
void quit();

int main(){
    std :: cout << "Command list: " << std :: endl << "------------------" << std :: endl;
    std :: cout << "add: adds a new item to the inventory." << std :: endl << "------------------" << std :: endl;
    std :: cout << "update : updates an existing item in the inventory." << std :: endl << "------------------" << std :: endl;
    std :: cout << "search : searches for an item in the inventroy." << std :: endl << "------------------" << std :: endl;  
    std :: cout << "display all: displays all the item in the inventory." << std :: endl << "------------------" << std :: endl; 
    std :: cout << "remove : removes an item from the inventory." << std :: endl << "------------------" << std :: endl; 
    std :: cout << "remove all: removes all the items in the inventory." << std :: endl << "------------------" << std :: endl; 
    std :: cout << "quit: exits the program." << std :: endl << "------------------" << std :: endl;
    while(run == true){
        std :: cout << "Enter a command: ";
        std :: getline(std :: cin, command);
        std :: cout << std :: endl;
        if(command == "search"){
            if(n != 0)
                search();
            else
                std :: cout << "The inventory is empty!" << std :: endl;
        }else if(command == "display all"){
            display_all();                  
        }else if(command == "quit"){
            quit();             
        }else if (command == "add") {
            add();
            n++;
        }else if(command == "remove"){
            remove();
        }else if(command == "remove all"){
            remove_all();
        }else if(command == "update"){
            std :: cout << "which item would you like to update? ";
            std :: getline(std :: cin, update_item);
            for (int i = 0; i < n; i++) {
                if(update_item == inventory[i].name){
                    update(inventory[i]);
                    item_exist = true;
                    i = n;
                }
            }
            if(item_exist == false)
                std :: cout << "This item does not exist in the inventory! " << std :: endl;
            item_exist = false;
        }else{ 
            std :: cout << "Unknown command! " << std :: endl;
        }
        std :: cout << std :: endl << "------------------" << std :: endl;
    }
}


void add(){
    std :: cout << "Enter the name of the item: ";
    std :: getline(std :: cin, inventory[n].name);
    std :: cout << "Enter the description of the item: ";
    std :: getline(std :: cin, inventory[n].description);
    std :: cout << "Enter the price of the item: ";
    std :: cin >> inventory[n].price;
    std :: cin.ignore(std :: numeric_limits < std :: streamsize > :: max(), '\n');
    std :: cout << "Enter the quantity of the item: ";
    std :: cin >> inventory[n].quantity;
    std :: cin.ignore(std :: numeric_limits < std :: streamsize > :: max(), '\n');
    std :: cout << std :: endl << "Item added!";
}

void update(item &inv){
    std :: cout << "What would you like to update? ";
    std :: getline(std :: cin, update_info);
    if(update_info == "name"){
        std :: cout << "Enter the updated name: ";
        std :: getline(std :: cin, inv.name);
    }
    else if(update_info == "description"){
        std :: cout << "Enter the updated description: ";
        std :: getline(std :: cin, inv.description);
    }
    else if(update_info == "price"){
        std :: cout << "Enter the updated price: ";
        std :: cin >> inv.price;
        std :: cin.ignore(std :: numeric_limits < std :: streamsize > :: max(), '\n');
    }
    else if(update_info == "quantity"){
        std :: cout << "Enter the updated quantity: ";
        std :: cin >> inv.quantity;
        std :: cin.ignore(std :: numeric_limits < std :: streamsize > :: max(), '\n');
    }
    std :: cout << std :: endl << "item updated!" << std :: endl;
}

void display_all(){
    if(n == 0)
        std :: cout << "The inventory is empty!" << std :: endl;
    else{
        std :: cout << "List of items: " << std :: endl << "------------------" << std :: endl;
        for(int i = 0; i < n; i++){
            display_item(inventory[i]);
        }
    }
}

void search(){
    std :: cout << "Search by name or description? ";
    std :: getline(std :: cin, srch_type);
    if(srch_type == "name"){
        std :: cout << "Enter the name of the item you are looking for: ";
        std :: getline(std :: cin, srch_item);
        for(int i = 0; i < n; i++){
            if(inventory[i].name == srch_item){
                display_item(inventory[i]);
                item_exist = true;
            }
        }
        if(item_exist == false)
            std :: cout << "Item does not exist in the inventroy." << std :: endl;
        item_exist = false;
    }else if(srch_type == "description"){
        std :: cout << "Enter the description of the item you are looking for: ";
        std :: getline(std :: cin, srch_item);
        for(int i = 0; i < n; i++){
            if(inventory[i].description == srch_item){
                display_item(inventory[i]);
                item_exist = true;
            }
        }
        if(item_exist == false)
            std :: cout << "Item does not exist in the inventory." << std :: endl;
        item_exist = false;
    }else{
        std :: cout << "" << std :: endl;
        search();
    }
}

void display_item(item inv){
    std :: cout << "Name: " << inv.name << std :: endl;
    std :: cout << "Description: " << inv.description << std :: endl;
    std :: cout << "price: " << inv.price << "$" << std :: endl;
    std :: cout << "quantity: " << inv.quantity << std :: endl;
    std :: cout << "------------------" << std :: endl;
}

void remove(){
    std :: cout << "What item would you like to remove? ";
    std :: getline(std :: cin, remove_item);
    for(int i = 0; i < n; i++){
        if(remove_item == inventory[i].name){
            inventory[i] = inventory[n - 1];
            inventory[n - 1] = {};
            i = n;
            n--;
            item_exist = true; 
        }
    }
    if(item_exist == true)
        std :: cout << "Item removed!" << std :: endl;
    else
        std :: cout << "Item does not exist in the inventory!" << std :: endl;
    item_exist = false;
}

void remove_all(){
    for(int i = 0; i < n; i++){
        inventory[i] = {};
    }
    n = 0;
    std :: cout << "All items have been removed!" << std :: endl;
}

void quit(){
    run = false;
}
