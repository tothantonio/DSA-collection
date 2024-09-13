#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

class Solution{
    //Time: O(n)
    //Space: O(n)
public:

    int height(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    bool isBalanced(TreeNode* root){
        if(root == NULL) return true;
        int lh = height(root->left);
        int rh = height(root->right);

        return abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};

int main(){

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);

    Solution s;
    cout << s.isBalanced(root) << endl;
    return 0;
}