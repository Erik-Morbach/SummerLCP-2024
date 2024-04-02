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
const int maxn = 312345;
const int mod = 998244353;

vector<int> prox[maxn];
int dist[maxn];
int begDist[maxn];
int endDist[maxn];

int dfs(int v, int p){
	int endd = v;
	for(int w:prox[v]){
		if(w==p) continue;
		dist[w] = dist[v] + 1;
		int atu = dfs(w,v);
		if(dist[atu] > dist[endd]){
			endd = atu;
		}
	}
	return endd;
}

void solve(){
	int n;
	cin >> n;
	for(int i=1;i<n;i++){
		int a,b;
		cin >> a >> b;
		prox[a].push_back(b);
		prox[b].push_back(a);
	}

	dist[1] = 0;
	int aux = dfs(1, -1);
	dist[aux] = 0;
	int ini = dfs(aux, -1);
	for(int i=0;i<=n;i++) begDist[i] = dist[i];
	dist[ini] = 0;
	int endd = dfs(ini, -1);
	for(int i=0;i<=n;i++) endDist[i] = dist[i];
	
	int diam = dist[endd];

	for(int i=1;i<=n;i++){
		cout << max(diam, max(endDist[i], begDist[i]) + 1) << "\n";
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


