#include <bits/stdc++.h>
using namespace std;
//path optimization in find function 
//union by rank
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
   //making the parent node equal to the real leader of the node
   return parents[node] = find(parents[node],parents);
 }

 void union1(int x,int y,vector<int>& parents,vector<int>& ranks)
 {
     int s1=find(x,parents);
     int s2=find(y,parents);

     if(s1!=s2)
     {
         // doing union of smaller set with the larger one
         if(ranks[s1]<ranks[s2])
         {
             parents[s1]=s2;
             ranks[s2]+=ranks[s1];
         }
         else
         {
              parents[s2]=s1;
             ranks[s1]+=ranks[s2];
         }
     }
 }

 bool contains_cycle(int n)
 {
     vector<int> parents(n+1,-1);
     vector<int> ranks(n+1,1);

     for(auto it:adj){

         int x=it.first;
         int y=it.second;

         int s1=find(x,parents);
         int s2=find(y,parents);

         if(s1!=s2)
         union1(s1,s2,parents,ranks);
         else return true;

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