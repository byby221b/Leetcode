#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution{
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i=1;i<=n;i++){
            if(i%15==0){
                res.push_back("FizzBuzz");
            }else if(i%3==0){
                res.push_back("Fizz");
            }else if(i%5==0){
                res.push_back("Buzz");
            }else{
                res.push_back(int2str(i));
            }
        }
            
        return res;
    }
private:
    
    string int2str(int n){
        stringstream s;
		s << n;
        return s.str();
    }     
};


int main(){
	Solution su = Solution();
	vector<string> res = su.fizzBuzz(9999);
	
	cout << res.size() << endl;
	
	return 0;
}
