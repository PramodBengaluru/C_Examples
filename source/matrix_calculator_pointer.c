
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>
#include <stdlib.h>
void display_matrix(int* mptr,unsigned m,unsigned n);
void get_elements(int* mptr,unsigned m,unsigned n);
void add(int *amat,int *bmat,int *resmat,unsigned m,unsigned n);
int comp(int *amat,int *bmat,unsigned m,unsigned n);
void sub(int *amat,int *bmat,int *resmat,unsigned m,unsigned n);
void trans(int *amat,int *cmat,unsigned m,unsigned n);
int diagsum(int *amat,unsigned m);
int lower_sum(int *amat,unsigned m);
int upper_sum(int *amat,unsigned m);
void mul(int *amat,int *bmat,int *resmat,unsigned am,unsigned an,unsigned bn);  //bm not sent because bm=an for multiplication

unsigned row=0,column=0;
int main()
{
    int *aptr,*bptr,*cptr;
    unsigned am,an,bm,bn,cm,cn;//dimensions

    enum op_type {ADD=1,SUB,COMP,MUL,TRANS,DIAGSUM,UPPRSUM,LOWRSUM} op;
    printf("Enter the Matrix operation\n");
    printf("1.Add\n2.Subtract\n3.Equality Check\n4.Multiply\n5.Transpose\n6.Sum of Diagonal Elements\n7.Upper Traingular matrix Sum\n8.Lower Traingular matrix Sum\n");
    scanf("%d",(int *)&op);
    if((op>0)&&(op<9))
    {
    printf("Enter Matrix A dimensions,m X n\n");
    scanf("%u%u",&am,&an);
    if((op>5)&&(am!=an)){
        printf("Enter a square Matrix\n");
        exit(-1);
    }
    aptr=(int *)malloc((sizeof(int))*am*an);
    printf("Enter Elements, Row after Row\n");
    get_elements(aptr,am,an);    

    //2 Matrix operations and sanity checks
    if(op<=4)
    {
     printf("Enter Matrix B dimensions,m X n\n");
     scanf("%u%u",&bm,&bn);     
     if(op<4)
     {
        if((am!=bm)||(an!=bn)) 
        {
         printf("Matrix Dimensions not correct \n");
         exit(-1);
        }        
     }
     else if(op==4)
     {
        if(an!=bm) 
        {
         printf("No of Columns of A should be equal to no of Rows of B \n");
         exit(-1);
        }         
     }
     printf("Enter Elements, Row after Row\n");
    bptr=(int *)malloc((sizeof(int))*bm*bn);
    get_elements(bptr,bm,bn);     
    }
    }
    else
    {
     printf("Wrong opcode\n");
     exit(-1);
    }
    
switch(op)
{
    case ADD :  cptr=(int *)malloc((sizeof(int))*am*an);
                add(aptr,bptr,cptr,am,an);
                printf("A Matrix is\n");
                display_matrix(aptr,am,an);
                printf("B Matrix is\n");
                display_matrix(bptr,am,an);
                 printf("Result Matrix is\n");
                display_matrix(cptr,am,an);
                break;
    case SUB :  cptr=(int *)malloc((sizeof(int))*am*an);
                sub(aptr,bptr,cptr,am,an);
                printf("A Matrix is\n");
                display_matrix(aptr,am,an);
                printf("B Matrix is\n");
                display_matrix(bptr,am,an);
                printf("Result Matrix is\n");
                display_matrix(cptr,am,an);
                break;
    case COMP : printf("A Matrix is\n");
                display_matrix(aptr,am,an);
                printf("B Matrix is\n");
                display_matrix(bptr,am,an);
                if(comp(aptr,bptr,am,an))
                printf("The Matrices are equal\n");
                else printf("The Matrices are not equal\n");
    case MUL  : cptr=(int *)malloc((sizeof(int))*am*bn);
                mul(aptr,bptr,cptr,am,an,bn);
                printf("A Matrix is\n");
                display_matrix(aptr,am,an);
                printf("B Matrix is\n");
                display_matrix(bptr,bm,bn);
                printf("Result Matrix is\n");
                display_matrix(cptr,am,bn);
                break;
    case TRANS : cptr=(int *)malloc((sizeof(int))*an*am);
                trans(aptr,cptr,am,an);
                printf("A Matrix is\n");
                display_matrix(aptr,am,an);
                printf("Result Matrix is\n");
                display_matrix(cptr,an,am);
                break;
    case DIAGSUM:printf("A Matrix is\n");
                 display_matrix(aptr,am,an);
                printf("The Sum of diagonal elements are %d\n",diagsum(aptr,am)); 
                break;
    case UPPRSUM:printf("A Matrix is\n");
                 display_matrix(aptr,am,an);
                printf("The Sum of upper triangular elements are %d\n",upper_sum(aptr,am)); 
                break;
    case LOWRSUM:printf("A Matrix is\n");
                 display_matrix(aptr,am,an);
                printf("The Sum of lower triangular elements are %d\n",lower_sum(aptr,am)); 
                break;
    default  :  break;
}
free(aptr);
}

