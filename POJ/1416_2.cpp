/*
	Name: 
	Copyright: 
	Author: 
	Date: 04/07/19 15:03
	Description: dfs
*/


#include <iostream>

using namespace std;

int digits[10];
int count,target;
int path[10];
int maxSum,pathLen;
bool reject;

void dfs(int curr,int sum,int level,int pathIdx,int *tmpPath){
	if(level<0){
		sum += curr;
		tmpPath[pathIdx] = curr;
		if(sum==maxSum){
			reject = true;
		}else if(sum <= target && sum>maxSum){
			maxSum = sum;
			pathLen = pathIdx + 1;
			for(int i=0;i<pathLen;i++){
				path[i] = tmpPath[i];
			}
			reject = false;
		}
		
		return;
	}
	
	if(sum > target){
		return;
	}
	
	tmpPath[pathIdx] = curr;
	dfs(digits[level],sum+curr,level-1,pathIdx+1,tmpPath);
	dfs(curr * 10 + digits[level],sum,level - 1,pathIdx,tmpPath);
}

bool run(){
	int num;
	
	cin >> target >> num;
	
	if(target==0 && num==0) {
		return false;
	}
	
	if(target==num){
		cout << num << " " << num << endl;
		return true;
	}
	
	count = 0;
	int tmp = num;
	while(tmp!=0){
		digits[count] = tmp%10;
		tmp/=10;
		count ++;
	}
	
	maxSum = -1;
	reject = false;
	int tmpPath[10];
	
	dfs(digits[count-1],0,count-2,0,tmpPath);
	
	if(maxSum==-1){
		cout << "error" << endl;
	}else if(reject){
		cout << "rejected" << endl;
	}else{
		cout << maxSum << " ";
		for(int i=0;i<pathLen;i++){
			cout << path[i] << " ";
		}
		cout << endl;
	}
	
	return true;
}


int main(){
	while(run());
	return 0;
}
 
