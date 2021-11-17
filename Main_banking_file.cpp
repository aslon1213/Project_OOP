// Ballar mana shhu faylga yoziladi kodlariz
// Ertaga qanaqa ishlash kerakligini tushuntirishga harakat qilama
// Banking system 
// banking system 
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;
int bal;
void write_changes();
int main();
int logged_in();
// this array to store credentials of currently logged in account
string current_acc[3];
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
            break;
        case 3:
            cout << "Good bye" << endl;
            return 0;
            break;
        default:
            main();
    }
    return 0;
}


//Deposit
void deposit(){
    int deposit,b,summ;
    string a=current_acc[2];
    stringstream geek(a);
    cout<<"Enter how much you want to deposit"<<endl;
    cin>>deposit;
    geek>>b;
    summ=b+deposit;
    current_acc[2] = to_string(summ);
    cout<<"Your current balance is "<<current_acc[2]<<"$"<<endl;
    write_changes();
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


// writies changes made to account to data.txt
void write_changes(){   
    fstream myfile;
    fstream temp_file;
    //opening files to read and write
    myfile.open("data.txt",ios::in); // the main file
    temp_file.open("temp_data.txt",ios::out); // template file
    //copy data.txt to temp_Data.txt
    if(myfile.is_open()){
        string line;
        while(getline(myfile,line)){
            temp_file << line << endl;
        }
        temp_file.close();
        myfile.close();
    }
    // reopening files to re-write the contents of data.txt(mainfile)
    myfile.open("data.txt", ios::out);
    temp_file.open("temp_data.txt", ios::in);
    // making changes to the data.txt 
    if(temp_file.is_open()){
        string line;
        while(getline(temp_file,line)){
            string lines[3];
            stringstream ss(line);
            string word;
            int i = 0;
            while (ss >> word) {
                lines[i] = word;
                i++;
            }
            if(lines[0] == current_acc[0]) {
                myfile << current_acc[0] << " " << current_acc[1] << " " << current_acc[2] << endl;
                continue;
            }
            myfile << lines[0] << " " << lines[1] << " " << lines[2] << endl;
        }
        myfile.close();
        temp_file.close();
    }
}



//Balance - shows current balance of a user
int balance(){
cout<<"        Your balance is     ------   "<<current_acc[2]<<"$     --------"<<endl << endl;
return 0;
}

//Withdraw
int withdraw(){
    int with;
    string i=current_acc[2];
     stringstream geek(i);
     int bal;
     geek>>bal;
     if(bal>=250){
         cout<<"----How much you want to withdraw: "<<endl;
         cin>>with;
         if ( bal >= with){
             bal =bal - with;
         cout<<with<<" withdrawn from your account. Your current balance is "<<bal<<"$"<<endl;
         string ball = to_string(bal);
         current_acc[2] = ball;
         write_changes();
         }else {
             cout<<"Sorry :( You don't have enough money to withdraw"<<endl;
         }   
     }else{
         cout<<"Sorry :( You don't have enough money to withdraw"<<endl;
     }
     return 0;
}



// This fucntion opens - The window after succesfull login happens
int logged_in() {
    cout << "1. Balance" << endl;
    cout << "2. Widthdraw" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Exchange rates" << endl;
    cout << "5. Exit" << endl;
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
            case 3: deposit();
            logged_in();
            break;
        case 5:
        cout<<"Good bye."<<endl;
 
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




// Aslon KHamidov 10:36