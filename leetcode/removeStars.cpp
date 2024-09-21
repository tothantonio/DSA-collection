#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution{
public:
    string removeStars(string s){  
        stack<char> st;
        for(char c : s){
            if(c == '*'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(c);
            }
        }
        s = "";
        while(!st.empty()){
            s += st.top();
            st.pop();
        }
        
        reverse(s.begin(), s.end());
        return s;
    }
};

int main(){

    Solution s;

    string str = "leet**cod*e";

    cout << s.removeStars(str) << endl;
    return 0;
}