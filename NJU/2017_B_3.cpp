/*
	Name: 
	Copyright: 
	Author: 
	Date: 27/06/19 14:17
	Description: dp解法，考虑前i步能跳的最远距离 
*/
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
  		int size = nums.size();
  		
  		if(size<=1){
  			return true;
		}
		
		int far = nums[0];
		bool flag = false;
		if(far>=size-1){
			return true;
		}
		
		for(int i=1;i<size;i++){
			if(far >= i && far < i + nums[i]){
				far = i + nums[i];
			}
			
			if(far>=size-1){
				flag = true;
				break;
			}
		}
		
		return flag;
    }
};

int main(){
//	vector<int> test = {2,3,1,1,4};
	vector<int> test = {3,2,1,0,4};
	
	Solution su = Solution();
	string res;
	if(su.canJump(test)){
		res = "true";
	}else{
		res = "false";
	}
	cout << res << endl;
	return 0;
}

