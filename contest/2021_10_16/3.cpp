#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct node
    {
        int to, next, val;
    };

    int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience)
    {
        int n = patience.size(), m = edges.size(), tot = 0;
        vector<int> dis(n, 10000000);
        vector<int> first(n + 5);
        vector<node> edge(m * 2 + 5);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (int i = 0; i < m; i++)
        {
            edge[++tot].to = edges[i][1];
            edge[tot].val = 1;
            edge[tot].next = first[edges[i][0]];
            first[edges[i][0]] = tot;
            edge[++tot].to = edges[i][0];
            edge[tot].val = 1;
            edge[tot].next = first[edges[i][1]];
            first[edges[i][1]] = tot;

        }
        dis[0] = 0;
        q.push(pair<int, int>(0, 0));
        while (q.size())
        {
            pair<int, int> cur = q.top();
            q.pop();
            if (cur.first > dis[cur.second])
                continue;
            for (int i = first[cur.second]; i; i = edge[i].next)
                if (dis[edge[i].to] > dis[cur.second] + edge[i].val)
                {
                    dis[edge[i].to] = dis[cur.second] + edge[i].val;
                    q.push(pair<int, int>(dis[edge[i].to], edge[i].to));
                }
        }
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            int time = ((dis[i] * 2 - 1) / patience[i]) * patience[i] + dis[i] * 2 + 1;
            if (time > ans)
            {
                ans = time;
            }
        }
        return ans;
    }
};