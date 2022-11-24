// https://leetcode.com/problems/permutations/
// https://www.codingninjas.com/codestudio/problems/permutations-of-a-string_985254?leftPanelTab=1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Leetcode : Permutate vector<int>
// vector<vector<int>> permute(vector<int>& nums) {
//         if(nums.size() == 1) return {nums};
//         vector<vector<int>> ans;
//         for(int i = 0; i < nums.size(); i++){
//             int current = nums[i];
//             vector<int> restNums = nums;
//             restNums.erase(restNums.begin() + i);
//             vector<vector<int>> restPermutations = permute(restNums);
//             for(int i = 0; i < restPermutations.size(); i++){
//                 restPermutations[i].push_back(current);
//                 ans.push_back(restPermutations[i]);
//             }
//         }
//         return ans;
// }

// CodeStudio : Permutate string.
void solution(string str, int index, vector<string> &ans){
    if(index >= str.length()){
        ans.push_back(str);
        return;
    }
    for(int i = index; i < str.length(); i++){
        swap(str[i],str[index]);
        solution(str, index + 1, ans);
        swap(str[i],str[index]);
    }    
}


vector<string> generatePermutations(string &str)
{
    // write your code here
    vector<string> ans;
    int index  = 0;
    solution(str, index, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    string str = "abc";
    vector<string> ans;
    ans = generatePermutations(str);
    for(string s : ans){
        cout << s << endl;
    }
}