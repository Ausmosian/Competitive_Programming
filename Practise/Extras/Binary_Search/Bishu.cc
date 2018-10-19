//https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/bishu-and-soldiers/
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int my_upper_bound(vector<int> power,int bishu_power){
    int i=0;
    int f=power.size()-1;
    int ans=-1;
    while(i<=f){
        int mid=(i+f)/2;

        if(power[mid]<bishu_power) i=mid+1;

        else if(power[mid]>bishu_power) f=mid-1;

        else{
            ans=mid;
            i=mid+1;
        } 
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tot_soldiers; cin>>tot_soldiers;

    vector<int> power;

    for(int i=0;i<tot_soldiers;i++){
        int num; cin>>num;
        power.push_back(num);
    }
    sort(power.begin(),power.end());

    vector<int> power_sum;   //power_sum[i]=power[0]+power[1]+.....power[i];
    int curr_sum=0;
    for(int i=0;i<tot_soldiers;i++){
        curr_sum+=power[i];
        power_sum.push_back(curr_sum);
    }

    int query; cin>>query;

    while(query--){
        int bishu_power; cin>>bishu_power;

        
        if(bishu_power< power.front()){
            cout<<0<<" "<<0<<endl;
            continue;
        }
        if(bishu_power> power.back()){
            cout<<tot_soldiers<<" "<< power_sum.back()<<endl;
            continue;
        }

        int index=my_upper_bound(power,bishu_power);
        cout<<index+1<<" "<<power_sum[index]<<endl;
        
    }
    return 0;
}
