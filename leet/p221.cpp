#include<bits/stdc++.h>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
  if (matrix.size() <= 0) return 0;
  int m = matrix.size();
  int n = matrix[0].size();
  int mx = 0;
  vector<vector<int>> dp(m, vector<int>(n, 0));

  for (int i=0; i<m; ++i) {
  dp[i][0] = matrix[i][0] - '0';
  mx = max(mx, dp[i][0]);
  }

  for (int i=0; i<n; ++i) {
  dp[0][i] = matrix[0][i] - '0';
  mx = max(mx, dp[0][i]);
  }

  for (int i=1; i<m; ++i) 
  for (int j=1; j<n; ++j)
    if (matrix[i][j] == '1') {
    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
    mx = max(mx, dp[i][j]);
    }
  return mx*mx;
}

int main(int argc, char** argv) {
  return 0;
}