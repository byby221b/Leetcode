/*
	Name: 
	Copyright: 
	Author: 
	Date: 04/07/19 14:14
	Description: dfs 由于数据量比较小只有6位所以可以直接搜索
				简单剪枝，sum>target直接跳出搜索 
*/

#include <iostream>

using namespace std;

bool run(){
	int target,num;
	
	cin >> target >> num;
	
	if(target==0 && num==0) {
		return false;
	}
	
	if(target==num){
		cout << num << " " << num << endl;
		return true;
	}
	
	int digits[10];
	int count = 0;
	int tmp = num;
	while(tmp!=0){
		digits[count] = tmp%10;
		tmp/=10;
		count ++;
	}
	
	int magic = 1 << (count - 1);
	
	int sum;
	bool reject = false;
	int maxSum = -1 , maxMagic = -1;
	for(int m=0;m<magic;m++){
		sum = 0;
		tmp = digits[count-1];
		int mTmp = m;
		bool con_flag = false;
		for(int i=count-2;i>=0;i--)	{
			int flag = mTmp&1;
			mTmp = mTmp >> 1;
			if(flag==1){
				tmp = 10 * tmp + digits[i] ;
			}else{
				sum += tmp;
				tmp = digits[i];
				if(sum>target){
					con_flag = true;
					break;
				}
			}
		}
		
		if(con_flag) continue;
		sum += tmp;
//		cout << sum << endl;
		if(sum==maxSum){
			reject = true;
		}else if(sum <= target && sum > maxSum){
			reject = false;
			maxSum = sum;
			maxMagic = m;
		}
	}
	
	if(maxSum==-1){
		cout << "error" << endl;
	}else if(reject){
		cout << "rejected" << endl;
	}else{
		cout << maxSum << " ";
		tmp = digits[count-1];
		for(int i=count-2;i>=0;i--)	{
			int flag = maxMagic & 1;
			maxMagic = maxMagic >> 1;
			if(flag==1){
				tmp = 10 * tmp + digits[i] ;
			}else{
				cout << tmp << " ";
				tmp = digits[i];
			}
		}
		cout << tmp << " " << endl;
	}
	
	return true;
}


int main(){
	while(run());
	return 0;
}
 
