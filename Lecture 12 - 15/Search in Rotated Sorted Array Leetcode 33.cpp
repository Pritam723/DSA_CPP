// Leetcode 153. Find Minimum in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array
// https://www.codingninjas.com/codestudio/problems/search-in-rotated-sorted-array_1082554

#include<iostream>
#include<vector>
using namespace std;

int getPivot(vector<int>& nums){

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

    return s;

}

int searchSolUsingPivot(vector<int>& nums, int target) {
    int pivotIndex = getPivot(nums);
    cout << "Pivot Element is " << pivotIndex;
    int s,e,m;
    // {6,7,8,9,0,1,2,3,4}
    // So pivotIndex = 4 we will get. Now we need to see, which side key is in.
    // Say key = 7. Check with arr[0] again to see if it is on L1 or L2.

    // But what if pivotIndex is 0. Pivot Index == 0 means that the array is already sorted.
    // So, it will not be possible to get the idea of L1 and L2.

    // if(pivotIndex == 0) we need to search the whole array.

    if(target >= nums[0]){
        s = 0;
        e = pivotIndex;
    }else{
        s = pivotIndex;
        e = nums.size() - 1;
    }
    // Overwrite the above.
    if(pivotIndex == 0){
        s = 0;
        e = nums.size() - 1;
    }

    m = s + (e-s)/2;
    // Now, simply do the binary search.

    while(s <= e){
        if(nums[m] == target)
            return m;
        else if(target > nums[m])
            s = m + 1;
        else
            e = m - 1;

        m = s + (e-s)/2;
    }
    return -1;

}


int searchMySol(vector<int>& nums, int target) {
    int s = 0, e = nums.size() - 1;
    int m = s + (e-s)/2;

    while(s <= e){

        if(nums[m] == target)
            return m;
        
        if(target >= nums[0]){ // Take example [1,3,5] , 1.
            if(nums[m] >= nums[0] && nums[m] < target)  // Take example [1,3] , 3.
                s = m + 1;
            else
                e = m - 1;
        }else{

            if(nums[m] < nums[0] && nums[m] > target)
                e = m - 1;
            else
                s = m + 1;

        }
        m = s + (e-s)/2;

    }
    return -1;

}



int main(){

    int key;
    cin >> key;

    vector<int> arr = {2,3,5,8};

    // Dry run done on sorted array. It works fine.

    cout << "Index is : " << searchSolUsingPivot(arr, key);

    return 0;
}
