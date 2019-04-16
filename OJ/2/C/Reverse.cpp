#pragma warning(disable:4996)
#include<iostream>
#include<cstring>

using namespace std;

void Merge(char str[][11], int begin, int mid, int end);
void Merge_sort(char str[][11], int begin, int end);

char str[10000000][11];
char str_left[10000000][11];
char str_right[10000000][11];

long long num = 0;
long long sum = 0;

int main(){
	cin >> num;
	for (int i = 0; i < num; ++i){
		scanf("%s", str[i]);
	}
	/*for(int i = 0; i < num; ++i){
	printf("%s ", str[i]);
	}
	printf("%s ", str[0]);*/
	Merge_sort(str, 0, num - 1);
	printf("wo yi yue du guan yu chao xi de shuo ming\n");
	cout << sum << "\n";
}

void Merge_sort(char str[][11], int begin, int end){
	if (begin < end){
		int mid = (begin + end) / 2;
		Merge_sort(str, begin, mid);
		Merge_sort(str, mid + 1, end);
		Merge(str, begin, mid, end);
	}
}

void Merge(char str[][11], int begin, int mid, int end){
	//printf("%s ", str[0]);
	for (int i = 0; i < mid - begin + 1; ++i){
		//printf("%s ", str[0]);
		//printf("%s ", str[begin + i]);
		strcpy(str_left[i], str[begin + i]);
	}
	for (int j = 0; j < end - mid; ++j){
		strcpy(str_right[j], str[mid + j + 1]);
	}
	strcpy(str_left[mid - begin + 1], "zzzzzzzzzz");
	strcpy(str_right[end - mid], "zzzzzzzzzz");
	int m = 0, n = 0;
	for (int t = begin; t <= end; ++t){
		if (strcmp(str_left[m], str_right[n]) <= 0){
			if (m == mid - begin + 1){//左边数组到达末尾 
				strcpy(str[t], str_right[n]);
				n++;
			}
			else{
				strcpy(str[t], str_left[m]);
				m++;
			}
		}
		else{
			sum += (mid - m - begin + 1);
			strcpy(str[t], str_right[n]);
			n++;
		}
	}
}