#include <iostream>

using namespace std;
string rev(string s){
    string str="";
    for (int i =s.size()-1;i>=0;i--){
        str.push_back(s[i]);
    }
    return str;
}
void checkPallindrom(string s){
    int i=0;
    bool b=true;
	while(i<s.size()/2){
        if (s[i]!=s[s.size()-i-1]){
            b=false;
            break;
            
        }
        i++;
    }
    if(b){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}


void city_tour(){
    //ques https://www.hackerearth.com/problem/algorithm/city-tour/
    
}
void jiya_sub(){
/*ques https://www.hackerearth.com/problem/algorithm/jiyas-sequence/
Jiya likes a sequence if all its elements when multiplied yields a number , 
whose least significant digit is either 2, 3 or 5.
Given the number of  test case t.The first line of each test case is a number n.
Next line contains n integers - A1,A2,......An.
For each given test case tell whether the given sequence will be liked by Jiya.

INPUT FORMAT-
First line constains t number of test cases.
Every test case has first line as the number of intergers the sequence contains, followed by sequence in the next line.

OUTPUT FORMAT -
Print "YES" or "NO",whether Jiya likes the sequence or not*/
    int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long int prod=1;
		for (int i=0;i<n;i++){
            int ai;
		    cin>>ai;    
			prod =prod *ai;
		}
        int last =prod%10;
		if (last==2||last==3||last==5){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}
char upper(char c){
    //ques :hackerearth : capitalbaazi
	return 'A'+(c-'a');
    
}
void binary_dig(){
    /*binary wala :ques https://www.hackerearth.com/problem/algorithm/gpl/
    It's Binod's Birthday and all his friends want to have a great GPL for him. But Binod being so schemy, he locked his room with a secret number and given his friends a Binary string of secret number.
His friends have no knowledge about binary strings. Would you help his friends to convert given Binary String to Decimal and participate in Binod's GPL.
Binary String is a string with only '0' and '1'  as it's characters.


Examples : "000101", "10101", "1", "0", "01" are Binary Strings.
    "Ab3024", "123", "1A", "6", "AA" are not Binary Strings

Input Format
First Line :
Integer that denotes number of test cases.
For each Test Case :
Integer for size of Binary String and Binary String

Output Format
For each Test case, print Single Line integer containing the secret number.
*/
    long long int t;
    cin>>t; //no of test cases
    while(t--){
		int n;//size of string 
		cin>>n; 
        string s;// actual string of 0s and 1s; 
        cin>>s;


        //main concept: 1101: 1*2^3 + 1*2^2 + 0*2^1 + 1
        long long int num=0; //decimal number conversion
        
		long long int power2=1; //do [!C]? to make use of 1 then 2 then  4 then 8 like 2^of 0,1,2,3...
	    for (int i =n-1;i>=0;i--){
            int binary_digit =s[i]-'0';  // [!C]? s[i]: 0 or 1 -> to convert string 0/1(ASCII values) to integer 0/1 vale  
            num=num+(binary_digit*power2);
			power2*=2;
	    }   


        cout<<num<<endl;
    }
}

int main() {
    cout<<"k";
    
    
	
}