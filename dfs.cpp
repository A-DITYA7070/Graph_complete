#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>adj[],unordered_map<int,bool>&vis){
   vis[node]=true;
   cout<<node<<"-->";
   for(auto it:adj[node]){
    if(!vis[it]){
        dfs(it,adj,vis);
    }
   }
}
int main(){
cout<<"Enter the no of nodes and edges of graph "<<endl;
int n,e;
cin>>n>>e;
vector<int>adj[n];
cout<<"Enter the connected edges of graph "<<endl;
for(int i=0;i<e;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}
unordered_map<int,bool>vis;
cout<<"dfs traversal of graph is "<<endl;
for(int i=0;i<n;i++){
    if(!vis[i]){
        dfs(i,adj,vis);
    }
}
return 0;
}