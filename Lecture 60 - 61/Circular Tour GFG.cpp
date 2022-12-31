// https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1
#include<iostream>
#include<queue>
using namespace std;

struct petrolPump{
    int petrol;
    int distance;
};

int tourAltSol(petrolPump p[],int n)
{
    //Your code here
    int pertrolSum = 0;
    int distanceSum = 0;
    vector<int> offset;
    queue<int> q;
    
    for(int i = 0; i < n; i++){
        pertrolSum = pertrolSum + p[i].petrol;
        distanceSum = distanceSum + p[i].distance;
        offset.push_back(p[i].petrol - p[i].distance);
    }
    if(distanceSum > pertrolSum) return -1;
    
    // See S(N) = O(1) expected. So use the arrays only.
    int sum = 0;
    int i = 0;
    while(q.size() != n){ // i.e. we have reached a solution.
        int item = offset[i];
        sum = sum + item;
        if(sum >= 0){
            q.push(i);
            
        }else{
            while(sum < 0){
                if(q.empty()){
                    sum = 0;
                    break;
                }
                sum = sum - offset[q.front()];
                q.pop();
            }
        }
        i = (i+1)%n;
    }
    return q.front();
    
}

int tour(petrolPump p[],int n)
{
    //Your code here
    int start = 0;
    int balance = 0;
    int deficit = 0;
    
    for(int i = 0; i < n; i++){
        balance = balance + p[i].petrol - p[i].distance;
        
        if(balance < 0){
            deficit = deficit - balance;
            start = i + 1;
            balance = 0;
        }
    }
    
    if(balance >= deficit) return start;
    return -1;
}