/* Team members:
   we did project on Macos , so that is why some codes like system("clear")=system("cls") can not be found
   U2110167 Bahodir Khamidov
   U2110166 Aslonkhuja Khamidov
   U2110177 Nodirbek Khudoyberdiev    -->>If you ask why we called our bank like "BANK" because the first letter of our names))) such a magic!
   U2110164 Khabibullokh Khallokov
   We are from section 004 !
*/
#include <iostream> 
#include <fstream>  // read and write file 
#include <string> // to use getline function and manage string
#include <cstring> // geek 
#include <sstream> // stringstream - datatype 
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
//this array used to store credentials of account being used to transfer money 
string transfer_acc[6];
int login();
int add_account();
//user data for resetting


// and main function
int main() {
    cout << "           * * * * *   * * * * * *   *       *   *   *" << endl;
    cout << "           *       *   *         *   * *     *   *  *" << endl;
    cout << "           *       *   *         *   *  *    *   * *" << endl;
    cout << "           * * * * *   * * * * * *   *   *   *   *" << endl;
    cout << "           *       *   *         *   *    *  *   * *" << endl;
    cout << "           *       *   *         *   *     * *   *  *" << endl;
    cout << "           * * * * *   *         *   *       *   *   *" << endl;
    cout << "" << endl;
    cout << "" << endl;
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


// writies changes made to account to data.txt
void write_changes(int cho = 0) {
    fstream myfile;
    fstream temp_file;
    //opening files to read and write
    myfile.open("data.txt", ios::in); // the main file
    temp_file.open("temp_data.txt", ios::out); // template file
    //copy data.txt to temp_Data.txt
    if (myfile.is_open()) {
        string line;
        while (getline(myfile, line)) {
            temp_file << line << endl;
        }
        temp_file.close();
        myfile.close();
    }
    // reopening files to re-write the contents of data.txt(mainfile)
    myfile.open("data.txt", ios::out);
    temp_file.open("temp_data.txt", ios::in);
    // making changes to the data.txt 
    if (temp_file.is_open()) {
        string line;
        while (getline(temp_file, line)) {
            string lines[6];
            stringstream ss(line);
            string word;
            int i = 0;
            while (ss >> word) {
                lines[i] = word;
                i++;
            }
            if (cho == 0)
            {
                if (lines[0] == current_acc[0])
                {
                    myfile << current_acc[0] << " " << current_acc[1] << " " << current_acc[2] << " " << current_acc[3] << " " << current_acc[4] << " " << current_acc[5] << endl;
                    continue;
                }
            }
            else if (cho == 1)
            {
                if (lines[0] == transfer_acc[0])
                {
                    myfile << transfer_acc[0] << " " << transfer_acc[1] << " " << transfer_acc[2] << " " << transfer_acc[3] << " " << transfer_acc[4] << " " << transfer_acc[5] << endl;
                    continue;
                }
            }

            myfile << lines[0] << " " << lines[1] << " " << lines[2] << " " << lines[3] << " " << lines[4] << " " << lines[5] << endl;
        }
        myfile.close();
        temp_file.close();
    }
}


// function to rewrite changes made to file (user_data.txt)
void write_changes_user_data(string arr[]) {
    fstream main_file; // main file data to read from
    fstream tempfile; // template file


    // copying data from user_data.txt to template file 
    main_file.open("user_data.txt", ios::in); 
    tempfile.open("tem_data.txt", ios::out);
    if (main_file.is_open() && tempfile.is_open())
    {
        string line;
        while (getline(main_file, line))
        {
            tempfile << line << endl;
        }
        tempfile.close();
        main_file.close();
    }

    main_file.open("user_data.txt", ios::out); // file rewritten - main_file_here
    tempfile.open("tem_data.txt", ios::in); // template file

    if (tempfile.is_open() && main_file.is_open())
    {
        string line;
        while (getline(tempfile, line))
        {
            string linesss[5];
            stringstream ss(line);
            string word;
            int i = 0;
            while (ss >> word)
            {
                linesss[i] = word;
                i++;
            } // if condition true then write changed line and continue to next loop
            if (linesss[0] == arr[0]) {
                main_file << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << endl;
                continue;
            }
            main_file << linesss[0] << " " << linesss[1] << " " << linesss[2] << " " << linesss[3] << " " << linesss[4] << endl;
        }
    }
    main_file.close();
    tempfile.close();

}


//function should have changed the passwords of current account and rewrite to the files("data.txt","user_data.txt")
void change_password(string log_name, string new_password, int cho = 0)
{
    string array_data[5];
    fstream user_data, filename;
    user_data.open("user_data.txt", ios::in);
    filename.open("data.txt", ios::in);
    if (user_data.is_open() && filename.is_open())
    {
        string line;
        while (getline(user_data, line))
        {
            stringstream ss(line);
            string word;
            int i = 0;
            while (ss >> word)
            {
                array_data[i] = word;
                i++;
            }
            if (array_data[0] == log_name)
            {
                array_data[1] = new_password;
                write_changes_user_data(array_data);
                if (cho == 0)
                {
                    current_acc[1] = new_password;
                    write_changes(0);
                    cout << "Your password has been changed" << endl;
                }
                else
                {
                    string line_2;
                    while (getline(filename, line_2))
                    {
                        login_name(line_2);
                        if (current_acc[0] == array_data[0])
                        {
                            current_acc[1] = new_password;
                            write_changes(0);
                            cout << "Your password has been changed" << endl;
                        }
                    }
                }

            }

            break;


        }
    }
    user_data.close();
    filename.close();
}

//Withdraw money from account's wallet and write changes to data.txt
int withdraw(int with, int cur = 2) {
    string i = current_acc[cur];
    stringstream geek(i);
    int bal;
    geek >> bal;
    if (bal >= 250) {
        if (bal >= with) {
            bal = bal - with;
            cout << with << " withdrawn from your account. Your current balance on this wallet is " << bal << endl;
            string ball = to_string(bal);
            current_acc[cur] = ball;
            write_changes(0);
            return 1;
        }
        else {
            cout << "Sorry :( You don't have enough money to withdraw - 1" << endl;
        }
    }
    else {
        cout << "Sorry :( You don't have enough money to withdraw - 2 or your balance is less than wintdrawing limit" << endl;
    }
    return 0;
}


// to convert from string to int given string and return integer value
int convert_from_str_to_int(string c) {

    int b;
    stringstream geek(c);
    geek >> b;
    return b;
}


//Balance - shows current balance of a user
int balance(int cho = 0) {
    if (cho == 0) {
        cout << "        Your wallet balances:     ------   " << current_acc[2] << "$     --------" << endl;
        cout << "                                  ------   " << current_acc[3] << "€ --------" << endl;
        cout << "                                  ------   " << current_acc[4] << "UZS  --------" << endl;
        cout << "                                  ------   " << current_acc[5] << "₽   --------" << endl;

    }
    return 0;
}


//Deposit money to currrent logged account and write changes to the file(data.txt)
void deposit(int cho = 0, int cur = 2, int money = 0)
{
        string a;
    int b, summ;
    if (cho == 0)
    {
        a = current_acc[cur];
        stringstream geek(a);
        geek >> b;
        summ = b + money;
    }
    else if (cho == 1)
    {
        a = transfer_acc[cur];
        stringstream geek(a);
        geek >> b;
        summ = b + money;
    }

    // for choice dopisiting values 
    if (cho == 0)
    {
        current_acc[cur] = to_string(summ);
        balance();
        write_changes();
    }
    else
    {
        transfer_acc[cur] = to_string(summ);
        write_changes(1);
    }

}


// checks whether a new given account name exist in file(data.txt) or not
// if yes returns 0 else 1
int new_account_check(string name) {
    fstream myfile;
    myfile.open("data.txt", ios::in);
    if (myfile.is_open()) {
        string line;
        while (getline(myfile, line)) {
            login_name(line);
            if (current_acc[0] == name) {
                return 0;
            }
        }
    }
    return 1;
}


//INhas contract payment with 5% cashback only in our bank
void inha_contract_pay() {
    

    float amount; string cond; //declaring a variable via operator float 
     const int SIZE = 7; // Maximum size for the c-string
    char id[SIZE];   // to hold id c-string.
    int length;
    cout << "*** Welcome to wonderful program where you can pay IUTs contract with magic 5% cashback***\n";
    cout << "Please enter id number = U"; 
    cin >> id; //putting stream insertion operator to accept input 
    length=strlen(id);
    while(length!=7){
        cout<<"Id number have to consist 7 numbers!! "<<endl;
        cin>>id;//putting stream insertion operator to accept input 
        length=strlen(id);
    }
    cout << " * How much money you want to pay ? (limit: 750$-3000$) = ";
    cin >> amount;
    if (amount >= 750 && amount <= 3000)//using conditianl statement if to declare condition in which amount should be between 750 and 3000$
    {//condition for amount of money
        cout << " Account id: " << id << endl;
        cout << " Amount of money you want to pay ? " << amount << endl;
        cout << " * Is everything correct(Yes/No) = "; cin >> cond;//putting stream insertion operator to accept input 

        if (cond == "Yes" || cond == "yes" || cond == "Y" || cond == "y") {
            int cashback;//declaring a variable via operator int
            cashback = amount * 0.05; //formula to calculate our 5% cashback
            cout << " *** You have succesfully paid :)) *** \n";
            cout << " *** You have received " << cashback << "$ as a cashback to your balance *** \n";
            if(withdraw(amount,2)){
                deposit(0, 2, cashback); //will go to out dollar wallet 
            }else {
                logged_in(); //will go to our main menu
            }
            
        }
        else cout << " *** Unfortunately payment is cancelled :( ***\n"; //if some errors using else statement to show different output if the condition is not met
    }
}//if some errors using else statement to show different output if the condition is not met


// Function which manages adding a new account to files(data.txt,user_data.txt)
int add_account() {
    
    string name, pas2;
    const int SIZE = 12; // Maximum size for the c-string
    char pass[SIZE];   // to hold password c-string.
    int length;

    do {
        cout << " *****************   Creating new account  ****************" << endl;
        cout << "Account Name: -> ";
        cin >> name;
        cout << "Password -> ";
        cin >> pass;
        length = strlen(pass);
        while (length < 6 || length > 10)
        {
            cout << "Error: password is not between 6 and " << (SIZE - 2) << " characters long.\n" << "Enter the password again: ";
            cin >> pass;
            length = strlen(pass);
        }
        cout << "Please retype password -> ";
        cin >> pas2;
        if (pass == pas2) {
            if (new_account_check(name)) {  // existing account check
                fstream filename_1, filename_2;
                filename_1.open("data.txt", ios::app);
                filename_2.open("user_data.txt", ios::app);
                if (filename_1.is_open()) {
                    string first_name, second_name, phone_number;
                    cout << "We want to store more information about you to help you manage your account later" << endl << "1. Enter your First name: ";
                    cin >> first_name;
                    cout << "2. Enter second name: ";
                    cin >> second_name;
                    cout << "3. Enter your phone number" << "(note that when typing your number exclude + sign on the beginning, only numbers ----> ";
                    cin >> phone_number;
                    // writing to data.txt
                    filename_1 << name << " " << pass << " " << "0" << " " << "0" << " " << "0" << " " << "0" << endl;
                    filename_1.close();//closing
                    //writing to user_data.txt
                    filename_2 << name << " " << pass << " " << first_name << " " << second_name << " " << phone_number << endl;
                    filename_2.close();//closing 
                    system("clear");
                    cout << "Your account has benn succesfully added to system :)" << endl;
                    system("clear");
                    main();
                }
            }
            else {
                cout << "This account name exists in system. Please choose another name!" << endl;
                add_account();
            }
        }
        else {
            cout << "Paswords do not match each other!!! " << endl << "Retype again or exit" << endl;
            add_account();
        }
    } while (pass != pas2);
    return 0;
}




// function to transfer money from one of the currenct user's wallets to another accounts wallet 
int transfer_money() {

    // checking transferring accounts existense and assigning values of it to a array transfer_acc[6]
    fstream myfile; 
    myfile.open("data.txt", ios::in); // file to be read in order to check existence of transfering account
    // checking account existence in system 
    if (myfile.is_open())
    {
        int n = 0;  
        // if n= 0 account is not data.txt, 
        //otherwise(n= 1) it exists so loop will be repeated untill user will provide actual user_name
        do
        {
            string tr_acc;
            cout << "To which Account you want to transfer money: ";
            cin >> tr_acc;
            string line;
            while (getline(myfile, line)) 
            {
                stringstream ss(line);
                string word;
                int i = 0;
                while (ss >> word) 
                {
                    transfer_acc[i] = word;
                    i++;
                }
                if (transfer_acc[0] == tr_acc) 
                {
                    n = 1; 
                    break;
                }
            }
            if (n == 0) 
            {
                cout << "There is no account match to transfer with this name..... Please try again !" << endl;
            }
        } while (n == 0);
    }

    // getting wallet type and amount of money to be used
    int money; // amount of money should be transfered
    int type; // type of wallet 
    cout << "Please choose your wallet for specific currency transfer should be done: " << endl;
    cout << "1: Dollar - ($)" << endl << "2: Euro - (€)" << endl << "3. Uzbek Som ---> UZS() " << endl << "4: Russian Ruble ---> RB(₽)  " << endl << "5: Exit --------- \n";
    cin >> type;
    // Printing the choice of user ---- wallet choice
    switch (type)
    {
    case 1: cout << "You have chosen Dollar - ($) wallet" << endl << endl;
        break;
    case 2: cout << "You have chosen Euro - (€) wallet" << endl << endl;
        break;
    case 3: cout << "You have chosen Uzbek Som ---> UZS() wallet" << endl << endl;
        break;
    case 4: cout << "You have chosen Rubl - () wallet" << endl << endl;
        break;
    case 5: return 0;
    default: cout << "Please choose one from above" << endl;
        break;
    }
    //getting amount 
    cout << "What is the amount of money you want to transfer: ";
    cin >> money;
    //checking balance of the user, if it is below 250 or asked amount is higher than actual balance, statement will be executed
    if (money > (convert_from_str_to_int(current_acc[type + 1]) - 250) || money < 0) {
        cout << "Sorry it seems the amount of money YOU are transferring is higher than your WALLET BALANCE!!!" << endl << endl;
        logged_in();
    }

    // all actions go here --- after all checks 
    switch (type) {
        // dollar wallet
    case 1:  withdraw(money);
        deposit(1, 2, money); /// deposit(1,2,money ) -- 1 - transfer_acc[]   2 - transfer_acc[2] 
        logged_in();           // deposit(0,2,money) --- 0 - current_acc[]    2 - current_acc[2]
        break;
        // euro wallet
    case 2: withdraw(money, 3);
        deposit(1, 3, money);
        logged_in();
        break;
        //som, UZS wallet
    case 3: withdraw(money, 4);
        deposit(1, 4, money);
        logged_in();
        break;
        // Rub wallet
    case 4: withdraw(money, 5);
        deposit(1, 5, money);
        logged_in();
        break;
    case 5: return 0;
    default: return 0;
        break;
    }
    return 0;
}

//function to change currect account's password
int changes_cur_pass()
{
    
    cout << "CHANGING PASSWORD OF CURRENT ACCOUNT -- MENU" << endl;
    string old_pass;
    char new_pass[12];
    int length;
    // chechking user input for password correctness
    // if input is "exit", function stops and returns 0
    do
    {
        if (old_pass == "exit" || old_pass == "EXIT" || old_pass == "Exit")
        {
            return 0;
        }
        cout << "Enter your current password(enter exit to get back): ";
        cin >> old_pass;
    } while (old_pass != current_acc[1]);
    // getting input of a new account and checking it length
    do
    {
        cout << "New password: ";
        cin >> new_pass;
        length = strlen(new_pass);
    } while (length < 6);
    //rewrite files with a new password
    change_password(current_acc[0], new_pass, 0);
    return 0;
}


// This fucntion opens - The window after succesfull login happens
// MAIN MENU
int logged_in() {
   // printing menu 
    cout << " ACCOUNT NAME ----- " << current_acc[0] << " --------" << endl << endl;
    cout << "         >>>>>>>>>>>>>>>>>>>>>>>>>>>>>Our MENU(operations):<<<<<<<<<<<<<<<<<<<<\n";
    cout << "         (✷‿✷)                  1. Balance                                (✷‿✷)" << endl;
    cout << "         (✷‿✷)                  2. Withdraw                               (✷‿✷)" << endl;
    cout << "         (✷‿✷)                  3. Deposit                                (✷‿✷)" << endl;
    cout << "         (✷‿✷)                  4. Transfer money                         (✷‿✷)" << endl;
    cout << "         (✷‿✷)                  5. Daily exchange rates                   (✷‿✷)" << endl;
    cout << "         (✷‿✷)                  6. Converting money into other currencies (✷‿✷)" << endl;
    cout << "         (✷‿✷)                  7. Pay to inha contract (5% cashback)     (✷‿✷)" << endl;
    cout << "         (✷‿✷)                  8. Change password of current account     (✷‿✷)" << endl;
    cout << "         (✷‿✷)                  9. Exit (may need to give feedback)       (✷‿✷)" << endl;
    cout << "         >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n ";
    cout << "                         ****Please choose any option from menu****          \n";
    int choice;
    string exit_choice;
    string tr_acc; //transfer account's name
    cin >> choice;

    // switch case based on user's input ( note used should always input numbers not string or char or any other data type)
    switch (choice) {
    case 1:     system("clear"); // clear terminal 
            balance(0); // show balance 
            logged_in();
            break;
    case 2: int money, wallet_type;
        cout << "Please, choose one of your wallets below   " << endl;
        cout << "1: Dollar ---> USD($)" << endl << "2: Euro ---> (€)" << endl << "3. Uzbek Som ---> UZS()" << endl << "4: Russian Ruble ---> RB(₽) " << endl << "5: Exit --------- ";
        cin >> wallet_type;
        if ( wallet_type <= 5 && wallet_type >= 1)
        {
            if (wallet_type == 5) 
            {
                logged_in();
            }
            cout << "Type amount of money you wanna withdraw from your account: ";
            cin >> money;
            if(money > 0) 
            {
            withdraw(money, wallet_type + 1);
            }
        }
        logged_in();
        break;
    case 3: cout << "Please, choose one of your wallets below   " << endl;
        cout << "1: Dollar" << endl << "2: Euro - (€)" << endl << "3. Uzbek Som ---> UZS() " << endl << "4: Russian Ruble ---> RB(₽) \n" << "5: Back to menu----> " << endl;
        cin >> wallet_type;
        if ( wallet_type >= 1 && wallet_type <= 5)
        {
            if (wallet_type == 5)
            {
                logged_in();
            }
            int moneydeposit;
            cout << "How much you want to deposit : ";
            cin >> moneydeposit;
            if(moneydeposit>0) 
            {
                deposit(0, wallet_type + 1, moneydeposit);
            }
        }
        
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


    case 8:
        //For Macos Users its system("clear") 
        system("clear");
        changes_cur_pass();
        system("clear");
        cout << " Your password has been succesfully changed " << endl << endl;
        logged_in();
        break;


    case 9:
        cout << "Please, Provide feedback before you leave, It will help us to improve our services :))" << endl << endl;
        cout << "Type 1 to give feedback or Type anything to exit from your account ----> ";
        cin >> exit_choice;
        if (exit_choice == "1") {
            feedback();
            cout << "Our team appreciate your feedback" << endl;
        }else{
            for(int j = 0; j < 100; j++){    
                cout << "                   Thanks for choosing us 🙂 👋                    " << endl;
            }
            system("clear");
            main();
        }
        
        //system.pause();
        break;
    case 7: inha_contract_pay();
        logged_in();
        break;
    default:cout << "Our team is working on this, please wait" << endl;
        logged_in();
        break;

    }
    return 0;
}


// function to reset password of a user
void reset()
{   /*function checks whether four inputs taken from 
    user exists and correspond with each other in user_data.txt*/    

    system("clear");
    string log_name, first_name, second_name, phone;
    const int SIZE = 12; // Maximum size for the c-string   // to hold password c-string.
    char password[SIZE];
    string array_data[5]; // array to store particular user's data from user_data.txt
    cout << "1. Enter user login name for which you want to reset the password: ";
    cin >> log_name;
    cout << "2. Enter your first name: " << endl;
    cin >> first_name;
    cout << "3. Enter your second name: " << endl;
    cin >> second_name;
    cout << "4. Enter your phone number: " << endl;
    cin >> phone;

    fstream user_data, filename;

    user_data.open("user_data.txt", ios::in); // 
    filename.open("data.txt", ios::in); // 
    if (user_data.is_open())
    {
        string line;
        // looping throught each line of user_data.txt
        while (getline(user_data, line)) {
            stringstream ss(line);
            string word;
            int i = 0;
            while (ss >> word) {
                array_data[i] = word;
                i++;
            } // if inputs correspond with user_data.txt then reset will be allowed
            if (array_data[0] == log_name && array_data[2] == first_name && array_data[3] == second_name && array_data[4] == phone) {
                cout << "Resetting your password" << endl;
                cout << "New password for your account: " << endl;
                cin >> password;
                int length;
                length = strlen(password);
                //checking length of new password
                while (length <= 6 || length >= 10)
                {
                    cout << "Error: password is not between 6 and " << (SIZE - 2) << " characters long.\n" << "Enter the password again: ";
                    cin >> password;
                    length = strlen(password);
                }
                //then new password is rewritten to files
                array_data[1] = password;
                write_changes_user_data(array_data);
                string line_2;
                while (getline(filename, line_2))
                {
                    login_name(line_2);
                    if (current_acc[0] == array_data[0])
                    {

                        current_acc[1] = password;
                        write_changes(0);
                        main();
                        break;
                    }
                }
                break;

            }
        }
    }
    user_data.close();
}


// login checking function
int login() {


    int i = 0; // checking wrong input times
    // if inputs are wroong three times then user will be given a way to reset the password   

    while (1)
    {
        fstream myfile;
        myfile.open("data.txt", ios::in);

        string name, password;

        if (i >= 3)
        {
            cout << "It seems you forgot your password or username. -- If you want to reset your password, please write RESET or reset" << endl;
        }
        cout << "The login name : ";
        cin >> name;
        if ((name == "reset" || password == "reset" || name == "RESET" || name == "Reset") && i >= 3)
        {
            cout << "You have been redirected to reset password tool !!!!" << endl << endl;
            reset();
        }
        cout << "The password : ";
        cin >> password;

        if ((name == "reset" || password == "reset") && i >= 3) {
            cout << "You have been redirected to password reset tool !!!!" << endl << endl;
            reset();
        }
        /*system("clear");*/
        // where the file is read and login is checked
        string line;
        while (getline(myfile, line))
        {   
            login_name(line);
            //if login_name and it's corresponding passwords are found in data.txt then MAIN MENU(logged_in()) will appear
            if (current_acc[0] == name && current_acc[1] == password)
            {
                cout << current_acc[0] << " ->-> 🥳 Congratulations 🥳! You have succesfully logged to your account <-<- " << endl;
                logged_in();
                system("clear");
                main();
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
    cout << " These exchange rates only for today, it is changing on a daily basis 🤩🤩🤩 \n";


}




//Conversion proggram
void converting() {
    
    string currency, currency2;
    double value, value2; //declaring a variable via operator double
    
    cout << "<<<<<<<<<<<<< Welcome to our conversion programm, we are over the moon to see you here :)) >>>>>>>>>>>>>>>>>>\n";
    cout << "*****************************Which currency would you like to convert?***************************************\n";
    
    cout << "                           (We have 4 different options: Rub, Sum, Dollars, Euro)                            \n ";

    cin>> currency;
    cout << "To which currency you would like to convert to?\n";
    cin >> currency2;
    cout << "How much money you wanna convert?\n";
    cin >> value;
    
     
   //using conditianl statement if to declare our condition 
   /* using a nested loop  in which one loop resides inside another loop where the inner loop gets executed 
   first, satisfying all the set of conditions that prevailed within the loop followed by an outer 
   loop set of conditions.*/
    if (currency == "Dollar" || currency == "dollar" || currency == "USD") {
        if (currency2 == "Rub" || currency2 == "rub") {
            value2 = value * 74.77;        //formula to calculate 
            cout << value << "$ is equal to " << value2 << " rub " << "\n";//output
        }
        else if (currency2 == "Sum" || currency2 == "sum") {
            value2 = value * 9800;//formula to calculate 
            cout << value << "$ is equal to " << value2 << " sum" << "\n";

        }
        else if (currency2 == "Euro" || currency2 == "euro") {
            value2 = value * 1;//formula to calculate 
            cout << value << "$ is equal to " << value2 << " euros " << "\n";

        }
    }
    else if (currency == "Rub" || currency == "rub") {
        if (currency2 == "Dollar" || currency2 == "dollar" || currency2 == "USD") {
            value2 = value * 0.013;//formula to calculate 
            cout << value << " rubs is equal to " << value2 << " dollars" << "\n";
        }
        else if (currency2 == "Sum" || currency2 == "sum") {
            value2 = value * 144.37;//formula to calculate 

            cout << value << " rubs is equal to " << value2 << " sums" << "\n";
        }
        else if (currency2 == "Euro" || currency2 == "euro") {
            value2 = value * 0.012;//formula to calculate 
            cout << value << "rubs is equal to " << value2 << " euros" << "\n";
        }
    }
    else if (currency == "euro" || currency == "Euro") {
        if (currency2 == "Dollar" || currency2 == "dollar" || currency2 == "USD") {
            value2 = value * 1.12;
            cout << value << " euros is equal to " << value2 << " dollars" << "\n";
        }
        else if (currency2 == "Rub" || currency2 == "rub") {
            value2 = value * 84.02;
            cout << value << " euros is equal to " << value2 << " rubs" << "\n";
        }
        else if (currency2 == "Sum" || currency2 == "sum") {

            value2 = value * 1.46;//formula to calculate 

            cout << value << " euros is equal to " << value2 << " sums" << "\n";

        }
    }
    else if (currency == "Sum" || currency == "sum") {
        if (currency2 == "Dollar" || currency2 == "dollar" || currency2 == "USD") {
            value2 = value * 0.009;
            cout << value << "sums is equal to " << value2 << "dollars" << "\n";
        }
        else if (currency2 == "Euro" || currency2 == "euro") {
            value2 = value * 0.67;
            cout << value << " sums is equal to " << value2 << " euros" << "\n";

        }
        else if (currency2 == "Rub" || currency2 == "rub") {
            value2 = value * 9805;
            cout << value << " sums is equal to " << value2 << " rubs" << "\n";

        }

    }
    else {

        cout << "Unfortunately you have mistaken, check spelling. Try again please";

    }
}


//function to get feedback from user and store it to feedbacl.txt file
void feedback()
{
   
    string response;
    getline(cin, response); /*The getline function takes an input stream and a string as parameters 
    and reads a line of text from the stream into the string.*/
    cout << "Dear clients we need your feedback in order to improve the quality of our services\n ";
    cout << "Please write your feedback there =>> \n";
    getline(cin, response);  // takes input from the user and places it into the string
    fstream myfile;
    myfile.open("feedback.txt", ios::app);
    if (myfile.is_open()) {
        myfile << current_acc[0] << " ";  //opening  and saving our feedback in data txt
        myfile << response;
        myfile << endl;
    }
    myfile.close();
    cout << "Your feedback was: " << response << endl;

}
