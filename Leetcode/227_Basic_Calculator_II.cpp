/*
	Name: 
	Copyright: 
	Author: 
	Date: 29/08/19 10:18
	Description: Õ»;µÝ¹éÏÂ½µ·ÖÎö·¨ 
*/

#include <iostream> 
#include <string>
#include <stack>
using namespace std;


//class Solution {
//public:
//	
//    int calculate(string s) {
//  		string::iterator iter = s.begin();
//  		
//  		stack<int> num;
//  		stack<char> oper;
//  		
//  		int tmp;
//  		while(iter!=s.end()){
//  			if(*iter==' '){
//  				iter ++;
//  				continue;
//			}
//  			
//  			if((*iter)>='0' && (*iter)<='9'){
//  				tmp = 0;
//				while((iter!=s.end())&&(((*iter)>='0' && (*iter)<='9') ||(*iter==' '))){
//					if(*iter!=' '){
//						tmp = tmp*10 + ((*iter)  - '0');
//					}
//					iter++;
//				}
//				num.push(tmp);
//			}else{
//				if(*iter=='+' || *iter=='-'){
//					while(!oper.empty()){
//						char op = oper.top();
//						oper.pop();
//						int num2 = num.top();
//						num.pop();
//						int num1 = num.top();
//						num.pop();
//						num.push(cal(num1,num2,op));	
//					}
//					oper.push(*iter);
//				}else{
//					while(!oper.empty() && (oper.top()=='*' || oper.top()=='/')){
//						char op = oper.top();
//						oper.pop();
//						int num2 = num.top();
//						num.pop();
//						int num1 = num.top();
//						num.pop();
//						num.push(cal(num1,num2,op));
//					}
//					oper.push(*iter);
//				}
//				iter ++;
//			}
//		}
//		
//		while(!oper.empty()){
//			char op = oper.top();
//			oper.pop();
//			int num2 = num.top();
//			num.pop();
//			int num1 = num.top();
//			num.pop();
//			num.push(cal(num1,num2,op));	
//		}
//  		
//  		return num.top();
//    }
//    
//private:
//	int cal(int num1,int num2,char op){
//		switch(op){
//			case '+': return num1+num2;
//			case '-': return num1-num2;
//			case '*': return num1*num2;
//			case '/': return num1/num2;
//		}
//		return 0;
//	}
//    
//};

class Solution {
public:
	bool isNum(char ch){
		return (ch>='0' && ch<='9');
	}
	
	int getNum(string::iterator &iter,string::iterator end){
		int res = 0;
		while(iter!=end && (isNum(*iter) || *iter==' ')){
			if(*iter!=' '){
				res = res * 10 + (*iter - '0');
			}
			iter++;
		}
		return res;
	}
	
	int getItem(string::iterator &iter,string::iterator end){
		int res = getNum(iter,end);
//		skip(iter,s.end());
		while(iter!=end && (*iter=='*' || *iter=='/')){
			char op = *iter;
			iter++;
			int num = getNum(iter,end);
//			skip(iter,s.end());
			if(op=='*'){
				res *= num;
			}else{
				res /= num;
			}
		}
		
		return res;
	}
	
	int calculate(string s) {
		string::iterator iter = s.begin();
		
		int res = getItem(iter,s.end());
//		skip(iter,s.end());
		while(iter!=s.end()){
			char op = *iter;
			iter++;
			int num = getItem(iter,s.end());
//			skip(iter,s.end());
			
			if(op=='+'){
				res += num;
			}else{
				res -= num;
			}
		}
		
		return res;
	}
private:
	void skip(string::iterator &iter,string::iterator end){
		while(iter!=end && (*iter)==' ') iter ++;
	}
};


int main(){
	Solution su = Solution();
	string test = "3+ 2 * 2 ";
//	string test = " 3/2 ";
//	string test = "2147483647";
	int res = su.calculate(test);
	
	cout << res << endl;
	
	return 0;
}

