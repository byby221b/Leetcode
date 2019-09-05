#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin,s.end());
    }
	
};

int main(){
	Solution su = Solution();
//	vector<char> test = {'h','e','l','l','o'};
	vector<int> test = {1,2,3,4,5};
	
	su.reverseString(test);
//	reverse(test.begin(),test.end());
	
	for(auto item:test){
		cout << item << " ";
	}
	cout << endl;
	
	return 0;
}
