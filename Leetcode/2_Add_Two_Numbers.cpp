/*
	Name: 
	Copyright: 
	Author: 
	Date: 07/08/19 09:41
	Description: 
*/

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *root = new struct ListNode(0);
        ListNode *curr = root;
        int carry = 0;
        while(l1!=NULL && l2!=NULL){
        	ListNode* newNode = new struct ListNode((carry + (l1->val) + (l2->val)) % 10);
//        	newNode->val = (carry + (l1->val) + (l2->val)) % 10;
//        	newNode->next = NULL;
        	curr->next = newNode;
        	
        	curr = newNode;
        	carry = (carry + (l1->val) + (l2->val)) / 10;
        	
        	l1 = l1->next;
        	l2 = l2->next;
		}
        
        while(l1!=NULL){
        	ListNode* newNode = new struct ListNode((carry + (l1->val)) % 10);
//        	newNode->val = (carry + (l1->val)) % 10;
//        	newNode->next = NULL;
        	curr->next = newNode;
        	
        	curr = newNode;
        	carry = (carry + (l1->val)) / 10;
        	
        	l1 = l1->next;
		}
		
		while(l2!=NULL){
        	ListNode* newNode = new struct ListNode((carry + (l2->val)) % 10);
//        	newNode->val = (carry + (l2->val)) % 10;
//        	newNode->next = NULL;
        	curr->next = newNode;
        	
        	curr = newNode;
        	carry = (carry + (l2->val)) / 10;
        	
        	l2 = l2->next;
		}
		
		if(carry){
			ListNode* newNode = new struct ListNode(carry);
//        	newNode->val = carry;
//        	newNode->next = NULL;
        	curr->next = newNode;
		}
		
		return (root->next);
    }
};

ListNode *create(int *data){
	ListNode *root = new struct ListNode(0);
	ListNode *curr = root;
	int *p = data;
	while(*p!=-1){
		ListNode *newNode = new struct ListNode(*p);
//		newNode->val = *p;
//		newNode->next = NULL;
		
		curr->next = newNode;
		curr = newNode;
		
		p++;
	}
	
	return (root->next);
}

void show(ListNode *root){
	while(root!=NULL){
		cout << root->val ;
		root = root->next;
	}
}

int main(){
//	int data1[4] = {2,4,3,-1};
//	int data2[4] = {5,6,4,-1};
//	int data1[4] = {3,2,-1,-1};
//	int data2[4] = {2,9,-1,-1};
//	int data1[4] = {0,-1,-1,-1};
//	int data2[4] = {0,-1,-1,-1};
	int data1[4] = {9,9,9,-1};
	int data2[4] = {9,-1,9,-1};
	
	ListNode *l1 = create(data1);
	ListNode *l2 = create(data2);
	
	Solution su = Solution();
	show(su.addTwoNumbers(l1,l2));
	
	return 0;
}
