#include <iostream>
using namespace std;

int main()
{
    int num, minus=0,result=0;
    char op;
    while(1){
        cin>>num;
        if(!minus) result+=num;
        else result+=-num;
        op=cin.get();
        if(op=='\n') break;
        if(op=='-') minus=1;
    }
    cout<<result<<endl;
}

