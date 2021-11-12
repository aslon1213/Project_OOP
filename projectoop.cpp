// Ballar mana shhu faylga yoziladi kodlariz
// Ertaga qanaqa ishlash kerakligini tushuntirishga harakat qilama
// Banking system 
// banking system 
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <curses.h>
using namespace std;
int bal;
int main();
int logged_in();
string current_acc[3];

//Balance
int balance(){
cout<<"Your balance is: "<<current_acc[2]<<endl;
return 0;
}
//Withdraw
int withdraw(){
    int with,result;
    string i=current_acc[2];
     stringstream geek(i);
     int bal;
     geek>>bal;
     if(bal>=250){
         cout<<"How much you want to withdraw: "<<endl;
         cin>>with;
         result=bal-with;
         cout<<with<<" withdrawn from your account. Your current balance is "<<result<<endl;
     }
     else{
         cout<<"Sorry :( You don't have enough money to withdraw"<<endl;
     }
}

int login();
int add_account();


int main() {
    fstream filename;
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
    string name, pas2;
    const int SIZE = 12; // Maximum size for the c-string
    char pass[SIZE];   // to hold password c-string.
    int length;

    do {
        cout << " *****************   Creating new account ****************" << endl;
        cout << "Account Name: -> ";
        cin >> name;
       
        cout << "password -> ";
        cin >> pass;
        length = strlen(pass);
         while (length < 6 || length > 10)
{
    cout << "Error: password is not between 6 and " << (SIZE - 2) << " characters long.\n"<< "Enter the password again: ";
     cin>>pass;
    length = strlen(pass);
}
        cout << "retype password -> ";
        cin >> pas2;
       
        system("clear");

        if (pass == pas2) {  
            if (new_account_check(name)) {  // existing account check
                fstream filename;
                filename.open("data.txt", ios::app);
                if (filename.is_open()) {
                    filename << name << "\t" << pass << "\t" << 0 << "\n";
                    filename.close();
                    cout << "You account has benn succesfully added yo system" << endl;
                    main();
                } 
            }else{ cout << "This account name exists in system. Please choose another name";}
        }else {
            cout << "paswords do not match each other!!! " << endl << "Retype again or exit" << endl;
            add_account();} 
    }
    while (pass != pas2);
    return 0;
}






// This fucntion opens - The window after succesfull login happens
int logged_in() {
    cout << "1.Balance" << endl;
    cout << "2.Widthdrawl" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Convert currency" << endl;
    cout << "5. Get Credit" << endl;
    cout << "6. Exit" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            balance();
            logged_in();
            break;
            case 2: withdraw();
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
    system("clear");
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
