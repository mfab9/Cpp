#include<iostream>
#include <vector>
#include<utility>
#include<algorithm>
using namespace std;
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}
//how many times array is rotated{INDEX OF MIN ELm} 
int solve(vector <int >&v){
    int n=v.size();
    int s=0,e=n-1,m,nxt,prev;
    
    while (s<=e){
        m=s+(e-s)/2;
        nxt=(m+1)%n;
        prev=(m+n-1)%n;
        if (v[prev]>=v[m] && v[m]<=v[nxt]){
            cout<<"Rotated "<<m<<" times\n";
            return m;
        }
        if (v[m]<=v[e]){
            e=m-1;
        }
        else if (v[s]<=v[m]) {
            s=m+1; 
        }
    }    
}
//search in sorted array :
int BiSearch(vector <int>v ,int l,int h ,int key){
    int s=l,e=h,m;
    while(s<=e){
        m=s+(e-s)/2;
        if (v[m]==key){
            cout<<"found at "<<m<<" index\n";
            return m;
        }
        if (v[m]>key){
            e=m-1;
        }
        else{
            s=m+1;
        }

    }
    return -1;
}
//search in rotated array 
int searchRot(vector <int>v,int key){
    int index=solve(v);
    int l=BiSearch(v,0,index-1,key);
    int r=BiSearch(v,index,v.size()-1,key);
    if (l==-1){
        return r;
    }
    return l;
}
//Search in nearly sorted arrray ;
int BiNearly(vector <int > v,int key){
    int s=0,e=v.size()-1,m;
    while(s<=e){
        m=s+(e-s)/2;
        // for checking key 
        if (v[m]==key){
            cout<<"found at "<<m<<" index\n";
            return m;
        }
        else if (v[m+1]==key){
            return m+1;
        }
        else if (v[m-1]==key){
            return m-1;
        }
        //for moveement 
        if (v[m]>key){
            e=m-1;
        }
        else{
            s=m+1;
        }

    }
    return -1;
}
// Search for floor of an element {greateas element that is smaller than(=) key }
int BiFloor(vector <int> v,int key){
    int s=0,e=v.size()-1,m,candidate=-1;
    while (s<=e){
        m=s+(e-s)/2;
        if (v[m]<=key){
            candidate=v[m];
            s=m+1;
        }
        else if (v[m]>key){
            e=m-1;
        }

    }
    return candidate;
}
// Search for CEIL of an element {smallest element that is greater than(=) key }
int BiCeil(vector <int> v,int key){
    int s=0,e=v.size()-1,m,candidate=-1;
    while (s<=e){
        m=s+(e-s)/2;
        
        if (v[m]>=key){
            candidate=v[m];
            e=m-1;
        }
        else if (v[m]<key){
            s=m+1;
        }

    }
    return candidate;
}
// Next Alphabet element:IP =f v=acfh op=h: smallest element that is greter than the key
char BiAlph(vector <char> v,char c){
    int s=0,e=v.size()-1,m;
    char candidate='#';
    // int key=c-'0';
    while (s<=e){
        m=s+(e-s)/2;
        if (v[m]==c){
            s=m+1;
        }
        else if (v[m]>c){
            candidate=v[m];
            e=m-1;
        }
        else if (v[m]<c){
            s=m+1;
        }

    }
    return candidate;

}

