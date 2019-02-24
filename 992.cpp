//
// Created by kphf1 on 2019/2/23.
//

#include <iostream>
#include <vector>
//#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int res=0;
        int front=0,end=0; //[front,end)
        unordered_map<int,int> diffElementNum;
        int len=A.size();
        while(diffElementNum.size()<K&&end<len){
            diffElementNum[A[end]]++;
            end++;
        }
        if(diffElementNum.size()<K)
            return res;
        else
            res++;
        while(true){
            int k=end;
            while(k<len){
                if(diffElementNum.count(A[k])==1){
                    res++;
                    k++;
                }
                else
                    break;
            }
            //cout<<"res:"<<res<<endl;
            diffElementNum[A[front]]--;
            if(diffElementNum[A[front]]==0)
                diffElementNum.erase(A[front]);
            front++;
            while(end<len&&diffElementNum.size()<K){
                diffElementNum[A[end]]++;
                end++;
            }
            if(diffElementNum.size()==K)
                res++;
            else
                break;
        }
        return res;
    }
};

void test(){
    Solution s;
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    cout<<s.subarraysWithKDistinct(A,2)<<endl;
}
int main(){
    test();
    return 0;
}
