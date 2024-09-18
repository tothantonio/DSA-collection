#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    //Time: O(amount * coins.size())
    int coinChange(vector<int>& coins, int amount){
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] >= 0){
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }
        return dp[amount] != amount + 1 ? dp[amount] : -1;
    }  
};

int main(){

    Solution s;

    vector<int>coins = {1, 2, 5};
    int amount = 11;

    cout << s.coinChange(coins, amount) << endl;
    return 0;
}

//  0, 1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11 (index)
//  0, 1,  1, 12, 12, 12, 12, 12, 12, 12, 12, 12