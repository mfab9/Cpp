#include <bits/stdc++.h>
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
/*

1.Nearest Greater to Left/right.
2.Nearest smaller to left/right
3.Stock span problem
4.Maximising Area of Histogram
5.Maximum area of rectangle in Binary Matrix
*/
using namespace std;
vector<int> NGL(int arr[],int n){
    /*j DEPEND ON i -> stack
    for (int i =0;i<n-1;i++){
        int greaterIs=-1;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]) greaterIs=arr[j];
        }
        cout<<arr[i]<<"-->"<<greaterIs<<endl;

    */

   /*
   on my own 
   stack<int> s;
   ?declaring by (n) is important to use of v[i]; ow infi loop?
   vector<int> v(n);
   for(int i=n-1;i>=0;i--){
    *dum move: dont access top in an empty  // int t=s.top();
        while(!s.empty() && s.top()<=arr[i]){
        s.pop();
        }
        //means either we found the correct top or s is empty now 
        if (s.empty()) v[i]=-1;
        else v[i]=s.top();

        !mistake: forget to push and always checking top in loop w/o pushing atg
        s.push(arr[i]);
   }   
   return v;
   */
  stack<int> s;
  vector<int> v;
  for(int i=n-1;i>=0;i-- ){
    if (s.size()==0) v.push_back(-1);
    else if (s.size()>0&&s.top()>arr[i]) v.push_back(s.top());
    else if (s.size()>0 && s.top()<=arr[i]){
        while(s.size()>0&&s.top()<=arr[i]){
            s.pop();
        }
        if (s.size()==0) v.push_back(-1);
        else v.push_back(s.top());

    }
    s.push(arr[i]); 
  }


  reverse(v.begin(),v.end());
  return v;
}
vector<int> NGR(int arr[],int n){
    stack<int> s;
    vector<int> v;
    for (int i =0;i<n;i++){
        if (s.size()==0) v.push_back(-1);
        else if (s.size()>0&&s.top()>arr[i]) v.push_back(s.top());
        else if (s.size()>0 && s.top()<=arr[i]){
            while(s.size()>0&&s.top()<=arr[i]){
                s.pop();
            }
            if (s.size()==0) v.push_back(-1);
            else v.push_back(s.top());
        }
    s.push(arr[i]);

    }
    return v;
}

vector<int>NSL(int arr[],int n){
    stack<int> s;
    vector<int> v;
    for (int i =0;i<n;i++){
        if (s.size()==0) v.push_back(-1);
        else if (s.size()>0&&s.top()<arr[i]) v.push_back(s.top());
        else if (s.size()>0 && s.top()>=arr[i]){
            while(s.size()>0&&s.top()>=arr[i]){
                s.pop();
            }
            if (s.size()==0) v.push_back(-1);
            else v.push_back(s.top());
        }
        s.push(arr[i]);
    }

    return v;
    
}
vector<int>NSR(int arr[],int n){
    stack<int> s;
    vector<int> v;
    for (int i =n-1;i>=0;i--){
        if (s.size()==0) v.push_back(-1);
        else if (s.size()>0&&s.top()<arr[i]) v.push_back(s.top());
        else if (s.size()>0 && s.top()>=arr[i]){
            while(s.size()>0&&s.top()>=arr[i]){
                s.pop();
            }
            if (s.size()==0) v.push_back(-1);
            else v.push_back(s.top());
        }
        s.push(arr[i]);
    }
    reverse(v.begin(),v.end());

    return v;
    
}

vi stock(int arr[],int n){
    stack<ii> s;
    vi v;
    for(int i=0;i<n;i++){
        if(s.size()==0)v.push_back(i-(-1));
        else if (v.size()>0&&s.top().first>=arr[i])v.push_back(i-s.top().second);
        else if (v.size()>0&&s.top().first<arr[i]){
            while(s.size()>0&&s.top().first<arr[i]){
                s.pop();
            }
            if (s.size()==0)v.push_back(i-(-1));
            else v.push_back(i-s.top().second);
        }
        s.push({arr[i],i});
    }
    return v;
}

int hist(int arr[],int n){
    stack<ii> s,s2;
    vector<int> l,r;
    for (int i =0;i<n;i++){
        if (s.size()==0) l.push_back(-1);
        else if (s.size()>0&&s.top().first<arr[i]) l.push_back(s.top().second);
        else if (s.size()>0 && s.top().first>=arr[i]){
            while(s.size()>0&&s.top().first>=arr[i]){
                s.pop();
            }
            if (s.size()==0) l.push_back(-1);
            else l.push_back(s.top().second);
        }
        s.push({arr[i],i});
    }
    
    for (int i =n-1;i>=0;i--){
        if (s2.size()==0) r.push_back(n);
        else if (s2.size()>0&&s2.top().first<arr[i]) r.push_back(s2.top().second);
        else if (s2.size()>0 && s2.top().first>=arr[i]){
            while(s2.size()>0&&s2.top().first>=arr[i]){
                s2.pop();
            }
            if (s2.size()==0) r.push_back(n);
            else r.push_back(s2.top().second);
        }
        s2.push({arr[i],i});
    }
    reverse(r.begin(),r.end());

    vi w(n),area(n);
    for(int i=0;i<n;i++){
        w[i]=(r[i]-l[i])-1;
        area[i]=w[i]*arr[i];
    }
    return *max_element(area.begin(),area.end()); 
}
int rextMatrix(int a[4][4],int n){
    
    int v1[n];
    forz(i,n){
        v1[i]=a[0][i];
    }
    int v2[n];
    forz(i,n){
        if(a[1][i]==0)v2[i]=0;
        else v2[i]=v1[i]+a[1][i];
    }
    int v3[n];
    forz(i,n){
        if(a[2][i]==0)v3[i]=0;
        else v3[i]=v2[i]+a[2][i];
    }
    int v4[n];
    forz(i,n){
        if(a[3][i]==0)v4[i]=0;
        else v4[i]=v3[i]+a[3][i];
    }
    int m1,m2,m3,m4;
    m1=hist(v1,4);
    m2=hist(v2,n);
    m3=hist(v3,n);
    m4=hist(v4,n);
    int res=max({m1,m2,m3,m4});
    return res;
    
    // int v[n];
    // forz(i,n){
    //     v[i]=a[0][i];
    // }
    // int mx=hist(v,4);
    // foro(i,n-1){
    //     forz(j,n){
    //         if(a[i][j]==0)v[j]=0;
    //         else v[j]=v[j]+a[i][j];
    //     }
    //     mx=max(mx,hist(v,n));
    // }
    // return mx;

}

int main(){
    int a[4][4];
    forz(i,4){
        forz(j,4){
            cin>>a[i][j];
        }
    }
    cout<<rextMatrix(a,4);


}