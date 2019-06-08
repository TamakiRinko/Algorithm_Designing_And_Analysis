#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<stack>
using namespace std;

enum Color{White = 0, Gray, Black};

struct Node{
    Color color;    //颜色
    Node(){
        color = White;
    }
};

struct Edge{
    int v;          //点的标号
    int weight;     //边的权值
    Edge(int i, int wei){
        v = i;
        weight = wei;
    }
};

vector<Node> node;
vector< vector<Edge> > AdjVertices;
stack<int> mystack;
int* longest;       //最长距离数组
int n;              //顶点个数

void Longest_Path();
void DFS_topo(int v);
void Longest();

int main(){
    scanf("%d", &n);
    longest = new int[n];
    for(int i = 1; i < n; ++i){
        longest[i] = 0x80000000;    //初始化为-∞
    }
    longest[0] = 0;                 //0到0最长为0
    for(int i = 0; i < n; ++i){
        Node temp;
        node.push_back(temp);
        vector<Edge> temp2;
        //temp2[0].v = i;         //????
        //temp2[0].weight = 0;    //????
        AdjVertices.push_back(temp2);
    }
    string str;
    int u, v, weight;
    while(scanf("%d%d%d", &u, &v, &weight) != EOF){
        Edge temp(v, weight);
        AdjVertices[u].push_back(temp);
    }
    Longest_Path();
    system("pause");
    return 0;
}

void Longest_Path(){
    DFS_topo(0);
    Longest();
}

void DFS_topo(int v){
    node[v].color = Gray;
    vector<Edge>::iterator it;
    int w;
    for(it = AdjVertices[v].begin(); it != AdjVertices[v].end(); ++it){
        w = (*it).v;
        if(node[w].color == White){
            DFS_topo(w);
        }
    }
    node[v].color = Black;
    mystack.push(v);
}

void Longest(){
    int v;
    while(!mystack.empty()){
        v = mystack.top();
        mystack.pop();
        vector<Edge>::iterator it;
        int w;
        for(it = AdjVertices[v].begin(); it != AdjVertices[v].end(); ++it){
            w = (*it).v;
            if(longest[v] + (*it).weight > longest[w]){
                longest[w] = longest[v] + (*it).weight;
            }
        }
    }
    cout << "I have read the rules about plagiarism punishment" << endl;
    for(int i = 1; i < n; ++i){
        cout << longest[i] << " ";
    }
}