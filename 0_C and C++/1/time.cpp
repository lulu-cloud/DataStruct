#include<iostream>
#include <windows.h>
using namespace std;

//O(n^2)
void fun_1(int n){
    int i,j,x=0;
    for(i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            x++;
        }
    }
}

//O(sqrt(n))

void fun_2(int n){
    int i=0,s=0;
    while(s<n){
        i++;
        s+=i;
    }
}

