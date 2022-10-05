#include <bits/stdc++.h>
using namespace std;
//detect cycle in a directed graph

class graph{
 list<pair<int,int>> adj;

 public:

 void add_edge(int n)
 {
     int x,y;
     for(int i=0;i<n;i++)
     {
       cin>>x>>y;
       adj.push_back(make_pair(x,y));
     }
 }

 int find(int node,vector<int>& parents)
 {
   if(parents[node]==-1)
   return node;

   return find(parents[node],parents);
 }

 void union1(int x,int y,vector<int>& parents)
 {
     int s1=find(x,parents);
     int s2=find(y,parents);

     if(s1!=s2)
     {
         parents[s1]=s2;
     }
 }

 bool contains_cycle(int n)
 {
     vector<int> parents(n+1,-1);

     for(auto it:adj){

         int x=it.first;
         int y=it.second;

         int s1=find(x,parents);
         int s2=find(y,parents);

         if(s1!=s2)
         union1(s1,s2,parents);
         else
         {
            return true;
         }
     }
     parents.clear();
     return false;
 }

};

int main()
{
     std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
        int n;
        cin>>n;
        graph g;
        g.add_edge(n);
        if(g.contains_cycle(n))
        cout << "Cycle present\n";
        else
        {
            cout<<"Cycle not present\n";
        }


    return 0;
}