// Ballar mana shhu faylga yoziladi kodlariz
// Ertaga qanaqa ishlash kerakligini tushuntirishga harakat qilaman



// Banking system 
// banking system 

#include <iostream>
using namespace std;
using std:: left;
using std:: right;

#include <fstream>
using std::ofstream;
using std:: ifstream;

#include <iomanip>
using std::setw;
using std::setprecision;

int display(char name, double balance);


int main() {
    ofstream outClientFile("data.dat", ios::app);
    ifstream inClientFile("data.dat","ios::in");

    char name[30];
    double balance;

    /*while(cin >> name >> balance ) {
        outClientFile << name << " " << balance << "" << endl;
        cout << " ? ";
    }*/
    while (inClientFile >> name >> balance >>) {
        display(name,balance);
    }
    

    return 0;
}

void display(char name, double balance) {
    cout << left << setw(10) << account << setw(13) << name << setw(7) << setprecision(2) << right << balance << endl;
}


