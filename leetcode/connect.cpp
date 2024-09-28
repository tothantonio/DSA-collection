#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node* right;
    Node* left;
    Node* next;

    Node(): val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next):
        val(_val), left(_left), right(_right), next(_next) {}
};

class Solution{
    //Time: O(n)
    //Space: O(1)
public:
    Node* connect(Node* root){
        if(root == NULL)
            return NULL;
        
        if(root->left != NULL){
            root->left->next = root->right;
        }

        if(root->right != NULL && root->next != NULL){
            root->right->next = root->next->left;
        }

        connect(root->left);
        connect(root->right);

        return root;
    }
};

void print(Node* root){
    if(root == NULL) return;

    cout << root->val << " # ";

    if(root->next != NULL){
        cout << root->next->val << endl;
    }
    print(root->left);
    print(root->right);
}

int main(){

    Solution s;

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node* res = s.connect(root);

    print(res);

    return 0;
}