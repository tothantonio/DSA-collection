#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


//Brute Force
class Solution {
    //Time: O(n^2)
    //Space: O(1)
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {};
    }
};

//hashmap
class Solution2 {
    //Time: O(n)
    //Space: O(n)
    public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> numMap;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            numMap[nums[i]] = i;
        }

        for(int i = 0; i < n; i++){
            int complement = target - nums[i];
            if(numMap.count(complement) && numMap[complement] != i){
                return{i, numMap[complement]};
            }
        }
        return {};
    }
};

int main(){

    vector<int> nums = {2, 1, 7, 15};
    int target = 16;
    Solution2 sol;
    
    vector<int> result = sol.twoSum(nums, target);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}