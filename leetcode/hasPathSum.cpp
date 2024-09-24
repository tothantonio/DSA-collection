#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    //Time: O(n)
    //Space: O(n) - worst case, O(logn) - average(for a balanced tree)
    bool hasPathSum(TreeNode* root, int targetSum){
        if(root == nullptr){
            return false;
        }

        targetSum -= root->val;

        if(root->left == nullptr && root->right == nullptr){
            return targetSum == 0;
        }

        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};
void preorder(TreeNode* root){
    if(root){
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

   preorder(root);
    cout << endl;

    Solution s;
    int targetSum = 22;

    if(s.hasPathSum(root, targetSum)){
        cout << "true";
    }
    else cout << "false";

    return 0;
}