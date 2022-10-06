#include <bits/stdc++.h>

using namespace std;


int box[9][9];


void print()
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            printf("%d",box[row][col]);
        }
        printf("\n");
    }
}

bool isSafe(int row,int col, int num)
{
    if(box[row][col]!=0)
        return false;
    for (int i = 0; i < 9; i++)
    {
        if (box[row][i] == num || box[i][col] == num)
        {
            return false;
        }
    }
    int start_row=(row/3)*3,start_col=(col/3)*3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (box[start_row + i][start_col + j] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool FindPos(int &row, int &col)
{
    int mn=100000,cnt=0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if(box[i][j]!=0)
                continue;
            cnt=0;
            for(int k=1;k<=9;k++)
            {
                if (isSafe(i,j,k))
                    cnt++;
            }
            if(cnt<mn)
            {
                mn=cnt;
                row=i;
                col=j;
            }
        }
    }
    if(mn<10)
        return true;
    return false;
}

bool call()
{
    int row, col,mx=100,cnt=0;

    if (!FindPos(row, col))
        return true;

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(row, col, num))
        {
            box[row][col] = num;

            if (call())
                return true;

            box[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    int t,id=1,i,n,m,j;
    scanf("%d",&t);
    char ch;
    while(id<=t)
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                cin >> ch;
                if (ch == '.')
                  box[i][j] = 0;
                else {
                  box[i][j] = ch -48;
                }
            }
        }

        call();
        printf("Case %d:\n",id++);
        print();
    }
    return 0;
}