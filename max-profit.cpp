#include <iostream>
#include <vector>
using namespace std;

class Solution {
    //Time: O(n)
    //Space: O(1)
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < buy){
                buy = prices[i];
            }
            else if(prices[i] - buy > profit){
                profit = max(profit, prices[i] - buy);
            }
        }
        return profit;
    }
};

int main(){

    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution sol;
    cout << sol.maxProfit(prices) << endl;

    return 0;
}

