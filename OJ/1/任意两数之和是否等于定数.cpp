#include <iostream>
using namespace std;


int main(){
    int n, c;
    int* arr = new int[n];
    cin >> n;
    for(int i = 0; i < n; ++i)  cin >> arr[i];
    cin >> c;
    for(int i = 0; i < n; ++i){
        if(arr[i] > c)  break;
        for(int j = i + 1; j < n; ++j){
            if(arr[i] + arr[j] == c){
                cout << arr[i] << " " << arr[j] << endl;
            }
            else if(arr[i] + arr[j] > c)    break;
        }
    }
    //system("pause");
    return 0;
}