#include <iostream>
#include <cstdio>
#include <stack>

#define LEN 7

using namespace std;

char buf[10];

bool isDigit(char a){
	return (a>='0' && a<='9');
}

void cal(stack<int> &nums,stack<char> &op){
	char currOp = op.top();
	op.pop();
	
	int num2 = nums.top();
	nums.pop();
	int num1 = nums.top();
	nums.pop();
	
	switch(currOp){
		case '+': nums.push(num1+num2);break;
		case '-': nums.push(num1-num2);break;
		case 'x': nums.push(num1*num2);break;
		case '/': nums.push(num1/num2);break;
		default: break;
	}
	
}

void run(){
	scanf("%s",buf);
	stack<int> nums;
	stack<char> op;	
	
	for(int i=0;i<LEN;i++){
		if(isDigit(buf[i]))	nums.push(buf[i]-'0');
		else{
			if(buf[i]=='+' || buf[i]=='-'){
				while(!op.empty()){
					cal(nums,op);
					
				}
			}else{
				while(!op.empty() && (op.top()=='x' || op.top()=='/')){
					cal(nums,op);

				}
			}
			op.push(buf[i]);
		}
	}
	
	while(!op.empty()){
		cal(nums,op);
	}
	
//	cout << nums.top() << endl;
	if(nums.top()==24){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	
}


int main(){
	int n;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		run();
	}
	
	return 0;
}
