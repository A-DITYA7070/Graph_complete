#include<bits/stdc++.h>
using namespace std;
class Graph{
    int v;
    list<pair<int,int>>*adj;
    public:
    Graph(int v){
        this->v=v;
        adj=new list<pair<int,int>>[v];
    }
    void addEdges(int x,int y,int wt){
        adj[x].push_back({y,wt});
        adj[y].push_back({x,wt});
    }
    void dijastra(int src){
        vector<int>dist(v,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({src,0});
        dist[src]=0;
        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();
            list<pair<int,int>>::iterator it;
            for(it=adj[u].begin();it!=adj[u].end();it++){
                int x=(*it).first;
                int wt=(*it).second;
                if(dist[x]>dist[u]+wt){
                    dist[x]=dist[u]+wt;
                    pq.push({dist[x],x});
                }
            }
        }
        for(int i=0;i<v;i++){
           cout<<"dist from src to dest "<<i<<" is "<<dist[i]<<endl;
        }
    }

};
int main(){
cout<<"enter the no of nodes and edges "<<endl;
int n,e;
cin>>n>>e;
Graph g(n);
for(int i=0;i<e;i++){
    cout<<"Enter the connected nodes and weights "<<endl;
    int x,y,z;
    cin>>x>>y>>z;
    g.addEdges(x,y,z);
}
int src;
cout<<"Enter the src node "<<endl;
cin>>src;
g.dijastra(src);
return 0;
}