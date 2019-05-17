#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

enum Color{White = 0, Gray, Black};

struct Node{
    //int id;       //id
    Color color;    //颜色
    int disT;       //发现时间
    int back;       //back值
    int parent;     //父结点
    Node(){
        color = White;
        disT = 0;
        back = 0;
        parent = -1;
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

int time = 0;
int n;
Node* node;
Adj** AdjVertices;
vector<int> point;
vector< pair<int, int> > edge;
int root_tree = 0;

void wrapper_point();
void wrapper_edge();
void DFS_point(int v);
void DFS_edge(int v);
bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.first < b.first;
}

int main(){
    int u, v;
    cin >> n;
    AdjVertices = new Adj *[n];
    for(int i = 0; i < n; ++i){
        AdjVertices[i] = NULL;
    }
    node = new Node[n];
    /*for(int i = 0; i < n; ++i){
        cout << node[i].color << " ";
    }
    cout << endl;
    */
    //vector< vector<int> > AdjVertices(n);//邻接表
    //vector<Node> node(n);//顶点表
    while(cin >> u >> v){
        Adj* temp = new Adj(v);
        temp->next = AdjVertices[u];
        AdjVertices[u] = temp;
        temp = new Adj(u);
        temp->next = AdjVertices[v];
        AdjVertices[v] = temp;
    }
    /*for(int i = 0; i < n; ++i){
        Adj* cur = AdjVertices[i];
        while(cur != NULL){
            cout << cur->id << " ";
            cur = cur->next;
        }
        cout << endl;
    }*/
    wrapper_point();
    for(int i = 0; i < n; ++i){
        node[i].color = White;
    }
    time = 0;
    wrapper_edge();
    return 0;
}

void wrapper_point(){
    for(int i = 0; i < n; ++i){
        if(node[i].color == White){
            DFS_point(i);
            if(root_tree == 1 || root_tree == 0){
                point.pop_back();
            }
        }
    }
    sort(point.begin(), point.end());
    for(vector<int>::iterator it = point.begin(); it != point.end(); it++){
        cout << *it << endl;
    }
}

void wrapper_edge(){
    for(int i = 0; i < n; ++i){
        if(node[i].color == White){
            DFS_edge(i);
        }
    }
    sort(edge.begin(), edge.end(), cmp);
    for(vector< pair<int, int> >::iterator it = edge.begin(); it != edge.end(); it++){
        cout << (*it).first << " " << (*it).second << endl;
    }
}

void DFS_point(int v){
    node[v].color = Gray;
    time += 1;
    node[v].disT = time;
    node[v].back = node[v].disT;
    Adj* cur = AdjVertices[v];
    int w;
    int root_trees = 0;//根的子树个数
    while(cur != NULL){
        w = cur->id;
        cur = cur->next;
        if(node[w].color == White){
            node[w].parent = v;
            root_trees++;
            DFS_point(w);
            if(node[w].back >= node[v].disT){
                //cout << v << endl;
                point.push_back(v);
            }
            node[v].back = (node[v].back > node[w].back)?node[w].back:node[v].back;
        }
        else if(node[w].color == Gray && w != node[v].parent){
            node[v].back = (node[v].back > node[w].back)?node[w].back:node[v].back;
        }
    }
    if(node[v].parent == -1){//根结点
        root_tree = root_trees;
    }
    node[v].color = Black;
    time += 1;
}

void DFS_edge(int v){
    node[v].color = Gray;
    time += 1;
    node[v].disT = time;
    node[v].back = node[v].disT;
    Adj* cur = AdjVertices[v];
    int w;
    while(cur != NULL){
        w = cur->id;
        cur = cur->next;
        if(node[w].color == White){
            node[w].parent = v;
            DFS_edge(w);
            node[v].back = (node[v].back > node[w].back)?node[w].back:node[v].back;
            if(node[w].back > node[v].disT){
                //cout << v << " " << w << endl;
                if(v < w){
                    edge.push_back(make_pair(v, w));
                }
                else{
                    edge.push_back(make_pair(w, v));
                }
            }
        }
        else if(node[w].color == Gray && w != node[v].parent){
            node[v].back = (node[v].back > node[w].back)?node[w].back:node[v].back;
        }
    }
    node[v].color = Black;
    time += 1;
}