/**
* @author: Priyansh Bhardwaj
* @link: https://www.codechef.com/LTIME100A/problems/POINTMEE
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
#define vi vector<int>
#define uset unordered_set
#define umap unordered_map
using namespace std;

void solveMain() {
	int n;
	cin>>n;
	pair ar[n];
	umap<int, int> X, Y, diff, sums;
	for(int i=0;i<n;i++) {
		cin>>ar[i].F;
		X[ar[i].F]++;
	}
	for(int i=0;i<n;i++) {
		cin>>ar[i].S;
		Y[ar[i].S]++;
		diff[ar[i].F-ar[i].S]++;
		sums[ar[i].F+ar[i].S]++;
	}
	int ans = 2*n, cur;
	for(auto &x: X) {
		for(auto &y: Y) {
			cur = 0;
			for(auto &a: ar) {
				if(a.F == x.F && a.S == y.F) continue;
				if(a.F == x.F || a.S == y.F || a.F-a.S == x.F-y.F || a.F+a.S == x.F+y.F) {
					cur++;
				} else {
					cur += 2;
				}
			}
			ans = min(ans, cur);
		}
	}

	for(auto &d: diff) {
		for(auto &s: sums) {
			int xx = s.F+d.F, yy = s.F-d.F;
			// cout<<xx/2.0<<" , "<<yy/2.0<<endl;
			xx = ((xx&1) ? INT32_MAX : (xx>>1));
			yy = ((yy&1) ? INT32_MAX : (yy>>1));
			cur = 0;
			for(auto &a: ar) {
				if(a.F == xx && a.S == yy) continue;
				if(a.F == xx || a.S == yy || a.F-a.S == d.F || a.F+a.S == s.F) {
					cur++;
				} else {
					cur += 2;
				}
			}
			ans = min(ans, cur);
		}
	}
	for(auto &d: diff) {
		for(auto &x: X) {
			int xx = x.F, yy = x.F-d.F;
			cur = 0;
			for(auto &a: ar) {
				if(a.F == xx && a.S == yy) continue;
				if(a.F == xx || a.S == yy || a.F-a.S == xx-yy || a.F+a.S == xx+yy) {
					cur++;
				} else {
					cur += 2;
				}
			}
			ans = min(ans, cur);
		}
	}
	for(auto &d: sums) {
		for(auto &x: X) {
			int xx = x.F, yy = d.F-x.F;
			cur = 0;
			for(auto &a: ar) {
				if(a.F == xx && a.S == yy) continue;
				if(a.F == xx || a.S == yy || a.F-a.S == xx-yy || a.F+a.S == xx+yy) {
					cur++;
				} else {
					cur += 2;
				}
			}
			ans = min(ans, cur);
		}
	}
	for(auto &d: diff) {
		for(auto &y: Y) {
			int xx = d.F+y.F, yy = y.F;
			cur = 0;
			for(auto &a: ar) {
				if(a.F == xx && a.S == yy) continue;
				if(a.F == xx || a.S == yy || a.F-a.S == xx-yy || a.F+a.S == xx+yy) {
					cur++;
				} else {
					cur += 2;
				}
			}
			ans = min(ans, cur);
		}
	}
	for(auto &d: sums) {
		for(auto &y: Y) {
			int xx = d.F-y.F, yy = y.F;
			cur = 0;
			for(auto &a: ar) {
				if(a.F == xx && a.S == yy) continue;
				if(a.F == xx || a.S == yy || a.F-a.S == xx-yy || a.F+a.S == xx+yy) {
					cur++;
				} else {
					cur += 2;
				}
			}
			ans = min(ans, cur);
		}
	}

	cout<<ans<<endl;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	fastio
	int t=1;
	cin>>t;
	while(t--) {
		solveMain();
	}
	return 0;
}
