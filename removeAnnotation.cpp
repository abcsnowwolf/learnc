//
// Created by lyf on 2017/9/15.
//
/**
 * 本题为inter笔试编程题目，要求删除注释部分
 */

#include <iostream>
using namespace std;
void rmAnnotation(char *txt);
int main() {
    char txt[] = "2323/*dfkjd*/k*/dk/*d/*fhg*/12\0";
    rmAnnotation(txt);
    cout<<txt;
    return 0;
}
void rmAnnotation(char *txt){
    int cnt = 0;
    int start = 0;
    int end = 0;
    bool flag = false;
    while(txt[cnt] != '\0'){
        cnt++;
    }
    int length = cnt+1;
    cnt = 0;
    while(txt[cnt] != '\0'){
        if(!flag && txt[cnt] == '/' && txt[cnt+1] == '*'){
            start = cnt;
            flag = true;
        }
        if(flag && txt[cnt] == '*' && txt[cnt+1] == '/'){
            end = cnt+2;
            memcpy(txt + start,txt+end,sizeof(char) * (length - start));
            cnt = start-1;
            flag = false;
        }
        cnt++;
    }
    return;
}