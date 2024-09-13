#include <iostream>
#include <vector>
using namespace std;

class Solution{
    //Time: O(n)
    //Space: O(n)
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){

        //base case
        if(image[sr][sc] == color) return image;

        int oldColor = image[sr][sc];
        image[sr][sc] = color;

        if(sr > 0 && image[sr-1][sc] == oldColor) floodFill(image, sr-1, sc, color);
        if(sc > 0 && image[sr][sc-1] == oldColor) floodFill(image, sr, sc-1, color);
        if(sr < image.size()-1 && image[sr+1][sc] == oldColor) floodFill(image, sr+1, sc, color);
        if(sc < image[0].size()-1 && image[sr][sc+1] == oldColor) floodFill(image, sr, sc+1, color);

        return image;
    }
};

int main(){

    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, newColor = 2;

    Solution sol;
    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);

    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[0].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}