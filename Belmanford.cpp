#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int src,dest,weight;
};
struct Graph{
    int v,e;
    struct Edge* edge;
};
struct Graph* creategraph(int v,int e){
    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->v=v;
    graph->e=e;
    return graph;
};
void finalsol(int dist[],int n){
    cout<<"vertex dist from src vertex is "<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
}
void belmanFord(struct Graph* graph,int src){
    int v=graph->v;
    int e=graph->e;
    int storeDist[v];
    for(int i=0;i<v;i++){
        storeDist[i]=INT_MAX;
        storeDist[src]=0;
    }
    for(int i=1;i<=v-1;i++){
        for(int j=0;j<e;j++){
          int u=graph->edge[j].src;
          int v=graph->edge[j].dest;
          int wt=graph->edge[j].weight;
          if(storeDist[u]+wt < storeDist[v]){
            storeDist[v]=storeDist[u]+wt;
          }
        }
    }
    for(int i=0;i<e;i++){
        int u=graph->edge[i].src;
        int v=graph->edge[i].dest;
        int wt=graph->edge[i].weight;
        if(storeDist[u]+wt<storeDist[v]){
            cout<<"the graph contains negative edge cycle "<<endl;
        }
        finalsol(storeDist,v);
        return;
    }
}
int main(){
   int v,e,s;
   cout<<"enter the no of vertices in graph "<<endl;
   cin>>v;
   cout<<"Enter the no of edges in graph "<<endl;
   cin>>e;
   cout<<"enter the src vertex "<<endl;
   cin>>s;
   struct Graph* graph=creategraph(v,e);
   for(int i=0;i<e;i++){
       cout<<"enter edges1 src,dest,weight "<<endl;
       cin>>graph->edge[i].src;
       cin>>graph->edge[i].dest;
       cin>>graph->edge[i].weight;
   }
   belmanFord(graph,s);
return 0;
}