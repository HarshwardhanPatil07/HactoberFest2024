#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define trav(x) for(auto &i:(x))

const ll INF = ll(1e18);
const char nl = '\n';

vector<ll> parent, rnk;

void make_set(ll v) {
	parent[v] = v;
	rnk[v] = 0;
}

ll find_set(ll v) {
	if(parent[v] == v)
		return v;
	return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b) {
	a = find_set(a);
	b = find_set(b);
	if(a != b) {
		if(rnk[a] < rnk[b]) {
			swap(a, b);
		}
		parent[b] = a;
		if(rnk[a] == rnk[b])
			rnk[a]++;
	}
} 

struct Edge {
	ll a,b,cost;
};

bool cmpEdge(const Edge &e1, const Edge &e2) {
	return e1.cost < e2.cost;
}

ll n,m;
vector<Edge> edge;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);
	
	cin>>n>>m;
	while(m--) {
		ll a,b,c;
		cin>>a>>b>>c;
		a--, b--;
		edge.push_back({a,b,c});
	}
	parent.resize(n);
	rnk.resize(n);

	for(ll i=0; i<n; i++) {
		make_set(i);
	}

	sort(all(edge), cmpEdge);
	ll ans = 0;
	vector<Edge> mst;
	for(Edge e: edge) {
		if(find_set(e.a) != find_set(e.b)) {
			ans += e.cost;
			mst.push_back(e);
			union_sets(e.a, e.b);
		}
	}
	if(mst.size() == n-1) cout<<ans<<nl;
	else cout<<"IMPOSSIBLE"<<nl;

	return 0;
}
