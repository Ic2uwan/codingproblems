#include <bits/stdc++.h>
#define IOOPTI ios_base::sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

struct node{
	int d;
	node(int a){d = a;};
	node *next = nullptr;
	node *prv = nullptr;
};

void boost(node *curr, node **head){
	if(curr == nullptr || curr->prv == nullptr)
		return;
	node *prv = curr->prv;
	node *next = curr->next;
	node *prvPrv = prv->prv;
	prv->next = next;
	if(next != nullptr)
		next->prv = prv;
	curr->prv = prvPrv;
	curr->next = prv;
	if(prvPrv != nullptr)
		prvPrv->next = curr;
	else
		*head = curr;
	prv->prv = curr;
}

void bump(node *curr, node **head){
	if(curr->next!=nullptr)
		curr->next->prv = curr->prv;
	if(curr->prv!=nullptr)
		curr->prv->next = curr->next;
	if(curr==*head){
		*head = curr->next;
	}
	
}
void printList(node *head){
	while(head->next!=nullptr){
		cout << head->d << ' ';
		head = head->next;
	}
	cout << head->d;
	cout << "\n";
}
int main(){
	IOOPTI;
	int n;
	cin >> n;
	node *head = nullptr;
	node *lst = nullptr;
	unordered_map<int, node*> nm;
	for(int i = 0; i < n; ++i){
		if(i==0){
			head = new node(i+1);
			lst = head;
		}
		else{
			node *newNode = new node(i+1);
			newNode->prv = lst;
			lst->next = newNode;
			lst = newNode;
		}
		nm[i+1] = lst;
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; ++i){
		int t, x;
		cin >> t >> x;
		node *curr = nm[x];
		if(t == 0){
			bump(curr, &head);
		}
		else{
			boost(curr, &head);
		}
	}
	printList(head);

}