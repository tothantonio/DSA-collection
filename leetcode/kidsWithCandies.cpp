#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    //Time: O(n)
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies){

        int max_candy = candies[0];
        vector<bool> result(candies.size());

        for(int i = 1; i < candies.size(); i++){
            if(candies[i] >= max_candy){
                max_candy = candies[i];
            }
        }

        for(int i = 0; i < candies.size(); i++){
            if(candies[i] + extraCandies >= max_candy){
                result[i] = true;
            }
            else{
                result[i] = false;
            }
        }
        return result;
    }
};


int main(){

    Solution s;

    vector<int> candies = {4, 2, 1, 1, 2};
    int extraCandies = 1;

    vector<bool>res = s.kidsWithCandies(candies, extraCandies);

    for(int i = 0; i < res.size(); i++){
        if(res[i]){
            cout << "true ";
        }
        else{
            cout << "false ";
        }
    }
    cout << endl;
    return 0;
}