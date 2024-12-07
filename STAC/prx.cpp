#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
#define foro(i, n) for (int i = 1; i <= n; i++)
#define forz(i, n) for (int i = 0; i < n; i++)
using namespace std;

void pv(vi v){
    int n=v.size();
    forz(i,n)cout<<v[i]<<" ";
}
// 1
// nearest greater to right or next largest elemet :
//  ques: ip ={1,2,41,4,12,75} and op {2,41,75,12,75,-1}

// nearest greater to left
//  ques: ip ={1,2,41,4,12,75} and op {-1,-1,-1,41,41,-1}
vi ngl(vi v)
{
    int n = v.size();

    // ans(n) karne pe kuch gadvad hoehi idk what
    vi ans;

    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            ans.pb(-1);
        }
        else if (s.size() > 0 && s.top() > v[i])
        {
            ans.pb(s.top());
        }
        else if (s.size() > 0 && s.top() < v[i])
        {
            while (s.size() > 0 && s.top() < v[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                ans.pb(-1);
            }
            else
            {
                ans.pb(s.top());
            }
        }
        s.push(v[i]);
    }
    return ans;
}

// 2
vi stock(vi v)
{
    vi ans;
    int n = v.size();
    stack<ii> s;
    forz(i, n)
    {
        if (s.empty())
        {
            ans.pb(i + 1);
        }
        else if (s.size() > 0 && s.top().first > v[i])
        {
            ans.pb(i - s.top().second);
        }
        else if (s.size() > 0 && s.top().first < v[i])
        {
            while (s.size() > 0 && s.top().first < v[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                ans.pb(i + 1);
            }
            else
            {
                ans.pb(i - s.top().second);
            }
        }
        s.push({v[i], i});
    }
    return ans;
}
int histogram(vi v)
{
    vi l, r, ans;
    stack<ii> s;
    int n = v.size();
    forz(i, n)
    {
        if (s.empty())
        {
            l.pb(-1);
        }
        else if (s.size() > 0 && s.top().first < v[i])
        {
            l.pb(s.top().second);
        }
        else if (s.size() > 0 && s.top().first >= v[i])
        {
            while (s.size() > 0 && s.top().first >= v[i]){s.pop();}
            if (s.empty())
                l.pb(-1);
            else
                l.pb(s.top().second);
        }
        s.push({v[i], i});
    }
    while (s.size() > 0)
        s.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
            r.pb(n);
        else if (s.size() > 0 && s.top().first < v[i])
            r.pb(s.top().second);
        else if (s.size() > 0 && s.top().first >= v[i])
        {
            while (s.size() > 0 && s.top().first >= v[i])
                s.pop();
            if (s.empty())
                r.pb(n);
            else
                r.pb(s.top().second);
        }
        s.push({v[i], i});
    }

    reverse(r.begin(), r.end());

    forz(i,n){
        ans.pb(r[i] - l[i] - 1);
        ans[i]*=v[i];
    }
    return *max_element(ans.begin(),ans.end());
}
// 4
int maxRectangle(vvi v)
{
    int r = v.size();
    int c = v[0].size();
    vi ans(c, 0);
    int m=INT_MIN;
    forz(i, r)
    {
        forz(j, c)
        {
            if(v[i][j]==0) ans[j]=0;
            else ans[j] += v[i][j];
        }
        int x=histogram(ans);
        m=max(m,x);
    }
    return m;
}
int rainwater(vi v){
    int n=v.size();
    int maxl[n],maxr[n];
    maxl[0]=v[0];
    maxr[n-1]=v[n-1];
    foro(i,n){
        if(maxl[i-1]>=v[i]){
            maxl[i]=maxl[i-1];
        }
        else maxl[i]=v[i];
    }
    for(int i=n-2;i>=0;i--){
        if(maxr[i+1]>=v[i]){
            maxr[i]=maxl[i+1];
        }
        else maxr[i]=v[i];
    }
    int water=0;
    forz(i,n){
        water+=min(maxl[i],maxr[i])-v[i];
    }
    return water;
}
// fn
int minNum=INT_MAX;
stack<int> s;
int getMin(){
    if(s.size()==0)return -1;
    return minNum;
}
int topp(){
    if(s.empty())return -1;
    int res=s.top();
    if(res<minNum){
        // return 3 as top is 1 
        return minNum;
    }
    return res;
}
void popp(){
    if(s.empty())return;
    int res=s.top();
    if(res<minNum){
        //need to change min;
        minNum=2*minNum-res; //2*3-1 ==5 
    }
    s.pop();
}
void pushh(int x){
    if(s.empty()){
        s.push(x);
        minNum=x;
    }
    
    else if(x<minNum){
        s.push(2*x-minNum); //2*3-5==1
        minNum=x;
    }

    //...
    // >= idhar
    else {
        s.push(x);
        // min wont be effected
    }
}
void ps(stack<int>s){
    while(s.size()>0){
        cout<<s.top()<<endl;
        s.pop();
    }
}
int main()
{
    pushh(5);
    cout<<getMin();
    pushh(3);
    cout<<getMin();
    popp();
    pushh(7);
    cout<<getMin()<<endl;
    ps(s);

}