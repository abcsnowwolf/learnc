//
// Created by lyf on 2017/9/14.
//
/**
 * 招行信用卡中心笔试题，给定一个数组，A和B两个人从左侧开始，每次可以选择一个或两个数字
 * 两个人都足够聪明，A先开始选。数组最有一个数字被选取后，比较A所选的数字和与B所选的数字和，和大
 * 的获胜。
 * 输入：给定一个数组
 * 输出：A是否可以取胜（平局算A输）
 */

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