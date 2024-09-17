#include <iostream>
#include <string>
#include <numeric>

using namespace std;

class Solution{
public:
    string gcdOfStrings(string str1, string str2){
        return (str1 + str2 == str2 + str1)? 
        str1.substr(0, gcd(size(str1), size(str2))) : "";
    }
};

int main(){

    Solution s;
    string str1 = "ABABAB"; // len = 6
    string str2 = "ABAB";    // len = 3
    //the gcd of 2 strings is the substring of str1/str2 with the lenght = gcd(len(str1), len(str2))
    string res = s.gcdOfStrings(str1, str2);

    cout << res << endl;
    return 0;
}