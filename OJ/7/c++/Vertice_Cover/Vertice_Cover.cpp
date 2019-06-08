#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

enum Color{White = 0, Gray, Black};

struct Node{
    Color color;    //颜色
    Node(){
        color = White;
    }
};

vector<Node> node;
vector< vector<int> > AdjVertices;
int** chosen;

void DFS_Cover(int v);
int min_cover(int i, int j);

int main(){
    int n = 0;
    string str;
    int u, v, root;
    while(getline(cin, str)){
        n++;

        Node temp;
        node.push_back(temp);
        vector<int> temp2;
        AdjVertices.push_back(temp2);
        stringstream ss;            //string转int
        ss << str;
        ss >> u;
        if(n == 1){                 //根的位置
            root = u;
        }
        while(ss >> v){
            AdjVertices[u].push_back(v);
        }
    }
    chosen = new int*[n];
    for(int i = 0; i < n; ++i){
        chosen[i] = new int[2];
        chosen[i][0] = 0;       //没被选上，初始值为0
        chosen[i][1] = 1;       //被选上，初始值为1
    }
    DFS_Cover(root);
    cout << min_cover(chosen[root][0], chosen[root][1]);
    system("pause");
    return 0;
}

void DFS_Cover(int v){
    node[v].color = Gray;
    vector<int>::iterator it;
    int w;
    for(it = AdjVertices[v].begin(); it != AdjVertices[v].end(); ++it){
        w = *it;
        if(node[w].color == White){
            DFS_Cover(w);
            chosen[v][0] += chosen[w][1];   //父亲没被选中，子女必须被选中
            chosen[v][1] += min(chosen[w][0], chosen[w][1]);//父亲被选中，子女可被选中可不被选中
        }
    }
    node[v].color = Black;
}

int min_cover(int i, int j){
    return (i < j)?i:j;
}