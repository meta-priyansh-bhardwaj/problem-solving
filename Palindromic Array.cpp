#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    int ar[n];
	    for(int i=0;i<n;i++) {
	        cin>>ar[i];
	    }
	    int count=0;
	    for(int l=0,r=n-1;l<r;) {
	        if(ar[l]==ar[r]) {
	            l++;
	            r--;
	        } else if(ar[l] < ar[r]) {
	            count++;
	            ar[l+1] += ar[l];
	            l++;
	        } else {
	            count++;
	            ar[r-1] += ar[r];
	            r--;
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}
