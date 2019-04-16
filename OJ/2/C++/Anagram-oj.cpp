#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(pair<string, string> i1, pair<string, string> i2) 
{ 
    return (i1.first < i2.first) || (i1.first == i2.first && i1.second < i2.second);
} 
void groupAnagrams(vector<string>& strs) {
    vector<pair<string, string>> temp;
    for(int i = 0; i < strs.size(); i++)
        temp.push_back(make_pair(strs[i], strs[i]));
    for(int i = 0; i < temp.size(); i++){
        sort(temp[i].first.begin(), temp[i].first.end());
    }
    sort(temp.begin(), temp.end(), cmp);

    vector<string> res;
    int count = 0;
    bool flag = false;
    for(int i = 0; i < temp.size() - 1; i++){
        if(temp[i + 1].first == temp[i].first){
            if(!flag){
                count++;
                res.push_back(temp[i].second);
                flag = true;
            }
        }
        else
        {
            flag = false;
        }
    }
    cout << count << endl;
    sort(res.begin(), res.end());
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
}
int main(){
    int n = 0;
    cin >> n;
    vector<string> strs(n);
    for(int i = 0; i < n; i++)
        cin >> strs[i];
    groupAnagrams(strs);
    system("pause");
    return 0;
}