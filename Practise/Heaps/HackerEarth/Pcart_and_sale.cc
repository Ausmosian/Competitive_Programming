#include <iostream>
#include<queue>
#define MOD 1000000007
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,x; cin>>n>>m>>x;
    priority_queue<int,vector<int>,greater<int> > min_heap;
 
    while(n--){
        int num; cin>>num;
        min_heap.push(num);
    }
    int ans=0;
    while(m--){
        int curr=min_heap.top();
        min_heap.pop();
        ans+=curr;
        ans%=MOD;
        curr=(curr^x)+1;
        min_heap.push(curr);
    }
 
    cout<<ans;
}
