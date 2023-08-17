#include <bits/stdc++.h>
using namespace std;

int f(vector<int>& a, int i, int j, vector<vector<int>> dp){
    if(i > j) return 0;

    if(dp[i][j] != -1) return dp[i][j];
    int maxi = INT_MIN;
    for(int ind = i; ind <= j; ind++){
        int coins = (a[i-1] * a[ind] * a[j+1]) + f(a, i, ind-1, dp) + f(a, ind + 1, j, dp);
        maxi = max(maxi, coins);
    }
    return dp[i][j] = maxi;
}
int maxCoins(vector<int>& a) {
    int n = a.size();
    a.push_back(1);
    a.insert(a.begin(), 1);
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return f(a,1,n, dp);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    int element;
    for(int i = 0; i<n; i++){
        cin >> element;
        a.push_back(element);
    }

    cout << maxCoins(a) << endl;;
    return 0;
}