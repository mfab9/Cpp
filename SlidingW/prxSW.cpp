#include <bits/stdc++.h>
using namespace std;
void subA(int v[],int n,int k){
    int i=0,j=0,mx=INT_MIN,sum=0;
    while(j<n){
        sum+=v[j];
        if(j-i+1<k)j++;
        else if(j-i+1==k){
            mx=max(mx,sum);
            sum-=v[i];
            i++;
            j++;
        }
    }
    cout<<mx;
}

int main(){
    cout<<"l";
}