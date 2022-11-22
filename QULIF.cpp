#include <bits/stdc++.h>
using namespace std;

ifstream input("input.txt");
ofstream output("output.txt");

#define ll long long 
#define pii pair<ll,ll>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define sorta(v) sort(v.begin(),v.end())
#define mem(a,b) memset(a,b,sizeof(a));
#define GetBit(u) u & - u;
#define bit(u,i) ((u >> i) & 1)
#define mask(i) (1ll << i)

const ll cs = 2e5 + 7;
const ll mod = 1e9 + 7;
const ll INF = mod;
const ll maxN = 5e3 + 7;
const int block_size = 350;

int n;
int a[cs];
ll Prefix[cs];
ll sum = 0;
deque<int> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input >> n;
    for (int i = 1;i<=n;i++) {
        input >> a[i];
        Prefix[i] = Prefix[i - 1] + a[i];
    }
    sum = (Prefix[n] + 1) >> 1;
    int l = 1;
    ll res = LLONG_MAX;
    for (ll i = 1;i<=n;i++) {
        while (dq.size() && a[dq.back()] >= a[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        while (l <= i + 1 && Prefix[i] - Prefix[l - 1] - a[dq.front()]>= sum) {
            res = min(res,i - l + 1);
            l++;
            while (dq.size() && dq.front() < l) dq.pop_front();
        }
    }
    output << res - 1;
    return 0;
}
