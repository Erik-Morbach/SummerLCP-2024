#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
#define INF (1<<30)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define lsb(i) (i&(-i))
#define all(z) begin(z), end(z)
#define EPS ((double)(1e-9))
#define MOD 1000000007
const int maxn = 1123456;


int query(int l, int r){
	int response;
	cout << "? "<<l<<" "<<r<<endl;
	cin >> response;
	return response;
}

void answer(int x){
	cout << "! "<<x<<endl;
}

void solve(){
	int n, t;
	cin >> n >> t;
	int k;
	cin >> k;

	int l = 1;
	int r = n;

	int ans = INF;
	while(l<=r){
		int m = (l+r)/2;
		int qntZeros = m - query(1, m);
		if(qntZeros >= k){
			if(qntZeros == k)
				ans = min(ans, m);

			r = m-1;
		}
		else l = m+1;
	}
	answer(ans);
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0)->tie(0);
	int t = 1;
	//cin >> t;

	for(int caso=1;caso<=t;caso++){
		solve();
	}
	return 0;
}
