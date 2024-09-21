#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
    string removeDuplicates(string s){ 
        vector<char>st; 

        for(char c: s){
            if(!st.empty() && st.back() == c){
                st.pop_back();
            }
            else{
                st.push_back(c);
            }
        }

        string res(st.begin(), st.end());
        return res;
    }
};

int main(){

    Solution s;

    string str = "abbaca";

    cout << s.removeDuplicates(str) << endl;
    return 0;
}