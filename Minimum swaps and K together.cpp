#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n,k,count=0;
	    cin>>n;
	    int ar[n];
	    for(int i=0;i<n;i++) {
	        cin>>ar[i];
	    }
	    cin>>k;
	    for(int a: ar) {
	        if(a<=k) count++;
	    }
	    int bad=0;
	    for(int i=0;i<count;i++) {
	        if(ar[i]>k) bad++;
	    }
	    int ans = bad;
	    for(int i=count;i<n;i++) {
	        if(ar[i]>k) bad++;
	        if(ar[i-count]>k) bad--;
	        ans = min(ans, bad);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
