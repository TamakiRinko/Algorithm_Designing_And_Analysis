#include<iostream>  
using namespace std;

//合并a[first...mid]和b[mid...last]  
void mergearray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;

	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while (i <= m)
		temp[k++] = a[i++];

	while (j <= n)
		temp[k++] = a[j++];

	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
void mergesort(int a[], int first, int last, int temp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(a, first, mid, temp);    //左边有序
		mergesort(a, mid + 1, last, temp); //右边有序 
		mergearray(a, first, mid, last, temp); //合并两个有序的数组  
	}
}

bool MergeSort(int a[], int n)
{
	int *p = new int[n];
	if (p == NULL)
		return false;
	mergesort(a, 0, n - 1, p);
	delete[] p;
	return true;
}

int main(){
    int k, n;
    cin >> k >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    MergeSort(arr, n);
    int m = (n - 1) >> 1;
    for(int t = m - k; t < m + k; ++t){
        cout << arr[t] << " ";
    }
    cout << arr[m + k] << endl;
	system("pause");
    return 0;
}