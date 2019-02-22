// Maximal Rectangle
// Created by kphf1 on 2019/2/22.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int,int> maxSquare;
    int size;
    int max(int x,int y){
        if(x>y)
            return x;
        else
            return y;
    }
    int getMaxSquare(vector<vector<char>>& matrix,int t,int b,int l,int r){
        int index=t+b*size+l*size*size+r*size*size*size;
        if(maxSquare.count(index)!=0)
            return maxSquare[index];
        int maxValue=(b-t)*(r-l);
        for(int i=t;i<b;i++){
            for(int j=l;j<r;j++){
                if(matrix[i][j]=='0'){
                    int rMax=max(getMaxSquare(matrix,t,i,l,r),getMaxSquare(matrix,i+1,b,l,r));
                    int cMax=max(getMaxSquare(matrix,t,b,l,j),getMaxSquare(matrix,t,b,j+1,r));
                    maxValue=max(rMax,cMax);
                    maxSquare[index]=maxValue;
                    return maxValue;
                }
            }
        }
        maxSquare[index]=maxValue;
        return maxValue;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int h=matrix.size();
        int w = h>0 ? matrix[0].size():0;
        size=h>w?h:w;
        if(h*w==0)
            return 0;
        else
            return getMaxSquare(matrix,0,h,0,w);
    }

};

int main(){

}