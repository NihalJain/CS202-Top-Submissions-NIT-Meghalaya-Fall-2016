/* PROGRAM FOR IMPLEMENTING THE N-QUEENS PROBLEM
 %
 % Author: Shivam Prasad (prasadshivam2296@gmail.com)
 % Roll no.  :B15CS034
 % Date:    4th October 2016
 % Course:  Data Structures(CS202)
 % Course Instructor: Dr. Rajarshi Ray
 %
 %
 % Description: The program can 1. ASK THE USER FOR THE DIMENSTION OF THE BOARD
                                2. DISPLAY THE CHESSBOARD AFTER PLACING N-QUEENS IN IT


 */
#include<stdio.h>

int board[10][10];

/*
 * Function:  check
 * --------------------
 * Argument: The value of the row and column where we have to check.
 *
 * Functioning: Checks whether we can place a queen at the position or not.
 *
 *
 *  returns: 1 if YES, 0 if NO.
 */
int check(int row,int col,int n)
{
    int i,j;

    for(j=0; j<n; j++)
    {
        if((board[row][j]==1)&&(j!=col))
        {
            return 0;
        }
    }

    for(i=0; i<n; i++)
    {
        if((board[i][col]==1)&&(i!=row))
        {
            return 0;
        }
    }

    for(i=row,j=col; i>=0&&j>=0; i--,j--)
    {
        if(board[i][j]==1&&i!=row&&j!=col)
        {
            return 0;
        }
    }

    for(i=row,j=col; i<n&&j<n; i++,j++)
    {
        if(board[i][j]==1&&i!=row&&j!=col)
        {
            return 0;
        }
    }

    for(i=row,j=col; i>=0&&j<n; i--,j++)
    {
        if(board[i][j]==1&&i!=row&&j!=col)
        {
            return 0;
        }
    }

    for(i=row,j=col; i<n&&j>=0; i++,j--)
    {
        if(board[i][j]==1&&i!=row&&j!=col)
        {
            return 0;
        }
    }

    return 1;
}

/*
 * Function:  disp
 * --------------------
 * Argument: The dimension of the chessboard.
 *
 * Functioning: Displays the positions of the queens using a 1D array.
 *
 *
 * returns: void.
 */
void disp(int n)
{
    int i,j,B1D[10];

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(board[i][j]==1)
                printf("Q\t");
            else
                printf("-\t");
        }
        printf("\n");
    }

}

/*
 * Function:  queens
 * --------------------
 * Argument: The current row number, The dimensions of the board.
 *
 * Functioning: Places N queens in the board using backtracking and finally calls disp() to display the board.
 *
 *
 *  returns: void
 */
void queens(int row,int n)
{
    int i,j;

    if(row==n)
    {
        disp(n);
        exit(0);
    }

    for(j=0; j<n; j++)
    {
        board[row][j]=1;

        if(check(row,j,n)==1)
        {
            queens(row+1,n);
            board[row][j]=0;
            continue;
        }
        else board[row][j]=0;
    }
}

int main()
{
    int n,i,j;

    printf("Enter the dimension of the board (N):");
    scanf("%d",&n);
    queens(0,n);

    return 0;
}
