//
// Created by kphf1 on 2019/3/26.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> str;
        string res;
        int len=s.size();
        int i=0,j=0;
        while(i<len){
            while(i<len&&s[i]==' ')
                i++;
            if(i>=len)
                break;
            j=i+1;
            while(j<len&&s[j]!=' ')
                j++;
            str.push_back(s.substr(i,j-i));
            i=j+1;
        }
        for(int p=str.size()-1;p>=0;p--){
            if(p!=0)
                res=res+str[p]+' ';
            else
                res=res+str[p];
        }
        return res;
    }
};

int main(){
    Solution s;
    cout<<s.reverseWords("a good   example");
}