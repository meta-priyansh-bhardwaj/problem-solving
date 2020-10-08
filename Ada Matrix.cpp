#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int ar[n][n];
	    for(int i=0;i<n;i++) {
	        for(int j=0;j<n;j++) {
	            cin>>ar[i][j];
	        }
	    }
	    bool rows=true;
	    int ans=0;
	    for(int i=1;i<n;i++) {
	        if(rows) {
	            if(ar[0][i] != i+1) {
	                rows=false;
	                ans++;
	                if(i>1) ans++;
	            }
	        } else {
	            if(ar[i][0]!=i+1) {
	                rows=true;
	            }
	        }
	    }
	    cout<<ans<<'\n';
	}
	return 0;
}
