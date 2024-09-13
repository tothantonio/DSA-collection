#include <iostream>
#include <string>
using namespace std;

class Solution {
    //Time: O(n)
    //Space: O(1)
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            while(left < right && !isalnum(s[left])){
                left++;
            }

            while(left < right && !isalnum(s[right])){
                right--;
            }

            if(left < right && tolower(s[left]) != tolower(s[right])){
                return false;
            }

            left++;
            right--;

        }
        return true;
    }
};

int main(){

    string s = "race a car";
    Solution sol;
    if(sol.isPalindrome(s)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    return 0;
};