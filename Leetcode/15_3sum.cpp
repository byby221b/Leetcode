/*
	Name: 
	Copyright: 
	Author: 
	Date: 05/08/19 20:18
	Description: Ë«Ö¸Õë 
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        
        int n = nums.size();
        
        if(n<3){
        	return result;
		}
		
		sort(nums.begin(),nums.end());
		
		for(int i=0;i<n-2;i++){
			if(i!=0 && nums[i]==nums[i-1]) continue;
			if(nums[i]>0) break;
			
			int tmp = -nums[i];
			int left = i + 1 ,right = n - 1;
			while(left<right){
				if(nums[left]+nums[right]==tmp){
//					vector<int> ans;
//					ans.push_back(nums[i]);
//					ans.push_back(nums[left]);
//					ans.push_back(nums[right]);
					result.push_back({nums[i],nums[left],nums[right]});
					do{
						left ++;
					}while(nums[left]==nums[left-1] && left<right);
					do{
						right--;
					}while(nums[right]==nums[right+1] && left<right);
				}else if(nums[left]+nums[right]<tmp){
					do{
						left ++;
					}while(nums[left]==nums[left-1] && left<right);
				}else{
					do{
						right--;
					}while(nums[right]==nums[right+1] && left<right);
				}
			}
		}
        
        return result;
    }
};


int main(){
	Solution su = Solution();
	vector<int> test = {-1, 0, 1, 2, -1, -4};
//	vector<int> test = {0,0,0};
	vector<vector<int> > res = su.threeSum(test);
	
	for(int i=0;i<res.size();i++){
		cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << " " << endl; 
	}
	
	return 0;
}
