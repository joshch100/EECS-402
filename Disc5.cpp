
using namespace std;
#include <iostream>

// this is a class!
class BankAccount {
  private:
    //two attributes//
    double bill; //represents credit card bill
    double balance; // represents your balance

  public:

    // initializes bank account to 0
    BankAccount() {
      bill = 0;
      balance = 0;
    }

    // TODO: initializes bill to 0 and balance to initialAmount
    //Value constructor//
    BankAccount(int initialAmount) {
      balance = initialAmount;
      bill = 0;
    }
    
    //TODO: deposit the given amount into your balance
    void deposit(double amount) {
      balance += amount;
    }

    void charge(double amount) {
      bill += amount;
    }

    //TODO if you have enough money, withdraw the given amount and return ture
    // if you don't have enough money, just return false
    bool withdraw(double amount) {
      if(balance>=amount){
        balance -= amount;
        return true;
      }
      return false;

    }

    //TODOL Pay your credit card bill (you can go into debt here)
    // try to do this one using scope resolution!
    void payBill();


    // Challenge problem- don't worry if you can't get it yet
    // TODO pay your freind the given amount to their account 
    // You cannot go into debt here (return false if you don't have enough money)
    bool payFriend(BankAccount& friendAccount, double amount) {

      if(withdraw(amount)){

        friendAccount.deposit(amount);
        return true;

      }
      return false;

    }

    // prints current balance 
    void printBalance(){
      cout << "Current balance is: $" << balance << endl;
    }

    ~BankAccount() { //how do you know when the BankAccount object is destroyed
      cout << "dtor!!" << endl;
    }

}; //Don't forget the semi column


int main() {

  BankAccount myAccount;
  myAccount.deposit(100);
  myAccount.deposit(150);

  BankAccount friendAccount(100);

  myAccount.payFriend(friendAccount, 75);


  myAccount.printBalance(); 
  friendAccount.printBalance();
  // Why does the oupout print "two" dtors!

  return 0;
}


void BankAccount::payBill(){
  balance -= bill;
  bill = 0;
}



