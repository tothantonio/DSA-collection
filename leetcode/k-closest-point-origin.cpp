#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k){
        priority_queue<pair<int, vector<int>>> max_heap;
        for(int i = 0; i < points.size(); i++){
            int distance = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            max_heap.push({distance, points[i]});
            if(max_heap.size() > k){
                max_heap.pop();
            }
        }
        vector<vector<int>>ans;
        while(!max_heap.empty()){
            pair<int, vector<int>> p = max_heap.top();
            ans.push_back(p.second);
            max_heap.pop();
        }
        return ans;
    }
};

int main(){

    Solution s;

    vector<vector<int>> points = {{1, 3}, {-2, 2}};
    int k = 1;

    vector<vector<int>> result = s.kClosest(points, k);

    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}