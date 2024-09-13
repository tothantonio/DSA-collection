#include <iostream>
#include <vector>
using namespace std;

class Solution{
    //Time: O(n) 
    //Space: O(1)  constant space
public:
    int majorityElement(vector<int>&nums){
        int count = 0, candidate = 0;
        for(int i = 0; i < nums.size(); i++){
            if(count == 0){
                candidate = nums[i];
                count = 1;
            }
            else{
                if(candidate == nums[i]){
                    count++;
                }
                else{
                    count--;
                }
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == candidate){
                count++;
            }
        }
        if(count > nums.size() / 2)
            return candidate;
        return -1;
    }
};

int main(){

    Solution s;
    vector<int> nums = {3, 2, 3};

    cout << s.majorityElement(nums) << endl;
    return  0;
}