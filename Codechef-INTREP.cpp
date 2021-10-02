/**
* @author: Priyansh Bhardwaj
* @link: https://www.codechef.com/LTIME100A/problems/INTREP
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
#define matrix vector<vector<int> >
#define vi vector<int>
#define vi64 vector<i64>
#define uset unordered_set
#define umap unordered_map
#define mpr make_pair
using namespace std;

i64 modExp(i64 a, int ex);

#define N 101
uset<int> primes[N];
void solveMain() {
	i64 n;
	cin>>n;
	if(!(n&1)) {
		cout<<n*2<<" "<<n<<endl;
		return;
	}
	int x[2];
	for(int i=2;i+1<N;i++) {
		x[0] = x[1] = 0;
		for(int j=0;j<=1;j++) {
			for(uset<int>::iterator it=primes[i+j].begin();it!=primes[i+j].end();it++) {
				if(n%(*it)) {
					x[j]++;
				}
			}
		}
		// cout<<i<<" -> "<<x[0]<<" & "<<x[1]<<endl;
		if(x[0] == x[1]) {
			cout<<n*(i+1)<<" "<<n*i<<endl;
			return;
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	fastio
	int t=1;
	cin>>t;
	for(int i=2,j;i<N;i++) {
		j = i;
		for(int k=2;k*k<=j;k++) {
			if(j%k == 0) {
				primes[i].insert(k);
			}
			while(j%k == 0) {
				j /= k;
			}
		}
		if(j > 1) {
			primes[i].insert(j);
		}
		// cout<<i<<" -> ";
		// for(auto a: primes[i]) {
		// 	cout<<a<<", ";
		// }cout<<endl;
	}
	while(t--) {
		solveMain();
	}
	return 0;
}

i64 modExp(i64 a, int ex) {
	if(!ex) return 1;
	i64 b = modExp(a, ex>>1);
	b = (b*b)%MOD;
	if(ex&1) return (b*a)%MOD;
	return b;
}
