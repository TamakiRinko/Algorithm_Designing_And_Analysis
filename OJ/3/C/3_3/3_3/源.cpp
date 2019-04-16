#include<iostream>
using namespace std;

struct BinTreeNode{
	int value;
	BinTreeNode* leftChild;
	BinTreeNode* rightChild;
	BinTreeNode() : leftChild(NULL), rightChild(NULL){}
	BinTreeNode(int x, BinTreeNode* left = NULL, BinTreeNode* right = NULL){
		leftChild = left;
		rightChild = right;
		value = x;
	}
};

void PreShow(BinTreeNode* ls);
BinTreeNode* CreateTree(int* pre, int* pos, int index, int begin, int end);
int height(BinTreeNode* ls);
void length(BinTreeNode* ls);

int maxlen = 0;

int main(){
	int n;
	cin >> n;
	int* precur = new int[n];
	int* poscur = new int[n];
	for (int i = 0; i < n; ++i)	cin >> precur[i];
	for (int j = 0; j < n; ++j)	cin >> poscur[j];
	BinTreeNode* head = CreateTree(precur, poscur, 0, 0, n - 1);
	//PreShow(head);
	//cout << endl;
	cout << height(head) << endl;
	length(head);
	cout << maxlen << endl;
	return 0;
}

BinTreeNode* CreateTree(int* pre, int* pos, int index, int begin, int end){
	if (begin <= end){
		int index2 = 0;
		BinTreeNode* root = new BinTreeNode(pre[index]);
		for (int i = begin; i <= end; ++i){
			if (pos[i] == pre[index]){
				index2 = i;
				break;
			}
		}
		root->leftChild = CreateTree(pre, pos, index + 1, begin, index2 - 1);
		root->rightChild = CreateTree(pre, pos, index + (index2 - begin + 1), index2 + 1, end);
		return root;
	}
	return NULL;
}


void PreShow(BinTreeNode* ls){
	if (ls == NULL)	return;
	PreShow(ls->leftChild);
	PreShow(ls->rightChild);
	cout << ls->value << " ";
}

int height(BinTreeNode* ls){
	if (ls == NULL)	return -1;
	if (ls->leftChild == NULL && ls->rightChild == NULL)	return 0;
	int result1 = 0;
	int result2 = 0;
	if (ls->leftChild != NULL)	result1 = height(ls->leftChild);
	if (ls->rightChild != NULL)	result2 = height(ls->rightChild);
	result1 = (result1 > result2) ? result1 : result2;
	return result1 + 1;
}

void length(BinTreeNode* ls){
	if (ls == NULL || (ls->leftChild == NULL && ls->rightChild == NULL))	return;
	if (ls->leftChild != NULL)
		length(ls->leftChild);
	if (ls->rightChild != NULL)
		length(ls->rightChild);
	int lenl = height(ls->leftChild);
	int lenr = height(ls->rightChild);
	maxlen = (maxlen > lenl + lenr + 2) ? maxlen : (lenl + lenr + 2);
	return;
}