#include<bits/stdc++.h>
 using namespace std;
 void Bfs(int node,unordered_map<int,bool>&vis,unordered_map<int,list<int>>&adj){
    queue<int>q;
    if(!vis[node]){
      q.push(node);
      vis[node]=true;
    }
    while(!q.empty()){
       int f=q.front();
       cout<<f<<"-->";
       q.pop();
       for(auto it:adj[f]){
        if(!vis[it]){
            q.push(it);
            vis[it]=true;
        }
       }
    }
}
int main(){
  cout<<"Enter the no of nodes and edges "<<endl;
  int n,e;
  cin>>n>>e;
  unordered_map<int,bool>vis;
  unordered_map<int,list<int>>adj;
  vector<pair<int,int>>edges;
  cout<<"Enter the conncted nodes of graph "<<endl;
  for(int i=0;i<e;i++){
     int x,y;
     cin>>x>>y;
     edges.push_back({x,y});
   }
   for(int i=0;i<e;i++){
      int u=edges[i].first;
      int v=edges[i].second;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    cout<<"Bfs traversal of 0 based indexed graph is "<<endl;
    for(int i=0;i<n;i++){
      if(!vis[i]){
         Bfs(i,vis,adj);
       }
     }
     return 0;
   }