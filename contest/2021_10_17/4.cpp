#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct node{
        int to, next, val;
    };
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        int m = edges.size(), tot = 0;
        vector<int> dis(n + 5, 1000000000);
        vector<int> dis2(n + 5, 1000000000);
        vector<int> first(n + 5);
        vector<node> edge(m * 2 + 5);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (int i = 0; i < m; i++)
        {
            edge[++tot].to = edges[i][1];
            edge[tot].val = time;
            edge[tot].next = first[edges[i][0]];
            first[edges[i][0]] = tot;
            edge[++tot].to = edges[i][0];
            edge[tot].val = time;
            edge[tot].next = first[edges[i][1]];
            first[edges[i][1]] = tot;
        }
        dis[1] = 0;
        q.push(pair<int, int>(0, 1));
        while (q.size())
        {
            pair<int, int> cur = q.top();
            q.pop();
            if (cur.first > dis2[cur.second])
                continue;
            if ((cur.first / change) % 2 == 1) {
                cur.first = change * (cur.first / change + 1);
            }
            for (int i = first[cur.second]; i; i = edge[i].next)
                if (dis[edge[i].to] > cur.first + edge[i].val)
                {
                    if (dis[edge[i].to] < dis2[edge[i].to]) {
                        dis2[edge[i].to] = dis[edge[i].to];
                    }
                    dis[edge[i].to] = cur.first + edge[i].val;
                    q.push(pair<int, int>(dis[edge[i].to], edge[i].to));
                } else if (dis[edge[i].to] < cur.first + edge[i].val && dis2[edge[i].to] > cur.first + edge[i].val) {
                    dis2[edge[i].to] = cur.first + edge[i].val;
                    q.push(pair<int, int>(dis2[edge[i].to], edge[i].to));
                }
        }
        return dis2[n];
    }
};