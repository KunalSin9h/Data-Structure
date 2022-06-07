#include <iostream>
using namespace std;

typedef long long ll;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node{
    int data ;
    struct Node *left, *right;
};

//Utility function to create a new tree node
Node* newNode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. */
void POST_ORDER(struct Node *node){
    if(node == NULL)
        return;
    // First recur on left side
    POST_ORDER(node->left);
    // Second recur on right side
    POST_ORDER(node->right);
    // now deal with the node 
    cout << node->data << " ";
}

// Given a binary tree, print its nodes in inorder
void INORDER(struct Node *node){
    if(node == NULL)
        return;
    INORDER(node->left);
    cout << node->data <<" ";
    INORDER(node->right);
}

//Given a binary tree, print its nodes in preorder
void PRE_ORDER(struct Node *node){
    if(node == NULL)
        return;
    cout << node->data <<" ";
    PRE_ORDER(node->left);
    PRE_ORDER(node->right);
}

int heightTree(struct Node *node){
    if(node == NULL)
        return 0;
    return 1 + max(heightTree(node->left), heightTree(node->right));
}

int sizeTree(struct Node* node){
    if(node == NULL)
        return 0;
    return 1 + sizeTree(node->left) + sizeTree(node->right);
}

int main(){
    struct Node *root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->left = newNode(7);
    root->right->right = newNode(9);
    
    cout << "\nPreorder Traversal of Binary Tree\n";
    PRE_ORDER(root);

    cout << "\npostorder traversal of binary tree\n";
    POST_ORDER(root);

    cout << "\nInorder Traversal of Binary Tree\n";
    INORDER(root);    

    cout << "\nSize of this Binary Tree is ";
    cout << sizeTree(root) << endl;

    cout << "\nHeight of this binary Tree is ";
    cout << heightTree(root) << endl;

    return 0;
}