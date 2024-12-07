#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define vlli vector<lli>
#define vvi vector<vi>
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
#define foro(i, n) for (int i = 1; i <= n; i++)
#define forz(i, n) for (int i = 0; i < n; i++)
using namespace std;
// ascending order 0-10
int bi_1(vi v,int k){
    int s=0,e=v.size()-1;
    while(s<=e){
        int m=s+(e-s)/2;
        if(v[m]==k)return m;
        if(v[m]>k)e=m-1;
        else s=m+1;
    }
    return -1;
}
int main()
{
    cout<<bi_1({1,3,6,9,11,14},9);
    
}