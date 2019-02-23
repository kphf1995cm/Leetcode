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
    int getNodeNum(ListNode* head){
        ListNode* temp;
        temp=head;
        int num=0;
        while(temp!=NULL){
            num++;
            temp=temp->next;
        }
        return num;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* resHead=NULL;
        ListNode* last=NULL;
        ListNode* first=NULL;
        ListNode* lastFirst=NULL;
        ListNode* lastNode=NULL;
        if(k==1)
            return head;
        int num=getNodeNum(head);
        int turn=num/k;
        while(turn){
            turn--;
            for(int i=0;i<k;i++){
                if(i==0){
                    lastFirst=first;
                    first=head;
                    last=head;
                    head=head->next;
                }
                else{
                    lastNode=head->next;
                    head->next=last;
                    last=head;
                    if(i==k-1){
                        if(resHead==NULL)
                            resHead=head;
                        if(lastFirst!=NULL)
                            lastFirst->next=head;
                    }
                    head=lastNode;
                }
            }
        }
        if(resHead==NULL)
            resHead=head;
        else
            first->next=head;
        return resHead;
    }
};

void test(){
    ListNode* head=new ListNode(1);
    ListNode* temp=head;
    for(int i=2;i<=5;i++)
    {
        ListNode* value=new ListNode(i);
        temp->next=value;
        temp=value;
    }
    Solution s;
    ListNode* resHead=s.reverseKGroup(head,6);
    while(resHead){
        cout<<resHead->val<<" ";
        resHead=resHead->next;
    }
}

int main(){
    test();
    return 0;
}