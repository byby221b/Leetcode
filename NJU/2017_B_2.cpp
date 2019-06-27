/*
	Name: 
	Copyright: 
	Author: 
	Date: 27/06/19 14:11
	Description: greedy解法，比较trick 
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
		
		
		int target = size - 1;
		for(int i=size - 1;i>=0;i--){
			if(nums[i] + i>=target){
				target = i;
			}
		}
		
		return (target == 0);
		
    }
};

int main(){
	vector<int> test = {2,3,1,1,4};
//	vector<int> test = {3,2,1,0,4};
	
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

 

