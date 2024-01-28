#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//creating struct for employees
struct employee{
    string emname;
    int emid;
};

//creating struct for customers
struct customer{
    string cuname;
    int cuid;
    float balance;
};

//initializing maximum people read from file
const int people = 50;

int main(){

char type, dw;
string emname, cuname;
int emid, cuid, counter = 0;
float balance, t_amount;

//creating structure of arrays
struct employee emp[people];
struct customer cus[people];

cout << "123456789012345678901234567890123456789012345678901234567890\n";

//loop to keep running so long as it is reading a char and is less than 50 ppl
while(cin >> type && counter < people){

    //if employee then store name and id
    if (type == 'e'){

        cin >> emid >> emname;
        emp[emid-1].emname = emname;
        emp[emid-1].emid = emid;

    //if customer then store name, id, and balance
    } else if (type == 'c'){
        cin >>  cuid >> cuname >> balance;
        cus[cuid-1].cuname = cuname;
        cus[cuid-1].cuid = cuid;
        cus[cuid-1].balance = balance;

    //if transaction then store, customer id, employee id, withdraw/deposit, and amount of w/d
    } else {
        cin >> cuid >> emid >> dw >> t_amount;
        //cout the name of the person doing the transaction and the employee
        cout << setw(15) << right << cus[cuid-1].cuname << " " << setw(15) << right << emp[emid-1].emname;
            //if deposit then add amount to balance and print that out
            if(dw == 'd'){
                cus[cuid-1].balance += t_amount;
                cout<< setw(1) << left <<" +$" << setw(7) << right << fixed << setprecision(2) << t_amount << fixed << setprecision(2) << setw(1) << left <<" $" << setw(9) << right << cus[cuid-1].balance << endl;
            //if withdraw then subtract amount from balance and print that out
            } else{
                cus[cuid-1].balance -= t_amount;
                cout << setw(1) << left <<" -$" << setw(7) << right << fixed << setprecision(2) << t_amount << fixed << setprecision(2)<< setw(1) << left << " $" << setw(9) << right <<  cus[cuid-1].balance << endl;
            }
    }

    counter++;
}

return 0;
}