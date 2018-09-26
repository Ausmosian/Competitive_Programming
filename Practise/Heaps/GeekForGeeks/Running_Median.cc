//PROBLEM: Find median in a stream
//LINK: https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0

#include <iostream>
#include<queue>
#include<climits>
using namespace std;
int main() {
    int n; cin>>n;
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int> > min_heap;
    int median=INT_MAX;
    for(int i=1;i<=n;i++){
        int num; cin>>num;

        if(num<median) max_heap.push(num);
        else min_heap.push(num);

        if(max_heap.size()-min_heap.size()==2){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if(min_heap.size()-max_heap.size()==2){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

        if(max_heap.size()-min_heap.size()==1){
            median=max_heap.top();
        }
        else if(min_heap.size()-max_heap.size()==1){
            median=min_heap.top();
        }

        if(max_heap.size()==min_heap.size()){
            median=(min_heap.top()+max_heap.top())/2;
        }

        cout<<median<<endl;
    }
}
