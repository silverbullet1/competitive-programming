// 1 : 28 pm

#include<iostream>
using namespace std;

struct node {
	node *left, *right;
	int data;
};

node* newNode(int data) {
	node *temp = new node();
	temp->left = temp->right = NULL;
	temp->data = data;
}
node* insert(node* root, int data) {
	if(!root) {
		root = newNode(data);
		return root;
	}
	else if (data < root->data) {
		root->left = insert(root->left, data);
	}
	else 
		root->right = insert(root->right, data);
	return root;
}

void preOrder(node *root) {
	if(root) {
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

node* lca(node* root, int n1, int n2) {
	if(!root) return NULL;
	else if(root->data > n1 and root->data < n2)
		return root;
	else if(root->data > n1 and root->data > n2)
		return lca(root->left, n1, n2);
	else if(root->data <n1 and root->data < n2)
		return lca(root->right, n1, n2);
	return root;
}

int main() {
	node *root = NULL;
	root = insert(root, 20);
	insert(root, 25);
	insert(root, 15);
	insert(root, 5);
	insert(root, 10);
	insert(root, 2);
	preOrder(root);
	cout << lca(root,20,2)->data << " "<<lca(root,15,5)->data << " ";
	return 0;
}

///1:32 pm