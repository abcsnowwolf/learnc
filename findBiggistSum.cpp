//
// Created by lyf on 2017/9/14.
//

#include <iostream>
using namespace std;
int findTallest(int people[],int m,int cnt,int rec[]);
int main() {
    int m;
    cin>>m;
    int people[m];
    int sum = 0;
    int rec[m];
    for(int i=0;i<m;i++){
        cin>>people[i];
        sum += people[i];
        rec[i] = -1;
    }
    int A = findTallest(people,m,0,rec);
    if(A > sum / 2){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}
int findTallest(int people[],int m,int cnt,int rec[]){
    if(cnt >= m){
        return 0;
    }
    if(rec[cnt] != -1){
        return rec[cnt];
    }
    int sum = 0;
    for(int i = cnt;i<m;i++){
        sum += people[i];
    }
    //A选一个的时候
    int sum1 = sum - findTallest(people,m,cnt+1,rec);
    //A选两个的时候
    int sum2 = 0;
    if(m > cnt+1){
        sum2 = sum - findTallest(people,m,cnt+2,rec);
    }
    int res = max(sum1,sum2);
    rec[cnt] = res;
    return res;
}