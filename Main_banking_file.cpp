// Ballar mana shhu faylga yoziladi kodlariz
// Ertaga qanaqa ishlash kerakligini tushuntirishga harakat qilama
// Banking system 
// banking system 
#include <iostream>
using namespace std;
#include <fstream>

#include <string>

#include <bits/stdc++.h>

string current_acc[3];



int login();
int add_account();


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

    switch (choice) {
        case 1:
            login();
            break;
        case 2:
            add_account();
        case 3:
            cout << "STOP" << endl;
            return 0;
        default:
            main();
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

// account adds logged accounts credential(name,password,balance) to global array current_acc to easy access
void login_name(string s) {
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

// checks whether a new given account name exist in file(data.txt) or not
// if yes returns 0 else 1
int new_account_check(string name) {
    fstream myfile;
    myfile.open("data.txt", ios:: in );
    if (myfile.is_open()) {
        string line;
        while (getline(myfile, line)) {
            login_name(line);
            if(current_acc[0] == name) {
                return 0;
            }
}
    }
    return 1;
}


// Function which manages adding a new account a file(data.txt)
int add_account() {
    string name, pas1, pas2;
    do {
        cout << " *****************   Creating new account ****************" << endl;
        cout << "Account Name: -> ";
        cin >> name;
        cout << "password -> ";
        cin >> pas1;
        cout << "retype password -> ";
        cin >> pas2;

        if (pas1 == pas2) {  
            if (new_account_check(name)) {  // existing account check
                fstream filename;
                filename.open("data.txt", ios::app);
                if (filename.is_open()) {
                    filename << name << "\t" << pas1 << "\t" << 0 << "\n";
                    filename.close();
                    cout << "You account has benn succesfully added yo system" << endl;
                    main();
                } 
            }else{ cout << "This account name exists in system. Please choose another name";}
        }else {
            cout << "paswords do not match each other!!! " << endl << "Retype again or exit" << endl;
            add_account();} 
    }
    while (pas1 != pas2);
    return 0;
}






// This fucntion opens - The window after succesfull login happens
int logged_in() {
    cout << "1.Widthdrawl" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Convert currency" << endl;
    cout << "4. Get Credit" << endl;
    cout << "5. Exit" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            cout << "Our team is working on this, please wait" << endl;
            logged_in();
            break;
        case 5:
            return 0;
        default:
            cout << "Our team is working on this, please wait" << endl;
            logged_in();
            break;
    }
    return 0;
}


// login checking function
int login() {
    fstream myfile;
    string name, password;
    // where the file is read and login is checked
    cout << "The login name : ";
    cin >> name;
    cout << "The password : ";
    cin >> password;
    myfile.open("data.txt", ios:: in );
    if (myfile.is_open()) {
        string line;
        while (getline(myfile, line)) {
            login_name(line);
            if (current_acc[0] == name && current_acc[1] == password) {
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
