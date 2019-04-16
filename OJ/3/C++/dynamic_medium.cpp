#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b);


int main(){
	vector<int> arrs;//small 小根堆，存放后一半
	vector<int> arrb;//big 大根堆，存放前一半
	vector<int> result;
	int nums = 1;//初始小根堆有1个元素
	int numb = 0;
	int temp;
	make_heap(arrb.begin(), arrb.end());
	//------压入第一个元素，此时为中位数-------
	cin >> temp;
	arrs.push_back(temp);
	make_heap(arrs.begin(), arrs.end(), cmp);
	result.push_back(temp);
	//cout << arrs[0] << " ";
	//-----------------------------------------
	while (cin >> temp){
		if (temp >= arrs[0]){//大于等于，则压入小根堆
			arrs.push_back(temp);
			push_heap(arrs.begin(), arrs.end(), cmp);
			nums++;
		}
		else{
			arrb.push_back(temp);//小于等于，则压入大根堆
			push_heap(arrb.begin(), arrb.end());
			numb++;
		}
		if (numb >= nums){//大根堆元素大于等于一半
			pop_heap(arrb.begin(), arrb.end());
			temp = arrb.back();
			arrs.push_back(temp);
			push_heap(arrs.begin(), arrs.end(), cmp);
			nums++;
			numb--;
			arrb.pop_back();
		}
		else if (numb < nums - 2){//小根堆元素过多
			pop_heap(arrs.begin(), arrs.end(), cmp);
			temp = arrs.back();
			arrb.push_back(temp);
			push_heap(arrb.begin(), arrb.end());
			nums--;
			numb++;
			arrs.pop_back();
		}
		result.push_back(arrs[0]);
	}
	for(int i = 0; i < nums + numb; ++i){
		cout << result[i] << " ";
	}
	return 0;
}


bool cmp(int a, int b){
	return (a > b);
}