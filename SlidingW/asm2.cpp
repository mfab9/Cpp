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

int sub(string s)
{
    unordered_map<char,int> m;
    int i=0,j=0;
    int n=s.size();
    int c=0;
    while(j<n){
        m[s[j]]++;
        while(m['a']>0&&m['b']>0&&m['c']>0){
            c+=n-j;
            m[s[i]]--;
            i++;
        }
        j++;
    }   
    return c;
}
vi countOcrOfAnagram(int n, int k, string p, string s)
{
    vi v;
    map<char, int> m;
    int c = 0;
    if(n<k){
        return {};
    }
    forz(i, k)
    {
        if (m.find(p[i]) != m.end())
            m[p[i]]++;
        else
        {
            m[p[i]] = 1;
            c++;
        }
    }

    int i = 0, j = 0;
    while (j < n)
    {
        if (m.find(s[j]) != m.end())
        {
            m[s[j]]--;
            if (m[s[j]] == 0)
                c--;
        }
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            if (c == 0)
                v.pb(i);
            if (m.find(s[i]) != m.end())
            {
                m[s[i]]++;
                if (m[s[i]] == 1)
                    c++;
            }
            i++;
            j++;
        }
    }
    return v;
}
int main()
{   
    //1
    // string n;cin>>n;
    // cout<<sub(n);

    //2
    string n,p;
    cin>>n>>p;
    vi v=countOcrOfAnagram(n.size(),p.size(),p,n);
    int x=v.size();
    cout<<'[';

    forz(i,x){

        if(i<x-1&& v[i]>=0)cout<<v[i]<<", ";
        else if(v[i]>=0)cout<<v[i];
    }
    cout<<']';

}