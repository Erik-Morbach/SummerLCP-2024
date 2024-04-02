#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
#define INF (1<<30)
#define LINF (1LL<<61)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define lsb(i) (i&(-i))
#define all(z) begin(z), end(z)
#define EPS ((double)(1e-9))
const int maxn = 212345;
const int maxp = 20;
const int mod = 998244353;

int values[maxn];
int ans[maxn];

namespace lis{
	vi lis;
	ii add(int x){
		ii respo;
		auto it = lower_bound(all(lis), x);
		respo.x = it - lis.begin();
		if(it == lis.end()){
			lis.push_back(x);
			respo.y = -1;
			return respo;
		}
		respo.y = *it;
		if(*it > x) *it = x;
		return respo;
	}
	int query(){
		return lis.size();
	}
};

namespace graph{
	vi prox[maxn];
	void add(int u, int v){
		prox[u].push_back(v);
		prox[v].push_back(u);
	}

	void dfs(int v, int p){
		ii curr = lis::add(values[v]);
		ans[v] = lis::query();
		for(int w: prox[v]){
			if(w==p) continue;
			dfs(w, v);
		}
		if(curr.y==-1) lis::lis.pop_back();
		else lis::lis[curr.x] = curr.y;
	}
};

void solve(){
	int n;
	cin >> n;

	for(int i=2;i<=n;i++){
		int p;
		cin >> p;
		graph::add(i, p);
	}
	for(int i=1;i<=n;i++){
		cin >> values[i];
	}

	graph::dfs(1, -1);

	for(int i=2;i<=n;i++){
		cout << ans[i] << " \n"[i==n];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for(int caso=1;caso<=t;caso++){
		solve();
	}
	return 0;
}


