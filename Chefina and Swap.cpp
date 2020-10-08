#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

ll overall(ll m,ll n) {
    return ((n+m)*(n-m+1))/2;
}

ll findMid(ll n, ll c=0) {
    if(c==-1) c = overall(1,n);
    ll b = 2*n+1;
    ll mid = (b - sqrt(b*b-4*c))/2;
    return n-mid;
}

int main() {
	ll t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    if(n<4) {
            switch(n){
                case 1:
                case 2:
                    cout<<"0\n";
                    break;
                case 3:
                    cout<<"2\n";
                    break;
            }
            continue;
        }
        ll sum = overall(1,n);
        if(sum%2) {
            cout<<"0\n";
            continue;
        }
        ll m=findMid(n, sum);
        sum/=2;
        ll half=overall(m+1,n);
        if(half<sum){
            half+=m;
            m--;
        }
        ll diff=half-sum,ans=0;
        if(!diff) {
            ans = (m*(m-1))/2 + ((n-m)*(n-m-1))/2;
        }
        ans += n-m;
        cout<<ans<<'\n';
	}
	return 0;
}
