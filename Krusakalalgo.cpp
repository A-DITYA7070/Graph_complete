#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v,wt;
    node(int u,int v,int wt){
        this->u=u;
        this->v=v;
        this->wt=wt;
    }
};
bool comp(node a,node b){
    return a.wt<b.wt;
}
int findPar(int u,vector<int>&parent){
    if(u==parent[u])return u;
    return parent[u]=findPar(u,parent);
}
void Union(int u,int v,vector<int>&parent,vector<int>&rank){
     u=findPar(u,parent);
     v=findPar(v,parent);
     if(rank[u]<rank[v]){
        parent[u]=v;
     }
     else if(rank[v]<rank[u]){
        parent[v]=u;
     }else{
        parent[v]=u;
        rank[u]++;
     }
}
int main(){
int n,m;
cin>>n>>m;
vector<node>edges;
for(int i=0;i<12;i++){
    int x,y,z;
    cin>>x>>y>>z;
    edges.push_back(node(x,y,z));
}
sort(edges.begin(),edges.end(),comp);
vector<int>parent(n);
for(int i=0;i<n;i++){
    parent[i]=i;
}
vector<int>rank(n,0);
int cost=0;
vector<pair<int,int>>mst;
for(auto it:edges){
    if(findPar(it.v,parent)!=findPar(it.u,parent)){
        cost += it.wt;
        mst.push_back({it.u,it.v});
        Union(it.u,it.v,parent,rank);
    }
}
cout<<cost<<endl;
for(auto it:mst){
    cout<<it.first<<"->"<<it.second<<endl;
}
return 0;
}