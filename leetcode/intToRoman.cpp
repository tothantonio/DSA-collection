#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
    string intToRoman(int num){
        vector<int> n = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string res = "";
        int i = 0;

        while(num > 0){

            while(num >= n[i]){
                res += romans[i];
                num -= n[i];
            }
            i++;
        }
        return res;
    }
};

int main(){

    Solution s;

    cout << s.intToRoman(3749) << endl;
    return 0;
}