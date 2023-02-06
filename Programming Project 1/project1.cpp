
#include <iostream> //Req'd for cout
#include <cmath>
using namespace std;

//Programmer: Joshua Chang 
//Date: September 2021
/*Purpose: To implement functionality to accrue interest for an investment 
account.*/ 

bool accrueInterest(double &balanceAmt, const int numMonths, 
                                     const bool doPrintEachMonth);
bool accrueOneMonthsInterest( double &balanceAmt, const bool doPrintInfo);
//prototype

#ifdef ANDREW_TEST
#include "andrewTest.h"
#else
int main()
{   
    double balanceAmt = 0;
    int numMonths = 0;
    char printorNot;

    cout << "Enter the initial balance of the account: "; 
    //Prompt cin >> balanceAmt;
    cin >> balanceAmt;
    cout << "Enter the number of months to accrue interest: "; 
    //Prompt cin >> numMonths;
    cin >> numMonths;
    cout << "Show month-by-month results - 'y' for yes, any other for no:"; 
    //Prompt cin >> printorNot;
    cin >> printorNot;

    if (balanceAmt >= 0)
    {
        if(numMonths <= 0)
        {
            cout << "ERROR in accrueInterest: numMonths must be > 0, but the" 
            << " value " << numMonths << " was was provided!" << endl;
            cout << "Sorry, an error was detected. Unable to provide results!" 
            << endl;
            return 0;
        }
        
    }

    else if (balanceAmt < 0)
    {
        cout << "ERROR in accrueOneMonthsInterest: balanceAmt must be >= 0,"
        << " but the value " << balanceAmt << " was was provided!" << endl;
        cout << "Sorry, an error was detected. Unable to provide results!" 
        << endl;

        return 0;
    }   
 
    
    bool yesNo;  //doprinteachmonth //**can my yesNo be printorNot, so it would be the same as char printorNot?***********************
    if (printorNot == 'y')
    {
        yesNo = true;
    //accrueInterest(balanceAmt, numMonths, true);
    }
    else
    {
        yesNo = false;
    }

   
    accrueInterest(balanceAmt, numMonths, yesNo); //function call
    


    return 0; 
}
#endif



bool accrueInterest(double &balanceAmt, const int numMonths, const bool 
doPrintEachMonth)
{
    double totalInterestAccured=0; // the total interest accured  
    double initialBalance = balanceAmt;

  
    if (doPrintEachMonth) //**revise the true and false here to printorNot? **********************************
    {
        for (int i = 0; i < numMonths; i++) 
        { 
            accrueOneMonthsInterest(balanceAmt, doPrintEachMonth); 
            //function call  
        }
    }

    cout << "Interest accrued for " <<  numMonths << " months!"  << endl;
    cout << " " << endl;


    if (!doPrintEachMonth) // **********************************
    {
        for (int i = 0; i < numMonths; i++) 
        { 
            accrueOneMonthsInterest(balanceAmt, doPrintEachMonth); 
            //function call
        }
    }

    
    totalInterestAccured = balanceAmt - initialBalance; 
    //Calculate the Total interest accured 
    cout << "Initial balance: " << initialBalance << endl;
    cout << "Total interest accrued: " << totalInterestAccured << endl;
    cout << "Final balance: " << balanceAmt << endl;
    
    return true;
}





bool accrueOneMonthsInterest(double &balanceAmt, const bool doPrintInfo)
{
    double interestRate; // the interest rate for each month
    const double MINIMUM_INTEREST_RATE = 0.0015 ; 
    // the minimum interest rate for each month
    const double MAXIMUM_INTEREST_RATE = 0.004 ; 
    // the maximum interest rate for each month  
    const double STANDARD_INTEREST_RATE = 0.00225 ; 
    // the standard interst rate for each month 
    double interestAccured; // the interest accured for one month
    const double CUSTOMERBALANCE_1000 = 1000 ; // Customer balances at $1000.00
    const double CUSTOMERBALANCE_15000 = 15000 ; /*Customer balances at 
    $15000.00*/

    

    if (balanceAmt < CUSTOMERBALANCE_1000)
    {
        interestRate = MINIMUM_INTEREST_RATE;
    }
    else if (balanceAmt >= CUSTOMERBALANCE_15000)
    {
        interestRate = MAXIMUM_INTEREST_RATE;
    }
    else 
    {
        interestRate = STANDARD_INTEREST_RATE;
    }


    if (doPrintInfo == true)  //**********************************
    {
        interestAccured = balanceAmt * interestRate;
        cout << "Accruing interest for 1 month:" << endl; 
        cout << "  " << "Initial balance: " << balanceAmt << endl;
        cout << "  " << "Initial rate: " << interestRate << endl;
        cout << "  " << "Interest accrued: " << interestAccured << endl;
        balanceAmt = balanceAmt + interestAccured;
        cout << "  " << "New Balance: " << balanceAmt << endl;
    }

    if (doPrintInfo == false) // **********************************
    {
        interestAccured = balanceAmt * interestRate;
        balanceAmt = balanceAmt + interestAccured;
    }

    return true;
}