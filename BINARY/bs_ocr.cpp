#include <iostream>
#include <vector>
using namespace std;
int solve_last(vector<int> v,int k){
    int s=0;
    int e=v.size()-1;
    int m;
    int save=-1;
    while (s<=e){
        m=s+(e-s)/2;
        if (v[m]==k){
            
            save=m; //need to save that occured index and move in any ()side for continueing the search
            //move to more last side in search of prolly of lst occerrence
            s=m+1;
        }
        else if (v[m]<k){
            s=m+1;
        }
        else if (v[m]>k){
            e=m-1;
        }
    }
    return save;
}
using namespace std;
int solve(vector<int> v,int k){
    int s=0;
    int e=v.size()-1;
    int m;
    int save=-1;
    while (s<=e){
        m=s+(e-s)/2;
        if (v[m]==k){
            save=m; //need to save that occured index and move in any ()side for continueing the search
            e=m-1;
        }
        else if (v[m]<k){
            s=m+1;
        }
        else if (v[m]>k){
            e=m-1;
        }
    }
    return save;
}
double myPow(double x, int n) {
    if(n==0) return 1;
    double temp=myPow(x,n/2);
    double res=temp*temp;
    if(n%2==1) res=res*x; 
    
}
int main(){
   
    cout<<myPow(34.00515,-3);

    
    return 0;

}
