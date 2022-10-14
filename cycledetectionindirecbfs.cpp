#include<bits/stdc++.h>
using namespace std;
vector<int>toposort(int v,vector<int>adj[]){
    vector<int>indeg(v,0),ans;
    queue<int>q;
    for(int i=0;i<v;i++){
        for(auto it:adj[i]){
            indeg[it]++;
        }
    }
    for(int i=0;i<v;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
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
vector<int>ans=toposort(n,adj);
if(ans.size()==n){
    cout<<"No cycle present in the graph "<<endl;
}else{
    cout<<"Cycle present in the graph "<<endl;
}
return 0;
}