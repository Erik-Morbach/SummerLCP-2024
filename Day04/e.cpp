#include <bits/stdc++.h>
#include <queue>
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

namespace graph{
	int n;
	vi prox[maxn];
	int vizi[maxn];
	void add(int a, int b){
		prox[a].push_back(b);
		prox[b].push_back(a);
	}
	void setup(int n){
		graph::n = n;
		for(int i=0;i<=n;i++) {
			prox[i].clear();
			vizi[i] = 0;
		}
	}

	vi dist(int s){
		priority_queue<ii, vector<ii>, less<ii>> que;
		vi di(n+1, INF);
		que.push({0,s});
		di[s] = 0;
		while(que.size()){
			auto atu = que.top();
			que.pop();
			if(atu.x != di[atu.y]) continue;
			int nextDist = atu.x+1;
			for(auto w: prox[atu.y]){
				if(nextDist >= di[w]) continue;
				di[w] = nextDist;
				que.push({nextDist, w});
			}
		}
		return di;
	}
	bool haveCicle(int v, int p){
		vizi[v] = 1;
		for(int w: prox[v]){
			if(w == p) continue;
			if(vizi[w]){
				return true;
			}
			if(haveCicle(w, v)) return true;
		}
		vizi[v] = 0;
		return false;
	}
};

namespace dsu{
	int pai[maxn];
	int siz[maxn];
	void setup(int n){
		for(int i=0;i<=n;i++){
			pai[i] = i;
			siz[i] = 1;
		}
	}
	int find(int v){
		return (v==pai[v]?v:pai[v] = find(pai[v]));
	}
	void unio(int u, int v){
		u = find(u);
		v = find(v);
		if(siz[u] < siz[v]) swap(u,v);
		siz[u] += siz[v];
		pai[v] = u;
	}
};

void solve(){
	int n, a, b;
	cin >> n >> a >> b;
	graph::setup(n);
	dsu::setup(n);
	int cycle[2];

	for(int i=0;i<n;i++){
		int u, v;
		cin >> u >> v;
		if(dsu::find(u) != dsu::find(v)){
			dsu::unio(u,v);
		}
		else{
			cycle[0] = u;
			cycle[1] = v;
		}
		graph::add(u,v);
	}

	vi dToA = graph::dist(a);
	vi dToB = graph::dist(b);
	
	graph::haveCicle(cycle[0], cycle[1]); // Go the other way around to find the cycle

	bool ans = false;
	for(int i=1;i<=n and !ans;i++){
		if(graph::vizi[i]){
			if(dToA[i] > dToB[i]) ans = true;
		}
	}
	if(ans) cout << "YES\n";
	else cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	for(int caso=1;caso<=t;caso++){
		solve();
	}
	return 0;
}


