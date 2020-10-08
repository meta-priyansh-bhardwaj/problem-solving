#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,l,h) for(int i=l;i<h;i++)

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k,a;
	    cin>>n>>k;
	    int ar[n];
	    loop(i,0,n){
	        cin>>ar[i];
	    }
	    unordered_map<int,int> count;
	    int track[n][n]={0};
	    loop(i,0,n){
	        loop(j,0,n) track[i][j]=0;
	    }
	    loop(i,0,n){
	        count.clear();
	        loop(j,i,n){
	            if(j==i) track[i][j]=0;
	            else track[i][j]=track[i][j-1];
	            count[ar[j]]++;
	            if(count[ar[j]]>1){
    	            if(count[ar[j]]==2) track[i][j]++;
    	            track[i][j]++;
	            }
	        }
	    }
	    int ans = INT32_MAX;
	    int dp[101][n+1];
	    loop(i,0,101){
	        loop(j,0,n){
	            dp[i][j]=0;
	        }
	    }
	    loop(i,1,n+1){
	        dp[1][i]=track[0][i-1];
	    }
	    loop(i,2,101){
	        dp[i][1]=0;
	    }
	    loop(i,2,101){
	        loop(j,2,n+1){
	            int best=INT32_MAX;
	            loop(p,1,j){
	                best=min(best,dp[i-1][p]+track[p][j-1]);
	            }
	            dp[i][j]=best;
	        }
	    }

	    loop(table,1,101){
    	    ans = min(ans,table*k+dp[table][n]);
    	}
    	cout<<ans<<'\n';
	}
	return 0;
}
