#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution{
public:
    int maxDepth(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return max(left, right) + 1;
    }
};

int main(){

    Solution s;

    TreeNode* root = new TreeNode();
    root->val = 3;
    root->left = new TreeNode();
    root->left->val = 9;
    root->right = new TreeNode();
    root->right->val = 20;
    root->right->left = new TreeNode();
    root->right->left->val = 15;
    root->right->right = new TreeNode();
    root->right->right->val = 7;

    cout << s.maxDepth(root) << endl;
    return 0;
}