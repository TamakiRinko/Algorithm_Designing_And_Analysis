#include<iostream>
#include<utility>
#include<string>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//void func1();

/*int main(){
    func1();
    system("pause");
}*/


/*
由于pair类型的使用比较繁琐，因为如果要定义多个形同的pair类型的时候，可以时候typedef简化声明：
typedef pair<string, string> author;
author pro("May", "Lily");
author joye("James", "Joyce");
*/


/*
void func1(){
    pair<string, string> str1("hahaha", "sdsdsd");
    pair<string, string> str2 = str1;
    str1 = make_pair("qwe", "zxc");
    cout << str1.first << "  " << str1.second << endl;
    cout << str2.first << "  " << str2.second << endl;
    str2.swap(str1);//交换两个值
    cout << str1.first << "  " << str1.second << endl;
    cout << str2.first << "  " << str2.second << endl;
}
*/



bool cmp(pair<string, string>& a, pair<string, string>& b){//升序
	return (a.first < b.first);
}

/*
bool cmp2(vector<string>& a, vector<string>& b){
	return a.
}
*/


int main(){
	long long num;
	cin >> num;
    vector<string> strin(num);//暂存输入
	vector< pair<string, string> > str;//前后两个名称
	//string* str = new string(num);//编译不过
	for (long long i = 0; i < num; ++i){
		cin >> strin[i];//类似数组，用下标寻址
		//vector也可用类似于栈的方式进行push, pop
		//pair<T1,T2> make_pair (T1 x, T2 y)
		str.push_back(make_pair(strin[i], strin[i]));//存入str中
	}
	//sort:给出范围，默认从小到大，cmp：比较函数，bool型，返回为真的为cmp中参数的前后关系
	//sort(str[0], str[num - 1], cmp);//初排，调整变位词间的顺序关系，为何不行？？
	//cout << str[0].first << endl;
	sort(str.begin(), str.end(), cmp);
	for(long long i = 0; i < num; ++i){
		sort(str[i].first.begin(), str[i].first.end());//原单词排序
	}
	//sort(str[0], str[num - 1], cmp);//第二次，使相同变位词聚集
	sort(str.begin(), str.end(), cmp);
	vector<string> result;
	long long sum = 0;
	bool flag = false;
	long long t = 0;
	for (long long i = 0; i < num - 1; ++i){
		long long whether = (str[i].first == str[i + 1].first);
		if (whether == 1 && flag == false){
			sum++;
			result.push_back(str[i].second);
			flag = true;
			t++;
		}
		else if (whether == 0){
			flag = false;
		}
	}
	//sort(result[0], result[sum - 1]);//????????????????????
	sort(result.begin(), result.end());
	printf("wo yi yue du guan yu chao xi de shuo ming\n");
	cout << sum << endl;
	for (long long i = 0; i < sum; ++i){
		cout << result[i] << endl;
	}
	system("pause");
	return 0;
}
