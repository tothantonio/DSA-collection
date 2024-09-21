#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) { 
        stack<char> st;
        for(char c:s){
            if(c == '(' || c == '[' || c == '{'){
                st.push(c);
            }
            else{
                if(st.empty() ||
                (c == ')' && st.top() != '(') ||
                (c == ']' && st.top() != '[') ||
                (c == '}' && st.top() != '{'))
                {
                    return false;
                }
               st.pop();
            }
        }
        return st.empty();
    }
};


int main(){
    string s = "(){}[]";
    Solution sol;
    if(sol.isValid(s)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    return 0;
}