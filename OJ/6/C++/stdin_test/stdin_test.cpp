#include<iostream>
#include<string>
#include<sstream>
using namespace std;


int main(){
    string str;
    int num;
    
    while(getline(cin, str)){
        cout << str << endl;
        stringstream ss;
        ss << str;
        while(ss >> num){
            cout << num << endl;
        }
        cout << str << endl;
    }
}