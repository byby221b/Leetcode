#include <iostream> 
#include <string>



using namespace std;

class Solution {
public:
	bool isSpace(char ch){
		return (ch==' ');
	}
	bool isSign(char ch){
		return (ch=='+' || ch=='-');
	}
	bool isDigit(char ch){
		return (ch>='0' && ch<='9');
	}
	int convertSign(char ch){
		return (ch=='+') ? 1 : -1;
	}
	int convertDigit(char ch){
		return (ch-'0');
	}
    int myAtoi(string str) {
        int state = 1;
        long long sum = 0;
        int sign = 1;
        
		string::iterator iter = str.begin();
		while(iter!=str.end() && state!=3){
			switch(state){
				case 1:{
					if (isSpace(*iter)){
						state = 1;
					}else if(isSign(*iter)){
						state = 2;
						sign = convertSign(*iter);
					}else if(isDigit(*iter)){
						state = 2;
						sum = sum * 10 + convertDigit(*iter);
					}else{
						state = 3;
					}
					break;
				}
				case 2:
				{
					if(isDigit(*iter)){
						state = 2;
						sum = sum * 10 + convertDigit(*iter);
					}else{
						state = 3;
					}
					break;
				}
			}
			if (sign*sum>=BOUND){
				sum = BOUND - 1;
				break;
			}else if(sign*sum<(-BOUND)){
				sum = BOUND;
				break;
			}
			iter ++;
		}
		
		return (sign*sum);
    }
private:
    const long long BOUND = 2147483648;
};

int main(){
	Solution solution = Solution();
//	string test = "42";
//	string test = "     -42";
//	string test = "4193 with words";
//	string test = "words and 987";
//	string test = "-91283472332";
	string test = "91283472332";
//	string test = "";
	cout << solution.myAtoi(test) << endl;
	return 0;
}
