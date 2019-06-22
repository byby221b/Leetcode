/*
	Name: 
	Copyright: 
	Author: Yong Bai
	Date: 18/04/19 16:13
	Description: 
*/

#include <iostream>
#include <string>

using namespace std;
/*
class Solution {
public:
	int findPalindromic(string::iterator left,
						 string::iterator right,
						 int maxLength
						){
//		cout << right - left << endl;
		while((right-left+1)>maxLength){
			string::iterator leftTmp = left, rightTmp = right;
			while(leftTmp<=rightTmp){
				if(*leftTmp == *rightTmp){
					leftTmp ++;
					rightTmp --;
				}else{
					break;
				}
			}
			if(leftTmp > rightTmp){
//				cout << "maxLength:" << right - left + 1 << endl;
				return (right - left + 1);
			}
			left ++;
		}
		
		return -1;
	}
    string longestPalindrome(string s) {
    	if(s==""){
    		return s;
		}
  		int maxLength = 0;
  		string::iterator maxTail = s.begin();
  		for(string::iterator p = s.begin();p!=s.end();p++){
  			int currLength = findPalindromic(s.begin(),p,maxLength);
  			if(currLength!=-1){
  				maxLength = currLength;
  				maxTail = p;
			}
		}
		int begin = maxTail - s.begin() - maxLength + 1;
		return s.substr(begin,maxLength);
    }
};
*/
class Solution {
public:
	string longestPalindrome(string s){
		int maxLength = 0;
		string::iterator idx = s.begin();
		string::iterator maxStart = s.begin();
		while(idx<s.end()){
			string::iterator begin = idx,end = idx;
			while(end+1<s.end() && *end==*(end+1)){
				end ++;
			}
			idx = end + 1;
			
			while(*(begin-1)==*(end+1) && begin-1>=s.begin() && end+1<s.end()){
				cout << (*begin) << " " << (*end) << endl;
				begin --;
				end ++;
			}
			
			int currLength = end - begin + 1;
			if(currLength>maxLength){
				maxLength = currLength;
				maxStart = begin;
			}
		}
		int start = maxStart - s.begin();
		return s.substr(start,maxLength);
	}
};

int main(){
	Solution solution = Solution();
	string test = "babad";
//	test = "cbbd";
	test = "a";
	test = "qwertyuiopasdfghjklzxcvbbnmn";
	test = "";
	test = "abcdasdfghjkldcba";
	cout << solution.longestPalindrome(test);
	return 0;
}

