#include<bits/stdc++.h>
using namespace std;
bool detect(int node,vector<int>adj[],int color[]){
   queue<int>q;
   q.push(node);
   color[node]=1;
   while(!q.empty()){
    int f=q.front();
    q.pop();
    for(auto it:adj[f]){
        if(color[it]==-1){
            color[it]=1-color[f];
            q.push(it);
        }else if(color[it]==color[f]){
            return false;
        }
    }
   }
   return true;
}
string isBipartite(int v,vector<int>adj[]){
    int color[v];
    memset(color,-1,sizeof color);
    for(int i=0;i<v;i++){
        if(color[i]==-1){
            if(!detect(i,adj,color)){
                return "NO";
            }
        }
    }
    return "YES";
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
cout<<"Is graph bipartite : "<<isBipartite(n,adj)<<endl;
return 0;
}