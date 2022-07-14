/*
   Date : 14 7 2022
   Tobi Where are you ?
   🧡 🐘
*/

#include<bits/stdc++.h>

#define ll long long
#define task "table"

#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 700 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

ll n,m,q;
ll a[MAX][MAX];
ll f[MAX][MAX];
ll pref[MAX][MAX];

struct querry{
	ll c;
	ll x,y,u,v;
	ll w;
};

vector<querry> yu;


void sub1(){
	// n * m * q = 500 ^ 2 *100 = 1 e 7
	while(q--){
		
		ll c,x,y,u,v;
		cin>>c;
		
		if(c == 1){
			ll val;
			cin>>x>>y>>u>>v>>val;
			
			for(ll i = x;i <= u;i++){
				for(ll j = y;j <= v;j++){
					
					a[i][j] += val;
					
				}
			}
			
		}else {
			
			
			cin>>x>>y>>u>>v;
			
			ll sum = 0;
			
			for(ll i = x;i <= u;i++){
				for(ll j = y;j <= v;j++){
					
					sum += a[i][j];
					
				}
			}
			
			
			
			cout<<sum<<'\n';
		}
		
	}
	
	
}

ll get(ll x,ll y,ll u,ll v){
	
	return pref[u][v] - pref[x - 1][v] - pref[u][y - 1] + pref[x - 1][y - 1];
	
}


void sub2(){
	
	bool ok = 0;
	
	for(ll i = 0;i < yu.size();i++){
		
		if(yu[i].c == 2)break;
		
		
		ll x = yu[i].x;
		ll y = yu[i].y;
		ll u = yu[i].u;
		ll v = yu[i].v;
		ll w = yu[i].w;
		
		a[x][y] += w;
		a[u + 1][v + 1]+= w;
		a[x][v + 1] -=w;
		a[u + 1][y] -=w;
		
	}
	
	
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= m;j++){
			pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
			//cout<<pref[i][j]<<" ";
		}
		//cout<<"\n";
	}
	
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= m;j++){
			pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
			//cout<<pref[i][j]<<" ";
		}
		//cout<<"\n";
	}
	
	for(ll i = 0;i < yu.size();i++){
		
		if(yu[i].c == 1)continue;
		
		
		ll x = yu[i].x;
		ll y = yu[i].y;
		ll u = yu[i].u;
		ll v = yu[i].v;
		
		//cout<<x<<""<<y<<" "<<u<<" "<<v<<"\n";
		cout<<get(x,y,u,v)<<"\n";
		
	}
	
	
	
}

/*ll bit[MAX][MAX];

/*void sub3(){
	
	for(ll i = 0;i < yu.size();i++){
		
		ll c = yu[i].c;
		ll x = yu[i].x;
		ll y = yu[i].y;
		ll u = yu[i].u;
		ll v = yu[i].v;
		ll w = yu[i].w;
		
		
		if(c == 1){
			
			update(x,y,w);
			update(u + 1,v + 1,w);
			update(x,v + 1,-w);
			update(u + 1,y,-w);
			
		}else{
			
			cout<<query(x,y,u,v)<<'\n';
			
		}
		
	}
	
}*/

ll bit[MAX][MAX][2];

// 0 = 2

void add(ll id,ll dx,ll val,bool c){
	for(;id <= m;id += id &-id)bit[dx][id][c] += val;
}

void update_range(ll l,ll r,ll dx,ll val){
	
	add(l,dx,val * (m - l + 1),1);
	add(r + 1,dx,-(m - r) * val,1);
	add(l,dx,val,0);
	add(r + 1,dx,-val,0);
	
}

ll get(ll id,ll dx,bool c){
	
	ll sum = 0;
	for(;id > 0;id -= id&-id)sum += bit[dx][id][c];
	return sum;
}

ll presum(ll id,ll dx){
	
	return get(id,dx,1) - get(id,dx,0) * (m - id);
	
}

ll get_range(ll l,ll r,ll dx){
	return presum(r,dx) - presum(l - 1,dx);
}

ll pre2[MAX][MAX];
void sub3(){
	for(ll i = 1;i <= n;i++){
		
		for(ll j = 1;j <= m;j++){
			//add(j,i,a[i][j],0);
			//cout<<get(j,i)<<" ";
			pre2[i][j] = pre2[i][j - 1] + a[i][j];
			//cout<<pre2[i][j]<<" ";
		}
		//cout<<"\n";
	}
	
	for(ll i = 0;i < yu.size();i++){
		
		ll c = yu[i].c;
		ll x = yu[i].x;
		ll y = yu[i].y;
		ll u = yu[i].u;
		ll v = yu[i].v;
		ll w = yu[i].w;
		
		if(c == 1){
			
			for(ll z = x;z <= u;z++){
				update_range(y,v,z,w);
			}
			
			
		}else{
			
			//cout<<"hi";
			
			ll sum = 0;
			for(ll z = x;z <= u;z++){
				//cout<<presum(v,z)<<" ";
				//cout<<presum(y - 1,z)<<"\n";
				sum += get_range(y,v,z);
				sum += pre2[z][v] - pre2[z][y - 1];
			}
			cout<<sum<<'\n';
		}
		
		
		
	}
	
	
	
}
signed main(){
	
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(ifstream(task".inp")){
		
		freopen(task".inp","r",stdin);
		freopen(task".out","w",stdout);
		
		
	}
	
	
	cin>>n>>m>>q;
	
	
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= m;j++){
			cin>>a[i][j];
			//update(i,j,a[i][j,0);
		}
	}
	
	
	/*if(q <= 100){
		
		sub1();
		return 0;
	}*/
	
	bool ok1 = 1;
	ll maxx = 1;
	for(ll i = 1;i <= q;i++){
		
		ll c,x,y,u,v,w;
		cin>>c>>x>>y>>u>>v;
		
		if(c < maxx)ok1 = 0;
		maxx = max(maxx,c);
		//cout<<maxx<<'\n';
		
		if(c == 2){
			
		
			yu.push_back({c,x,y,u,v,-1});
			
			
		}else{
	
		
			cin>>w;
			
			yu.push_back({c,x,y,u,v,w});
			
		}
		
		
	}
	//cout<<ok1<<"\n";
	/*if(ok1){
		
		sub2();
		return 0;
		
	}*/
	
	sub3();
	
	
}