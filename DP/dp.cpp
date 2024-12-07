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

// 0/1 knapsack problem-> kuch items hai and ek weight diya  hai and hame item me se choose karna hai ki konsa
// hum choose kare ki hamara profit maximum ho.

// problem 1: item[],value[],W.(n is size of vecotrs) where items have weights and value has profit respectily
int knapsackRec(int item[], int value[], int w, int n)
{
    if (n == 0 || w == 0)
        return 0;
    if (item[n - 1] <= w)
    {
        return max(value[n - 1] + knapsackRec(item, value, w - item[n - 1], n - 1), knapsackRec(item, value, w, n - 1));
    }
    else
    {
        return knapsackRec(item, value, w, n - 1);
    }
}

// memo: jiski values change horhi (choti hoti jarhi)  hai unka matrix banegi t[n+1][w+1]
int t[100 + 1][1000 + 1]; // n<101,w<101
int knapsackByMemo(int item[], int value[], int w, int n)
{
    if (n == 0 || w == 0)
        return 0;

    // checking t[][]
    if (t[n][w] != 0)
        return t[n][w];
    if (item[n - 1] <= w)
    {
        // added t[][]
        return t[n][w] = max(value[n - 1] + knapsackByMemo(item, value, w - item[n - 1], n - 1), knapsackByMemo(item, value, w, n - 1));
    }
    else
    {
        // added t[][]
        return t[n][w] = knapsackByMemo(item, value, w, n - 1);
    }
}
// Real dp
//  yha matrix ka first r/c base value se init hote hai hai to yha n+2 elms honge to n+1 tk elms bne and after base init we stoill have t[n] to axs
// The approach : choti chhoti sub problems ko solve karke hum next value bhr rhe or answer nikal rhe and last me last cell ko bhr ke we got our answer
int dp[102][1002];
int knapsackfordp(int item[], int value[], int w, int n)
{
    if (n == 0 || w == 0) // rec fn ki base condn to vo real dp ke init mem change hojati hai we rthrn 0 so init 0
        return 0;

    // above code change into :
    //  all elems in matrix init as 0

    if (item[n - 1] <= w)
    {
        return max(value[n - 1] + knapsackfordp(item, value, w - item[n - 1], n - 1), knapsackfordp(item, value, w, n - 1));
    }
    // above code change into :
    //  t[n][w]=max(value[n-1]+ t[n-1][w-item[n-1]],t[n-1][w])
    else
    {
        return knapsackfordp(item, value, w, n - 1);
    }
    // above code change into :
    //  t[n][w]=t[n-1][w]
}
int knapsackDp(int item[], int value[], int w, int n)
{

    // above code change into :
    //  all elems in matrix init as 0
    int t[n + 1][w + 1];
    forz(i, n + 1)
    {
        forz(j, w + 1)
        {
            t[i][j] = 0;
        }
    }

    // solving all sub problems
    foro(i, n)
    {
        foro(j, w)
        {
            if (item[i - 1] <= j)
            {
                t[i][j] = max(value[i - 1] + t[i - 1][j - item[i - 1]], t[i - 1][j]);
            }
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][w];
}

bool problem1(int arr[], int w, int n)
{
    bool t[n + 1][w + 1];
    forz(i, n + 1)
    {
        forz(j, w + 1)
        {
            if (i == 0)
                t[i][j] = false;
            if (j == 0)
                t[i][j] = true;
        }
    }
    foro(i, n)
    {
        foro(j, w)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][w];
}

bool problem2(int arr[],int n){
    // dp kaise ? see yha hum bbar baar check kar rhe ki subset ka sum kya bana and badki left out subset ka sum kya bana and kya vo dono equal hai 
    //ek array ko do subset me divide kar sakte jiska sum equal hhaye
    //array sub 1 and sub 2 ka sum hai let s so dono sum s hai and 2s milke array ka sum mil tha hai 
    //now 2s will alwyas be even regardless of s.
    //means array ka sum even hoga tabhi possible hai ki subset ho maybe . even hone ke baad still chance ki sub set namile

    // eg: 22 ko half partiction karskte 11,11 but 23 ?? not exit any 2 subset  jo 

    //check sum : if even means chance we can get a subset 
    int s=0;
    forz(i,n){
        s+=arr[i];
    }
    if(s%2)return false;
    //now if even then we do something ... idk ..now 
//now if i know arrayka sum 22 hai so i need to check konse subset hai jo sum 11 ie s/2 bana rhe 
    return problem1(arr,s/2,n);
}


int problem3(int a[],int n,int sum){
    // int c=0;
    // forz(i,n){
    //     bool res=problem1(a,sum,n-i);
    //     if(res)c++;
    // }
    // return c;
    int t[n+1][sum+1];
    forz(i,n+1 ){
        forz(j,sum+1){
            if (i==0)t[i][j]=0;
            if(j=0)t[i][j]=1;
        } 
    }
    forz(i,n+1){
        forz(i,sum+1){
             
        }
    }

}
int main()

{
    int arr[] = {2,3,5,6,8,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << problem3(arr, n,10);
}
