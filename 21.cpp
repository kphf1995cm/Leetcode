//
// Created by kphf1 on 2019/2/23.
//

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head=NULL;
        ListNode* curNode=NULL;
        if(l1==NULL||l2==NULL){
            if(l1==NULL)
                head=l2;
            else
                head=l1;
        }
        else{
            if(l1->val<l2->val){
                head=l1;
                l1=l1->next;
            }
            else{
                head=l2;
                l2=l2->next;
            }
            curNode=head;
            while(l1!=NULL&&l2!=NULL){
                if(l1->val<l2->val){
                    curNode->next=l1;
                    l1=l1->next;
                }
                else{
                    curNode->next=l2;
                    l2=l2->next;
                }
                curNode=curNode->next;
            }
            if(l1==NULL)
                curNode->next=l2;
            else
                curNode->next=l1;
        }
        return head;
    }
};

int main(){

}