#include <iostream>
#include <vector>
using namespace std;

class Node{

private:

    int data{0};
    int tag{0};
    Node* left{nullptr};
    Node* right{nullptr};

public:

    Node(int tag, int data = 0){
        this->tag = tag;
        this->data = data;
    }

    void insert(int val);
    bool contains(int val);
    void printInorder();
};

void Node::insert(int val){
    if(val <= this->data){
        if(this->left == nullptr){
            this->left = new Node(val);
        }else{
            this->left->insert(val);
        }
    }else{
        if(this->right == nullptr){
            this->right = new Node(val);
        }
        else{
            this->right->insert(val);
        }
    }
}

bool Node::contains(int val){
    if(val == this->data){
        return true;
    }else if (val < this->data){
        if(this->left == nullptr) return false;
        return this->left->contains(val);
    }else{
        if(this->right == nullptr)return false;
        return this->right->contains(val);
    }
}

void Node::printInorder(){
    if(this->left != nullptr){
        this->left->printInorder();
    }
    cout << this->data << '\n';
    if(this->right != nullptr){
        this->right->printInorder();
    }
}

int main(){

    int N;cin >> N;
    vector<vector<Node>> BinaryTree.com

    return 0;
}