// Binary search on an infinite array
int BiInfinity(vector <int>v,int key){
    int s=0,e=1,m;
    while (key>v[e]){
        s=e+1;
        e=e*2;
    }
    while (s<=e){
        m=s+(e-s)/2;
        if (v[m]==key){
            return v[m];
        }
        if (v[m]>key){
            e=m-1;
        }
        else {
            s=m+1;
        }

    }
    return -1;
    
}
//Index of First "1" in A binary Sorted array(00000111)
int BiBinaryOne(vector<int> v){
    int s =0, e=v.size()-1,m,save;
    while(s<=e){
        m=s+(e-s)/2;
        if (v[m]==1){
            save=m;
            e=m-1;
        }
        else {
            s=m+1;
        }

    }
    return save;
}
// elelment that has a minimum difference with key
int BiMinimumDiff(vector <int>v,int key){
    int s=0,e=v.size()-1,m;
    while(s<=e){
        m=s+(e-s)/2;
        if (v[m]==key){
            return 0;
        }
        else if (v[m]>key){
            e=m-1;
        }
        else {
            s=m+1;
        }
    }
    int l=abs(v[e]-key);
    int r=abs(key-v[s]);
    return min(l,r);
}
// Binary Search On Answer : find Peak Element 
//ip:array (unsorted) op:index of peak(v[prev]<v[m]>v[next])element ;
int BiPeak(vector <int>v){
    int s=0,e=v.size()-1,m;
    while (s<=e){
        m=s+(e-s)/2;
        // if (m>0 && m<v.size() && v[m-1]<v[m] && v[m]>v[m+1]){
        //     return v[m];
        // }
        if (m>0 && m<v.size()-1){
            if (v[m-1]<v[m]&&v[m]>v[m+1]){
                return v[m];
            }
            
            else if (v[m-1]<v[m]){
                s=m+1;
            }
            else{
                e=m-1;
            }
            
        }
        else if (m==0){
            // arrray:[1] then we cant able to check the v[1]
            if (v.size()>1 && v[0]<v[1]){
                return v[1];
            }
            else {
                return v[0];
            }
        }
        else {
            
            if (v[v.size()-1]>v[v.size()-2]){
                return v[v.size()-1];
            }
            else{
                return v[v.size()-2];
            }
        }


    }
    return -1;
}
int BiMaxBitonic(vector <int>v){
    int s=0,e=v.size()-1,m;
    while (s<=e){
        m=s+(e-s)/2;
        // if (m>0 && m<v.size() && v[m-1]<v[m] && v[m]>v[m+1]){
        //     return v[m];
        // }
        if (m>0 && m<v.size()-1){
            if (v[m-1]<v[m]&&v[m]>v[m+1]){
                return m;
            }
            
            else if (v[m-1]<v[m]){
                s=m+1;
            }
            else{
                e=m-1;
            }
            
        }
        else if (m==0){
            // arrray:[1] then we cant able to check the v[1]
            if (v.size()>1 && v[0]<v[1]){
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            
            if (v[v.size()-1]>v[v.size()-2]){
                return v.size()-1;
            }
            else{
                return v.size()-2;
            }
        }


    }


}
int BiSearchBitonic(vector<int>v,int key){
    int s=0,e=v.size()-1,index=BiMaxBitonic(v);
    int l =BiSearch(v,0,index,key);
    int r=BiSearch(v,index+1,e,key);
    if (l==-1){
        return r;
    }
    else {
        return r;
    }
    return -1;    
}
pair<int,int> searchInMatrix(vector <vector <int>> v, int key){
    /*int rows = 3;
    int cols = 3;
    // Create a 2D vector
    vector<vector<int>> matrix;
    // Populate the 2D vector using push_back
    int c=0;
    for (int i = 0; i < rows; ++i) {
        vector<int> row;
        for (int j = 0; j < cols; ++j) {
            c++;
            row.push_back(c);
        }
        matrix.push_back(row);
    }
    printMatrix(matrix);
    cout<<endl;
    pair<int,int> cords=searchInMatrix(matrix,7);
    cout<<"i="<<cords.first<<",j="<<cords.second;
    */
    int rows=v.size();
    int cols=v[0].size();
    int i=0,j=cols-1;
    while (i>=0&& j>=0&j<cols&&i<rows){
        if (v[i][j]==key){
            cout<<v[i][j];
            return {i,j};
        }
        else if (v[i][j]<key){
            i++;
        }
        else {
            j--;
        }
    }
    return {-1,-1};
}

//Allocate pages problem -------------------------------------------------------------------------------------
// pS: hamare pe books ki list[v] hai now i need to distribute books to kisd [kids] suchthvat every kid got minimum number of pages to 
// read where k is the req kids among  i need to distribute agar distribute katrekarte i stuck at where i have some books left and all those k got books and i have to add 
// another kid kyunki me ek hi kid ko sari books nhi de skta and isiliye k kids ko deti jitni ban skti thi still i left some books so 
// i have to add another kid ,last me kya k kids me hi kaam ho paaya ya nahi ... ya mere pe books bch gyi or kids > k kids se , so ab i need to give some more books
// to each kid so k kids me hi kaam hojaye => i have to inc no. 
bool kid(vector <int>v,int sum,int k){
    if (v.size()<k){
        return false;
    }
    int s=0;
    int i=0;
    int kid=1;
    while(i<v.size()){
        
        s+=v[i];
        if (s>sum){
            s=v[i];
            kid++;
            if (kid>k){
                return false;
            }
        }
        //v.erase(v.begin()+i); 
        
        i++;
    }
    return true;
}
int allotPages(vector <int >&v,int k){
    int save=-1;
    //max(s)==40
    int s=*max_element(v.begin(),v.end());
    //
    //
    int sum=0;
    for(int i =0;i<v.size();i++){
        sum+=v[i];
    }
    //e==90 but here 100 for safety only 
    int e=sum;
    while(s<=e){
        //cout<<s<<" "<<e<<endl;
        //int m=s+(e-s)/2;
        int m = s + (e - s) / 2;
        if (kid(v,m,k)){
            cout<<m<<endl;
            save=m;
            e=m-1;
        }
        else{
            s=m+1;
        }
    }
    return save;
}
// ------------------------------------------------------------------------------------------------------

int main (){



}