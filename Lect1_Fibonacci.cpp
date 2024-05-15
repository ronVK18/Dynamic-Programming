#include <bits/stdc++.h>
using namespace std;
int fibonacciUsingRecursion(int n){
    if(n == 0 || n == 1){
        return n;
    }
    return fibonacciUsingRecursion(n-1) + fibonacciUsingRecursion(n-2);
}
int fibonacciUsingDPMethod1(int n,vector<int> &dp){
     if(n == 0 || n == 1){
        return n;
    }

    if(dp[n]!=-1) return dp[n];
    return dp[n]=fibonacciUsingDPMethod1(n-1,dp) + fibonacciUsingDPMethod1(n-2,dp);
}

int main(){
    int n;
    cin >> n;
    cout << fibonacciUsingRecursion(n) << endl;
    //DP Method 1 Memoization Technique
    vector<int> dp(n+1, -1);
    cout << fibonacciUsingDPMethod1(n,dp) << endl;
    //DP Method 2 Tabulation Technique
    vector<int> dp2(n+1, -1);
    dp2[0]=0;
    dp2[1]=1;
    for(int i=2;i<=n;i++){
        dp2[i]=dp2[i-1]+dp2[i-2];
    }
    cout<<dp2[n]<<endl;
    //Space Optimized DP Method 3
    int prev2=0,prev1=1,curr;
    for(int i=2;i<=n;i++){
        curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    cout<<curr<<endl;
    return 0;
}