// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// bool isVisited(pair<int,int> pos, vector<pair<int,int>> visitedInPath){
//     for(int i = 0; i < visitedInPath.size(); i++){
//         if(visitedInPath[i] == pos) return true;
//     }
//     return false;
// }

    
// void solution(vector<vector<int>> m, int n, int r, int c, vector<pair<int,int>> visitedInPath, string output, vector<string> &ans){
//     pair<int,int> pos = make_pair(r,c);
//     if( r < 0 || c < 0 || r >= n || c >= n ||  m[r][c] == 0 || isVisited(pos,visitedInPath)) return;
    
//     if(r == n-1 && c == n-1){
//         ans.push_back(output);
//         return;
//     }
    
//     visitedInPath.push_back(pos);
    
//     // Calling Solution for UP.
//     output.push_back('U');
//     solution(m,n,r-1,c,visitedInPath,output,ans);
//     output.pop_back();
    
//     // Calling Solution for DOWN.
//     output.push_back('D');
//     solution(m,n,r+1,c,visitedInPath,output,ans);
//     output.pop_back();
    
    
//     // Calling Solution for LEFT.
//     output.push_back('L');
//     solution(m,n,r,c-1,visitedInPath,output,ans);
//     output.pop_back();
    
    
//     // Calling Solution for RIGHT.
//     output.push_back('R');
//     solution(m,n,r,c+1,visitedInPath,output,ans);
//     output.pop_back();
// }
    
// vector<string> findPath(vector<vector<int>> &m, int n) {
//     // Your code goes here
//     int r = 0, c = 0;
//     vector<pair<int,int>> visitedInPath;
//     vector<string> ans;
//     string output;
    
//     solution(m,n,r,c,visitedInPath,output,ans);
    
//     return ans;
// }

void solutionAlt(vector<vector<int>> m,int n,int r,int c,vector<vector<int>> visited,string path,vector<string> &ans){

    if(r < 0 || r >= n || c < 0 || c >= n || m[r][c] == 0 || visited[r][c] == 1) {
        return;
    }
    if(r == n-1 && c == n-1){

        ans.push_back(path);
        return;
    }
    visited[r][c] = 1;

    // Call for UP
    path.push_back('U');
    solutionAlt(m,n,r-1,c,visited,path,ans);
    path.pop_back();

    // Call for DOWN
    path.push_back('D');
    solutionAlt(m,n,r+1,c,visited,path,ans);
    path.pop_back();


    // Call for LEFT
    path.push_back('L');
    solutionAlt(m,n,r,c-1,visited,path,ans);
    path.pop_back();

    // Call for RIGHT
    path.push_back('R');
    solutionAlt(m,n,r,c+1,visited,path,ans);
    path.pop_back();

    visited[r][c] = 0; // No need to write this. Cause anyway this call is getting popped.
    //However if we send visited CBR, then we must do this.


}


vector<string> findPathAlt(vector<vector<int>> &m, int n) {
    vector<string> ans;
    string path;
    int r = 0, c = 0;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    solutionAlt(m,n,r,c,visited,path,ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n = 4;
    vector<vector<int>> m = {
                            {1, 0, 0, 0},
                            {1, 1, 0, 1}, 
                            {1, 1, 0, 0},
                            {0, 1, 1, 1}
                        };

    vector<string> ans = findPathAlt(m,n);
    
    for(string str : ans){
        cout << str << endl;
    }
    

}