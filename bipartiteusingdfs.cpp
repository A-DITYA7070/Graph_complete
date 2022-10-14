#include<bits/stdc++.h>
using namespace std;
bool detect(int node,vector<int>adj[],int color[]){
    for(auto it:adj[node]){
        if(color[it]==-1){
            color[it]=1-color[node];
            if(!detect(it,adj,color)){
                return false;
            }
        }
        else if(color[it]==color[node]){
            return false;
        }
    }
    return true;
}
bool check(vector<int>adj[],int n){
    int color[n];
    memset(color,-1,sizeof color);
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            color[i]=1;
            if(!detect(i,adj,color)){
                return false;
            }
        }
    }
    return true;
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
cout<<"Is graph bipartite : "<<check(adj,n)<<endl;
return 0;
}