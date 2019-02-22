// find the first and last position of element in sorted array
// peng
// 2019-2-22

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void parse(vector<int>&res,vector<int>&nums,int s,int e,int target){
        if(e>s){
            int m=(s+e)/2;
            if(nums[m]<target)
                parse(res,nums,m+1,e,target);
            else{
                if(nums[m]>target)
                    parse(res,nums,s,m-1,target);
                else
                {
                    if(res[0]==-1){
                        res[0]=m;
                        res[1]=m;
                    }
                    else{
                        if(m<res[0])
                            res[0]=m;
                        if(m>res[1])
                            res[1]=m;
                    }
                    parse(res,nums,s,m-1,target);
                    parse(res,nums,m+1,e,target);
                }
            }
        }
        else{
            if(s==e&&nums[s]==target){
                if(res[0]==-1){
                    res[0]=s;
                    res[1]=s;
                }
                else{
                 if(s<res[0])
                     res[0]=s;
                 if(s>res[1])
                     res[1]=s;
                }
            }
        }

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(-1);
        res.push_back(-1);
        if(nums.size()!=0)
            parse(res, nums, 0, nums.size() - 1, target);
        return res;
    }
};
void test(){
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(10);
    Solution s;
    vector<int> res=s.searchRange(nums,7);
    for(size_t i=0;i<res.size();i++)
        cout<<res[i]<<" ";
    cout<<endl;
}
int main() {
    test();
    return 0;
}