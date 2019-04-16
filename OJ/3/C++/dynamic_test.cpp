#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b);


int main(){
	vector<int> arrs;//small ��0�6????????????
	vector<int> arrb;//big ?????????????
	vector<int> result;
	int nums = 1;//???��0�6??????1?????
	int numb = 0;
	int temp;
	make_heap(arrb.begin(), arrb.end());
	//------?????????????????�0�7�0�9??-------
	cin >> temp;
	arrs.push_back(temp);
	make_heap(arrs.begin(), arrs.end(), cmp);
	result.push_back(temp);
	//cout << arrs[0] << " ";
	//-----------------------------------------
	for(int i = 0; i < 10; ++i){
		cin >> temp;
		if (temp >= arrs[0]){//?????????????��0�6????
			arrs.push_back(temp);
			push_heap(arrs.begin(), arrs.end(), cmp);
			nums++;
		}
		else{
			arrb.push_back(temp);//��0�6???????????????
			push_heap(arrb.begin(), arrb.end());
			numb++;
		}
		if (numb >= nums){//?????????????????
			pop_heap(arrb.begin(), arrb.end());
			temp = arrb.back();
			arrs.push_back(temp);
			push_heap(arrs.begin(), arrs.end(), cmp);
			nums++;
			numb--;
			arrb.pop_back();
		}
		else if (numb < nums - 2){//��0�6??????????
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
	cout << nums + numb << endl;
	for(int i = 0; i < nums + numb; ++i){
		cout << result[i] << " ";
	}
	system("pause");
	return 0;
}


bool cmp(int a, int b){
	return (a > b);
}
