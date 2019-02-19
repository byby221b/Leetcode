#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swap(vector<int>& nums,int idx1,int idx2){
    int tmp = nums[idx1];
    nums[idx1] = nums[idx2];
    nums[idx2] = tmp;
}

void sortColors(vector<int>& nums) {
    if(nums.empty()) return;
    
    int begin = 0,end = nums.size()-1;
    while(nums[begin]==0) begin++;
    while(nums[end]==2) end--;
    
    int i = 0;
    while(i<nums.size() && begin<end){
        if(nums[i]==0 && i>begin){
            swap(nums,i,begin);
            while(nums[begin]==0) begin++;
        }
        else if(nums[i]==2 && i<end){
            swap(nums,i,end);
            while(nums[end]==2) end--;
        }
        else{
            i ++;
        }
    }
}

void output(vector<int> a){
	for(auto item:a){
		cout << item << " " ;
	}
	cout << endl;
}

int main(){
	int _a[] = {2,0,2,2,0,2,1,2};
	vector<int> a(_a,_a+sizeof(_a)/sizeof(_a[0]));
	sortColors(a);
	output(a);
	return 0;
}
