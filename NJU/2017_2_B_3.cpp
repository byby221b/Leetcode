/*
	Name: 
	Copyright: 
	Author: 
	Date: 27/06/19 21:24
	Description: 求两个数的和不一定需要两层for循环 
*/


#include <iostream>
#include <algorithm> 
#include <vector>

using namespace std;


	class Solution {
	public:
	    int triangleNumber(vector<int>& nums) {
	  		int size = nums.size();
	  		if(size<3){
	  			return 0;
			}
			
			sort(nums.begin(),nums.end());
			
			int res = 0;
			for(int i=size-1;i>0;i--){
				if(nums[i]==0) break;
				
				int l = 0 , r = i - 1;
				while(nums[l]==0 && l<size) l++;
				while(l < r){
					if(nums[l] + nums[r]>nums[i]){
						res += ( r - l );
						r --;
					}else{
						l ++;
					}
				}
			}
			
			return res;
	    }	
	};



int main(){
	vector<int> test = {2,3,2,4};
//	vector<int> test = {0,0,0};
	Solution su = Solution();
	cout << su.triangleNumber(test) << endl;
	return 0;
}
