#include<bits/stdc++.h>
using namespace std;

int minimumMoves(string s) {
    int size = s.size();
    int pos = 0, ans = 0;
    while(pos < size)
    {
        if(s[pos] == 'X')
        {
            ans++;
            pos += 3;
        }
        else
            pos++;
    }
    return ans;
}

int main()
{
    string s;
    cin>>s;
    cout<<minimumMoves(s);
}