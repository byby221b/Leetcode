#include <iostream>
#include <vector>
using namespace std;
/*
	Name: 
	Copyright: 
	Author: 
	Date: 30/01/20 15:39
	Description: ¶þ·Ö²éÕÒ 
*/

class Solution {
public:
	int findHead(vector<int> &nums){
		
//		if(size==2){
//			return (nums[0]>nums[1]) ? 1 : 0;
//		}
		
		int left = 0, right = size - 1;
		while(nums[left]>nums[right]){
//			cout << left << " " << right << endl;
			int mid = (left + right) / 2;
			if (nums[mid]>=nums[0]){
				left = mid;
			}else{
				right = mid;
			}
			
			if(right-left==1){
				left = right;
				break;
			}
		}
		
		return left;
	}
	
//	int fetchNum(vector<int>& nums, int idx){
//		return (idx>=size) ? nums[idx - size] : nums[idx];
//	}
	
//	int binSearch(vector<int>& nums,int head, int target){
//		int left = head, right = head + size - 1;
//		int mid,value;
//		while(left<=right){
////			cout << left << " " << right << endl;
//			mid = (left + right) / 2 ;
//			value = (mid>=size) ? nums[mid-size] : nums[mid];
//			if (value==target){
//				return ((mid>=size) ? mid-size : mid);
//			}else if(value<target){
//				left = mid + 1;
//			}else{
//				right = mid - 1;
//			}
//		}
//		return -1;
//	}
	int binSearch(vector<int>& nums,int head, int target){
		int left,right;
		if (target < nums[head]){
			return -1;
		}
		if(target <= nums[size-1]){
			left = head;
			right = size - 1;	
		}else{
			left = 0;
			right = head - 1;
		}
		
		int mid,value;
		while(left<=right){
			cout << left << " " << right << endl;
			mid = (left + right) / 2 ;
			value = (mid>=size) ? nums[mid-size] : nums[mid];
			if (value==target){
				return ((mid>=size) ? mid-size : mid);
			}else if(value<target){
				left = mid + 1;
			}else{
				right = mid - 1;
			}
		}
		return -1;
	}
	
    int search(vector<int>& nums, int target) {
    	size = nums.size();
    	if (size==0) return -1;
    	if (size==1){
    		if (nums[0]==target) return 0;
    		else return -1;
		}
		// size >=2
		int head = findHead(nums);
		cout << "Head:\t" << head << endl;
		int res = binSearch(nums,head,target);
		cout << "Res:\t" << res << endl;
		return res;
    }
private: 
	int size;
};

int main(){
	Solution solution = Solution();
	vector<int> nums = {4,5,6,7,0,1,2};
//	vector<int> nums = {1,2,3};
//	vector<int> nums = {3,1,2};
	int target = 4;
	
	solution.search(nums,target);
	
	return 0;
}
