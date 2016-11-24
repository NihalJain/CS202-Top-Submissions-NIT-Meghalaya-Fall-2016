/*Tiling problem*/
/*Submitted By-
                          Chandrani Kar
                          Roll No-B15CS031
                          Assignment 4
                          Date:20/09/2016
                  */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int B[128][128], marker = 1;
/*
*Function TB which will fill the chess board using L shaped tiles except the defective cell..
*
*orr: refers to the origin row..
*
*orc: refers to the origin column..
*
*defc: refers to the defective cell column..
*
*defr: refers to the defective cell row..
*
*n: refers to the size of the chessboard..
*/

void TB(int orr, int orc, int defr, int defc, int n)
{
    /*when size becomes 1x1,cannot be further divided ,so we return*/
    if (n == 1)
        return;

    int tile_no,Size ;

    tile_no= marker++;  /*tiles will be marked by the tile number*/
    /*half the size*/
    Size= n/2;

    /* tile top-left quadrant*/
    if (defr <= orr + Size-1&& defc <= orc + Size-1)
        /*if defective cell is in this quadrant*/
        TB(orr, orc, defr, defc, Size);
    else
    {
        /*if defective cell is not in this quadrant ,then make an imaginary defective cell in bottom right corner of the chess board*/
        B[orr + Size - 1][orc + Size - 1] = tile_no;
        TB(orr, orc, orr+Size-1, orc+Size-1, Size);
    }
    /* tile top-right quadrant*/
    if (defr <= orr + Size -1&& defc >= orc + Size)
        /*if defective cell is in this quadrant*/
        TB(orr, orc+Size, defr, defc, Size);
    else
    {
        /*if defective cell is not in this quadrant ,then make an imaginary defective cell in bottom left corner of the chess board*/
        B[orr + Size - 1][orc + Size] = tile_no;
        TB(orr, orc+Size, orr+Size-1, orc+Size, Size);
    }
    /* tile bottom-left quadrant*/
    if (defr >= orr + Size && defc <= orc + Size-1)
        /*if defective cell is in this quadrant*/
        TB(orr+Size, orc, defr, defc, Size);
    else
    {
        /*if defective cell is not in this quadrant ,then make an imaginary defective cell in top right corner of the chess board*/
        B[orr + Size][orc + Size - 1] = tile_no;
        TB(orr+Size, orc, orr+Size, orc+Size-1, Size);
    }

    /*tile bottom-right quadrant*/
    if (defr >= orr + Size && defc >= orc + Size)
        /*if defective cell is in this quadrant*/
        TB(orr+Size, orc+Size, defr, defc, Size);
    else
    {
        /*if defective cell is not in this quadrant ,then make an imaginary defective cell in top left corner of the chess board*/
        B[orr + Size][orc + Size] = tile_no;
        TB(orr+Size, orc+Size, orr+Size, orc+Size, Size);
    }
}


main()
{
    int i,j,k,n, defr, defc;

    printf("Enter k where the size of the board will be n X n where n=2^k \n");
    scanf("%d",&k) ;
    n=pow(2,k);

    printf("Enter the coordinates of the defective square,i.e.,the row and column number of the defective cell in the chessboard\n");
    scanf("%d%d",&defr,&defc);

    B[--defr][--defc] = 0;  /*defective cell marked by 0*/

    TB(0, 0, defr, defc, n);
    for ( i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("  %2d", B[i][j]);   /*printing the chess board*/
        printf("\n");
    }

}
