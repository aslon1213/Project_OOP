/*
/////////////////////////////////////////////////////////////////////////////////
Additional features: 
1. Reset password ------- Nodir
2. Change password --------- Nodir

4. Credit -- 1) leasing   2) home credit    3) overdrive   4) Microcredit ----------Khabibullokh
5. Exchange rates - update --------- Khabibullokh
6. Exchange money -------- Aslon maybe you will do this guys



/////////////////////////////////////////////////////////////////////////////
Implemented  Aslon
7. Different currencies - done
3. transfer money   - done (not fully only some small checks should be implemented
but generally works good, transfer money from to another account)
8. Accounts with four currency types - <done>
9. Depositing to four currency types based on input - done
10. Withdrawing from one of four currency types based on input - done

*/




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
int main();
//Exchange rates
void exchange_rates();
void converting();
void feedback();
int logged_in();
// this array to store credentials of currently logged in account
string current_acc[6];
//
string transfer_acc[6];
int login();
int add_account();
//user data for reseting
void reset()
{
string name , surname , phone; 
string array_data[3]={name,surname,phone };
cout<<"Enter your first name: "<<endl;
cin>>array_data[0];
cout<<"Enter your second name: "<<endl;
cin>>array_data[1];
cout<<"Enter your phone number: "<<endl;
cin>>array_data[2];
fstream user_data;
user_data.open("user_data.txt",ios::app);
if(user_data.is_open()){
 user_data<<array_data[0]<<" "<<array_data[1]<<" "<<array_data[2]<<endl;
    user_data.close();
}}


int main(){
    fstream filename;
    fstream user_data;
    int choice;
       cout << "         🏦🏦🏦  Welcome to our bank named 'BANK'! 🏦🏦🏦         \n ";
    cout << ">>>>>>>>>>>>> Please login or add acoount: <<<<<<<<<<<<<<<" << "\n";
    cout << "*                      1. Login=>>                        *" << endl;
    cout << "*                      2. Add account=>>                  *" << endl;
    cout << "*                      3. Exit=>>                         *" << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>> 💸💸💸  <<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            login();
            break;
        case 2:
            add_account();
            break;
        case 3:
            cout << "            Good bye, have a nice day ʘ‿ʘ 👋 🤚          " << endl;
            return 0;
            break;
        default:
            main();
            
    }
    return 0;
}

// writies changes made to account to data.txt
void write_changes(int cho = 0){   
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
            string lines[6];
            stringstream ss(line);
            string word;
            int i = 0;
            while (ss >> word) {
                lines[i] = word;
                i++;
            }
            if(cho == 0)
            {
                if(lines[0] == current_acc[0]) 
                {
                    myfile << current_acc[0] << " " << current_acc[1] << " " << current_acc[2] << " " << current_acc[3] << " " << current_acc[4] << " " << current_acc[5] << endl;
                    continue;
                }
            }else if (cho == 1)
            {
                if(lines[0] == transfer_acc[0]) 
                {
                    myfile << transfer_acc[0] << " " << transfer_acc[1] << " " << transfer_acc[2] << " " << transfer_acc[3] << " " << transfer_acc[4] << " " << transfer_acc[5] << endl;
                    continue;
                }
            }

            myfile << lines[0] << " " << lines[1] << " " << lines[2] <<" "<< lines[3] << " " << lines[4] << " " << lines[5] << endl;
        }
        myfile.close();
        temp_file.close();
    }
}

// to convert from string to int given string and return integer value
int convert_from_str_to_int(string c) {
    
    int b;
    stringstream geek(c);
    geek>>b;
    return b;   
}
//Balance - shows current balance of a user
int balance(int cho = 0){
    if(cho == 0){
            cout<<"        Your wallet balances:     ------   "<<current_acc[2]<<"$     --------"<<endl;
            cout<<"                                  ------   "<<current_acc[3]<<"€ --------" <<endl;
            cout<<"                                  ------   "<<current_acc[4]<<"UZS  --------" <<endl;
            cout<<"                                  ------   "<<current_acc[5]<<"₽   --------" <<endl;

    }
    return 0;
}


