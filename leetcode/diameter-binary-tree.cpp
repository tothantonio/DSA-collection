#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
    //Time: O(n)
    //Space: O(n)
{
public:

    int dfs(TreeNode *root, int &dia){
        if(root == NULL){
            return 0;
        }
        int left = dfs(root->left, dia);
        int right = dfs(root->right, dia);

        dia = max(dia, left + right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int dia = 0;
        dfs(root, dia);
        return dia;
    }
};

int main(){

    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << s.diameterOfBinaryTree(root) << endl;
    return 0;
}