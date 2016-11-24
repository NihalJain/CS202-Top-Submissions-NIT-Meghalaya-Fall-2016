  /* PROGRAM FOR IMPLEMENTING THE DEFECTIVE CHESS BOARD PROBLEM
  % 
  % Author: Shivam Prasad (prasadshivam2296@gmail.com) 
  % Roll no.  :B15CS034 
  % Date:    19th September 2016 
  % Course:  Data Structures(CS202)
  % Course Instructor: Dr. Rajarshi Ray
  % 
  % 
  % Description: The program can 1. ASK THE USER FOR THE DIMENSTION OF THE BOARD
                                 2. ASK THE USER THE POSITION OF THE DEFECT
                                 3. DISPLAY THE CHESSBOARD AFTER PLACING THE TILES
								
  */ 
#include <stdio.h>
#include<math.h>

int board[10][10],tile=1;

void puttiles(int Ox,int Oy,int dx,int dy,int size)
{
	int tile_num,n, quad;
	if (size==1)
		return;
	
	tile_num=tile++;
	n=size/2;

	/*Finding out the quadrant*/
	if(dx<Ox+n && dy<Oy+n)
	  	quad=2;
	else if (dx<Ox+n && dy>=Oy+n)
	  	quad=3;
	else if(dx>=Ox+n && dy<Oy+n)  
	  	quad=1;
	else if(dx>=Ox+n && dy>=Oy+n)
		quad=4;
	
	/* If Defect lies in second Quadrant, fill that Quadrant with tiles,recursively*/
	if (quad==2)
		puttiles(Ox,Oy,dx,dy,n);
	/* Else, make a fake defect in the second Quadrant, fill that Quadrant with tiles,recusively*/
	else{
		board[Ox+n-1][Oy+n-1]=tile_num;
		puttiles(Ox,Oy,Ox+n-1,Oy+n-1,n);
     }


    /* If Defect lies in third Quadrant, fill that Quadrant with tiles, recursively*/
	if (quad==3)
		puttiles(Ox,Oy+n,dx,dy,n);
	/* Else, make a fake defect in the third Quadrant, fill that Quadrant with tiles,recursively*/
	else{
		board[Ox+n-1][Oy+n]=tile_num;
		puttiles(Ox,Oy+n,Ox+n-1,Oy+n,n);
	 }
	
	
	/* If Defect lies in first Quadrant, fill that Quadrant with tiles,recursively*/
	if (quad==1)
		puttiles(Ox+n,Oy,dx,dy,n);
	/* Else, make a fake defect in the first Quadrant, fill that Quadrant with tiles,recursively*/
	else{	
		board[Ox+n][Oy+n-1]=tile_num;
		puttiles(Ox+n,Oy,Ox+n,Oy+n-1,n);
	 }


	/* If Defect lies in fourth Quadrant, fill that Quadrant with tiles,recursively*/
	if (quad==4)
		puttiles(Ox+n,Oy+n,dx,dy,n);
	/* Else, make a fake defect in the fourth Quadrant, fill that Quadrant with tiles,recursively*/
	else{
		board[Ox+n][Oy+n]=tile_num;
		puttiles(Ox+n,Oy+n,Ox+n,Oy+n,n);
	 }

}

main()
{
	int n ,dx,dy,i,j;
	
	printf("Enter n such that side =2^n\nn(<=3)=");
    	scanf("%d",&n);
	
	n=pow(2,n);
	
	printf("\nWhere do you want to have the defect?\n");
		scanf("%d%d",&dx,&dy);
	
	puttiles(0,0,dx,dy,n);
	
	/* Printing The board*/
		printf ("\nChess board:\n");

	for(i=0;i<n;i++)	{
		for (j=0;j<n;j++){
			printf("%d\t",board[i][j]);
		 }
		printf("\n");
	 }
	
}
