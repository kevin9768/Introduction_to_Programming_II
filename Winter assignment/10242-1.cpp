#include<stdio.h>
#define MAX 15
int board[MAX+1][MAX+1]={0};
void place(int m, int n, int row);
int total,M,N;

int main()
{
    scanf("%d%d",&M,&N);
    total=0;
    place(0,0,0);
    printf("%d\n",total);
    return 0;
}



void place(int m, int n, int row)
{
    int col;
    if(m==M&&n==N){
        total++;
    }
    else if(row<(M+N)&&m<=M&&n<=N){
        for(col=0;col<(M+N);col++){
            int status,ok;
            for(status=1;status<=2;status++){
                if(status==1){
                    ok=1;
                    board[row][col]=1;/*攻擊範圍對角線處列-行為定值(=row-col),副對角線列+行為定值(row+col)*/
                    int i;
                    for(i=0;i<row;i++){/*檢查是否會被之前放的棋子攻擊*/
                        if(board[i][col]!=0||board[i][-row+col+i]!=0||board[i][row+col-i]!=0){
                            board[row][col]=0;
                            ok=0;
                            break;/*若會被攻擊,則取消放置*/
                            }
                    }
                    if(ok==1){
                        place(m+1,n,row+1);/*放下一顆皇后*/
                        board[row][col]=0;/*改回來*/
                    }
                }
                else{
                    ok=1;
                    board[row][col]=2;
                    int i;
                    for(i=0;i<row;i++){
                        if(board[i][col]!=0||board[i][-row+col+i]==1||board[i][row+col-i]==1){/*主副對角線處有皇后*/
                            board[row][col]=0;
                            ok=0;
                            break;
                            }
                    }
                    if(ok==1){
                        place(m,n+1,row+1);
                        board[row][col]=0;
                    }
                }

            }
        }
    }
}