//Deposit
void deposit(int cho = 0,int cur = 2, int money = 0)
{
    string a;
    int b,summ;
    if (cho == 0)
    {
        a=current_acc[cur];
        stringstream geek(a);
        geek>>b;
        summ=b+money;
    }else if ( cho == 1) 
    {
        a = transfer_acc[cur];
        stringstream geek(a);
        geek >> b;
        summ = b + money;
    }
    
    // for choice dopisiting values 
    if(cho == 0) 
    {
        current_acc[cur] = to_string(summ);
        balance();
        write_changes();
    }else
    {
        transfer_acc[cur] = to_string(summ);
        write_changes(1);
    }
    
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


void inha_contract_pay() {
    
     float amountM; char cond; string id ;
        int countN = 0;

        if (countN != 6 || id.length()!=6) { 
            countN = 0; 
            cout << "Enter id of your account = "; cin >> id; 

}       cout << " * How much money you want to pay for this account (limit: 1-100) = ";  
        cin >> amountM;
        if (amountM >= 1 && amountM <= 100 ) 
        {//condition for amount of money
            cout << " Accound id: " << id << endl; 
            cout << " Amount of money you want to pay ? " << amountM << endl; 
            cout << " * Is everything correct(Y/N) = "; cin >> cond; 
            if (cond == 'y' || cond == 'Y' ) { 
                int cashback;
                cashback = amountM * 0.05;
                cout << " *** Payment has been successfully excuted � \n"; 
                cout << " *** You received " << cashback << "$ as cashback to your balance"; 
                deposit(0,2,cashback);
            } 
            else cout << " *** Payment is cancelled :(\n"; 
        } 
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
        cout << "Password -> ";
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
        reset();
       
        system("clear");

        if (pass == pas2) {  
            if (new_account_check(name)) {  // existing account check
                fstream filename;
                filename.open("data.txt", ios::app);
                if (filename.is_open()) {
                    filename << name << " " << pass << " " << "0" << " " << "0" << " " << "0" << " " << "0" << endl;
                    filename.close();
                    cout << "You account has benn succesfully added yo system" << endl;
                    main();
                } 
            }else{ cout << "This account name exists in system. Please choose another name"<<endl;
            login();
            }
        }else {
            cout << "paswords do not match each other!!! " << endl << "Retype again or exit" << endl;
            add_account();} 
    }
    while (pass != pas2);
    return 0;
}


//Withdraw
int withdraw(int with, int cur = 2){
    string i=current_acc[cur];
    stringstream geek(i);
    int bal;
    geek>>bal;
    if(bal>=250){
        if ( bal >= with){
            bal = bal - with;
            cout<<with<<" withdrawn from your account. Your current balance on this wallet is "<<bal<<endl;
            string ball = to_string(bal);
            current_acc[cur] = ball;
            write_changes(0);
        }else {
            cout<<"Sorry :( You don't have enough money to withdraw - 1"<<endl;
        }   
    }else{
        cout<<"Sorry :( You don't have enough money to withdraw - 2 or your balance is less than wintdrawing limit"<<endl;
    }
    return 0;
}


int transfer_money(){
    
    // checking transferring accounts existense and assigning values of it to a array transfer_acc[6]
    string tr_acc;
    fstream myfile;
    myfile.open("data.txt",ios::in);
    if(myfile.is_open()){
        int n = 0;
        do 
        {
            cout << "To which Account you want to transfer money: ";
            cin >> tr_acc;
            string line;
            while(getline(myfile,line)){
                stringstream ss(line);
                string word;
                int i = 0;
                while (ss >> word) {
                transfer_acc[i] = word;
                i++;
                }
                if(transfer_acc[0] == tr_acc) {
                    n = 1;
                    break;
                }
            }
            if(n == 0) {
                cout << "There is no account match to transfer with this name..... Please try again !" << endl;
            }
        }while(n == 0);
    }
    
    // getting wallet type and amount of money to be used
    int money;
    int type; // type of wallet
    cout << "Please choose your wallet for specific currency transfer should be done: " << endl;
    cout << "1: Dollar - ($)" << endl << "2: Euro - (€)" << endl <<"3. Uzbek Som ---> UZS() " << endl <<"4: Russian Ruble ---> RB(₽)  " <<endl << "5: Exit --------- ";
    cin >>  type;
    // Printing the choice of user ---- wallet choice
    switch (type)
    {
    case 1: cout << "You have chosen Dollar - ($) wallet" << endl<<endl;
        break;
    case 2: cout << "You have chosen Euro - (€) wallet" << endl<<endl;
        break;
    case 3: cout << "You have chosen Uzbek Som ---> UZS() wallet" << endl<<endl;
        break;
    case 4: cout << "You have chosen Rubl - () wallet" << endl<<endl;
        break;
    case 5: return 0;
    default: cout << "Please choose one from above" << endl;
        break;
    }
    cout << "What is the amount of money you want to transfer: ";
    cin >> money;
    if( money > convert_from_str_to_int(current_acc[type+1]) - 250){
        cout << "Sorry it seems the amount of money YOU are transferring is higher than your WALLET BALANCE!!!" << endl << endl;
        logged_in();
    }
    
    // all actions go here
    switch (type){
    case 1:  withdraw(money);
             deposit(1,2,money);
             logged_in();
        break;
    case 2: withdraw(money,3);
            deposit(1,3,money);
            logged_in;
            break;
    case 3: withdraw(money,4);
            deposit(1,4,money);
            logged_in;
            break;
    case 4: withdraw(money,5);
            deposit(1,5,money);
            logged_in;
            break;
    case 5: return 0;
    default: cout << "Please choose one from above" << endl;
        break;
    }
    return 0;
}


