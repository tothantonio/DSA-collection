#include <iostream>
#include <string>


using namespace std;

class Solution{
public:
    //Time: O(n)
    string mergeAlternately(string word1, string word2){
        int i = 0, j = 0;
        int n = word1.size();
        int m = word2.size();
        string res = "";

        while(i < n && j < m){
            res += word1[i];
            res += word2[j];

            i++;
            j++;
        }

        while(i < n){
            res += word1[i];
            i++;
        }

        while(j < m){
            res += word2[j];
            j++;
        }
        return res;
    }
};

int main(){

    Solution s;

    string word1 = "abc";
    string word2 = "pqr";

    string res = s.mergeAlternately(word1, word2);

    cout << res;
    return 0;
}