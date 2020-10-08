#include <bits/stdc++.h>
using namespace std;
#define HI 524288

int main() {
	int t,n;
	cin>>t;
	while(t--) {
	    cin>>n;
	    int64_t sum,low,high;
	    cout<<"1 1"<<endl;
	    cin>>low;
	    cout<<"1 "<<HI<<endl;
	    cin>>high;
	    sum = (low/HI)*HI + high%HI;
	    //cout<<(low/HI)*HI<<" + "<<high%HI<<" = "<<sum<<endl;
	    //sum -= (int64_t)HI*n;
	    int k=1,ones;
	    int64_t diff,res,ans=0;
	    while(k<=HI) {
	        if(k==1) res=low;
	        else if(k==HI) res=high;
	        else {
	            cout<<"1 "<<k<<endl;
	            cin>>res;
	            //cout<<"Collected: "<<res<<endl;
	        }
	        if(res==-1) break;
	        diff = (sum-res)/k;
	        ones = (n+diff)/2;
	        //cout<<"Ones: "<<ones<<" diff: "<<diff<<" n: "<<n<<endl;
	        //if(!ones) break;
	        if(ones%2) ans += k;
	        k=k<<1;
	    }
	    cout<<"2 "<<ans<<endl;
	    cin>>res;
	    if(res!=1) break;
	}
	return 0;
}
