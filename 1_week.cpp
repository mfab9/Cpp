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
// -------------------------------------DIV4(964)-------------------------------------
// E
void TripleOperator()
{
    /*x or y kp choose hame optimally karna so oprtion km hojaye
    so apn pehle zero bana lenge jo minimum ho sbme then us zero ko baar baar x lenge then kisi ko bhi y lenge */
    int t;
    cin >> t;
    while (t--)
    {
    }
}
// D
void LIGHTS()
{

    lli k, n;
    cin >> n >> k; //
    lli a[n];
    lli mx = LLONG_MIN;
    forz(i, n)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    } //}
    sort(a, a + n);

    // 2 3 4 left =>13 and right means left+k-1 (13 to 16)
    // low means req range ka low for each elm;2(10 to 14) then ans for now is comomn:
    // common:                        yha se max 13 and 14 idhar min so range karrib hopaye and ans will be the min of both as i need the jaise hi light on wo wala time
    lli left = mx;
    lli right = left + k - 1;
    lli ans = left;
    forz(i, n)
    {
        lli diff = left - a[i];
        lli x = diff / (2 * k);
        lli low = a[i] + x * 2 * k;

        if (diff % (2 * k) >= k)
            low += 2 * k;

        lli high = low + k - 1;

        // getting ans:
        left = max(low, left);
        right = min(right, high);
        if (left > right)
        {
            cout << "-1" << endl;
            return;
        }
        ans = left;
    }
    cout << ans << endl;
}
// C
void SHOWER()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string g;
        cin >> g;
        int n = s.size(), m = g.size();
        int j = 0;
        int i = 0;
        while (i < n && j < m)
        {
            if (s[i] == '?')
            {
                s[i] = g[j];
            }
            if (s[i] == g[j])
            {
                i++;
                j++;
                continue;
            }
            i++;
        }
        if (j < m)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        forz(i, n)
        {
            if (s[i] == '?')
                s[i] = 'a';
        }
        cout << s << endl;
    }
} //
// B
int CARD_GAME(int a[], int n, int x)
{
    forz(i, n)
    {
        if (a[i] == x)
            return i;
    }
    return -1;
}
// ------------------------------------------DIV2()------------------------------------------
void Kdist()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, k;
        cin >> x >> y >> k;
        if (k % 2)
        {
            cout << x << " " << y << endl;
        }
        foro(i, k / 2)
        { 
            cout << x - i << " " << y - i << endl;
            cout << x + i << " " << y + i << endl;
        }
    }
}

int main()

{
    Kdist();
}
