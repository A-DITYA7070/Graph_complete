#include<bits/stdc++.h>
using namespace std;
void dfs(int node,stack<int>&st,vector<int>&vis,vector<int>adj[]){
    vis[node]=true;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,st,vis,adj);
        }
    }
    st.push(node);
}
void revDfs(int node,vector<int>&vis,vector<int>transpose[]){
    cout<<node<<"--";
    vis[node]=1;
    for(auto it:transpose[node]){
        if(!vis[it]){
            revDfs(it,vis,transpose);
        }
    }
}
int main(){
cout<<"Enter the no of nodes and edges "<<endl;
int n,e;
cin>>n>>e;
vector<int>adj[n+1];
cout<<"Enter the connected nodes of the directed acyclic graph "<<endl;
for(int i=0;i<e;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
}
stack<int>st;
vector<int>vis(n+1,0);
for(int i=0;i<n;i++){
    if(!vis[i]){
        dfs(i,st,vis,adj);
    }
}
vector<int>transpose[n+1];
for(int i=1;i<=n;i++){
    vis[i]=0;
    for(auto it:adj[i]){
        transpose[it].push_back(i);
    }
}
cout<<"printing strongly connected component : "<<endl;
while(!st.empty()){
    int node=st.top();
    st.pop();
    if(!vis[node]){
        revDfs(node,vis,transpose);
        cout<<endl;
    }
}
return 0;
}