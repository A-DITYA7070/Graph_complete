#include<bits/stdc++.h>
using namespace std;
bool isCycle(int node,int parent,vector<int>adj[],unordered_map<int,bool>&vis){
   vis[node]=true;
   for(auto it:adj[node]){
    if(!vis[it]){
        if(isCycle(it,node,adj,vis)){
            return true;
        }
     }else if(it!=parent){
            return true;
        }
   }
   return false;
}
string detectCycle(int v,vector<int>adj[]){
    unordered_map<int,bool>vis;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(isCycle(i,-1,adj,vis)){
                return "Yes";
            }
        }
    }
    return "No";
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
cout<<"cycle in the graph : "<<detectCycle(n,adj)<<endl;
return 0;
}