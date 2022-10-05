#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

//to find out the number of connected components in an undirected graph
 
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int i)
{
    visited[i]=true;
    for (int &v : adj[i])
        if (!visited[v])
            dfs(v);
}
 
void solve()
{
    int n;
    cin>>n;
    
    adj.clear();
    visited.clear();
    adj.resize(n+1);
    visited.resize(n+1,false);
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
 
    int c=0;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i);
            c++;
        }
    }
 
    cout<<c<<endl;
	return;
}

signed main()
{
	std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
	   
       solve();
       
	
	return 0;
}