#include <iostream>
using namespace std;
 
// Data structure to store a Binary Search Tree node
struct Node
{
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
 
// Function to perform inorder traversal of the tree
void inorder(Node* root)
{
    if (root == nullptr)
        return;
 
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Recursive function to insert an key into BST using a reference parameter
// Using pointer to pointer
// void insert(Node* &root, int key)
// {
//     // if the root is null, create a new node an return it
//     if (root == nullptr)
//     {
//         root = newNode(key);
//         return;
//     }
 
//     // if given key is less than the root node, recurse for left subtree
//     // else recurse for right subtree
//     if (key < root->data)
//         insert(root->left, key);
//     else    // key >= root->data
//         insert(root->right, key);
// }

//Either catch and update the reference everytime
Node* insert(Node* root, int key)
{
    // if the root is null, create a new node an return it
    if (root == NULL)
    {
        root = newNode(key);
        return root; //Important line..removing it will destroy the program
    }
 
    // if given key is less than the root node, recurse for left subtree
    // else recurse for right subtree
    if (key < root->data)
        root->left = insert(root->left, key);
    else    // key >= root->data
       root->right = insert(root->right, key);

    return root; // Will always return the root of the whole tree. Not the subtree ones.
}
// Or make root a global variable

// main function
int main()
{
    cout << "Hello";
    Node* root = nullptr;
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
 
    for (int key : keys) {
        root = insert(root, key); //Only last function call will be stored..so this will be initialized with only once i.e in the very beginning.
        cout << "Root = " << root->data << "\n";
    }

    cout << endl;
    inorder(root);
 
    return 0;
}