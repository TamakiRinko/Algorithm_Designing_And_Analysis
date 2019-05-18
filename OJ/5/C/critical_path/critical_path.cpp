#include<iostream>
using namespace std;

enum Color{White = 0, Gray, Black};

struct Node{
    //int id;       //id
    Color color;    //颜色
    int est;        //最早开始时间
    int eft;        //最早结束时间
    int l;          //完成所需时间
    Node(){
        color = White;
        est = 0;
        eft = 0;
    }
};

struct Adj{
    int id;
    Adj* next;
    Adj(int x){
        id = x;
        next = NULL;
    }
};

void wrapper();
void DFS_critical(int v);

//int m;
int n;
int timenecessary = 0;
Node* node;
Adj** AdjVertices;

int main(){
    int index, ltime;   //完成时间
    int u, v;           //结点
    //cin >> n >> m;
    cin >> n;
    node = new Node[n];
    for(int i = 0; i < n; ++i){
        cin >> index >> ltime;
        node[index - 1].l = ltime;
    }
    AdjVertices = new Adj *[n];
    for(int i = 0; i < n; ++i){
        AdjVertices[i] = NULL;
    }
    /*for(int i = 0; i < m; ++i){
        cin >> u >> v;
        Adj* temp = new Adj(v - 1);
        temp->next = AdjVertices[u - 1];
        AdjVertices[u - 1] = temp;
    }*/
    while(cin >> u >> v){
        Adj* temp = new Adj(v - 1);
        temp->next = AdjVertices[u - 1];
        AdjVertices[u - 1] = temp;
    }
    wrapper();
    cout << timenecessary << endl;
    //system("pause");
    return 0;
}

void wrapper(){
    for(int i = 0; i < n; ++i){
        if(node[i].color == White){
            DFS_critical(i);
            timenecessary = (timenecessary < node[i].eft)?node[i].eft:timenecessary;
        }
    }
}

void DFS_critical(int v){
    node[v].color = Gray;
    node[v].est = 0;
    Adj* cur = AdjVertices[v];
    int w;
    while(cur != NULL){
        w = cur->id;
        cur = cur->next;
        if(node[w].color == White){
            DFS_critical(w);
            if(node[w].eft >= node[v].est){
                node[v].est = node[w].eft;
            }
        }
        else if(node[w].eft >= node[v].est){
            node[v].est = node[w].eft;
        }
    }
    node[v].eft = node[v].est + node[v].l;
    node[v].color = Black;
}