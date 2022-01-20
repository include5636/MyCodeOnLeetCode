#include<bits/stdc++.h>
using namespace std;

/*
main idea: 遍历所有城市，如果遇到未访问过的城市，就进行dfs（访问所有与其相连的城市并标记为已访问），同时省份数量++（可以理解为需要新建一个省份来容纳这些城市）。
*/

class Solution {
public:
    void search(int curCity, vector<bool>& visited, int n, vector<vector<int>>& isConnected ) {
        visited[curCity] = true;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && isConnected[curCity][i]) {
                search(i, visited, n, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int numOfProvince = 0, n = isConnected.size();
        vector<bool> visited(n);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                numOfProvince++;
                search(i, visited, n, isConnected);
            }
        }
        return numOfProvince;
    }
};