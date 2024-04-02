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

enum{
	KeyOrNothing = 0,
	Door
};
namespace graph{
	vi prox[maxn];
	int vizi[maxn];
	int key[maxn];
	int keyCnt = 0;
	void setup(int n){
		keyCnt = 0;
		for(int i=0;i<=n;i++){
			prox[i].clear();
			vizi[i] = 0;
			key[i] = 0;
		}
	}
	void setKey(int keyRoom, int doorRoom){
		keyCnt++;
		key[keyRoom] = keyCnt;
		key[doorRoom] = -keyCnt;
	}
	void add(int a, int b){
		prox[a].push_back(b);
		prox[b].push_back(a);
	}

	bool dijkstra(int s, int t){
		priority_queue<pair<ii, int>, vector<pair<ii,int>>, greater<pair<ii,int>>> que;
		que.push({{KeyOrNothing, 0}, s});
		set<int> have;
		int counter = 0;
		int lastNotDoor = 1;
		vizi[s] = lastNotDoor;
		while(que.size()){
			auto atu = que.top();
			que.pop();
			//cout << "I'm in ("<< atu.x.x<<", "<<atu.x.y<<"), "<<atu.y<<endl;
			if(atu.y == t) return true;
			if(atu.x.x == KeyOrNothing){
				if(key[atu.y] > 0)
					have.insert(key[atu.y]);
				lastNotDoor++;
			}
			else{
				int k = abs(key[atu.y]);
				if(!have.count(k)){
					//cout << "I do not have a key and ";
					//cout << vizi[atu.y] <<" x "<<lastNotDoor<<endl;
					if(vizi[atu.y] == lastNotDoor) continue;
					//cout << "Pushing..."<<endl;
					que.push({{Door, ++counter}, atu.y});
					vizi[atu.y] = lastNotDoor;
					continue;
				}
			}
			for(auto w: prox[atu.y]){
				if(vizi[w]) continue;
				vizi[w] = 1;
				int tip = key[w] < 0 ? Door: KeyOrNothing;
				que.push({{tip, counter}, w});
			}
		}
		return false;
	}

};
void solve(){
	int n, k, m;
	cin >> n >> k >> m;
	if(n==k and k==m and n==-1) exit(0);
	graph::setup(n);
	for(int i=0;i<k;i++){
		int a, b;
		cin >> a >> b;
		graph::setKey(a, b);
	}
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		graph::add(a, b);
	}
	bool ans = graph::dijkstra(1, n);
	if(ans) cout << "Y\n";
	else cout << "N\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for(int caso=1;/*caso<=t*/;caso++){
		solve();
	}
	return 0;
}


