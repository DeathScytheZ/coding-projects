#include <iostream>
#include <string>

const float price_toppings = 1.5;
float pizza_price[4] = {5.25, 8.75, 10.5, 12.25};
bool valid_size = false;
float pizza_cost(float s, int t);
struct pizza{
    int size;
    int toppings;
};

int main(){
    pizza p;
    std :: cout <<  "Available pizza sizes: " << std :: endl;
    for(int i = 0; i < 4; i++){
        switch(i){
            case 0 : std :: cout << "1_small ------ " << pizza_price[i] << "$" << std :: endl; break ;
            case 1 : std :: cout << "2_medium ------ " << pizza_price[i] << "$" << std :: endl; break ;
            case 2 : std :: cout << "3_large ------ " << pizza_price[i] << "$" << std :: endl; break ;
            case 3 : std :: cout << "4_extra large ------ " << pizza_price[i] << "$" << std :: endl; break ;
        }
    }

    while(valid_size == false){
        std :: cout << "What size do you want your pizza? (1 through 4): ";
        std :: cin >> p.size;
        for(int i = 1; i <= 4; i++){     
            if(p.size == i){
                i = 5;
                valid_size = true;
                p.size -= 1;
            }
        }
    } 
    
    while(p.toppings < 1 || p.toppings > 5){
        std :: cout << "How many toppings do you want on your pizza? (up to 5 toppings are available): ";
        std :: cin >> p.toppings; 
    }

    std :: cout << "The pizza you ordered costs " << pizza_cost(pizza_price[p.size],p.toppings ) << "$";
}

float pizza_cost(float s, int t){
    float cost = s + t * price_toppings;
    return cost;
}

