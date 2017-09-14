//
// Created by lyf on 2017/9/14.
//
/**
 * 滴滴秋招题目，给出一个数组，要求将数组中可以xor得0的数字分组，求得给定数组中可分出的最多的组数
 */

#include <iostream>
#include <map>


using namespace std;
int findMaxZone(map<int,int> a,int start,int n);
int main() {
    int n;
    cin>>n;
    int a[n];
    int result = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int xorVal;
    map<int,int> roadMap;
    for(int i = 0;i<n;i++){
        xorVal = 0;
        for(int j=i;j<n;j++){
            xorVal = xorVal xor a[j];
            if(xorVal == 0){
                roadMap.insert(make_pair(i,j));
                break;
            }
        }
    }
    result = findMaxZone(roadMap,0,n);
    cout<<result;
}
int findMaxZone(map<int,int> a,int start,int n){
    int sum = 0;
    int last = 0;
    if(start > n){
        return 0;
    }
    int firstEnd = INT_MAX;
    for(int i=start;i<n;i++){
        if(i >= firstEnd ){
            break;
        }
        if(a.find(i) != a.end()){
            if(firstEnd == INT_MAX){
                firstEnd = a[i];
            }
            sum = 1 + findMaxZone(a,a[i]+1,n);
        }
        if(sum > last){
            last = sum;
        }
    }
    return last;
}