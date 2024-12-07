#include <iostream>
#include <vector>

using namespace std;
int solve_1(vector <int>v,int key){
//this by striver :
    int s=0;
    int e=v.size()-1;
    int m=0;
    while(s<=e){
        m=s+(e-s)/2;
        if (v[m]==key){
            
            return m; 
        }
        // first half
        if (v[s]<=v[m]){
            //mean first half is sorted
            // check for the key in this sorted half
            if (v[s]<=key && key<=v[m]){
                // check in first that key is present or not
                //means it shoud be in the first half oonly so move to first half by e=m-1
                e=m-1; 

            }
            else {
                s=m+ 1; 
            }

        }
        else{
            //second half is sorted 
            if (v[m]<=key && key<=v[e]){
                // check in second that key is present or not  
                s=m+1; 

            }
            else {
                e=m-1; 
            }

        }
    }
    return -1;
}

int main(){
    vector<int> v={7,8,1,2,3,4,5,6};
    solve_1(v,0);

}
