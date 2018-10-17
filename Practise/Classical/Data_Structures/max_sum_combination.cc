#include <iostream>
#include<queue>
#include<algorithm>
using namespace std;
//class to handle a TRIPLET
template <typename T>
class Triplet{
    public:
    T first;
    T second; 
    T third;
    Triplet(T x,T y,T z){
        first=x;
        second=y;
        third=z;
    }
};
//Comparator class for heap
class myComp{
    public:
    bool operator ()(Triplet<int> t1,Triplet<int> t2){
        return (t1.first<t2.first);
    }
};
int main() {
    priority_queue<Triplet<int>,vector<Triplet<int> >,myComp> max_heap;
    int n; cin>>n;
    vector<int> a;
    vector<int> b;

    for(int i=1;i<=n;i++){
        int num; cin>>num;
        a.push_back(num);
    }
    //Sort in descending order
    sort(a.begin(),a.end(),greater<int>() );
    for(int i=1;i<=n;i++){
        int num; cin>>num;
        b.push_back(num);
    }
    //Sort in descending order
    sort(b.begin(),b.end(),greater<int>());
    
    int k; cin>>k;

    Triplet<int> t(a[0]+b[0],0,0);
    max_heap.push(t);
    vector<int> ans;
    while(k--){
        Triplet<int> t0=max_heap.top();
        max_heap.pop();
        int sum=t0.first;
        int i=t0.second;
        int j=t0.third;
        ans.push_back(sum);
        //Push cross Pairs
        Triplet<int> t1(a[i]+b[j+1],i,j+1);
        Triplet<int> t2(a[i+1]+b[j],i+1,j);
        max_heap.push(t1);
        max_heap.push(t2);
    }

    for(auto i: ans){
        cout<<i<<" ";
    }
}
