// Leetcode 153. Find Minimum in Rotated Sorted Array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include<iostream>
#include<vector>
using namespace std;

int findMin(vector<int>& nums) {
    int s = 0, e = nums.size() - 1;
    int m = s + (e-s)/2;

    if(nums[s] < nums[e])
        return s;

    while(s < e){

        if(nums[m] >= nums[0])
            s = m + 1;
        else
            e = m;
    
        m = s + (e-s)/2;
    }

    cout << s << e << m << endl;

    return m;
}


int main(){

    vector<int> arr = {1,2,3,4,5,6,7,8,9};

    cout << "Index is : " << findMin(arr);

    return 0;
}