// This fucntion opens - The window after succesfull login happens
int logged_in() {
    cout << "         >>>>>>>>>>>>>>>>>>>>>>>>>>>> Our MENU(operations): <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
    cout << "         (✷‿✷)                  1. Balance                                (✷‿✷)" << endl;
    cout << "         (✷‿✷)                  2. Withdraw                               (✷‿✷)" << endl;
    cout << "         (✷‿✷)                  3. Deposit                                (✷‿✷)" << endl;
    cout << "         (✷‿✷)                  4. Transfer money                         (✷‿✷)" << endl;
    cout << "         (✷‿✷)                  5. Daily exchange rates                   (✷‿✷)" << endl;
    cout<<  "         (✷‿✷)                  6. Converting money into other currencies (✷‿✷)  \n";
    cout << "         (✷‿✷)                  7. Exit                                   (✷‿✷)" << endl;
    cout << " 8. Pay to inha" << endl;
    cout << "         >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n ";
    int choice;
    string tr_acc; //transfer account
    cin >> choice;
    switch (choice) {
        case 1:
            balance(0);
            logged_in();
            break;
        case 2: int money,wallet_type;
                cout << "Please, choose one of your wallets below   " <<endl;
                cout << "1: Dollar ---> USD($)" << endl << "2: Euro ---> (€)" << endl <<"3. Uzbek Som ---> UZS()" << endl <<"4: Russian Ruble ---> RB(₽) " <<endl << "5: Exit --------- ";
                cin >> wallet_type;
                cout << "Type amount of money you wanna withdraw from your account: ";
                cin >> money;
                withdraw(money,wallet_type + 1);
                logged_in();
                break;
        case 3: cout << "Please, choose one of your wallets below   " <<endl;
                cout << "1: Dollar" << endl << "2: Euro - (€)" << endl <<"3. Uzbek Som ---> UZS() " << endl <<"4: Russian Ruble ---> RB(₽) " <<endl << "5: Exit --------- ";
                cin >> wallet_type;
                int moneydeposit;
                cout << "How much you want to deposit : ";
                cin >> moneydeposit;
                deposit(0,wallet_type + 1,moneydeposit);
                logged_in();
                break;
                case 5: exchange_rates();
                logged_in();
                break;
                
        case 4: cout << "(Note that you can transfer money only within accounts in our database)" << endl; 
                transfer_money();
                break;
        case 6: converting();
        logged_in();
        break;

    case 7:
        feedback();
       cout << "                   Thanks for choosing us 🙂 👋                    "<<endl;
          
        break;
        return 0;
    case 8: inha_contract_pay();
            logged_in();
            break;
        default:
            cout << "Our team is working on this, please wait" << endl;
            logged_in();
            break;
    }
    return 0;
}


// login checking function
int login() {

    
        int i =  0; // checking wrong input timess    
   
    while(1)   
    {  
        fstream myfile; 
         myfile.open("data.txt", ios:: in );
   
    string name, password;
    
    if ( i >= 3)
    {
        cout << "It seems you forgot your password or username. -- If you want to reset your password, please write RESET or reset" << endl;
    }
    cout << "The login name : ";
    cin >> name;
    if((name == "reset" || password == "reset" ||name == "RESET" || name == "Reset") && i >= 3) 
    {
        cout << "You have been redirected to reset password tool !!!!" << endl << endl;
        reset();
    }
    cout << "The password : ";
    cin >> password;
    if((name == "reset" || password == "reset") && i >= 3) {
        cout << "You have been redirected to password reset tool !!!!" << endl << endl;
        reset();
    }
    /*system("cls");*/
    // where the file is read and login is checked
    string line;
    while (getline(myfile, line)) 
    {
        login_name(line);
        if (current_acc[0] == name && current_acc[1] == password) 
        {
            cout << current_acc[0] << " ->-> 🥳 Congratulations 🥳! You have succesfully logged to your account <-<- " << endl;
            logged_in();
            break;
        }
    }
    cout << "You provided wrong crediantials " << endl;
    cout << "Try again" << endl;
    i++;       
    myfile.close();
}
    
    return 0;
}


