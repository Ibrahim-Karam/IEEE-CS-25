#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int n, x,ans=0;cin>>n;
    vector<vector<int>>G(n + 1);
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        G[i].push_back(x);
        G[x].push_back(i);
    }
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i]) {
            ans++;
            st.push(i);
            while (!st.empty())
            {
                int s = st.top();
                st.pop();
                if (vis[s]) continue;
                vis[s] = 1;
                for (int v : G[s])if (!vis[v]) st.push(v);
            }
        }
    }
    cout << ans;
    return 0;
}
