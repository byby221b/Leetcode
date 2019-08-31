/*
	Name: 
	Copyright: 
	Author: 
	Date: 31/08/19 21:04
	Description: 分治法,每次以小于k的字母为界,将字符串拆分 
*/



#include <iostream>
#include <string>
#include <cstring>

#define NUM 26

using namespace std;

class Solution {
public:
	void divide(string::iterator begin,string::iterator end,int k){
		if(begin==end || (end-begin)<k) return;
		
		int count[NUM];
		memset(count,0,sizeof(count));
		
		string::iterator iter = begin;
		
		while(iter!=end){
			count[(*iter)-'a'] ++;
			iter++;
		}
		
		bool flag = true;
		for(int i=0;i<NUM;i++){
			if(count[i]>0 && count[i]<k){
				flag = false;
				count[i] = -1;
			}else{
				count[i] = 0;
			}
		}
		
		//all more than k 
		if(flag){
			len = (end - begin > len) ? end - begin : len;
			return;
		}
		
		string::iterator head=begin,tail=begin;
		while(tail!=end){
			while(tail!=end && count[(*tail)-'a']==0) tail++;
			if(tail-head>len){
				divide(head,tail,k);
			}
			if(tail!=end){
				tail ++;
				head = tail;
			}
		}
		
	}
    int longestSubstring(string s, int k) {
  		len = 0;
  		divide(s.begin(),s.end(),k);
  		return len;
    }
private:
	int len;
};

int main(){
	Solution su = Solution();
//	string test = "aaabb";
//	string test = "ababbc";
//	string test = "a";
	string test = "cbcaaab";
	int k = 3;
	
	int res = su.longestSubstring(test,k);
	
	cout << res << endl;
	
	return 0;
}
