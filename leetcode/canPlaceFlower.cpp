#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool canPlaceFlower(vector<int>& flowerbed, int n){
        int cnt = 0;
        for(int i = 0; i < flowerbed.size(); i++){
            if(flowerbed[i] == 0){
                bool left_empty = (i == 0 || flowerbed[i - 1] == 0);
                bool right_empty = (i == flowerbed.size() || flowerbed[i + 1] == 0);

                if(left_empty && right_empty){
                    flowerbed[i] = 1;
                    cnt++;
                }
                if(cnt >= n){
                    return true;
                }
            }
        }
        return cnt >= n;
    }
};

int main(){

    Solution s;

    vector<int> flowebed = {1, 0, 0, 0, 1};
    int n = 2;

    bool ok = s.canPlaceFlower(flowebed, n);
    if(ok){
        cout << "true";
    }
    else cout << "false";
    return 0;
}