#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

enum Color{White = 0, Gray, Black};

struct Node{
    //int id;       //id
    Color color;    //颜色
    int group;      //小组号
    int necessary;  //最终算影响力时是否需要遍历
    Node(){
        color = White;
        group = 0;
        necessary = 1;
    }
};

vector<Node> node;
vector< vector<int> > AdjVertices;
vector< vector<int> > AdjVertices_transpose;
stack<int> mystack;
stack<int> mystack2;
int n = 0;                      //顶点数
int num = 0;                    //当前小组影响力数
int max_num = 0;                //最大影响力数
stack<int> max_group_leader;           //最大影响力小组首元
vector<int> max_impact;         //影响力最大顶点数组
int current_group = 0;          //当前组号
//vector<int> group_necessary;    //小组是否需要遍历

void DFS_stack_wrapper();
void DFS_stack(int v);
void DFS_impact();
void DFS_transpose(int v);
void DFS_num(int v);
void DFS_transpose_wrapper();
void make_white();
void DFS_num_wrapper();
void DFS_node(int v);

int main(){
    string str;
    int v;
    
    while(getline(cin, str)){
        Node temp;
        node.push_back(temp);
        vector<int> temp2;
        AdjVertices.push_back(temp2);
        vector<int> temp3;
        AdjVertices_transpose.push_back(temp3);
        //int temp4 = 1;              //需要遍历
        //group_necessary.push_back(temp4);
        stringstream ss;            //string转int
        ss << str;
        while(ss >> v){
            AdjVertices[n].push_back(v);
        }
        n++;
    }
    //cout << "I have read the rules about plagiarism punishment\n";
    DFS_impact();
    //system("pause");
}

void DFS_impact(){
    DFS_stack_wrapper();            //第一次DFS，进栈
    make_white();
    vector<int>::iterator it;
    for(int i = 0; i < n; ++i){     //转置
        for(it = AdjVertices[i].begin(); it != AdjVertices[i].end(); ++it){
            AdjVertices_transpose[*it].push_back(i);
        }
    }
    
    DFS_transpose_wrapper();        //给每个组染色
    make_white();

    DFS_num_wrapper();
    make_white();

    while(!max_group_leader.empty()){
        int v = max_group_leader.top();
        //cout << "v = " << v << endl;
        max_group_leader.pop();
        //max_impact.push_back(v);
        //DFS_node(v);
        for(int i = 0; i < n; ++i){
            if(node[i].group == node[v].group){
                max_impact.push_back(i);
            }
        }
    }
    
    cout << max_num << endl;

    sort(max_impact.begin(), max_impact.end());
    for(it = max_impact.begin(); it != max_impact.end(); it++){
        cout << *it << " ";
    }
}

void DFS_stack_wrapper(){
    for(int i = 0; i < n; ++i){
        if(node[i].color == White){
            DFS_stack(i);
        }
    }
}

void DFS_stack(int v){
    node[v].color = Gray;
    vector<int>::iterator it;
    int w;
    for(it = AdjVertices[v].begin(); it != AdjVertices[v].end(); ++it){
        w = *it;
        if(node[w].color == White){
            DFS_stack(w);
        }
    }
    node[v].color = Black;
    mystack.push(v);
    mystack2.push(v);
}

void DFS_transpose_wrapper(){
    int v;
    while(!mystack.empty()){
        v = mystack.top();
        mystack.pop();
        if(node[v].color == White){
            //cout << "transpose v = " << v << endl;
            current_group++;
            DFS_transpose(v);
        }
    }
}

void DFS_transpose(int v){
    node[v].color = Gray;
    node[v].group = current_group;
    vector<int>::iterator it;
    int w;
    for(it = AdjVertices_transpose[v].begin(); it != AdjVertices_transpose[v].end(); ++it){
        w = *it;
        if(node[w].color == White){
            DFS_transpose(w);
        }
    }
    node[v].color = Black;
}

void make_white(){
    for(int i = 0; i < n; ++i){     //染回白色
        node[i].color = White;
    }
}

void DFS_num_wrapper(){
    int v;
    while(!mystack2.empty()){
        v = mystack2.top();
        mystack2.pop();
        if(node[v].necessary == 1){
            DFS_num(v);
            if(num == max_num){
                max_group_leader.push(v);
            }
            else if(num > max_num){
                max_num = num;
                while(!max_group_leader.empty()){
                    max_group_leader.pop();
                }
                max_group_leader.push(v);
            }
            num = 0;
            make_white();
        }
    }
    /*
    for(int i = 0; i < n; ++i){
        if(node[i].color == White){
            DFS_num(i);
            if(num == max_num){
                max_group_leader.push(i);
            }
            else if(num > max_num){
                max_num = num;
                while(!max_group_leader.empty()){
                    max_group_leader.pop();
                }
                max_group_leader.push(i);
            }
            num = 0;
        }
    }
    */
}

void DFS_num(int v){
    node[v].necessary = 0;
    node[v].color = Gray;
    vector<int>::iterator it;
    int w;
    for(it = AdjVertices[v].begin(); it != AdjVertices[v].end(); ++it){
        w = *it;
        if(node[w].color == White){
            //if(node[w].group != node[v].group){         //该小组不再被遍历
            //group_necessary[node[w].group] = 0;
            //}
            num++;
            DFS_num(w);
        }
    }
    node[v].color = Black;
}
/*
void DFS_node(int v){
    max_impact.push_back(v);
    node[v].color = Gray;
    vector<int>::iterator it;
    int w;
    for(it = AdjVertices_transpose[v].begin(); it != AdjVertices_transpose[v].end(); ++it){
        w = *it;
        //cout << v <<"'s neighbor is " << w << endl;
        //cout << "node[" << w << "].color is " << node[w].color << endl;
        //cout << "node[" << w << "].group is " << node[w].group << endl;
        if(node[w].color == White){
            DFS_node(w);
        }
    }
    node[v].color = Black;
}
*/