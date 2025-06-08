1. Converting orginal Array into a Prefix Array
* #### Making
    - **of 0 based Array**

```cpp
int a[n];
forz(i,n)cin>>a[i];
foro(i,n-1)a[i]+=a[i-1];
forz(i,n)cout<<a[i]<<" "; // * old array={1 2 3} && newPfxAr = {1 3 6}
```
*
    - **of 1Based Array**
```cpp
int a[n+1]={0};
foro(i,n)cin>>a[i]; // * 1Based Array
foro(i,n)a[i]+=a[i-1];
forz(i,n+1)cout<<a[i]<<" "; // * old array={0,1 2 3} && newPfxAr = {0 1 3 6}
```
Have two choices Either `{1 3 6}` or `{0 1 3 6}` But 1 Based is Good as
in 0 based You have to Write IfElse in future either got 0based quesries or 1Based 
but in 1 Based array No need of IfElse

depending on the basis of L/R ( quiries ) have diff formulae for Extraction 

- Extraction from PrefixArray`{1 3 6}`
    * if L/R is 1 Based
        As Array is 0 Based and L/R 1 Based so convert L/R to 0 based 
    Note both array and quireies should be of same basis


```cpp
int l,r ;
cin>>l>>r;
cuz our Array itself was 0Based
l--;r--; // !! .'. converting 1Based L/r int 0Based 
if(l==0)cout<<a[r]<<endl;
else cout<<a[r]-a[l-1]<<endl; 
```
*
    * if L/R is  0 Based: bas l-- r-- wali line nahi likhni padegi else is same

* Extraction from PrefixArray `{0 1 3 6}`
    * if L/R of 1 Based : as Both array and lr of same basis direct use formula for lr 1 based `A[r]-A[l-1]`
```cpp
int l,r;
cin>>l>>r;
cout<<a[r]-a[l-1]<<endl;
```
*
    * for 0Based L/R same just formula changes as L/R is 0 Based so `A[r+1]-A[l]`
```cpp
int l,r;
cin>>l>>r;
l--;r--;
cout<<a[r+1]-a[l]<<endl; 
```
