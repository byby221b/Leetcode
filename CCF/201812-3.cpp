/*
	Name: 
	Copyright: 
	Author: 
	Date: 09/09/19 11:00
	Description: 只排序，未考虑合并，通过测试点6/10
				目前通过测试点7/10 
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct IP{
	unsigned int value;
	int len;
	IP *next;
	IP(unsigned int v,int l) : value(v), len(l), next(NULL){}
};

char buf[1024];

bool isDigit(char a){
	return (a>='0' && a<='9');
}

void output(IP *ip){
	unsigned int v = ip->value;
	
	printf("%d.%d.%d.%d/%d\n",(v>>24)&0xff,(v>>16)&0xff,(v>>8)&0xff,v&0xff,ip->len);
}

void readIP(IP *root,int n){
	char *ptr;
	int state,count,len;
	unsigned int tmpVal,ipVal;
	IP *iptr,*newPtr;
	for(int i=0;i<n;i++){
		fgets(buf,1024,stdin);
		ptr = buf;
		state = 0;
		count = 0;
		ipVal = 0;
		tmpVal = 0;
		len = 0;
		while(true){
			if(state==0){
				if(isDigit(*ptr)){
					count ++;
					state = 1;
					tmpVal = *ptr - '0';
				}
			}else if(state==1){
				if(isDigit(*ptr)){
					tmpVal = tmpVal * 10 + (*ptr - '0');
				}else if(*ptr=='.'){
					state = 0;
					ipVal = (ipVal << 8) + tmpVal;
				}else if(*ptr=='/'){
					state = 2;
					len = 0;
					ipVal = (ipVal << 8) + tmpVal;
					ipVal = (ipVal << (32-count*8));
				}else if(*ptr=='\n'){
					state = 3;
					len = count * 8;
					ipVal = (ipVal << 8) + tmpVal;
					ipVal = (ipVal << (32-len));
				}
			}else if(state==2){
				if(isDigit(*ptr)){
					len = len * 10 + (*ptr - '0');
				}else if(*ptr=='\n'){
					state = 3;
				}
			}else if(state==3){
				iptr = root;
				while(iptr->next){
					unsigned int v = iptr->next->value;
					int l = iptr->next->len;
					if(v<ipVal || (v==ipVal && l<len)){
						iptr = iptr->next;
					}else{
						break;
					}
				}
				newPtr = new IP(ipVal,len);
				newPtr->next = iptr->next;
				iptr->next = newPtr;
				break;
			}
			
			ptr++;
		}
	}
	
}

void mergeIP(IP *root){
	IP *ptr = root->next;
	IP *tmp;
	while(ptr && ptr->next){
		unsigned int mask = (0xffffffff) << (32 - (ptr->len));
		if(((ptr->next->value)&mask)==(ptr->value)){
			tmp = ptr->next;
			ptr->next = ptr->next->next;
			delete tmp;
		}else{
			ptr = ptr->next;
		}
	}
	
	IP *prePtr;
	ptr = root->next;
	while(ptr && (ptr->next)){
		if((ptr->len)&&(ptr->next->len)){
			unsigned int mask;
			if((ptr->len) > 1){
				 mask = (0xffffffff) << (32 - (ptr->len) +1);
			}else{
				mask = 0;
			}
			

			unsigned int pv = ptr->value;
			unsigned int nv = ptr->next->value;
			if((pv!=nv)&&((pv&mask)==(nv&mask))){
				(ptr->len) -= 1;
				ptr->value = pv & mask;
				
				IP *tmp = ptr->next;
				ptr->next = ptr->next->next;
				delete tmp;
				
				prePtr = root;
				while(prePtr->next != ptr) prePtr = prePtr->next;
				if(prePtr!=root) ptr = prePtr;
			}else{
				ptr = ptr->next;
			}
		}else{
				ptr = ptr->next;
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	IP *root;
	root = new IP(-1,-1);
	fgets(buf,1024,stdin);
	readIP(root,n);
	mergeIP(root);
	
	
	IP *iptr = root;
	while(iptr->next){
//		printf("0x%08x\t%d\t\n",iptr->next->value,iptr->next->len);
		output(iptr->next);
		iptr = iptr->next;
	}
	
	return 0;
}
