#include <iostream>
#include <vector>

using namespace std;
/*
	Name: 
	Copyright: 
	Author: 
	Date: 03/09/19 20:57
	Description: 对于每一个数，分别计算其左侧的乘积和右侧的乘积 
*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),1);
        res[0] = 1;
        
        for(int i=1;i<nums.size();i++){
        	res[i] = res[i-1] * nums[i-1];
		}
		
		int tmp = 1;
		for(int i=nums.size()-2;i>=0;i--){
			tmp *= nums[i+1];
			res[i] *= tmp;
		}
		
		return res;
    }
};


int main(){
	Solution su = Solution();
	
	vector<int> test = {2,3,4,5};
	
	vector<int> res = su.productExceptSelf(test);
	
	for(auto item:res) cout << item << " ";
	
	cout << endl;
	
	return 0;
}
