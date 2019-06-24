/*
	Name: 
	Copyright: 
	Author: 
	Date: 24/06/19 14:12
	Description: 注意进行剪枝，如果搜到0丢掉继续向下搜的话会产生错解
				相当于在字符中间放n-1个隔板，是一个组合问题，因此考虑dfs
				lintcode 570 
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param n: An integer
     * @param str: a string with number from 1-n in random order and miss one number
     * @return: An integer
     */
    int char2int(char a){
    	return (a - '0');
	}
	
	void dfs(int level,int n,string::iterator it,string::iterator end){
		if(level>n){
			int tmpRes = -1;
			int count = 0;
			for(int i=1;i<=n;i++){
				if(!mark[i]){
					tmpRes = i;
					count ++;
				}
			}
			if(count==1){
				res = tmpRes;
			}
			return;
		}
		
		if((*it)=='0'){
			return;
		}
		
		int tmp = char2int(*it);
		if(tmp==0) {
			return; 
		}
			
		if(tmp!=0 && !mark[tmp]){
			mark[tmp] = true;
			dfs(level+1,n,it+1,end);
			mark[tmp] = false;
		}
		
		if((it+1)!=end){
			int tmp = char2int(*it) * 10 + char2int(*(it+1));
			if(tmp<=n && !mark[tmp]){
				mark[tmp] = true;
				dfs(level+1,n,it+2,end);
				mark[tmp] = false;
			}
		}
		
		
	}
	
    int findMissing2(int n, string &str) {
    	mark = new bool[n+5];
    	
		for(int i=1;i<=n;i++){
			mark[i] = false;
		}
        
        dfs(1,n,str.begin(),str.end());
        
        return res;
        
        delete [] mark;
    }
    
    bool *mark;
    int res;
};

int main(){
	Solution su = Solution();
//	string test = "19201234567891011121314151618";
//	string test = "111098654327128213127262524232120191817161514";
	string test = "111098765432";
	cout << su.findMissing2(11,test) << endl;
	return 0;
}
