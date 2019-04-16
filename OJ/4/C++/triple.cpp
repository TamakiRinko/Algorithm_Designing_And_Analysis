#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, sum;
    cin >> n >> sum;
    int* arr = new int[n];
    for(int i = 0; i < n; ++i)  cin >> arr[i];
    sort(arr, arr + n);

    int two = 0;//两数之和
    int num = 0;//三元组个数
    for(int i = 0; i < n; ++i){
        two = sum - arr[i];//遍历数组，先固定一个元素，转换为二元组个数
        int p = 0, q = n - 1;
        //for(p = 0, q = n - 1; p < q; ++p, --q){
        while(p < q){
            if(p == i)  p++;//避开i
            if(q == i)  q--;//避开i
            if(p >= q)   break;
            int temp = arr[p] + arr[q];
            if(temp == two){
                num++;
                p++;
                q--;
            }
            else if(temp < two){
                p++;
            }
            else{
                q--;
            }
        }
    }
    cout << num / 3 << endl;//结果计算了3次
    //system("pause");
    return 0;
}