#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
    string addBinary(string a, string b){
        string res;
        int i = a.size() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while(i >= 0 || j >= 0 || carry){ // while there are still digits to add
            if(i >= 0){
                carry += a[i--] - '0'; 
            }
            if(j >= 0){
                carry += b[j--] - '0';
            }
            res += to_string(carry % 2);
            carry = carry / 2;
        }

        reverse(begin(res), end(res));
        return res;
    }
};

int main(){

    Solution s;
    string a = "11";
    string b = "1";

    cout << s.addBinary(a, b) << endl;
    return 0;
}