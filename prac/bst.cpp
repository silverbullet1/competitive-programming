#include<iostream>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

Node* newNode(int data) {
	Node* node = new Node;
	node->left = node->right = NULL;
	node->data = data;
}

Node* insert(Node *root, int data) {
	if(root == NULL) {
		root = newNode(data);
		return root;
	}
	else if(data < root->data) {
		root->left = insert(root->left, data);
	}
	else
		root->right = insert(root->right, data);
	cout <<"\t\tReturning " << root->data <<"\n";
	return root;
}

void inorder(Node *root) {
	if(root) {
		inorder(root->left);
		cout <<  root->data << " ";
		inorder(root->right);
	}
}

int main() {
	Node *root = NULL;
	int keys[] = {5,7,1,9,2,0,6,8};
	for(int key : keys) {
		root = insert(root, key);
		cout << "Inserting "<< key << endl;
	}
	inorder(root);
}