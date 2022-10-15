#include<bits/stdc++.h>
using namespace std;
int main(){
int c[3][3];
int p[3][3];
cout<<"enter the cost of the graph "<<endl;
for(int i=1;i<=3;i++){
    for(int j=1;j<=3;j++){
        cin>>c[i][j];
    }
}
for(int i=1;i<=3;i++){
    for(int j=1;j<=3;j++){
       p[i][j]=c[i][j];
    }
}
for(int k=1;k<=3;k++){
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
         if(p[i][k]+p[k][j] < p[i][j]){
            p[i][j]=p[i][k]+p[k][j];
        }
      }
   }
}
cout<<"the minimum cost of the graph is "<<endl;
for(int i=1;i<=3;i++){
    for(int j=0;j<3;j++){
        cout<<p[i][j]<<" ";
    }cout<<endl;
}
return 0;
}