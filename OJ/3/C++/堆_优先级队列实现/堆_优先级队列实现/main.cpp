#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//bool cmp(int a, int b);
struct cmp{
	bool operator()(const int &a, const int &b){
		return a>b;
	}
};


int main(){
	priority_queue<int> arrb;//大顶堆
	priority_queue<int, vector<int>, cmp> arrs;//小顶堆

	vector<int> result;
	int nums = 1;//初始小根堆有1个元素
	int numb = 0;
	int temp;
	//------压入第一个元素，此时为中位数-------
	cin >> temp;
	arrs.push(temp);
	result.push_back(temp);
	//cout << temp << " ";
	//cout << arrs[0] << " ";
	//-----------------------------------------
	while (cin >> temp){
		if (temp >= arrs.top()){//大于等于，则压入小根堆
			arrs.push(temp);
			nums++;
		}
		else{
			arrb.push(temp);//小于等于，则压入大根堆
			numb++;
		}
		if (numb >= nums){//大根堆元素大于等于一半
			temp = arrb.top();
			arrb.pop();
			arrs.push(temp);
			nums++;
			numb--;
		}
		else if (numb < nums - 2){//小根堆元素过多
			temp = arrs.top();
			arrs.pop();
			arrb.push(temp);
			nums--;
			numb++;
		}
		result.push_back(arrs.top());
		//cout << arrs.top() << " ";
	}
	for (int i = 0; i < nums + numb; ++i){
		cout << result[i] << " ";
	}
	return 0;
}


/*bool cmp(int a, int b){
	return (a > b);
}*/