#include <iostream>
#include <cmath>
#include <limits>

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* GetNewNode(int data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root, int data) {
	if (root == NULL) {
		root = GetNewNode(data);
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}

Node* FindMin(Node* root) {
	while (root->left != NULL) root = root->left;
	return root;
}

Node* Delete(Node* root, int data) {
	if (root == NULL) return root;
	else if (data < root->data) root->left = Delete(root->left, data);
	else if (data > root->data) root->right = Delete(root->right, data);
	else {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		else if (root->left == NULL) {
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		else {
			Node* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

void Query(Node* root, int data, int& closest) {
	if (root == NULL) return;
	if (abs(root->data - data) < abs(closest - data)) {
		closest = root->data;
	}
	if (data < root->data) {
		Query(root->left, data, closest);
	}
	else {
		Query(root->right, data, closest);
	}
}

int main() {
	Node* root = NULL;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::string operation;
		int x;
		std::cin >> operation >> x;
		if (operation == "insert") {
			root = Insert(root, x);
		}
		else if (operation == "delete") {
			root = Delete(root, x);
		}
		else if (operation == "query") {
			int closest = std::numeric_limits<int>::max();
			Query(root, x, closest);
			std::cout << closest << std::endl;
		}
	}
	return 0;
}