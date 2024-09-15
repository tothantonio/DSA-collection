#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> result;
        if(root == NULL) return result;

        queue<TreeNode*>Q;
        Q.push(root);

        while(!Q.empty()){
            int s = Q.size();
            vector<int>v;
            for(int i = 0; i < s; i++){
                TreeNode *node = Q.front();
                Q.pop();
                if(node->left != NULL) Q.push(node->left);
                if(node->right != NULL) Q.push(node->right);
                v.push_back(node->val);
            }
            result.push_back(v);
        }
        return result;
    }
};
int main(){

    Solution s;

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = s.levelOrder(root);

    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return  0;
}