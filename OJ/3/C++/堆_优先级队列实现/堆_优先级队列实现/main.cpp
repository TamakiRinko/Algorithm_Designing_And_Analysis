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
	priority_queue<int> arrb;//�󶥶�
	priority_queue<int, vector<int>, cmp> arrs;//С����

	vector<int> result;
	int nums = 1;//��ʼС������1��Ԫ��
	int numb = 0;
	int temp;
	//------ѹ���һ��Ԫ�أ���ʱΪ��λ��-------
	cin >> temp;
	arrs.push(temp);
	result.push_back(temp);
	//cout << temp << " ";
	//cout << arrs[0] << " ";
	//-----------------------------------------
	while (cin >> temp){
		if (temp >= arrs.top()){//���ڵ��ڣ���ѹ��С����
			arrs.push(temp);
			nums++;
		}
		else{
			arrb.push(temp);//С�ڵ��ڣ���ѹ������
			numb++;
		}
		if (numb >= nums){//�����Ԫ�ش��ڵ���һ��
			temp = arrb.top();
			arrb.pop();
			arrs.push(temp);
			nums++;
			numb--;
		}
		else if (numb < nums - 2){//С����Ԫ�ع���
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