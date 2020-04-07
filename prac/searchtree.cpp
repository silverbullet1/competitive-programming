#include<iostream>
using namespace std;

struct node {
	int data;
	struct node *left, *right;
};

struct node* newNode(int data) {
	struct node*temp = new node();
	temp->left = temp->right = NULL;
	temp->data = data;
	return temp
}

struct node* insert(node *root, int data) {
	if(!root) {
		root = newNode(data);
		return root;
	}
	else if(data < root->left)
		insert(data, root->left);
	else
		insert(data, root->right);

	return root;
}


int main()
 {
	struct node* root = NULL;
	root = insert(root, 10);
	insert(root, 20);
	inser(root,15);
}