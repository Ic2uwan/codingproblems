#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left = nullptr;
	Node *right = nullptr;
};
Node* an2t(Node *tree, int val){
	if(!tree){
		tree = new Node;
		tree->data = val;
	}else if(val < (tree->data)){
		tree->left = an2t(tree->left, val);
	}else{
		tree->right = an2t(tree->right, val);
	}
	return tree;
}
void preorder(Node *node){
	if(!node) return;
	cout << node->data << ' ';
	preorder(node->left);
	preorder(node->right);
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	while(cin >> n){
		Node *root = NULL;
		for(int i = 0; i < n; i++){
			cin >> m;
			root = an2t(root, m);
		}
		preorder(root);
		cout << '\n';
	}
}
