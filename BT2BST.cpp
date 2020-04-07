//Convert a given binary tree to BST (Binary Search Tree) by keeping original structure of the binary tree intact.

/*The idea is to traverse the Binary Tree and store its keys in a set. We know that an in-order traversal of a binary search tree returns the nodes in sorted order, 
so we traverse the tree again in in-order fashion and put back the keys present in set (in sorted order) back to their correct position in BST.
<p>The advantage of using set over vector/array is that the keys are always retrieved in sorted order from set. If we use vector/array,
we have to sort the keys first before inserting them back*/

#include <iostream>
#include <set>
using namespace std;

// Data structure to store a Binary Search Tree node
struct Node {
    int data;
    Node *left, *right;
};

// Function to create a new binary tree node having given key
Node* newNode(int key)
{
    Node* node = new Node;
    node->data = key;
    node->left = node->right = nullptr;

    return node;
}

// Function to perform in-order traversal of the tree
void inorder(Node* root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Function to traverse the binary tree and store its keys in a set
void extractKeys(Node *root, auto &set)
{
    // base case
    if (root == nullptr)
        return;

    extractKeys(root->left, set);
    set.insert(root->data);
    extractKeys(root->right, set);
}

// Function to put back keys in set in their correct order in BST
// by doing in-order traversal
void convertToBST(Node *root, auto &it)
{
    if (root == nullptr)
        return;

    convertToBST(root->left, it);

    root->data = *it;
    it++;

    convertToBST(root->right, it);
}

// main function
int main()
{
    /* Construct below tree
           8
         /   \
        /     \
       3       5
      / \     / \
     /   \   /   \
    10    2 4     6   */

    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(5);
    root->left->left = newNode(10);
    root->left->right = newNode(2);
    root->right->left = newNode(4);
    root->right->right = newNode(6);

    // traverse the binary tree and store its keys in a set
    set<int> set;
    extractKeys(root, set);

    // put back keys present in set in their correct order in BST
    auto it = set.begin();
    convertToBST(root, it);

    // print the BST
    inorder(root);

    return 0;
}