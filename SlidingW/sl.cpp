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
// 1.
// subsequence of 3 size of arr:[1 2 3 4]= [1 2 3] ✅ but [1,3, 4] ❌
// then those subarray ka sum batana hai
/* basic method using 2 for loops and i0 and j2 and ++ then ans*/
void maxSumInSubArray(int k, int n, int a[])
{
    int mx = 0, s = 0;
    int i = 0, j = 0;
    while (j < n)
    {
        // calculation here when increasing window size
        s += a[j];
        // increasing window's size
        if (j - i + 1 < k)
            j++;
        // if window is set ; now extract ans
        else if (j - i + 1 == k)
        {
            // getting ans
            mx = max(mx, s);
            // moving the  whole window
            //  2.1 remove old/calulated things
            s = s - a[i];
            // 2.2 actual movement
            i++;
            j++;
        }
    }
    // after gettting answers from all windows and maintaing only one from the window print that one thing
    cout << mx;
}
// 2.
void firstNegInWindow_K(int n, int k, int a[])
{
    list<int> v;
    int i = 0, j = 0;
    while (j < n)
    {
        // make calcculations
        if (a[j] < 0)
            v.pb(a[j]);
        //
        // inc window size
        if (j - i + 1 < k)
            j++;
        //
        // window is set: now extract ans
        else if (j - i + 1 == k)
        {
            // 1 get ans
            cout << v.front() << " ";
            //
            // 2. MOve WIndow
            // 2.1 . move window ( but remove those old/calculated things which are not our use now for the new window)
            if (a[i] == v.front())
                v.pop_front();
            // 2.2 now actual movement of window
            i++;
            j++;
        }
    }
}
// 3.
// MEdium
void countOcrOfAnagram(int n, int k, string p, string s)
{
    map<char, int> m;
    int c = 0;
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

    int i = 0, j = 0, res = 0;
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
                res++;
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
    cout << res << " ";
}
vector<int> maxElmInSub(int n, int k, int a[])
{
    int mx = INT_MIN;
    int smax = INT_MIN;
    vi res;
    vi v;
    int i = 0, j = 0;
    while (j < n)
    {
        if (mx < a[j])
        {
            smax = mx;
            mx = a[j];
        }
        else if (smax < a[j])
            smax = a[j];
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            res.pb(mx);
            if (mx == a[i])
            {
                mx = smax;
            }
            i++;
            j++;
        }
    }
    return res;
}
// VARIABLE SIZED
//  1.
void largest_k_with_sum_x(int n, int x, int a[])
{
    int i = 0, j = 0;
    int sum = 0;
    int mx = INT_MIN;
    while (j < n)
    {
        sum += a[j];
        if (sum < x)
            j++;
        else if (sum == x)
        {
            mx = max(j - i + 1, mx);
            j++;
        }
        else if (sum > x)
        {
            while (sum > x)
            {
                sum -= a[i];
                i++;
            }
            if (sum == x)
                mx = max(mx, j - i + 1);
            j++;
        }
    }
    cout << mx;

} //

// 2.
// Largest substring with k unique chars
void LargestSubstringWithKUniChars(string s, int k)
{
    /*
    cout<<"";
    string s="aabacbebebe";
    int k=3;
    LargestSubstringWithKUniChars(s,k); //7;
    s="aaaa";
    k=1;
    LargestSubstringWithKUniChars(s,k);// 4
    */
    int n = s.size();
    int i = 0, j = 0;
    map<char, int> m;
    int save = INT_MIN;
    int c = 0;
    while (j < n)
    {
        if (m.find(s[j]) != m.end())
        {

            m[s[j]] = 1;
        }
        else
        {
            m[s[j]]++;
        }

        if (m.size() < k)
            j++;
        else if (m.size() == k)
        {
            save = max(save, j - i + 1);
            j++;
        }
        else if (m.size() > k)
        {
            while (m.size() > k)
            {
                m[s[i]]--;
                if (m[s[i]] == 0)
                {
                    m.erase(s[i]);
                }
                i++;
            }

            if (m.size() == k)
            {
                save = max(save, j - i + 1);
            }
            j++;
        }
    }
    cout << save << endl;
}
// hard
void largestButNoRep(string s)
{
    /*
    cout << "";
    string s = "pwwkew";
    largestButNoRep(s);
    op 3
    */
    int i = 0, j = 0;
    map<char, int> m;
    int n = s.size();
    int save = INT_MIN;

    while (j < n)
    {
        // calc
        if (m.find(s[j]) != m.end())
            m[s[j]] = 1;
        else
            m[s[j]]++; // condition//
        if (m.size() < j - i + 1)
        {
            while (m.size() < j - i + 1)
            {
                m[s[i]]--;
                if (m[s[i]] == 0)
                {
                    m.erase(s[i]);
                }
                i++;
            }
        }
        else if (m.size() == j - i + 1)
        {
            if (save < j - i + 1)
                save = j - i + 1;
        }
        j++;
    }
    cout << save << endl;
}
void toy(string s, int k)
{
    // toy("abaccab",2); //4
    int i = 0, j = 0;
    int n = s.size();
    map<char, int> m;
    int save = INT_MIN;
    while (j < n)
    {
        // calculation;
        // condition k(count 2 hi chayiye , unique chars 2 only )
        //  m.size()==2
        if (m.find(s[j]) != m.end())
        {
            m[s[j]]++;
        }
        else
            m[s[j]] = 1;

        if (m.size() < k)
            j++;
        else if (m.size() == k)
        {
            if (save < j - i + 1)
                save = j - i + 1;
            j++;
        }
        else if (m.size() > k)
        {
            while (m.size() > k)
            {
                m[s[i]]--;
                if (m[s[i]] == 0)
                    m.erase(s[i]);
                i++;
            }
            if (m.size() == k)
            {
                if (save < j - i + 1)
                    save = j - i + 1;
            }
            j++;
        }
    }
    cout << save;
}
void minWindowSubstr(string s, string t)
{
    int i = 0, j = 0;
    int n = s.size(), m = t.size();
    map<char, int> mt;
    forz(i, m)
    {
        if (mt.find(mt[t[i]]) != mt.end())
        {
            mt[t[i]]++;
        }
        else
            mt[t[i]] = 1;
    }

    int k=mt.size();
    map<char,int> st;
    while (j < n)
    {
        if(st.find(st[s[j]])!=st.end())st[s[j]]++;
        else st[s[j]]=1;

        if(st.size()<k || st[s[j]]<mt[t[j]])j++;
    }
}
int main()
{
    int arr[]={100,200,300,400};
    maxSumInSubArray(2,4,arr);
}
