#include <iostream>
using namespace std;

int main(){
    int price, tax, TTC;
    string Type;
    cout << "Enter the price of the vehicle: ";
    cin >> price;
    cout << "Enter the type of the vehicle(commercial, transport, standard): ";
    cin >> Type;
    if (price <= 0){
        cout << "Invalide Value!";
    }else if (price <= 700000){
        tax = price * 3 / 100;
    }else if (price > 700000 and price <= 1000000){
        tax = price * 5 / 100;
    }else if (price > 1000000 and price <= 1500000){
        tax = price * 6 / 100;
    }else{
        tax = price * 8 / 100;
    }
    if (Type == "commercial" || Type == "transport"){
        tax /= 2;
    }
    cout << "Tax = " << tax << " DA." << endl;
    TTC = price + tax + 20000;
    cout << "TTC = " << TTC << " DA.";
}