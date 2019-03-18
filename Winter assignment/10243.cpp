#include<iostream>

using namespace std;

int main(){
    int size;
    cin >> size;
    int mat[size][size];
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            cin>>mat[i][j];
    
    int value[size-2][size-2];
    
    for(int i=0; i<size-2; i++)
        for(int j=0; j<size-2; j++){
            int temp=-1000000;
            for(int m=0; m<3; m++)
                for(int n=0; n<3; n++)
                    if(mat[i+m][j+n]>temp)
                        temp=mat[i+m][j+n];
            value[i][j]=temp;
        }
    
    for(int i=0; i<size-2; i++){
        cout<<value[i][0];
        for(int j=1; j<size-2; j++){
            cout<<' '<<value[i][j];
        }
        cout<<'\n';
    }
        
}