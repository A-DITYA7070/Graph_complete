//kahn's algorithm i.e topological sort using bfs..
#include<bits/stdc++.h>
using namespace std;
vector<int>topoSort(vector<int>adj[],int v){
    vector<int>indeg(v,0);
    for(int i=0;i<v;++i){
        for(int j:adj[i]){
           indeg[j]++;
        }
     }
    queue<int>q;
    for(int i=0;i<v;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        ans.push_back(f);
        for(auto it:adj[f]){
            indeg[it]--;
            if(indeg[it]==0){
                q.push(it);
            }
        }
    }
    return ans;
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
vector<int>ans=topoSort(adj,n);
cout<<"topological sort is "<<endl;
for(auto it:ans){
   cout<<it<<"-->";
}
return 0;
}