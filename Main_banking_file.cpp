// Ballar mana shhu faylga yoziladi kodlariz
// Ertaga qanaqa ishlash kerakligini tushuntirishga harakat qilaman



// Banking system 
// banking system 

#include <iostream>
using namespace std;

#include <fstream>
using std::ofstream;



int main() {
    ofstream outClientFile("data.dat", ios::app);


    char name[30];
    double balance;
    while(cin >> name >> balance ) {
        outClientFile << name < " " << balance << "" << endl;
        cout << " ? ";
    }    
    
    return 0;
}


