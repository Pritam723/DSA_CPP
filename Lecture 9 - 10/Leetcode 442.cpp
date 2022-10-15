// Leetcode 442. Find All Duplicates in an Array
// https://leetcode.com/problems/find-all-duplicates-in-an-array/

#include<iostream>
#include<vector>
#include <cstdlib>
using namespace std;

/*

O(1) space not including the input and output variables

The idea is we do a linear pass using the input array itself as a hash to store which numbers have been seen before.
We do this by making elements at certain indexes negative. See the full explanation here.

http://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/


*/

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans;
    for(int i = 0; i < nums.size() ; i++){
        
        int indexToCheck = abs(nums[i]) - 1;  // Ambiguity because of #include<vector>. Later Check.
        
        if(nums[indexToCheck] < 0){
            ans.push_back(abs(nums[i]));
        }
        else{
            nums[indexToCheck] = -nums[indexToCheck];
        }     
    }
    return ans;


}


int main(){

    vector<int> nums {4,3,2,7,8,2,3,1};

    vector<int> duplicates = findDuplicates(nums);

    for(int x : duplicates){
        cout << x << " ";
    }

    return 0;
}