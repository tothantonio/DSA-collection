#include <iostream>
using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int st = 0, dr = n;
        int m = 0;

        while(st <= dr){
            m = st + (dr - st) / 2;
            int rez = isBadVersion(m);
            if(rez == 1 && (m == 0 || isBadVersion(m - 1) != -1)){
                return m;
            }
            else if(rez == 0){
                st = m + 1;
            }
            else{
                dr = m - 1;
            }
        }
        return m;   
    }
};

int main(){


    return 0;
}