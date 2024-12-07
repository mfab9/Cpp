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

// 84737289 ->1......9
void inductionsort(vi &v, int x)
{
    if (v.size() == 0 || v.back() <= x)
    {
        v.push_back(x);
        return;
    }
    int temp = v.back();
    v.pop_back();
    inductionsort(v, x);
    v.push_back(temp);
}
vi sortArray(vi v)
{
    if (v.size() == 1)
        return v;

    // need a insert fn that insert a x into an array and manipulate that array so use *v
    int x = v.back();
    v.pop_back();
    v = sortArray(v);
    inductionsort(v, x);
    return v;
}

void printVector(const vector<int> &vec)
{
    for (int i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
}

// 2
void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << endl;
}

//3
void insertInStack(stack<int> &s, int x)
{
    if (s.size() == 0 || s.top() <= x)
    {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    insertInStack(s, x);
    s.push(temp);
}
void sortStack(stack<int> &s)
{
    if (s.size() == 1)
        return;
    int temp = s.top();
    s.pop();
    sortStack(s);
    insertInStack(s, temp);
}
//4
void deletmid(stack<int> &s, int nth)
{
    if (nth == 1)
    {
        s.pop();
        return;
    }
    int temp = s.top();
    s.pop();
    deletmid(s, nth - 1);
    s.push(temp);
}
stack<int> deleteMidStack(stack<int> s)
{
    if (s.size() == 0)
        return s;
    int nth = s.size() / 2 + 1;
    deletmid(s, nth);
    return s;
}


//5
stack<int> insertDown(stack<int> s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return s;
    }
    int temp = s.top();
    s.pop();
    s = insertDown(s, x);
    s.push(temp);
    return s;
}
stack<int> reverseStack(stack<int> s)
{
    if (s.size() == 1)
        return s;
    int temp = s.top();
    s.pop();
    s = reverseStack(s);
    s = insertDown(s, temp);
    return s;
}


//
int kthGrammer(int n, int k)
{
    if (n == 1 && k == 1)
        return 0; //...
    // each row and elm have relation?
    // n=1 and elm are 1 , n=2 ..elms are 2, n=3 ..emls are 8 ie 2^n-1 elms for n=n;
    //  (n,k )..
    //        now if k is half of (2^n-1) then return same as n-1,k elm have
    //       or if k is above of the () then return !(n-1,k) elm have
    int h = 1 << n - 1;
    if (k > h / 2)
        return !(kthGrammer(n - 1, k - h / 2));
    else
        return kthGrammer(n - 1, k);
}
/// @brief what is subset: [8 3 9] : [] ie fi is subset of s ..
//  [8] [3] [9]
// [8 3] [8 9]
// [3 9]
// [8 3 9] ie set  s is subset of s
/// @param op :
/// @param ip  :'abc'
void printSubset(string op, string ip)
{
    if (ip.size() == 0)
    {
        cout << op << " ";
        return;
    }
    string op1 = op;
    string op2 = op;
    char firstC = ip[0];
    ip.erase(ip.begin() + 0);
    op2.push_back(firstC);

    printSubset(op1, ip);
    printSubset(op2, ip);
}
void printUniqueSubset(string op, string ip, set<string> &s, vector<string> &v)
{
    if (ip.size() == 0)
    {
        if (s.find(op) == s.end())
        {
            s.insert(op);
            v.pb(op);
            return;
        }
    }
    string op1 = op;
    string op2 = op;

    char firstC = ip[0];
    ip.erase(ip.begin() + 0);
    op2.pb(firstC);
    printUniqueSubset(op1, ip, s, v);
    printUniqueSubset(op2, ip, s, v);
}
void appendWithSpaces(string op, string ip)
{
    if (ip.size() == 0)
    {
        cout << op << " ";
        cout << endl;
        return;
    }
    if (op.size() == 0)
    {
        char firstC = ip[0];
        ip.erase(ip.begin() + 0);
        op.push_back(firstC);
        appendWithSpaces(op, ip);
    }
    else
    {
        string op1 = op;
        string op2 = op;
        char firstC = ip[0];
        ip.erase(ip.begin() + 0);
        op2.pb('_');
        op2.pb(firstC);
        appendWithSpaces(op1, ip);
        appendWithSpaces(op2, ip);
    }
}
void appendwithCaseChange(string op, string ip)
{
    if (ip.size() == 0)
    {
        cout << op << " ";
        return;
    }
    string op1 = op;
    string op2 = op;
    op1.push_back(tolower(ip[0]));
    op2.pb(toupper(ip[0]));
    ip.erase(ip.begin() + 0);
    appendwithCaseChange(op1, ip);
    appendwithCaseChange(op2, ip);
}
void letterNumber(string op, string ip)
{
    if (ip.size() == 0)
    {
        cout << op << " ";
        return;
    }
    char x = ip[0];
    if ('A' <= x && x <= 'Z' || 'a' <= x && x <= 'z')
    {
        string op1 = op;
        string op2 = op;
        ip.erase(ip.begin() + 0);
        op1.pb(tolower(x));
        op2.pb(toupper(x));
        letterNumber(op1, ip);
        letterNumber(op2, ip);
    }
    else
    {
        op.pb(ip[0]);
        ip.erase(ip.begin() + 0);
        letterNumber(op, ip);
    }
}
void parenthesis(string op, int open, int close)
{
    if (open == 0 && close == 0)
    {
        cout << op << endl;
        return;
    }
    if (open < close)
    {
        string op1 = op;
        op1.pb(')');
        parenthesis(op1, open, close - 1);
    }
    if (open != 0)
    {
        string op2 = op;
        op2.pb('(');
        parenthesis(op2, open - 1, close);
    }
    return;
}
void appendBInaryDig(string op, int ones, int zeros, int n)
{
    if (n == 0)
    {
        cout << op << endl;
        return;
    }
    if (ones > zeros)
    {
        string op1 = op;
        op1.pb('0');
        appendBInaryDig(op1, ones, zeros + 1, n - 1);
    }
    string op2 = op;
    op2.pb('1');
    appendBInaryDig(op2, ones + 1, zeros, n - 1);
}
void joseph(vi v, int i, int k)
{
    if (v.size() == 1)
    {
        cout << v[0];
        return;
    }
    i = (i + k) % v.size();
    v.erase(v.begin() + i);
    joseph(v, i, k);
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    joseph(v, 0, k - 1);
}
