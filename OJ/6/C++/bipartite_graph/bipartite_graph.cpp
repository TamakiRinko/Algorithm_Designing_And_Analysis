#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<sstream>
using namespace std;

enum Color{White = 0, Gray, Black};

struct Node{
    //int id;       //id
    Color color;    //颜色
    bool Belonging; //是否与0在同一部
    Node(){
        color = White;
        Belonging = false;
    }
};
/*
struct Adj{
    int id;
    Adj* next;
    Adj(int x){
        id = x;
        next = NULL;
    }
};
*/
vector<Node> node;
vector< vector<int> > AdjVertices;

void BFS_bipartite(int v);

int main(){
    string str;
    int u, v;
    while(getline(cin, str)){
        Node temp;
        node.push_back(temp);
        vector<int> temp2;
        AdjVertices.push_back(temp2);
        stringstream ss;            //string转int
        ss << str;
        ss >> u;
        while(ss >> v){
            AdjVertices[u].push_back(v);
        }
    }
    //int u, v;
    /*
    while(cin >> u){
        Node temp;
        //cout << temp.color << " " << temp.Belonging << endl;
        node.push_back(temp);
        while(cin >> v){
            AdjVertices[u].push_back(v);
        }
    }*/
    /*for(int i = 0; i < 6; ++i){
        cin >> u;
        Node temp;
        //cout << temp.color << " " << temp.Belonging << endl;
        node.push_back(temp);
        vector<int> temp2;
        AdjVertices.push_back(temp2);
        for(int j = 0; j < 2; ++j){
            cin >> v;
            AdjVertices[u].push_back(v);
        }
    }*/
    cout << "wo yi yue du guan yu chao xi de shuo ming\n";
    BFS_bipartite(0);
    //system("pause");
}

void BFS_bipartite(int v){
    queue<int> myqueue;
    int w, u;
    node[v].color = Gray;
    node[v].Belonging = true;
    myqueue.push(v);
    while(!myqueue.empty()){
        w = myqueue.front();
        myqueue.pop();
        vector<int>::iterator it;
        for(it = AdjVertices[w].begin(); it != AdjVertices[w].end(); ++it){
            u = *it;
            if(node[u].color == White){
                node[u].color = Gray;
                node[u].Belonging = !(node[w].Belonging);
                myqueue.push(u);
            }
        }
        node[w].color = Black;
    }
    for(int i = 0; i < node.size(); ++i){
        if(node[i].Belonging == true){
            cout << i << endl;
        }
    }
}