//Exchange rates 
void exchange_rates()
{
  int  d; //int is a variable that can store some integer values
  double R, E, S, Y; //declaring variable via operator float

  cout << "******************************* Exchange rates in our bank: ***********************************" << "\n";
  cout << "Dear our client please if you want to know about exchange rates input amount of money in dollars: "; // just asking amount of money in order to convert
  cin >> d;// putting stream insertion operator to accept input
  R = d * 73.52;
  E = d * 0.89;
  S = d * 10736.39;//formulas to convert 
  Y = d * 6.39;
  cout << d << "$ => " << R << " Rubs " << endl;
  cout << d << "$ => " << E << " Euros " << endl; // outputs
  cout << d << "$ => " << S << " Sôms  " << endl;
  cout << d << "$ => " << Y << " Chinese yuans  " << endl;
  cout<< " These exchange rates only for today, it is changing on a daily basis 🤩🤩🤩 \n";
  
 
} 


//Conversion proggram
void converting() {
    string currency, currency2;
    double value, value2;
    cout << "<<<<<<<<<<<<< Welcome to our conversion programm, we are over the moon to see you here :)) >>>>>>>>>>>>>>>>>>\n";
    cout << "*****************************Which currency would you like to convert?***************************************\n";
    cout << "                           (We have 4 different options: Rub, Sum, Dollars, Euro)                            \n ";
    cin >> currency;
    cout << "To which currency you would like to convert to?\n";
    cin >> currency2;
    cout << "How much money you wanna convert?\n";
    cin >> value;
    if (currency == "Dollars" || currency == "dollars" || currency == "USD") {
        if (currency2 == "Rub" || currency == "rub") {
            value2 = value * 74.77;
            cout << value << "$ is equal to " << value2 << " rub "<< "\n";
        }
        else if (currency2 == "Sum" || currency == "sum") {
            value2 = value * 9800;
            cout << value << "$ is equal to " << value2<< " sum" << "\n";

        }
        else if (currency2 == "Euro" || currency == "euro") {
            value2 = value * 1;
            cout << value << "$ is equal to " << value2<<" euros " << "\n";

        }
    }
    else if (currency == "Rub" || currency == "rub") {
        if (currency2 == "Dollars" || currency == "dollars" || currency == "USD") {
            value2 = value * 0.013;
            cout << value << " rubs is equal to " << value2<<" dollars" << "\n";
        }
        else if (currency2 == "Sum" || currency == "sum") {
            value2 = value * 144.37;

            cout << value << " rubs is equal to " << value2<<" sums"        << "\n";
        }
        else if ( currency == "Euro" || currency == "euro") {
            value2 = value * 0.012;
            cout << value << "rubs is equal to " << value2<< " euros" << "\n";
        }
    }
    else if (currency == "euro" || currency == "Euro") {
        if (currency2 == "Dollars" || currency == "dollars" || currency == "USD") {
            value2 = value * 1.12;
            cout << value << " euros is equal to " << value2<<" dollars" << "\n";
        }
        else if (currency2 == "Rub" || currency == "rub") {
            value2 = value * 84.02;
            cout << value << " euros is equal to " << value2<<" rubs"      << "\n";
        }
        else if (currency2 == "Sum" || currency == "sum") {

            value2 = value * 1.46;

            cout << value << " euros is equal to " << value2 <<" sums"      << "\n";

        }
    }
    else if (currency == "Sum" || currency == "sum" ) {
        if (currency2 == "Dollars" || currency == "dollars" || currency == "USD") {
            value2 = value * 0.009;
            cout << value << "sums is equal to " << value2<<"dollars" << "\n";
        }
        else if (currency2 == "Euro" || currency == "euro") {
            value2 = value * 0.67;
            cout << value << " sums is equal to " << value2<<" euros" << "\n";

        }
        else if (currency2 == "Rub" || currency == "rub") {
            value2 = value * 9805;
            cout << value << " sums is equal to " << value2<< " rubs" << "\n";

        }

    }
        else {

        cout << "Unfortunately you have mistaken, check spelling. Try again please";

    }
}


void feedback()
{
    string response = "";
    
    cout << "Dear clients we need your feedback in order to improve the quality of our services\n ";
    cout<<"Please write your feedback there =>> \n";
    getline(cin,response);  // takes input from the user and places it into the string
    fstream myfile;
    myfile.open("feedback.txt",ios::app);
    if(myfile.is_open()){
        myfile << current_acc[0] << " ";
        for(int i = 0; i <= 400; i++){
            myfile << response[i];
            }
        myfile << endl;
    }
    myfile.close();
    cout<<"Your feedback was: "<< response <<endl;
    
}
