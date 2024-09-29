#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2){
        vector<vector<int>> ans(2);
        unordered_set<int>a(nums1.begin(), nums1.end());
        unordered_set<int>b(nums2.begin(), nums2.end());
        int n = nums1.size();
        int m = nums2.size();

        for(int i: a){
            if(b.find(i) == b.end()){
                ans[0].push_back(i);
            }
        }

        for(int j: b){
            if(a.find(j) == a.end()){
                ans[1].push_back(j);
            }
        }
        return ans;
    }
};

int main(){

    Solution s;
    vector<int> nums1 = {1, 2, 3, 3};
    vector<int> nums2 = {1, 1, 2, 2};

    vector<vector<int>> ans = s.findDifference(nums1, nums2);
    
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}