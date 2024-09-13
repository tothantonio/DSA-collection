#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    //Time: O(n)
    //Space: O(n)
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        vector<vector<int>> result;
        int i = 0;

        while(i < intervals.size() && intervals[i][1] < newInterval[0]){
            result.push_back(intervals[i]);
            i++;
        }

        while(i < intervals.size() && intervals[i][0] <= newInterval[1]){
            newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])}; 
            i++;
        }
        result.push_back(newInterval);

        while(i < intervals.size()){
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};

int main(){

    Solution s;

    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};

    vector<vector<int>> result = s.insert(intervals, newInterval);

    for(auto i : result){
        cout << i[0] << " " << i[1] << endl;
    }
    return 0;
}