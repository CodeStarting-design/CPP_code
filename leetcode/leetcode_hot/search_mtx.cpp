#include<vector>
#include<iostream>
using std::vector;
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix.front().size();
        // 先二分确定范围
        int left=0,right=m-1,len=0;
        while(left<=right){
            len=left+(right-left)/2;
            if(matrix[len][n-1]==target) return true;
            if(matrix[len][n-1]>target) right=len-1;
            else left=len+1;
        }
        left=0,right=n-1;
        int mid=0;
        while(left<=right){
            mid=left+(right-left)/2;
            if(matrix[len][mid]==target) return true;
            if(matrix[len][mid]>target) right=mid-1;
            else left=mid+1;
        }
        return false;
    }
int main(){
    vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    std::cout<<searchMatrix(matrix,1);
}