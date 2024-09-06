#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
    //Timme: O(n)
    //Space: O(1)
public:
    int maxSubArray(vector<int>& nums) {
        int MaxSum = nums[0];
        int Sum = nums[0];

        for(int i = 1; i < nums.size() ; i++){
            Sum = max(nums[i], Sum + nums[i]);
            MaxSum = max(MaxSum, Sum);
        }
        return MaxSum;
    }
};

int main(){

    Solution s;

    vector<int>nums = {5, 4, -1, 7, 8};

    cout << s.maxSubArray(nums) << endl;
    return 0;
}