#include<iostream>
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define UP 4
using namespace std;

int main(){
    int M, N, pos;
    cin>>M>>N>>pos;

    int mat[M][N];
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            mat[i][j]=0;

    int dir = RIGHT;
    int r=0, c=0;
    for(int i=1; i<=M*N; i++){
        mat[r][c]=i;
        //cout<<mat[r][c]<<'\n';
        //cout<<r<<' '<<c<<'\n';
        if(i==pos)  break;
        if(i==M*N)  break;
        switch(dir){
            case UP:
                if(mat[r-1][c]>0||r<1)  dir=RIGHT;
                break;
            case RIGHT:
                if(mat[r][c+1]>0||c+1==N)   dir=DOWN;               
                break;
            case DOWN:
                if(mat[r+1][c]>0||r+1==M)   dir=LEFT;                
                break;
            case LEFT:
                if(mat[r][c-1]>0||c<1)  dir=UP;
                break;
        }
        switch(dir){
            case UP:
                r--;
                break;
            case RIGHT:
                c++;
                break;
            case DOWN:
                r++;
                break;
            case LEFT:
                c--;
                break;
        }
    }
    cout<<r+1<<' '<<c+1<<'\n';
}