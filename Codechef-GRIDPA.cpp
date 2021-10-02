/**
* @author: Priyansh Bhardwaj
* @link: https://www.codechef.com/LTIME100A/problems/GRIDPA
*/
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define i64 long long
#define F first
#define S second
#define MOD 1000000007
#define pair pair<int, int>
#define pb push_back
#define endl '\n'
#define matrix vector<vector<int>>
using namespace std;
int dp[150*150*300];

int solve(string block[], int x, int y, int k, int n, int pts[], int K) {
	if(x+1 == n && y+1 == n) {
		return pts[x*n+y];
	}
	int key = (x*n+y)*K+max(k, 0);
	if(dp[key] != -2) {
		return dp[key];
	}
	int ans = -1;
	if(k+1 == K || !k) {
		if(x+1 < n && block[x+1][y] == '.') {
			ans = max(ans, solve(block, x+1, y, k, n, pts, K));
		}
		if(y+1 < n && block[x][y+1] == '.') {
			ans = max(ans, solve(block, x, y+1, k, n, pts, K));
		}
	}
	if(k) {
		if(x+1 < n) {
			ans = max(ans, solve(block, x+1, y, k-1, n, pts, K));
		}
		if(y+1 < n) {
			ans = max(ans, solve(block, x, y+1, k-1, n, pts, K));
		}
	}
	if(ans > -1) ans += pts[x*n+y];
	return dp[key] = ans;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	fastio
    
    int t;   
    cin>>t;
    while(t--) {
    	int n,k;
    	cin>>n>>k;
    	string block[n];
    	int pts[n*n];
    	for(int i=0;i<n;i++) {
    		cin>>block[i];
    	}
    	for(int i=0;i<n;i++) {
    		for(int j=0;j<n;j++) {
    			cin>>pts[i*n+j];
    		}
    	}
    	fill(dp, dp+n*n*(k+1), -2);
    	cout<<solve(block, 0, 0, k, n, pts, k+1)<<endl;
    }
	return 0;
}
