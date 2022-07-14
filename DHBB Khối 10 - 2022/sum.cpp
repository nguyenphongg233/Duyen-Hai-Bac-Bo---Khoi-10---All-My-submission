/*
   Date : 14 7 2022
   Tobi Where are you ?
   🧡 🐘
*/

#include<bits/stdc++.h>

#define ll long long
#define task "sum"

#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

signed main(){
	
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(ifstream(task".inp")){
		freopen(task".inp","r",stdin);
		freopen(task".out","w",stdout);
	}
	
	
	
	ll n,a,b;
	cin>>n>>a>>b;
	
	
	
	if(n <= 100){
		ll res = 0;
		for(ll i = 1;i <= n;i++){
			
			ll y = sqrt(i);
			res += (a % mod * i + b * y % mod) % mod;
			res %= mod;
			
			//cout<<(a % mod * i + b * sqrt(i))<<"\n";
			
		}
		
		cout<<res % mod;
		return 0;
		
	}else if(b == 0 && a == 1){
		
		ll res = ((n % mod) * ((n + 1) % mod)) / 2;
		
		cout<<res % mod;
		return 0;
	}
	
	ll sum = (((n % mod) * ((n + 1) % mod)) / 2) * (a % mod) ;
	sum %= mod;
	ll cnt = 0;
	vii rt;
	for(ll i = 1;i * i <= n;i++){
		
		if(i * i <= n)rt.push_back({i,i * i});
	}
	
	for(ll i = 0;i < rt.size() - 1;i++){
		
		ll x = rt[i].Y;
		ll y = rt[i + 1].Y;
		
		cnt += rt[i].X % mod * (y - x) % mod;
		cnt %= mod;
	}
	
	cnt += (rt[rt.size() - 1].X % mod * (n - rt.back().Y + 1) % mod) % mod;
	cnt %= mod;
	
	
	/*ll x = rt.back().Y;
	ll y = last * last;
	
	cnt += (min(y,n + 1) - x) * rt.back().X;
	cnt %= mod;*/
	
	//cout<<cnt<<" ";
	//cout<<(cnt % mod * (b % mod)) % mod<<"\n";
	sum += (cnt % mod * (b % mod)) % mod;
	sum %= mod;
	cout<<sum;
	
	
	
}