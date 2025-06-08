##### HERE we POST Problems(LINK) with solution(CODE) and the imgaes(Intuition/Pseudocode) links (Deploy images in CORRECT folder) 
---
> Deepak's Section

###### Edit here only 
---
> Ishaan's Section

###### Edit here only
---
> Rahul's Section

###### Edit here only
1. [Search in Rotated Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)
```C++
class Solution {
public:
    int findMinInd(vector <int>&v){
        // 345601,345012,78123456
        int s=0;
        int e=v.size()-1;
        
        //means array is not rotated so 0th has the lowest number so return 0 index;
        if (v[s]<v[e]){
            cout<<"ooo"<<endl;
            return s;
        }
        while (s<=e){
            int m=s+(e-s)/2;
            int n=(m+1)%v.size();
            int p=(m+v.size()-1)%v.size();
            
            if (v[p]>=v[m]&&v[m]<=v[n]){
                cout<<"pppp"<<endl;
                return m;
            }

            if (v[m]<=v[e]){
                e=m-1;
            }
            else if ( v[s]<=v[m]) {
                s=m+1;
            }
                    
        }
        return -1;
    }

    int binSearch(vector<int> &v,int k,int l,int h){
        int m,s=l,e=h;
        while (s<=e){
            m=s+(e-s)/2;
            if (v[m]==k){
                return m;
            }
            else if (v[m]<k){
                s=m+1;
            }
            else if (v[m]>k){
                e=m-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int index=findMinInd(nums);
        int l=binSearch(nums,target,0,index-1);
        int r=binSearch(nums,target,index,nums.size()-1);
        if (l==-1){
            return r;
        }
        else {
            return l;
        }
        return -1;        
    }

    
};
```
2. [Soldier And Bananas(800)*](https://codeforces.com/problemset/problem/546/A)
```C++
#include<iostream>
using namespace std;
int main(){
    //* (n(a+l))/2
    long long k,n,w,total;
    cin>>k>>n>>w;
    total=w*(k+(k*w))/2;
    if (total<=n) cout<<0;
    else cout<<total-n;
}
```
3. [Square?](https://codeforces.com/problemset/problem/1351/B)
```C++
int main(){
    //*
    cin>>t;
    while(t--){
        int l1,b1,l2,b2;
        cin>>l1>>b1>>l2>>b2;
        // check
        if ((l1==l2 && b1+b2==l1)||(l1==b2 && l2+b1==l1)||(l2==b1 &&l1+b2==l2)||(b1==b2&&l1+l2==b1)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
```
4. [Buy a Shovel](https://codeforces.com/problemset/problem/732/A)
```C++
#include<iostream>
using namespace std;
int fn(){
    int k,r;
    int sh=1;
    cin>>k>>r;
    while((k*sh)%10!=r){
        if((k*sh)%10==0) break;
        sh++;
    }
    cout<<sh;
}
int main(){
    fn();
}
```
5. [Dasha And stairs](https://codeforces.com/problemset/problem/761/A)
```c++
void DashaAndStairs(){
    int e,o;
    cin>>e>>o;
    int sum=e+o;
    //sum is even
    //edge 
    if (sum==0)cout<<"NO\n";
    else if(sum%2==0){
        if (e==o)cout<<"YES\n";
        else cout<<"NO\n";
    }
    //if sum is odd
    else {
        if (e+1==o||e==o+1)cout<<"YES\n";
        else cout<<"NO\n";
    }

}
```
6. [New Year](https://codeforces.com/contest/750/problem/A)
###### Binary search 


```C++
#include <iostream>
#include<vector>
using namespace std;
int BiFloor(vector <int> v,int key){
    int s=0,e=v.size()-1,m,candidate=-1;
    while (s<=e){
        m=s+(e-s)/2;
          
        if (v[m]<=key){
            candidate=m;
            s=m+1;
        }
        else if (v[m]>key){
            e=m-1;
        }

    }
    return candidate+1;
}
int createVeactor(vector <int>&v,int n){
    if (n==1){
        v.push_back(5);
        return 5;
    }
    int x=createVeactor(v,n-1)+5*n;
    v.push_back(x);
    return x;
}
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> v;
    createVeactor(v,n);
    cout<<BiFloor(v,240-k);
    return 0;
}
```

7. [Using More Ram](https://codeforces.com/problemset/problem/1987/A)
>Brute force 
```c++
#include <iostream>
using  namespace std;
void fn(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int i =1,c=0;
        while(true){
        c++;
        if (c==n){
            //cout<<i<<endl;
            break;
            }
        i=i+k;
        }
        cout<<i<<endl;
    }
    return;    
}
int main(){
    fn();
}

```

>(optimal): Getting the nth term of ap
```c++
#include <iostream>
using namespace std;
void fn_2(){
    //getting nth term of a ap is 1,(1+k),(1+2k),...,An.
    int t ;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        cout<<(k*(n-1)+1)<<endl;;
    }
    return;
}
int main(){
    fn_2(); 
}
```

8. [Multiple OF sum](https://codeforces.com/problemset/problem/1985/B)
>Sum of Gp 
```c++
#include<iostream>

using namespace std;

int primes[101];

void SieveAlgo(){
    //1: is A primes
    //0: is a COmp
    int n=100;

    for(int i=2;i<=n;i++){
        primes[i]=1;
    }
    primes[0]=primes[1]=0;
    for (int i=2;i*i<=n;i++){
        if (primes[i]){
            for (int j=i*i;j<=n;j+=i){
                primes[j]=0;
            }
        }
    }
}
void whichIsMax(int m){
    int max=0,num=0;
    for(int i=2;i<=m&&primes[i];i++){
        int n=m/i;
        int l=n*i;
        if (n>1){
            int sum=(n*(i+l))/2;
            if (max<sum) {
                max=sum;
                num=i;
            }
        }
        else if (max<i) {
            max=i;
            num=i;
        }

    }
    cout<<num<<endl;

}
int main(){
    int t;
    cin>>t;
    SieveAlgo();
    while(t--){
        int m;
        cin>>m;
        whichIsMax(m);
    }
    
}
``` 



9. E=[X-asis](https://codeforces.com/profile/FabBerry#)
```c++
#include <iostream>
#define for(i,n)  for (int i=0;i<n;i++)
using namespace std;
void fn(){
    int t;
    cin>>t;
    while(t--){
        int arr[3];
        for(i,3){
            cin>>arr[i];
        }
        int res=INT_MAX,v1=0;
        for(i,3){            
            for(j,3){
                v1+=abs(arr[j]-arr[i]);
            }
            if(res>v1){
                res=v1;
            }
            v1=0;
        }
        cout<<res<<endl;       
    }   
}
int main() {
    fn();
}

```

10. [Binary L/R]()
```c++
#include <bits/stdc++.h>
//#include <iostream>

#define mod 1000000007
#define pb push_back 
#define ff first 
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
#define foro(i,n) for(int i=1;i<=n;i++)
#define forz(i,n)  for (int i=0;i<n;i++)
using namespace std;


//*+-/
//++,-+,--,+-

int main() {
        // ios_base::sync_with_stdio(false);
        //     cin.tie(NULL);
    int n,k;
    cin>>n;
    vi v(n);
    forz(i,n)cin>>v[i];
    sort(v.begin(),v.end());
    cin>>k;
    while(k--){
        int l,r;
        cin>>l>>r;
        int s=0,e=n-1,m,lcandi=n,rcandi=-1;
    while (s<=e){
        m=s+(e-s)/2;
        if (v[m]<=r){
            rcandi=m;
            s=m+1;
        }
        else if (v[m]>r){
            e=m-1;
        }
    }
    s=0,e=n-1;
    while(s<=e){
        m=s+(e-s)/2;
        if (v[m]>=l){
            lcandi=m;
            e=m-1;
        }
        else if (v[m]<l){
            s=m+1;
        }
    }
    cout<<rcandi -lcandi+1<<" ";
        

    }
}

```

9. []()
```c++

```