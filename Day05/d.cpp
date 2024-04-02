#include <bits/stdc++.h>
#include <functional>
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
	vi prox[maxn];
	bool vizi[maxn];
	int low[maxn];
	int d[maxn];
	int f[maxn];
	int cnt = 1;
	int compo[maxn];
	vector<vi> compos;

	vector<int> currentCompo;
	void add(int a, int b){
		prox[a].push_back(b);
	}
	void dfs(int v, int p=-1){
		low[v] = d[v] = cnt++;
		vizi[v] = true;
		currentCompo.push_back(v);

		for(int w: prox[v]){
			if(!vizi[w]){
				dfs(w, v);
				low[v] = min(low[v], low[w]);
			}
			else if(compo[w] == 0)
				low[v] = min(low[v], d[w]);
		}

		if(low[v] == d[v]){
			compos.push_back({});
			while(1){
				int u = currentCompo.back();
				currentCompo.pop_back();
				compos.back().push_back(u);
				compo[u] = compos.size();
				if(u == v) break;
			}
		}
		f[v] = cnt++;
	}
};
void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		graph::add(a, b);
	}

	for(int i=1;i<=n;i++){
		if(!graph::vizi[i]) graph::dfs(i, -1);
	}

	if(graph::compos.size() == 1){
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
	int ans[2];
	int id = 0;
	for(int i=0;i<graph::compos.size() && id < 2;i++){
		if(graph::compos[i].size())
			ans[id++] = graph::compos[i][0];
	}

	if(graph::f[ans[0]] > graph::f[ans[1]]) swap(ans[0], ans[1]);

	cout <<ans[0] <<" "<<ans[1]<<"\n";

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


