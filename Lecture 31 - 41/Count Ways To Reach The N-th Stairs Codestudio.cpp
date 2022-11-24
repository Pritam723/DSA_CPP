// https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650

#include<iostream>
using namespace std;
#include<math.h>

int countDistinctWaysSol2(int nStairs) {
    //  Write your code here.
    int m = pow(10,9) + 7;
    if(nStairs == 0)
        return 1;
    if(nStairs == 1 || nStairs == 2)
        return nStairs;
    
    int count = 2;
    int f = 1, s = 2;
    int t;
    while(count < nStairs){
        t = f;
        f = s;
        s = ((t % m) + (s % m))%m;
        count++;
    }
    return s % m;
}

int countDistinctWays(int nStairs) {
    //  Write your code here.
    if(nStairs == 0)
        return 0;
    if(nStairs == 1 || nStairs == 2)
        return nStairs;
    return countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2);
}

int main(){

    int N;
    cin >> N;
    cout << countDistinctWays(N);
    return 0;
}



