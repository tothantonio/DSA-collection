#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int climbStairs_recursive(int n){
    //Time: O(2^n)
    //Space: O(n)
        if(n == 0 || n == 1){
            return 1;
        }
        return climbStairs_recursive(n - 1) + climbStairs_recursive(n - 2);
    }

    int climbStairs_dp(int n){
    //Time: O(n)
    //Space: O(n)
        if(n == 0 || n == 1){
            return 1;
        }

        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;

        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int climbStairs_two_variable(int n){
        //Time: O(n)
        //Space: O(1)
        if(n == 0 || n == 1){
            return 1;
        }

        int prev = 1, curr = 1;

        for(int i = 2; i <=n; i++){
            int tmp = curr;
            curr = prev + curr;
            prev = tmp;
        }
        return curr;
    }
};

int main(){

    Solution s;

    cout << s.climbStairs_recursive(3) << endl;
    cout << s.climbStairs_dp(4) << endl;
    cout << s.climbStairs_two_variable(3) << endl;
    return 0;
}