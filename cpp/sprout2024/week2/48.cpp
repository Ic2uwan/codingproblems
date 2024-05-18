#include <bits/stdc++.h>
#define IOOPTI ios_base::sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

struct Node{
	int data;
	Node *lc = nullptr, *rc = nullptr;
	Node(int dt){
		data = dt;
	}
};
void addNode(int data, Node *ptr){
	if(data > ptr->data){
		if(ptr->rc == nullptr){
			ptr->rc = new Node(data);
		}
		else{
			addNode(data, ptr->rc);
		}
	}
	else if(data < ptr->data){
		if(ptr->lc == nullptr){
			ptr->lc = new Node(data);
		}
		else{
			addNode(data, ptr->lc);
		}
	}
}
void traverse(Node *ptr){
	if(ptr->lc != nullptr){
		traverse(ptr->lc);
	}
	if(ptr->rc != nullptr){
		traverse(ptr->rc);
	}
	cout << ptr->data << '\n';
	return;

}

Node *head = nullptr;
int main(){
	IOOPTI;
	int n;
	cin >> n;
	int in;
	cin >> in;
	head = new Node(in);
	for(int i = 1; i < n; ++i){
		int in;
		cin >> in;
		addNode(in, head);
	}
	traverse(head);
}
