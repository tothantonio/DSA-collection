#include <iostream>
#include <vector>
using namespace std;

class Solution{
    //Time: O(n * m)
    //Space: O(1)
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
        int m = mat.size();
        int n = mat[0].size();
        int inf = n + m;

        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    continue;
                }
                int top = inf, left = inf;
                if(i - 1 >= 0) top = mat[i - 1][j];
                if(j - 1 >= 0) left = mat[i][j - 1];
                mat[i][j] = min(top, left) + 1;
            }
        }
        for(int i = m - 1; i > 0; i --){
            for(int j = n - 1; j > 0; j --){
                if(mat[i][j] == 0){
                    continue;
                }
                int bottom = inf, right = inf;
                if(i + 1 < m) bottom = mat[i + 1][j];
                if(j + 1 < n) right = mat[i][j + 1];
                mat[i][j] = min(mat[i][j], min(bottom, right) + 1);
            }
        }
        return mat;
    }
};

int main(){

    Solution s;

    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};

    vector<vector<int>> result = s.updateMatrix(mat);

    for(auto i : result){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}