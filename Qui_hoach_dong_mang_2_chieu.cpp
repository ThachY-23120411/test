		#include<iostream>
		#include<string>
		#include<cstring>
		using namespace std;
		#define ll long long
		ll a[300001];
		int main() {
			ll t; cin >> t;
			while (t--) {
				ll n, k;
				cin >> n >> k;
                for(ll i=0;i<=n;i++){
                    a[i]=0;
                }
				for (ll i = 1; i <= n; i++) {
					cin >> a[i];
				}
				ll dp[n+1][k+1];
				memset(dp, 0, sizeof(dp));
				for (ll i = 1; i <= min(n-1, k); i++)
                {
                    dp[i][i] = 1e18;
                }
				//.dp[i][j]: xet ts vi tri i , va j la so lan thuc hien op , va dp[i][j] la tong min khi xet ts phan tu thu i va so lan thuc hien op la j
				for (ll i = 1; i <= n; i++) {
					for (ll j = 0; j <= min(i-1,k); j++) {
						//.TH co so(TH1): ko thuc hien bat ki op nao len a[i]-->lay min tinh tu i-1 vs so lan th/hien op la j cong vs a[i] -->dp[i][j]=dp[i-1]+a[i];
						dp[i][j] = dp[i - 1][j] + a[i];
						//.TH2: co su dung q op len 1 phan tu trong doan tu [i - q  , i]-->Muc dich la de tong ts i c toi uu--> Ta se chon 1 phan tu nho nhat trong so cac phan tu trong doan [i-q+1,i] do de thuc hien q op len chinh phan tu nho nhat do
						// -->Khi thuc hien q op len phan tu nho nhat do (gia su la i=v) thi no se chuyen toan bo a[?] voi ? thuoc [i-q,i] thanh a[v] toan bo
						//--> Vi thuc hien q op len a[v]--> a[?]=a[v] voi ? thuoc [i-q,i] --> tong toi uu tinh ts vi tri i khi nay chinh la = < tong toi uu tinh ts vi tri ((i-q-1) -1)> + q*a[v];
						//.Xet ts vi tri i --> so op toi da co the th/hien len i la i-1 op.
                        ll val = a[i];
						for (ll o = 1; o <= j; o++) {
							val = min(val, a[i-o]);
							dp[i][j] = min(dp[i][j], dp[i - o - 1][j - o] + (o+1) * val);
						}
					}
				}
				cout<<dp[n][min(k,n-1)]<<endl;
		}
		}
