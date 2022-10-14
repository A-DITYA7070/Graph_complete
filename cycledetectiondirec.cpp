//cycle detection in directed graph using dfs..
#include<bits/stdc++.h>
using namespace std;
bool isCycle(int node,unordered_map<int,bool>&vis,unordered_map<int,bool>&dfsvis,vector<int>adj[]){
    vis[node]=true;
    dfsvis[node]=true;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(isCycle(it,vis,dfsvis,adj)){
                return true;
            }
        }else if(dfsvis[it]==true){
            return true;
        }
    }
    dfsvis[node]=false;
    return false;
}
string detect(int v,vector<int>adj[]){
    unordered_map<int,bool>vis;
    unordered_map<int,bool>dfsvis;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(isCycle(i,vis,dfsvis,adj)){
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
}
unordered_map<int,bool>vis;
cout<<"cycle in the graph : "<<detect(n,adj)<<endl;
return 0;
}