void get_elements(int* mptr,unsigned m,unsigned n)
{
    for(row=0;row<m;row++)
    {
        for(column=0;column<n;column++)
        {            
         scanf("%d",(mptr+(row*n)+column));
        }        
    }   
}

void display_matrix(int* mptr,unsigned m,unsigned n)
{
    for(row=0;row<m;row++)
    {
        for(column=0;column<n;column++)
        {            
         printf("%d ",*(mptr+(row*n)+column));
        } 
        printf("\n");
    }   
}

void add(int *amat,int *bmat,int *resmat,unsigned m,unsigned n)
{
       for(row=0;row<m;row++)
    {
        for(column=0;column<n;column++)
        {            
         *(resmat+(row*n)+column)=*(amat+(row*n)+column)+(*(bmat+(row*n)+column));
        }        
    }   
}

void sub(int *amat,int *bmat,int *resmat,unsigned m,unsigned n)
{
       for(row=0;row<m;row++)
    {
        for(column=0;column<n;column++)
        {            
         *(resmat+(row*n)+column)=*(amat+(row*n)+column)-(*(bmat+(row*n)+column));
        }        
    }   
}

int comp(int *amat,int *bmat,unsigned m,unsigned n)
{
    int flag=1;
    for(row=0;row<m;row++)
    {
        for(column=0;column<n;column++)
        {            
        if(*(amat+(row*n)+column)!=(*(bmat+(row*n)+column)))
        {
         flag=0; 
         break;
        }
        }
        if(flag==0) return 0;
    }
    return flag;   
}

void mul(int *amat,int *bmat,int *resmat,unsigned Am,unsigned An,unsigned Bn)
{
int term=0,elem_sum=0;
for(row=0;row<Am;row++)
{
 for(column=0;column<Bn;column++)
 {
     term=0;elem_sum=0;
     while(term<An)
     {
    elem_sum+=(*(amat+term+(row*An)))*(*(bmat+column+(term*Bn)));    //
    term++;
 }
 *(resmat+column+(Bn*row))=elem_sum;
}
}
}

void trans(int *amat,int *cmat,unsigned m,unsigned n)
{
           for(row=0;row<m;row++)
    {
        for(column=0;column<n;column++)
        {            
         *(cmat+(column*m)+row)=*(amat+(row*n)+column);
        }        
    }     
}

int diagsum(int *amat,unsigned m)
{
    int sum=0;
    for(row=0;row<m;row++)
    {
    sum+=*(amat+(row*m)+row);
    }
    return sum;
}

int upper_sum(int *amat,unsigned m)
{
       int sum=0;
       for(row=0;row<m;row++)
    {
        for(column=row;column<m;column++)
        {            
         sum+=*(amat+(row*m)+column);
        }        
    }
    return sum;
}

int lower_sum(int *amat,unsigned m)
{
       int sum=0;
       for(row=0;row<m;row++)
    {
        for(column=0;column<=row;column++)
        {            
         sum+=*(amat+(row*m)+column);
        }        
    }
    return sum;
}

