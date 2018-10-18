#include <iostream>
#include<vector>
using namespace std;

int rotated_search(vector<int> v, int key,int i,int f){
    while(i<=f){
        int mid=(i+f)/2;

        if(v[mid]==key) return mid;
        
        //Left part sorted
        if(v[i]<=v[mid]){
            if(key<v[mid] && key>=v[i]) f=mid-1;

            else i=mid+1;
        }
        //Right Part sorted
        else if(v[mid]<=v[f]){
            if(key>v[mid] && key<=v[f]) i=mid+1;

            else f=mid-1;
        }
    }
    return -1;
}

int main() {
    vector<int> v = {4,5,1,2,3};

    int t; cin>>t;
    while(t--){
    int key; cin>>key;
    cout<<rotated_search(v,key,0,v.size()-1)<<endl;
    }

    return 0;
}
