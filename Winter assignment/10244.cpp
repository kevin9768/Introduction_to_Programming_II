#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

struct vec{
    int dim;
    int value;
    vec(int d, int v):dim(d),value(v){};
};

int main(){
    vector<vec> a;
    vector<vec> b;

    int d,v;
    scanf("%d:%d", &d, &v);
    while(!(d==0&&v==0)){
        a.push_back(vec(d,v));
        scanf("%d:%d", &d, &v);
    }
    scanf("%d:%d", &d, &v);
    while(!(d==0&&v==0)){
        b.push_back(vec(d,v));
        scanf("%d:%d", &d, &v);
    }

    int a_size = a.size();
    //cout<<a_size<<'\n';   
    int b_size = b.size();
    //cout<<b_size<<'\n';
    int sum=0;
    for(int i=0; i<a_size; i++){
        for(int j=0; j<b_size; j++){
            if(a[i].dim==b[j].dim)
                sum += a[i].value*b[j].value;
        }
    }
    cout<<sum<<'\n';
}