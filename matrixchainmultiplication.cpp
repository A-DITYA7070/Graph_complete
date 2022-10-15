#include<bits/stdc++.h>
using namespace std;
int s[10][10];
void print_parens(int i,int j){
    if(i==j){
        cout<<"A"<<i;
    }else{
        cout<<"(";
        print_parens(i,s[i][j]);
        print_parens(s[i][j]+1,j);
        cout<<")";
    }
}
void mm(int p[],int length){
    int n=length-1;
    int i,j,k,l,q,m[10][10],a;
    for(i=1;i<=n;i++){
        m[i][i]=0;
    }
    for(l=1;l<n;l++){
        for(i=1;i<=n-l;i++){
            j=i+l;
            m[i][j]=INT_MAX;
            for(k=i;k<=j;k++){
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j]){
                    m[i][j]=q;
                    a=m[i][j];
                    s[i][j]=k;
                }
            }
        }
    }
    cout<<"printing the optimal parens "<<endl;
    print_parens(1,n);
    cout<<"minimum no of multiplication requiered "<<a<<endl;
    return;
}
int main(){
int p[20],n,i;
cout<<"enter the length of p "<<endl;
cin>>n;
for(int i=0;i<n;i++){
    cout<<"p["<<i<<"]"<<endl;
    cin>>p[i];
}
mm(p,n);
return 0;
}