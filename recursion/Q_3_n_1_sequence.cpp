//https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/Q
//https://www.youtube.com/watch?v=ofw5DAhdoYI

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long


// by Harsh (TLE)
int sequence(int n){
    if(n==1) return 1;
    if(n%2==0) return sequence(n/2) + 1 ;
    else return sequence((3*n) +1) + 1;
}


int shubham(int n, int count){

    count++;
    if(n==1) return (1, count);
    if(n%2!=0) return shubham((3*n) +1, count);
    if(n%2==0) return shubham(n/2, count);
    return count;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin>>n;

    cout<<sequence(3);
}




