#include <iostream>
#include<vector>
using namespace std;

int search_first_occ(vector<int> v, int key, int i,int f){
    int ans=-1;

    while(i<=f){
        int mid=(i+f)/2;
        // cout<<mid<<endl;
        if(key<v[mid]) f=mid-1;

        else if(key>v[mid]) i=mid+1;

        else{
            ans=mid;
            // f=mid-1;  //First Occurance
            i=mid+1;     //Last Occurance
        }
    }

    return ans;
}

int main() {
    vector<int> v = {1,1,2,2,2,4,4};
    int key; cin>>key;
    cout<<search_first_occ(v,key,0,v.size()-1);
}
