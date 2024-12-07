#include <bits/stdc++.h>

using namespace std;
void solve_1(int n){
    //questin :PRINT 1 to N=3
    //op:1 2 3
    if (n==1){
        cout<<1;
        return;
    }
    solve_1(n-1);
    cout<<" "<<n;
}
void insertfn(vector <int> &v ,int save){
    if (v.size()==0 || v.back()>=save){
        v.push_back(save);
        return;
    }
    int temp=v.back();
    v.pop_back();

    insertfn(v,save);
    v.push_back(temp);
    
}
void solve_3(vector<int> &v ){
    //solve_3 + insertfn()
    //SOrt array : 2 50 3 9 10 -1 0 
    //op: 50 10 9 3 2 0 -1 
    if (v.size()==1){
        return;
    }
    int save=v.back();
    v.pop_back();
    solve_3(v);
    insertfn(v,save);
}
void printVector(const std::vector<int>& vec) {
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
void printVector(const std::vector<string>& vec) {
    for (string i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
void solve_2(int n){
    //questin :PRINT N=3 to 1
    //op:3 2 1
    if (n==1){
        cout<<1;
        return;
    }
    cout<<n<<" ";
    solve_2(n-1);

}
stack<int> solve_4(stack<int> &s,int k ){
    if (k==1){
        s.pop();
        return s;
    }
    int temp=s.top();
    s.pop();
    solve_4(s,k-1);
    s.push(temp);
    return s;
}
stack<int> delet(stack<int> &s ){
    //ques: deleting the middle element [54321] 
    //solve_4 and delet()
    //op: [5421]
    if (s.size()==0){
        return s;
    }
    //or 
    /*if (k==1){
        s.pop();
        return;
    }
    or if (s.size()==3){

        s.pop();
        return;
    }*/
   int k=s.size()/2+1;
   solve_4(s,k);
   return s;
    
}
void printStack(std::stack<int> s) {
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}
void rev_ind(stack<int> &s, int save){
    if (s.size()==0){
        s.push(save);
        return ;
    }
    int temp=s.top();
    s.pop();
    rev_ind(s,save);
    s.push(temp);
}
void revrse(stack<int> &s){
    if (s.size()==1){
        return;
    }
    int save=s.top();
    s.pop();
    revrse(s);
    rev_ind(s,save);

}
int grammer(int n,int k){
    int size=pow(2,n-1);
    if (n==1 && k==1){
        return 0;
    }
    if (k<=size/2){
        return grammer(n-1,k);
    }
    else if (k>size/2){
        return !grammer(n-1,k-size/2);
    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//using rt method;

void solve_6(string ip,string op){
    //print all subsets; abc:
    // "" c b bc a ac ab abc 
    //aabc: c b bc a ac ab abc a ac ab abc aa aac aab aabc 
    if (ip.empty()){
        cout<<op<<" ";
        return;
    }
    string op_1=op;

    string op_2=op;
    op_2.push_back(ip[0]);


    ip.erase(ip.begin() +0);
    solve_6(ip,op_1);
    solve_6(ip,op_2);

}
void printSet(const set<string>& s) {
    for (const auto& subset : s) {
        cout << subset << endl;
    }
}
void solve_7(string ip,string op,set<string> &s){
     if (ip.empty()){
        s.insert(op);
        //cout<<"duplicate-"<<op<<" ";
        return;
        
    }
    string op_1=op;

    string op_2=op;
    op_2.push_back(ip[0]);


    ip.erase(ip.begin() +0);
    solve_7(ip,op_1,s);
    solve_7(ip,op_2,s);
}
void solve_8(string ip,string op){
    /*Permutaion with spaces : IP: ABC
    OP: A_B_c A_BC....*/
    if(ip.size()==0){
        cout<< op<<endl;;
        return;

    }
    if (op.size()==0){
        op.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        solve_8(ip,op);
    }
    string op_1=op;
    op.push_back('_');
    op.push_back(ip[0]);
    string op_2=op;
    op_2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    solve_8(ip,op_1);
    solve_8(ip,op_2);
    
}
void solve_11(string op,int o,int c){
    /*((()))
(()())
(())()
()(())
()()()
*/
    if (o==0&&c==0){
        cout<<op<<endl;
        return;
    }
    if (o!=0){
        string op1=op;
        op1.push_back('(');
        solve_11(op1,o-1,c);
    }
    // neeche wala should be if as else wont work
    if (o<c){
        string op2=op;
        op2.push_back(')');
        solve_11(op2,o,c-1);

    }
    return;
}
void solve_12(string op,int ones, int zeros,int n){
    // n-- WRONG IN FN CALL
    // why wehn i used n-- then no op , when changed the one fn call n-- to  n-1 then some thing happens in 
    // op then changed all things as n-- to n-1 in call then correct op means
    if (n==0){
        cout<<op<<endl;
        return;

    }
    if (ones>zeros){
        string op2=op;
        op2.push_back('0');
        solve_12(op2,ones,zeros+1,n-1);
        
    }
    string op1=op;
    op1.push_back('1');
    solve_12(op1,ones+1,zeros,n-1);

}
void solve_9(string ip,string op){
    /*Permutation with case changes :IP : abc
    op: abc
abC
aBc
aBC
Abc
AbC
ABc
ABC*/
    if (ip.size()==0){
        cout<<op<<endl;
        return;

    }
    string op1=op;
    string op2=op;
    op1.push_back(tolower(ip[0]));
    op2.push_back(toupper(ip[0]));
    ip.erase(ip.begin()+0);
    solve_9(ip,op1);
    solve_9(ip,op2);
}


void solve_10(string ip,string op){
    /*a1bc2
a1bC2
a1Bc2
a1BC2
A1bc2
A1bC2
A1Bc2
A1BC2
*/
    if (ip.size()==0){
        cout<<op<<endl;
        return;
    }
    if (isdigit(ip[0])){
        op.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        solve_10(ip,op);    
    }else {
        string op1=op;
        string op2=op;
        op1.push_back(tolower(ip[0]));
        op2.push_back(toupper(ip[0]));
        ip.erase(ip.begin()+0);
        solve_10(ip,op1);
        solve_10(ip,op2);

    }
    
    
    
}
//JOsEPh PRobLem
void solve_13(int index,int k,vector<int> &v){
    /*vector<int> v={1,2,3,4,5,6,7};
    int k=3;
    solve_13(0,k-1,v);*/
    if (v.size()==1){
        cout<<v[0];
        return;
    }
    index=(index+k)%v.size();
    v.erase(v.begin()+index);
    solve_13(index,k,v);
    return;
}
//Tower Of hanoi :
void solve_14(string from,string hlp,string dest,int disk){

    if (disk==1){
        cout<<"from "<<from<<" to "<<dest<<endl;
        return;
    }
    solve_14(from,dest,hlp,disk-1);
    cout<<"from "<<from<<" to "<<dest<<endl;
    solve_14(hlp,from,dest,disk-1);
    
}
void ins(string &s,char save){
    if (s.size()==0){
        s.push_back(save);
        return;
    }
    char temp=s.back();
    s.pop_back();
    ins(s,save);
    s.push_back(temp);
    return;
}
string rr(string &s){
    if (s.size()==0){
        return s;
    }
    char save=s.back();
    s.pop_back();
    rr(s);
    ins(s,save);
    return s;
}
int main(){


}