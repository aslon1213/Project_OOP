#include <iostream>
using namespace std;
int bal;
int main();
int balance(){
int bal;
bal=0;
cout<<"Your balance is: "<<bal<<endl;
main();
return bal;
}
int withdraw(){
    int with,result;
    
    if(::bal<500){
        cout<<"You don't have enough money to withdraw!"<<endl;
    }
    else if(bal>=500){
    cout<<"Enter how much you want to withdraw: "<<endl;
    cin>>with;
   result=::bal-with;
   cout<<with<<" withdrawn from your balance. Your current balance is "<<result<<endl;
    }

}
int main(){
int a;
cout<<"1.Balance Enquiry"<<endl;
cout<<"2.Withdraw Amount"<<endl;
cin>>a;

switch(a){
    case 1: balance();
    break;
    case 2: withdraw();
    break;

}
}

