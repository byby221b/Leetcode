/*
	Name: 
	Copyright: 
	Author: 
	Date: 29/06/19 19:44
	Description: 动态规划，单词枚举有点暴力
				(考试的时候不要忽略看似暴力的方法) 
*/

#include <iostream>
#include <string>

using namespace std;

string dic[605];

int main(){
	
	int W,L;
	cin >> W >> L;
	
	string msg;
	
	//input
	cin >> msg;
	for(int i=0;i<W;i++){
		cin >> dic[i];
	}
	
	
	int *dp = new int[L+5];
	
	dp[L] = 0;
	for(int i=L-1;i>=0;i--){
		int del = dp[i+1] + 1;
		
		for(int j=0;j<W;j++){
			string::iterator itWord = dic[j].begin();
			string::iterator itMsg = msg.begin() + i;
			for(;itMsg!=msg.end();itMsg++){
				if(itWord==dic[j].end()){
					break;
				}
				if(*itMsg==*itWord){
					itWord++;
				}
			}
			if(itWord==dic[j].end()){
				int idx = itMsg - msg.begin();
				int tmp = idx - i - dic[j].length() + dp[idx];
				if(tmp < del) del = tmp;
			}
		}
		
		dp[i] = del;
	}
	
	
	cout << dp[0] << endl;
	
	delete [] dp;
	
	return 0;
}

