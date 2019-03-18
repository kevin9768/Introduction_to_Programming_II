#include<iostream>

using namespace std;

void place_q(int row,int cnt_c,int cnt_q);

int count=0,M,N;

int q[11],c[11];

int valid(int row,int col,int isq){
    for(int i=1;i<row;i++){
        if(isq){
            if(row-i==col-q[i]||row-i==q[i]-col||row-i==c[i]-col||row-i==col-c[i]||c[i]==col||q[i]==col){
                return 0;
            }
        }
        else{
            if(row-i==col-q[i]||row-i==q[i]-col||c[i]==col||q[i]==col) return 0;
        }
    }
    return 1;
}
void place_c(int row,int cnt_c,int cnt_q){
    for(int i=0;i<M+N;i++){
        if(valid(row,i,0)){
            c[row]=i;
            if(row==M+N){
                count++;
            }
            else{
                if(cnt_q>0)place_q(row+1,cnt_c,cnt_q-1);
                if(cnt_c>0)place_c(row+1,cnt_c-1,cnt_q);
            }
            
        }
    }
    
}

void place_q(int row,int cnt_c,int cnt_q){
    for(int i=0;i<M+N;i++){
        if(valid(row,i,1)){
            q[row]=i;
            if(row==M+N){
                count++;
            }
            else{
                if(cnt_q>0)place_q(row+1,cnt_c,cnt_q-1);
                if(cnt_c>0)place_c(row+1,cnt_c-1,cnt_q);
            }
            
        }
    }
    
}

int main(){
    for(int i=0; i<11; i++){
        q[i]=20;
        c[i]=20;
    }
    cin>>M>>N;
    
    if(M>0)place_q(1,N,M-1);
    if(N>0)place_c(1,N-1,M);
    cout<<count<<'\n';
}