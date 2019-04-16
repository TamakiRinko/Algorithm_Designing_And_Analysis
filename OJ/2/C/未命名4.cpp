#include<iostream>
#include<cstring>
using namespace std;

struct str2{
	char str[101];
	char str_back[101];
	void operator = (str2& a){
		strcpy(str, a.str);
		strcpy(str_back, a.str_back);
	}
};

str2 str[1000000];
str2 str_left[1000000];
str2 str_right[1000000];
char str_left_2[1000000][101];
char str_right_2[1000000][101];
char str_result[1000000][101];
char word_left[101];
char word_right[101];


void Merge_sort_word(char* word, long long begin, long long end);
void Merge_word(char* word, long long begin, long long mid, long long end);
void Merge_struct(str2* str, long long begin, long long mid, long long end);
void Merge_sort_struct(str2* str, long long begin, long long end);
void Merge(char str[][101], long long begin, long long mid, long long end);
void Merge_sort(char str[][101], long long begin, long long end);


int main(){
	long long num;
	cin >> num;
	for (long long i = 0; i < num; ++i){
		scanf("%s", str[i].str);
		strcpy(str[i].str_back, str[i].str);
	}
	Merge_sort_struct(str, 0, num - 1);
	for (long long i = 0; i < num; ++i){
		//len[i] = strlen(str[i]);
		long long len = strlen(str[i].str);
		Merge_sort_word(str[i].str, 0, len - 1);
	}
	Merge_sort_struct(str, 0, num - 1);
	long long sum = 0;
	bool flag = false;
	long long t = 0;
	for (long long i = 0; i < num - 1; ++i){
		long long whether = strcmp(str[i].str, str[i + 1].str);
		if (whether == 0 && flag == false){
			sum++;
			strcpy(str_result[t], str[i].str_back);
			flag = true;
			t++;
		}
		else if (whether != 0){
			flag = false;
		}
	}
	Merge_sort(str_result, 0, sum - 1);
	printf("wo yi yue du guan yu chao xi de shuo ming\n");
	cout << sum << endl;
	for (long long i = 0; i < sum; ++i){
		printf("%s\n", str_result[i]);
	}
	return 0;
}

void Merge_sort_word(char* word, long long begin, long long end){
	if (begin < end){
		long long mid = (begin + end) / 2;
		Merge_sort_word(word, begin, mid);
		Merge_sort_word(word, mid + 1, end);
		Merge_word(word, begin, mid, end);
	}
}

void Merge_word(char* word, long long begin, long long mid, long long end){
	for (long long i = begin; i <= mid; ++i){
		word_left[i] = word[i];
	}
	for (long long j = mid + 1; j <= end; ++j){
		word_right[j] = word[j];
	}
	long long i = begin;
	long long j = mid + 1;
	long long t = begin;
	while (i <= mid && j <= end){
		if (word_left[i] <= word_right[j]){
			word[t] = word_left[i];
			i++;
		}
		else{
			word[t] = word_right[j];
			j++;
		}
		++t;
	}
	while (i <= mid){
		word[t] = word_left[i];
		i++;
		t++;
	}
	while (j <= end){
		word[t] = word_right[j];
		j++;
		t++;
	}
}

void Merge_sort_struct(str2* str, long long begin, long long end){
	if (begin < end){
		long long mid = (begin + end) / 2;
		Merge_sort_struct(str, begin, mid);
		Merge_sort_struct(str, mid + 1, end);
		Merge_struct(str, begin, mid, end);
	}
}

void Merge_struct(str2* str, long long begin, long long mid, long long end){
	//printf("%s ", str[0]);
	for (long long i = begin; i <= mid; ++i){
		//printf("%s ", str[0]);
		//printf("%s ", str[begin + i]);
		//strcpy(str_left[i], str[i]);
		str_left[i] = str[i];
	}
	for (long long j = mid + 1; j <= end; ++j){
		//strcpy(str_right[j], str[j]);
		str_right[j] = str[j];
	}
	long long m = begin;
	long long n = mid + 1;
	long long t = begin;
	while (m <= mid && n <= end){
		if (strcmp(str_left[m].str, str_right[n].str) <= 0){
			//strcpy(str[t], str_left[m]);
			str[t] = str_left[m];
			m++;
		}
		else{
			//strcpy(str[t], str_right[n]);
			str[t] = str_right[n];
			n++;
		}
		t++;
	}
	while (m <= mid){
		//strcpy(str[t], str_left[m]);
		str[t] = str_left[m];
		m++;
		t++;
	}
	while (n <= end){
		//strcpy(str[t], str_right[n]);
		str[t] = str_right[n];
		n++;
		t++;
	}
}


void Merge_sort(char str[][101], long long begin, long long end){
	if (begin < end){
		long long mid = (begin + end) / 2;
		Merge_sort(str, begin, mid);
		Merge_sort(str, mid + 1, end);
		Merge(str, begin, mid, end);
	}
}

void Merge(char str3[][101], long long begin, long long mid, long long end){
	//printf("%s ", str[0]);
	for (long long i = begin; i <= mid; ++i){
		//printf("%s ", str[0]);
		//printf("%s ", str[begin + i]);
		strcpy(str_left_2[i], str3[i]);
	}
	for (long long j = mid + 1; j <= end; ++j){
		strcpy(str_right_2[j], str3[j]);
	}
	long long m = begin;
	long long n = mid + 1;
	long long t = begin;
	while (m <= mid && n <= end){
		if (strcmp(str_left_2[m], str_right_2[n]) <= 0){
			strcpy(str3[t], str_left_2[m]);
			m++;
		}
		else{
			strcpy(str3[t], str_right_2[n]);
			n++;
		}
		t++;
	}
	while (m <= mid){
		strcpy(str3[t], str_left_2[m]);
		m++;
		t++;
	}
	while (n <= end){
		strcpy(str3[t], str_right_2[n]);
		n++;
		t++;
	}
}
