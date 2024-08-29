#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
    //Time: O(nlogn)
    //Space: O(1)
public:
    bool isAnagram(string s, string t){
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

class Solution2{
    //Time: O(n)
    //Space: O(1)
public:
    bool isAnagram(string s, string t){
        if(s.size() != t.size()){
            return false;
        }

        int count[26] = {0};
        for(int i = 0; i < s.size(); i++){
            count[s[i] - 'a'] ++;
            count[t[i] - 'a'] --;
        }

        for(int i = 0; i < 26; i++){
            if(count[i] != 0){
                return false;
            }
        }
        return true;
    }
};

int main(){

    Solution2 s;
    cout << s.isAnagram("rat", "car") << endl;
    return 0;
}