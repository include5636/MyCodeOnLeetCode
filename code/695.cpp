#include<bits/stdc++.h>
using namespace std;

/* 
简单dfs 
*/

class Solution {
public:
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}; // 右下左上

    int calcArea(vector<vector<int>>& grid, int m, int n, int x, int y) {
        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != 1) {
            return 0;
        }
        grid[x][y] = 2;
        int sumArea = 1;
        for (int i = 0; i <= 3; i++) {
            sumArea += calcArea(grid, m, n, x + dx[i], y + dy[i]);
        }
        return sumArea;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int curArea = calcArea(grid, m, n, i, j);
                    maxArea = max(maxArea, curArea);
                }
            }
        }
        return maxArea;
    }
};