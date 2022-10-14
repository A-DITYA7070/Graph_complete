//topological sort using dfs
#include<bits/stdc++.h>
using namespace std;
void topo(int node,unordered_map<int,bool>&vis,vector<int>adj[],stack<int>&st){
    vis[node]=true;
    for(auto it:adj[node]){
        if(!vis[it]){
            topo(it,vis,adj,st);
        }
    }
    st.push(node);
}
stack<int>toposort(int n,vector<int>adj[]){
    stack<int>st;
    unordered_map<int,bool>vis;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            topo(i,vis,adj,st);
        }
    }
    return st;
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
stack<int>st;
st=toposort(n,adj);
cout<<"printing topological sort "<<endl;
while(!st.empty()){
    cout<<st.top()<<"-->";
    st.pop();
}
return 0;
}