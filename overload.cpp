using namespace std;
#include <iostream>
#include <string>


//operator overloading examnple

class Bank_Account {
    private: 
        int savings;
        int checking;
        string accountName;
    
    public: 
        Bank_Account(int savingsIn, int checkingIn, string accountNameIn){
            savings = savingsIn;
            checking = checkingIn;
            accountName = accountNameIn;
        }

        Bank_Account(){};
        // >
        // if(account1 > account2)
        //compare total money
        //its boolean cuz we wanna get yes or no
        bool operator>(const Bank_Account& rhs){ //why do we put const here?
            if((savings+checking) > (rhs.savings + rhs.checking)){
                return true;
            }
            return false;
        }

        // +=
        // account += 5
            //deposit it to checkings
        void operator+=(int money){
            checking += 5;
        }
        
        // +
        // account3 = account1 + account2
        Bank_Account operator+(const Bank_Account& rhs){ //why do we put const here?
            Bank_Account newAccount;

            newAccount.savings = savings + rhs.savings;
            newAccount.checking = checking + rhs.checking;
            newAccount.accountName = "newAccount";

            return newAccount;
        }
    
};


int main(){
    Bank_Account one(1, 2, "First Account");
    Bank_Account two(1, 2, "Second Account");
    Bank_Account three(0, 0, "Third Account");



    

}