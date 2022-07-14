/*
   Date : 14 7 2022
   Tobi Where are you ?
   🧡 🐘
*/

#include<bits/stdc++.h>

#define ll long long
#define task "game"

#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 2e3+ 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

ll n,r;
ll a[MAX];

void sub1(){
	ll ans = 0;
	

    ll cnt = 0;
    ll po = 0;
    for(int i = 1; i <= n;i++){
        if(a[i]==1){
            cnt++;
        }else if(a[i]==0){
        	po++;
            ans = max(ans,cnt);
            cnt = 0;
        }
    }
    ans = max(ans,cnt);
    cout << ans + po;
}



signed main(){
	
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(ifstream(task".inp")){
		
		freopen(task".inp","r",stdin);
		freopen(task".out","w",stdout);
		
		
	}
	
	cin>>n>>r;
	
	ll cnt = 0;
	for(ll i = 1;i <= n;i++){
		cin>>a[i];
		//cnt += a[i] <= 1;
	}
	//cout<<cnt;
	
	sub1();

}