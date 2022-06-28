#include<bits/stdc++.h>
using namespace std;
#define inf 100000000
int main()
{
   int t;cin>>t;
   for(int k=1;k<=t;k++)
   {
       int n,m;cin>>n>>m;
       vector<pair<int,int>>graph[n+5];
       for(int i=0;i<m;i++)
       {
           int a,b,w;
           cin>>a>>b>>w;
           graph[a].push_back({b,w});
           graph[b].push_back({a,w});

       }
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

       vector<long long>dist(n+1,inf);
       dist[1]=0;
       pq.push({0,1});
       while(!pq.empty())
       {
           int curnod=pq.top().second;
           int curdist=pq.top().first;
           pq.pop();
           if(dist[curnod]<curdist)continue;
           for(auto child:graph[curnod])
           {
               if(dist[child.first]>curdist+child.second)
               {
                   dist[child.first]=curdist+child.second;
                   pq.push({dist[child.first],child.first});
               }
           }
       }
       printf("Case %d: ",k);
       if(dist[n]==inf)cout<<"Impossible"<<endl;
       else cout<<dist[n]<<endl;
   }
}
