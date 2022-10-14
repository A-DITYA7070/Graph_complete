#include<bits/stdc++.h>
using namespace std;
//cycle detection in undirected graph using bfs..
bool isCycle(int node,vector<int>adj[],unordered_map<int,bool>&vis){
   queue<int>q;
   unordered_map<int,int>parent;
   if(!vis[node]){
    q.push(node);
    vis[node]=true;
    parent[node]=-1;
   }
   while(!q.empty()){
    int f=q.front();
    q.pop();
    for(auto it:adj[f]){
        if(vis[it]==true && it!=parent[f]){
            return true;
        }else if(!vis[it]){
            vis[it]=true;
            q.push(it);
            parent[it]=f;
        }
    }
   }
   return false;
}
string detectcycle(int n,vector<int>adj[]){
    unordered_map<int,bool>vis;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(isCycle(i,adj,vis)){
                return "Yes";
            }
        }
    }
    return "NO";
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
cout<<"cycle in the graph : "<<detectcycle(n,adj)<<endl;
return 0;
}