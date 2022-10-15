#include<bits/stdc++.h>
using namespace std;
void dfs(int node,int parent,int &timer,vector<int>&disc,vector<int>&low,vector<int>adj[],unordered_map<int,bool>&vis){
    vis[node]=true;
    disc[node]=low[node]=timer++;
    for(auto nbr:adj[node]){
        if(nbr==parent){
            continue;
        }
        if(!vis[nbr]){
            dfs(nbr,node,timer,disc,low,adj,vis);
            low[node]=min(low[node],low[nbr]);
            if(low[nbr]>disc[node]){
                cout<<node<<" "<<nbr<<endl;
            }
         }else{
            low[node]=min(low[node],disc[nbr]);
        }
    }
}
int main(){
cout<<"Enter the node and the edges "<<endl;
int n,e;
cin>>n>>e;
vector<int>adj[n];
cout<<"Enter the pair of connected nodes of the graph "<<endl;
for(int i=0;i<e;i++){
   int x,y;
   cin>>x>>y;
   adj[x].push_back(y);
   adj[y].push_back(x);
}
int timer=0;
vector<int>disc(n);
vector<int>low(n);
unordered_map<int,bool>vis;
cout<<"Bridges in graph are.."<<endl;
for(int i=0;i<n;i++){
    if(!vis[i]){
        dfs(i,-1,timer,disc,low,adj,vis);
    }
}
return 0;
}