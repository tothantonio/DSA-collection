#include <iostream>
using namespace std;

class Solution{
public:
    bool canConstruct(string ransomNote, string magazine){
        int freq[26] = {0};
        for(int i = 0; i < magazine.size(); i++){
            freq[magazine[i] - 'a']++; // Count the frequency of each character in the magazine
        }

        for(int i = 0; i < ransomNote.size(); i++){
            if(freq[ransomNote[i] - 'a'] == 0){
                return false; // If the frequency of a character in the ransomNote is 0, return false
            }
            freq[ransomNote[i] - 'a']--; // Decrement the frequency of the character in the magazine
        }
        return true;
    }
};

int main(){

    Solution s;
    string ransomNote = "aa";
    string magazine = "aab";

    cout << s.canConstruct(ransomNote, magazine) << endl;
    return 0;
}