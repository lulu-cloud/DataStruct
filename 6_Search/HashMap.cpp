#include<iostream>
#include <windows.h>
#include<map>
#include<queue>
using namespace std;


int main()

{
    int data[]={1,7,6,34,54,7,3,1,6,7,7,34,99};

    map<int,int>m;
    for(int i=0;i<sizeof(data)/sizeof(int);i++){
        m[data[i]]++;
    }
    map<int,int>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        cout<<it->first<<" : "<<it->second<<endl;
    }

}