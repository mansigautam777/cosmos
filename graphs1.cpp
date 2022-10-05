#include <bits/stdc++.h>
using namespace std;

//insertion in an adjacency list
//bi-directional weighted graph

class graph{
     map<int, vector<pair<int,int>>> adj;
       int a,b,c;

       public:

       void addedge(int n)
       {
           for(int i=0;i<n;i++)
       {
           cin>>a>>b>>c;
           adj[a].push_back({b,c});
           adj[b].push_back({a,c});
       }
       }

       void printgraph()
       {
         for( auto it:adj)
       {
           cout<<it.first<<" - ";
           for(auto it1:(it.second))
           cout<<"("<<it1.first<<" , "<<it1.second<<"),";

           cout<<endl;
       }

       }


};

int main() {
     ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       int n;
       cin>>n;
      graph k;
      k.addedge(n);
      k.printgraph();

       
       return 0;
}