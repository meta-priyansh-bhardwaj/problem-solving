#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int m,n;
	    cin>>m>>n;
	    int ar[m][n];
	    for(int i=0;i<m;i++) {
	        for(int j=0;j<n;j++) {
	            cin>>ar[i][j];
	            //cout<<ar[i][j]<<" ";
	        }//cout<<endl;
	    }
	    for(int l=0,count=0;count<m*n;l++) {
	        for(int i=l;i<n-l && count<m*n;i++) {
	            cout<<ar[l][i]<<' ';
	            count++;
	        }
	        for(int i=l+1;i<m-l && count<m*n;i++) {
	            cout<<ar[i][n-l-1]<<' ';
	            count++;
	        }
	        for(int i=n-l-2;i>=l && count<m*n;i--) {
	            cout<<ar[m-l-1][i]<<' ';
	            count++;
	        }
	        for(int i=m-l-2;i>l && count<m*n;i--) {
	            cout<<ar[i][l]<<" ";
	            count++;
	        }
	    }cout<<endl;
	}
	return 0;
}
