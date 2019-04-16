#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int partition(vector<string>& arr, int begin, int end);
void select_k(vector<string>& arr, int begin, int end, int k);


int main(){
    int n, k;
    cin >> n >> k;
    vector <string> arr(n);
    for(int i = 0; i < n; ++i)  cin >> arr[i];

    int mid = (n - 1) / 2;
    select_k(arr, 0, n - 1, mid + 1);
    select_k(arr, 0, mid - 1, mid - k + 1);
    select_k(arr, mid + 1, n - 1, k);

    sort(arr.begin() + mid - k, arr.begin() + mid + k);
    for(int i = 0; i < 2 * k + 1; ++i){
        cout << arr[mid - k + i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}


/*int partition(vector<string>& arr, int begin, int end){//mine
    string pivot = arr[begin];
    int pivot_pos = begin;
    string temp;//暂存交换内容
    begin++;
    while(begin < end){
        if(arr[begin] > pivot && arr[end] < pivot){
            temp = arr[begin];
            arr[begin] = arr[end];
            arr[end] = temp;
            begin++;
            end--;
        }
        else if(arr[begin] <= pivot && arr[end] >= pivot){
            begin++;
            end--;
        }
        else if(arr[begin] <= pivot){
            begin++;
        }
        else{
            end--;
        }
    }
    if(arr[begin] > pivot){
        arr[pivot_pos] = arr[begin - 1];
        arr[begin - 1] = pivot;
        return begin - 1;
    }
    arr[pivot_pos] = arr[begin];
    arr[begin] = pivot;
    return begin;
}*/

int partition(vector<string>& arr, int begin, int end){//book
    string pivot = arr[end];//最右端
    string temp;
    int i = begin - 1;
    for(int j = begin; j < end; ++j){
        if(arr[j] < pivot){//i指示比pivot小的元素的右边界
            ++i;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[end];
    arr[end] = temp;
    return i + 1;
}

void select_k(vector<string>& arr, int begin, int end, int k){
    if(begin == end)    return;
    int pivot = partition(arr, begin, end);
    int x = pivot - begin + 1;
    if(k == x)  return;
    else if(k < x){
        select_k(arr, begin, pivot - 1, k);
    }
    else{
        select_k(arr, pivot + 1, end, k - x);
    }
}