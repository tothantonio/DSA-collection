#include <iostream>
#include <unordered_map>
using namespace std;

class Solution{
    //Time: O(n)
    //Space: O(n)
public:
    int longestPalindrome(string s){
        unordered_map<char, int>m;

        for(auto &c: s){ // meaning: for(auto c: s) c is a copy of the element in s
            m[c]++;
        }

        int cnt = 0;
        bool flag = false;

        for(auto &i: m){
            if(i.second % 2 == 0){ // even
                cnt += i.second;
            }
            else{ // odd
                cnt += i.second - 1;
                flag = true;
            }
        }
        return flag ? cnt + 1 : cnt;
    }
};

int main(){

    Solution s;

    cout << s.longestPalindrome("AAAAAA") << endl;
    return 0;
}