// Ballar mana shhu faylga yoziladi kodlariz
// Ertaga qanaqa ishlash kerakligini tushuntirishga harakat qilaman



// Banking system 
// banking system 

#include <iostream>
using namespace std;

#include <fstream>
#include <string>
#include <bits/stdc++.h>

string current_acc[3];



int login();



int main() {
    fstream filename;

    //filename.open("data.txt",ios::app);
    /*string name, password;
    int balance;
    if (filename.is_open())
    {
        cin >> name;
        cin >> password >> balance;
            filename << name << "\t" << password << "\t" << balance << "\n"; 
        filename.close();
    }*/
    
    


    //filename.open("data.txt",ios::in);
    int choice;
    cout << "1. Login" << endl;
    cout << "2. Add account " << endl;
    cout << "3. Exit " << endl;
    cin >> choice;

    switch (choice)
    {
    case 1: login();
        break;
    case 3: cout << "STOP" << endl;
            return 0;
    default:
        break;
    }
    
    
    /*if(filename.is_open()){
        string line;
        while (getline(filename,line))
        {
            cout << line << endl;
        }
        
    }*/


    /*char name[30];
    double balance;
    while(cin >> name >> balance ) {
        outClientFile << name < " " << balance << "" << endl;
        cout << " ? ";
    }    */
    
    return 0;
}


void login_name(string s)
{
    stringstream ss(s);
    string word;
    int i = 0;
    while (ss >> word) {
        current_acc[i] = word;
        i++;
    }
    /*for(int m = 0; m < 3; m++){
        cout << current_acc[m] << " ";
    }*/
}


int logged_in() {
    cout << "1.Widthdrawl" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Convert currency" << endl;
    cout << "4. Get Credit" << endl;
    cout << "5. Exit" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1: cout << "Our team is working on this, please wait" << endl;
        logged_in();
        break;
    case 5: return 0;
    default:
        cout << "Our team is working on this, please wait" << endl;
        logged_in();
        break;
    }
    return 0;
}

int login() {
    fstream myfile;
    string name, password;
    // where the file is read and login is checked
    cout << "The login name : ";
    cin >> name;
    cout << "The password : ";
    cin >> password;
    myfile.open("data.txt", ios::in);
    if(myfile.is_open()){
        string line;
        while(getline(myfile,line)){
            login_name(line);
            if(current_acc[0] == name && current_acc[1] == password){
                cout << current_acc[0] << " ---- You succesfully login to your account" << endl;
                logged_in();
                break;
            }
        }
        cout << "You provided wrong crediantials" << endl;
        cout << "Try again" << endl;
        login();        
    }


    return 0;
}

