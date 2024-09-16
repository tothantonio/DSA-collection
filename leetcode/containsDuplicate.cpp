#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution{
    //Time: O(nlogn)
    //Space: O(1)
public:
    bool containsDuplicate(vector<int>& nums){
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i + 1]){
                return true;
            }
        }
        return false;
    }

    bool containsDuplicateHash(vector<int>& nums){
        //Time: O(n)
        unordered_map<int, int> seen;
        for (int num : nums) { 
            if (seen[num] >= 1)
                return true;
            seen[num]++;
        }
        return false;
    }
};

int main(){

    Solution s;

    vector<int> nums = {1, 2, 3, 1};

    cout << s.containsDuplicateHash(nums) << endl;
    return 0;
}