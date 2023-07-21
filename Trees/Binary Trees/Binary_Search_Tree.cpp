#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

class BinaryTreeNode {
public:
    int value_;
    BinaryTreeNode* left_;
    BinaryTreeNode* right_;

    BinaryTreeNode(int value) :
        value_(value),
        left_(nullptr),
        right_(nullptr)
    {}

    ~BinaryTreeNode() {
        delete left_;
        delete right_;
    }

    BinaryTreeNode* insertLeft(int value) {
        this->left_ = new BinaryTreeNode(value);
        return this->left_;
    }

    BinaryTreeNode* insertRight(int value) {
        this->right_ = new BinaryTreeNode(value);
        return this->right_;
    }
};

int max_node(BinaryTreeNode *node) {
    if (node == nullptr) return INT_MIN;
    return max({node->value_, max_node(node->left_), max_node(node->right_)});
}

int min_node(BinaryTreeNode *node) {
    if (node == nullptr) return INT_MAX;
    return min({node->value_, min_node(node->left_), min_node(node->right_)});
}

bool is_BST(BinaryTreeNode* root) {
    if (root == nullptr) return true; 

    if (max_node(root->left_) < root->value_ && min_node(root->right_) > root->value_) {
        return is_BST(root->left_) && is_BST(root->right_);
    }

    return false;
}

void in_order(BinaryTreeNode* root) {
    cout << root->value_ << '\n';
    if (root->left_ != nullptr) {
        in_order(root->left_);
    }
    if (root->right_ != nullptr) {
        in_order(root->right_);
    }
}

int main(){

    BinaryTreeNode* root = new BinaryTreeNode(60);
    root->insertLeft(50);
    root->insertRight(70);
    root->left_->insertLeft(40);
    root->left_->insertRight(55);
    root->right_->insertLeft(65);
    root->right_->insertRight(75);


    cout << (is_BST(root) ? "BST" : "NO BST") << '\n';
   
    delete root; 
    return 0;
}
