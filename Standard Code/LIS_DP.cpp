/* Author : Chirag */
#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define pii pair<int, int>
#define pb push_back
#define pp pop_back
#define vi vector<int>
#define max_pq priority_queue<int>
#define min_pq priority_queue<int, vector<int>, greater<int>>
#define round_int(a) (int)((double)a + 0.5)
#define round_decimal(a, f) cout << fixed << setprecision(f) << a << endl;
#define log(a)            \
    for (auto a : a)      \
    {                     \
        cout << a << " "; \
    }
#define read(n) \
    int n;      \
    cin >> n;
#define endl "\n";
using namespace std;
double Euclid_Dis(pair<int, int> &A, pair<int, int> &B)
{
    ll T = ((B.first - A.first) * (B.first - A.first)) + ((B.second - A.second) * (B.second - A.second));
    return sqrt(T);
}
int ManHattan(int x, int y, int x0, int y0)
{
    return abs(x0 - x) + abs(y0 - y);
}
int ManHattan(pair<int, int> &A, pair<int, int> &B)
{
    return abs(A.first - B.first) + abs(A.second - B.second);
}
int LIS(vector<int> nums,int n){
    if(n == 0) return 0;
    vector<int> seq;
    seq.push_back(nums[0]);
    for(int i = 1;i < n;i++){
        if(nums[i] > seq.back()){
            seq.pb(nums[i]);
        }
        else{
            int idx = lower_bound(seq.begin(),seq.end(),nums[i]) - seq.begin();
            seq[idx] = nums[i];
        }
    }
    return seq.size();
}
void solve()
{   
    vector<int> nums = {5,8,3,7,9,1};
    int n = 6;
    int ans = LIS(nums,n);
    cout<<ans<<endl;
    return;
}

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main()
{
    clock_t begin = clock();
    file_i_o();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}