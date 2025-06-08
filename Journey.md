
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
7. [CFA](https://codeforces.com/contest/1997/problem/A)
```c++
#include <bits/stdc++.h>
string adds(char c,string s,int n){
   string res="";
   if(c>='a'&&c<'z')c=c+1;
   else c=c-1;
   int m=s.size();
   forz(i,m){
    if(i==n)res.push_back(c);
    res.push_back(s[i]);
   }
    return res;
}
//*+-/
//++,-+,--,+-
int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        string res="";
        cin>>s;
        
        int n=s.size();
        if(n==1){
            char c=s[0];
            if(c>='a'&&c<'z'){cout<<c;c=c+1;cout<<c;}
            else cout<<c-1<<c;
        }
        stack<char> st;
        st.push(s[0]);
        foro(i,n){
            char c=st.top();
            if(c==s[i]){
                res=adds(c,s,i);
                break;
            }
            st.push(s[i]);
        }
        cout<<res<<endl;
    }
}
```
9. [Prefix with Hash]()
```c++
int main() {
    int n;
    cin>>n;
    int a[n]={0};
    int t;cin>>t;
    // make the hash
    forz(i,t){
        int l,r,x;
        cin>>l>>r>>x;
        a[l]+=x;
        a[r+1]-=x;
    }
    // make the prfx
    foro(i,n-1){
        a[i]+=a[i-1];
    }
    int mx=a[0];
    forz(i,n){
        cout<<a[i]<<" ";
        if(mx<a[i])mx=a[i];
    }
    cout<<endl;
    cout<<mx;
    
}
```