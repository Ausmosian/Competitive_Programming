#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

bool mid_checker(vector<int> folders,int tot_workers,int mid){ 
    int n=folders.size();
    int curr_worker=1;
    int curr_worker_load=0;
    int max_load=mid;
    for(int i=0;i<n;i++){
        if(curr_worker_load+folders[i]>max_load){
            curr_worker_load=folders[i];
            curr_worker++;
            if(curr_worker>tot_workers) return false;
        }
        else curr_worker_load+=folders[i];
    }
    return true;
}

int min_max_func(vector<int> folders,int tot_workers){
    int n=folders.size();
    int i=*max_element(folders.begin(),folders.end());
    int f=accumulate(folders.begin(),folders.end(),0);
    int mid;
    int ans;
    while(i<=f){
        mid=(i+f)/2;
        if(mid_checker(folders,tot_workers,mid)==true){
            f=mid-1;
            ans=mid;
        }

        else i=mid+1;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t; cin >>t;

    while(t--){
    int cabinets_cnt; cin>>cabinets_cnt;

    vector<int> folders;

    for(int i=1;i<=cabinets_cnt;i++){
        int num; cin>>num;
        folders.push_back(num);
    }

    int workers; cin>>workers;

    cout<<min_max_func(folders,workers)<<endl;
    }
    return 0;
}
