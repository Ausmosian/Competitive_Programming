#include <iostream>
#include<cmath>
using namespace std;

double sq_root(int n,int prec){
    cout<<"in func";
    int p=0;
    double ans;
    double i=0;
    double f=n;
    while(p<=prec){

        //If we find the smallest range in which the answer lies, we go inside this range
        if(i>f){
            swap(i,f);
            i=ans;
            f=ans+pow(10,-p);
            //We increase precison so as to calculate next decimal 
            p++;
            if(p>prec) break;
        }
        
        //Calculate mid
        double mid=(i+f)/2;
        //Round off to nearest precision
        mid=mid*pow(10,p);
        mid=(int)mid;
        mid=mid*pow(10,-p);

        //Typical Binary Search
        if(mid*mid>n) f=mid-pow(10,-p);

        else if(mid*mid<n){
            ans=mid;
            i=mid+pow(10,-p);
        }
        else return mid;
    }

    return ans;
}

int main() {
    double n;
    int p;
    cin>>n>>p;

    cout<<sq_root(n,p);
}
