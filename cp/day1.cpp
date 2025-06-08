#include <string>
#include<iostream>
#include <vector>
using namespace std;

string hh(string command) {
    //https://leetcode.com/problems/goal-parser-interpretation/submissions/1310732284/
    string s="";
    //Sliding window 
    for (int i =0;i<command.size();){
        if (command[i]=='G'){
            //i++;
            s.push_back('G');
            i++;
        }
        else if (i+1<command.size()&&command[i+1]==')'){
            //i+=2;
            s.push_back('o');
            i+=2;
        }
        else if (i + 3 < command.size() && command[i] == '(' && command[i + 1] == 'a' && command[i + 2] == 'l' && command[i + 3] == ')' ){
            //i+=4;
            s.append("al");
            i+=4;
        }
    
    }
    return s;
}
int scoreOfString(string s) {

    int x=0;
    for (int i=0;i<s.size()-1;){
        cout<<s[i]-'0'<<s[i+1]<<endl;
        x+=abs(s[i]-s[i+1]);
        i+=1;
    }
    return x;
}


int main(){
    vector<int>v={4,5,6,7,0,1,2};
}