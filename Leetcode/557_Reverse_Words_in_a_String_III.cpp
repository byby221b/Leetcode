#include <iostream>
#include <string>
using namespace std;

/*
	Name: 
	Copyright: 
	Author: 
	Date: 02/09/19 10:52
	Description: 
*/

//class Solution {
//public:
//    string reverseWords(string s) {
//    	if(s=="") return s;
//    	
//  		char *res = new char[s.length()+5];
//  		char *ptr = res;
//		string::iterator begin = s.begin();
//		string::iterator end = s.begin();
//		string::iterator tmp;
//		while(end!=s.end()){
//			while(end!=s.end()&&(*end)!=' ') end++;
//			if(end!=s.begin()){
//				tmp = end - 1;
//				while(tmp>=begin){
//					*ptr = *tmp;
//					ptr ++;
//					tmp --;
//				}
//			}
//			*ptr = ' ';
//			ptr ++;
//			
//			if(end!=s.end()){
//				begin = end + 1;
//				end = end + 1;
//			}
//		}
//		*(ptr-1) = '\0';
//		
//		string str_res(res);
//		return str_res;
//    }
//};

class Solution {
public:
    string reverseWords(string s) {
    	if(s=="") return s;
    	
  		string::iterator 
		return str_res;
    }
};

int main(){
	Solution su = Solution();
	string test = "Let's take LeetCode contest";
//	string test = "hello";
	string res = su.reverseWords(test);
	
	cout << res << endl;
	
	return 0;
}
