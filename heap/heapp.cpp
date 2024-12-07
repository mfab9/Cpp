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
#define ppi pair<int, pair<int, int>>
using namespace std;
// identification : largest/smalest elm....,first k,intuition sorting ka feel hoga (O(nlogn) => O(nlog k))
//  smallest:max heap => max on top => priority queue<int> maxh;
// largest: min heap : priority queue<int,vi,greater<int>> => minh;

// 1.kth smallest elm

void problem1(int a[], int n, int k)
{
    // int a[6] = {7, 10, 4, 3, 20, 15};
    // int k = 3; // op:7
    priority_queue<int> maxh;
    forz(i, n)
    {
        /*
        if(maxh.empty())maxh.push(a[i]);
        else if(maxh.top()<a[i])maxh.push(a[i]);
        else if(maxh.top()>a[i]){
            int temp=maxh.top();
            maxh.pop();
            maxh.push(a[i]);
            maxh.push(temp);
        }
        */

        // hamne uper wali lines na likh ke only ye push line likhi and same op..wowwww
        maxh.push(a[i]);
        if (maxh.size() > k)
            maxh.pop();
    }
    cout << maxh.top();
    // takeaway : heap hai na uska top hamsesh pure heap ka largest hi hoga but uske neeche ka elms ka order sort ho na ho pata nhi but jarurat bhi nahi pata krne ki
}

void problem2(int a[], int n, int k)
{
    // get all first k largest elms from array
    priority_queue<int, vi, greater<int>> minh;
    forz(i, n)
    {
        minh.push(a[i]);
        if (minh.size() > k)
            minh.pop();
    }
    // need all the rest of the k elms
    while (minh.size() > 0)
    {
        cout << minh.top() << endl;
        minh.pop();
    }
}
// imp
void problem3(int a[], int n, int k)
{
    //
    vi v;
    priority_queue<int, vi, greater<int>> minh;
    for (int i = 0; i < n; i++)
    {
        minh.push(a[i]);
        if (minh.size() > k)
        {
            v.pb(minh.top());
            minh.pop();
        }
    }
    // now jo k elms reh gye hai minh heap me is 8 9 10, the first g=Largest elms so vo saare v me separatly push krdo
    while (minh.size() > 0)
    {
        v.pb(minh.top());
        minh.pop();
    }
    forz(i, v.size()) cout << v[i] << endl;
}
void problem4(int a[], int n, int x, int k)
{
    priority_queue<pair<int, int>> maxh;
    forz(i, n)
    {
        maxh.push({abs(x - a[i]), a[i]});
        if (maxh.size() > k)
        {
            maxh.pop();
        }
    }
    while (maxh.size() > 0)
    {
        cout << maxh.top().second << endl;
        maxh.pop();
    }
}
void problem5(int a[], int n, int k)
{
    // freq map
    unordered_map<int, int> m;
    priority_queue<ii, vii, greater<ii>> minh;
    forz(i, n)
    {
        if (m.find(a[i]) != m.end())
        {
            m[a[i]]++;
        }
        else
            m[a[i]] = 1;
    }
    for (auto i = m.begin(); i != m.end(); i++)
    {
        minh.push({i->second, i->first});
        if (minh.size() > k)
            minh.pop();
    }
    while (minh.size() > 0)
    {
        cout << minh.top().second << endl;
        minh.pop();
    }
}
void problem6(int a[], int n, int k)
{
    unordered_map<int, int> m;
    priority_queue<ii> maxh;
    forz(i, n)
    {
        if (m.find(a[i]) != m.end())
            m[a[i]]++;
        else
            m[a[i]] = 1;
    }
    for (auto i = m.begin(); i != m.end(); i++)
    {
        maxh.push({i->second, i->first});
    }
    while (maxh.size() > 0)
    {
        forz(i, maxh.top().first) cout << maxh.top().second << " ";
        maxh.pop();
    }
    // another apporach by comparison
}
void problem8(int a[], int n)
{
    priority_queue<int, vi, greater<int>> minh;
    forz(i, n)
    {
        minh.push(a[i]);
    }
    int cost = 0;
    while (minh.size() >= 2)
    {
        int x = minh.top();
        minh.pop();
        int y = minh.top();
        minh.pop();
        cost += x + y;
        // then jo x+y  yaaninew rope bani use bhi push krdunga so  if wo choti ho to use account me le in comparing ki consi choti ropes hai
        minh.push(x + y);
    }
    cout << cost;
}
void problem7(vii v ,int k){
    // vii v={{1,3},{-2,2},{5,8},{0,1}};
    // problem7(v,2);
    priority_queue<ppi> maxh;
    int n=v.size();
    forz(i,n){
        int d= v[i].first*v[i].first+v[i].second*v[i].second;
        maxh.push({d,{v[i]}});
        if(maxh.size()>k)maxh.pop();
    }
    while(maxh.size()>0){
        cout<<maxh.top().second.first<<","<<maxh.top().second.second<<endl;
        maxh.pop();
    }
}
int  problem9(int a[],int n,int k ){
    /*
    int a[] = {20, 8, 22, 4, 12, 10, 14};
    int k1 = 3,  k2 = 6 ;
    int k1Elm=problem9(a,7,k1);
    int k2Elms=problem9(a,7,k2);
    cout<<k1Elm<<" "<<k2Elms<<endl;
    int s=0;
    forz(i,7){
        if(a[i]>k1Elm&&a[i]<k2Elms){
            s+=a[i];
        }
    }
    cout<<s<<endl;
    */
    priority_queue<int> maxh;
    forz(i,n){
        maxh.push(a[i]);
        if(maxh.size()>k)maxh.pop();
    }
    return maxh.top();
}
int main()
{
    

    


}