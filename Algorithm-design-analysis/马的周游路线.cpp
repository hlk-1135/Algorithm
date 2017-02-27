#include<stdio.h>  
#include<stdlib.h>  
#define max 101   
  
int m,n;//棋盘大小  
int start_x,start_y;//起点位置  
int dx[8]={-2,-1,1,2,-2,-1,2,1};  
int dy[8]={-1,-2,-2,-1,1,2,1,2};  
int board[max][max]={0};  
  
int finish(int x,int y)  
{//判断是否是死路   
    if(x<1 || y<1 || x>m || y>n || board[x][y]!=0)  
        return 0;  
    else  
        return 1;  
}  
int next_move(int x,int y)  
{//判断下一步能否回到起点   
    for(int i=0;i<8;i++)  
        if(x+dx[i]==start_x && y+dy[i]==start_y)   
            return 1;  
    return 0;  
}  
void show(int n,int m)  
{//输出路线   
    for(int i=1;i<=m;i++) {  
        for(int j=1;j<=n;j++)  
            printf("%3d",board[i][j]);  
        printf("\n");  
    }         
}  
void move(int x,int y,int num)  
{  
    if(num==n*m && next_move(x,y)) {  
        show(n,m);  
        exit(1);  
    }  
    for(int i=0;i<8;i++) {  
        int next_x=x+dx[i];  
        int next_y=y+dy[i];  
        if(finish(next_x,next_y)) {  
            board[next_x][next_y]=num+1;  
            move(next_x,next_y,num+1);  
            board[next_x][next_y]=0;  
        }  
    }  
}  
int main()  
{  
    printf("请输入棋盘的行数和列数:\n");  
    scanf("%d%d",&m,&n);  
    printf("请输入起始坐标:\n");  
    scanf("%d%d",&start_x,&start_y);  
    board[start_x][start_y]=1;  
    int number=1;
    printf("马的周游路线为:\n");  
    move(start_x,start_y,number);  
    return 0;  
}
