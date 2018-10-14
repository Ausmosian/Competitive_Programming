//PROBLEM: Maximum distinct elements after removing k elements
//LINK: https://www.geeksforgeeks.org/maximum-distinct-elements-removing-k-elements/ 

#include <iostream>
#include<unordered_map>
#include<queue>
using namespace std;
int main() {
    int t; cin>>t;

    while(t--){
        int n,k; cin>>n>>k;
        unordered_map<int,int> hash;

        for(int i=1;i<=n;i++){
            int num; cin>>num;
            hash[num]++;
        }
        priority_queue<pair<int,int> > max_heap; 
        for(auto i: hash){
            if(i.second>1){
                max_heap.push(make_pair(i.second,i.first));
            }
        }

        while(!max_heap.empty()){
            pair<int,int> p=max_heap.top();
            k=k-p.first+1;
            max_heap.pop();
        }

        int u=hash.size();
        if(k>0) u-=k;

        cout<<u<<endl;

    }
}
