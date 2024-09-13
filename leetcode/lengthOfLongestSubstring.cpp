#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution{
public:
    //brute force
    //Time: O(n^3)


    bool allUnique(string s, int start, int end){
        set<char> set;
        for(int i = start; i < end; i++){
            char ch = s[i];
            if(set.find(ch) != set.end()){
                return false;
            }
            set.insert(ch);
        }
        return true;
    }

    int lenghtofLongestSubstring(string s){
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            for(int j = i + 1; j <= s.length(); j++){
                if(allUnique(s, i, j)){
                    ans = max(ans, j - i);
                }
            }
        }
        return ans;
    }

    //sliding window
    //Time: O(n)
    

    int lenghtOfLongestSubstring(string s){
        unordered_map<char, int> charMap;
        int left = 0;
        int maxLen = 0;

        for(int right = 0; right < s.length(); right++){
            if(charMap.count(s[right]) == 0 || charMap[s[right]] < left){
                charMap[s[right]] = right;
                maxLen = max(maxLen, right - left + 1);
            }else{
                left = charMap[s[right]] + 1;
                charMap[s[right]] = right;
            }
        }
        return maxLen;
    }
};

int main(){

    Solution s;
    string str = "abcabcbb";

    cout << s.lenghtOfLongestSubstring(str) << endl;
    return 0;
}