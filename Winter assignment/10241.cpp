#include<iostream>
#include<cstdio>
using namespace std;

int fv[5];
int nf[5];

void print(int n){
    printf("(%d", nf[0]);
    for(int i=1; i<n; i++)
        printf(",%d",nf[i]);
    cout<<")\n";
}

void change(int total, int cur, int n){
    if(cur<n){
        if(total==0) print(n);
        else if(total>0){
            change(total,cur+1,n);
            total-=fv[cur];
            nf[cur]++;
            change(total,cur,n);
            nf[cur]--;
            total+=fv[cur];
        }
    }

}

int main(){
    int nfv;
    cin >> nfv;
    for(int i=0; i<nfv; i++)
        cin >> fv[i];
    int total;
    cin >> total;

    change(total, 0, nfv);
}