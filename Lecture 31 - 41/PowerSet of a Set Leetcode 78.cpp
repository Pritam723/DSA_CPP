// https://leetcode.com/problems/subsets/
#include<iostream>
#include<vector>
using namespace std;

// My Solution.
// vector<vector<int>> getPowerSet(vector<int>& nums) {
    
//     if(nums.size() == 0) return {{}};

//     int key = nums[0];
//     vector<int> newNums(nums.begin() + 1, nums.end());
//     vector<vector<int>> powerSet = getPowerSet(newNums);

//     vector<vector<int>> powerSetTemp = powerSet;

//     for (int i = 0; i < powerSetTemp.size(); i++) {
//         powerSetTemp[i].push_back(key);
//     }

//     for (auto set : powerSetTemp) {
//         powerSet.push_back(set);
//     }

//     return powerSet;
// }

void solution(vector<int> nums,vector<int> output,int i,vector<vector<int>> &ans){
    if(i >= nums.size()){
        ans.push_back(output);
        return;
    }

    // Exclude current nums[i]

    solution(nums, output, i+1, ans);

    // Include current nums[i]

    output.push_back(nums[i]);

    solution(nums, output, i+1, ans);
}

vector<vector<int>> getPowerSetAlt(vector<int> nums){
    vector<vector<int>> ans;
    vector<int> output;
    int i = 0;

    solution(nums,output,i,ans);

    return ans;
}


int main(){
    vector<int> vec = {1,2,3};
    vector<vector<int>> ans1;
    ans1 = getPowerSetAlt(vec);

    for(auto v : ans1){
        for(auto elem : v){
            cout << elem << " ";
        }
        cout << endl;
    }

}
