#include<bits/stdc++.h>
using namespace std;
int main(){
int n=5,m=6;
vector<pair<int,int>>adj[n];
adj[0].push_back({1,2});
adj[0].push_back({3,6});
adj[0].push_back({0,2});
adj[0].push_back({2,3});
adj[0].push_back({3,8});
adj[0].push_back({4,5});
adj[0].push_back({1,3});
adj[0].push_back({4,7});
adj[0].push_back({0,6});
adj[0].push_back({1,8});
adj[0].push_back({1,5});
adj[0].push_back({2,7});
int parent[n];
int key[n];
bool mstset[n];
for(int i=0;i<n;i++){
    key[i]=INT_MAX;
    mstset[i]=false;
}
key[0]=0;
parent[0]=-1;
int weight=0;

for(int count=0;count<n-1;count++){
int mini=INT_MAX,u;

    for(int v=0;v<n;v++)
    {
        if(mstset[v]==false&&key[v]<mini){ 
        mini=key[v];
        u=v;
        mstset[u]=true;
        }
    }

for(auto it:adj[u]){
   int v=it.first;
   int weight=it.second;
   if(mstset[v]==false&&weight<key[v]){
    parent[v]=u;
    key[v]=weight;
   }
 }
}
cout<<"possible spanning tree "<<endl;
for(int i=1;i<n;i++){
    cout<<parent[i]<<"->"<<i<<endl;
}
return 0;
}