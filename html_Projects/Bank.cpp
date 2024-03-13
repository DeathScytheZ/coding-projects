#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

class account{
    private:
        double balance;
        std::string password;
        std::string nmbr;
    public:
        void setBalance(double b){
            balance = b;
        }

        void setPassword(std::string pswrd){
            password = pswrd;
        }

        void setNmbr(std::string num){
            nmbr = num;
        }

        double getBalance(){
            return balance;
        }

        std::string getPassword(){
            return password;
        } 

        std::string getNmbr(){
            return nmbr;
        }
};

void addAccount(std::vector<account> &accountList){
    account obj;
    std::string pswrd, num;
    srand(time(0));
    for(int i = 0; i < 16; i++){
        pswrd += 33 + rand() % (126 - 33 + 1);
        num += 48 + rand() % (57 - 48 + 1);
    }
    obj.setPassword(pswrd);
    obj.setNmbr(num);
    obj.setBalance(0);
    accountList.push_back(obj);
    std::cout << "Your account Number is: " << obj.getNmbr() << std::endl;
    std::cout << "Your account password is: " << obj.getPassword() << std::endl;
    
}

void checkBalance(std::vector<account> &accountList){
    bool found = false;
    int index;
    std::string num, pswrd;
    std::cout << "Enter your account number: ";
    std::cin >> num;
    for(int i = 0; i < accountList.size(); i++){
        if(accountList[i].getNmbr() == num){
            found = true;
            index = i;
            i = accountList.size();
        }
    }
    if(!found){
        std::cout << "Invalid account number!" << std::endl;
        return;
    }
    for(int i = 0; i < 3; i++){
        std::cout << "Enter your account password: ";
        std::cin >> pswrd;
        if(accountList[index].getPassword() == pswrd){
            std::cout << "Your account Balance is: " << accountList[index].getBalance() << " $" << std::endl;
            return;
        }else
            std::cout << "Password Incorrect, please try again." << std::endl;
    }
    std::cout << "Too many incorrect tries, a message has been sent to you phone number, please confirm your identity and try again!" << std::endl;
}


void deposit(std::vector<account> &accountList){
    std::string num;
    double amount;
    std::cout << "Enter the number of the account you want to diposit to: ";
    std::cin >> num;
    for(int i = 0; i < accountList.size(); i++){
        if(accountList[i].getNmbr() == num){
            std::cout << "Enter the amount of money you wanna deposit: ";
            std::cin >> amount;
            while(amount <= 10){
                std::cout << "The amount of money you want to deposit need to be above 10$." << std::endl;
                std::cout << "Enter the amount of money you wanna deposit: ";
                std::cin >> amount;
            }
            accountList[i].setBalance(accountList[i].getBalance() + amount);
            std::cout << "Deposit successful!" << std::endl;
            return;
        }
    }
    std::cout << "Invalid account number!" << std::endl;
}

void withdraw(std::vector<account> &accountList){
    bool found = false;
    double amount;
    int index;
    std::string num, pswrd; 
    std::cout << "Enter your account number: ";
    std::cin >> num;
    for(int i = 0; i < accountList.size(); i++){
        if(accountList[i].getNmbr() == num){
            found = true;
            index = i;
            i = accountList.size();
        }
    }
    if(!found){
        std::cout << "Invalid account number!" << std::endl;
        return;
    }
    for(int i = 0; i < 3; i++){
        std::cout << "Enter your account password: ";
        std::cin >> pswrd;
        if(accountList[index].getPassword() == pswrd){
            std::cout << "Enter the amount of money you would like to withdraw: ";
            std::cin >> amount;
            while(amount <= 0 || amount > accountList[index].getBalance()){
                std::cout << "Invalid amount, please try again!" << std::endl;
                std::cout << "Enter the amount of money you would like to withdraw: ";
                std::cin >> amount;
            }
            accountList[index].setBalance(accountList[index].getBalance() - amount);
            std::cout << "withdrawal successful, your balance now is: " << accountList[index].getBalance() << " $" << std::endl;
            return;
        }else
            std::cout << "Password Incorrect, please try again." << std::endl;
    }
    std::cout << "Too many incorrect tries, a message has been sent to you phone number, please confirm your identity and try again!" << std::endl;
}


void transfer(){

}


int main(){
    std::vector<account> accountList;
    addAccount(accountList);
    deposit(accountList);
    checkBalance(accountList);
    withdraw(accountList);
    checkBalance(accountList);
}