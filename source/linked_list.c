
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>
#include <stdlib.h>
#define XCH(a,b) temp_val=a;a=b;b=temp_val;
void display_list(void);
void sort();
void destroy();
void search();
void delete();
void add();

typedef struct node_struct{
 int val;
 struct node_struct *Next;    
} Node;
int i=0;
int pos=0,temp_val=0;
Node *root=NULL;
Node *temp,*temp1,*temp2;

int main()
{        
    enum op_type {CREAT=1,ADD,ADDTOSTART,ADDTOEND,DEL,SEARCH,DISP,SORT,DESTROY,EXIT} op;

    printf("1.Create list\t2.Add an element at a position\n3.Add to start\t4.Add to End\n5.Delete an element\t6.Search for an element\n7.Display list\t8.Sort the list\n9.Delete the entire list\t10.Exit\n");
    while(1)
    {
    printf("Enter the operation to perform\n");
    scanf("%d",(int *)&op);


switch(op)
{
/****************************************************************************************************************************************************************************/    
    case CREAT:
        printf("Enter the element to be placed at root\n");
        scanf("%d",&temp_val);
        root=(Node *)malloc(sizeof(Node));
        root->Next=NULL;
        root->val=temp_val;
        break;        
        
/****************************************************************************************************************************************************************************/        
    case ADDTOSTART :if(root!=NULL)
    {        
        printf("Enter the element to add\n");
        scanf("%d",&temp_val);
        temp1=(Node *)malloc(sizeof(Node)); 
        temp1->val=root->val;
        temp1->Next=root->Next;        
        root->val=temp_val;
        root->Next=temp1;
    }
    else printf("List does not exist. Create a list first\n");
                break;
    
/****************************************************************************************************************************************************************************/            
    
    case ADDTOEND :
        
        if(root!=NULL)
    {        
        temp=root;
        printf("Enter the element to add\n");
        scanf("%d",&temp_val);
        while(temp->Next!=NULL) temp=temp->Next;
        temp1=(Node *)malloc(sizeof(Node)); 
        temp1->val=temp_val;
        temp1->Next=NULL;//Terminate the list
        temp->Next=temp1;
        
    }
    else printf("List does not exist. Create a list first\n");
        break;
/****************************************************************************************************************************************************************************/                
    case ADD:   add();                
                break;
/****************************************************************************************************************************************************************************/    
    case DEL :  delete();
                break;
/****************************************************************************************************************************************************************************/                    
                
    case SEARCH :search();
                break;
/****************************************************************************************************************************************************************************/        
    case DISP  : display_list();                
                break;
/****************************************************************************************************************************************************************************/         
    case SORT :sort();
                break;
/****************************************************************************************************************************************************************************/    
    case DESTROY:destroy();        
                break;
/****************************************************************************************************************************************************************************/        
    case EXIT:exit(0);    
/****************************************************************************************************************************************************************************/            
    default  :  exit(-1);
}
}
}

void display_list()
{
    if(root!=NULL)
    {        temp=root;
    printf("The list contains following elements\n");
        while(temp)
        {
            printf("%d ",temp->val);
            temp=temp->Next;
        }
        printf("\n");        
    }
     else printf("List does not exist. Create a list first\n");
}

void sort()
{
     if(root!=NULL)          //Using Selection Sort
    {
        for(temp=root;(temp->Next)!=NULL;temp=temp->Next) //-1 because largest element will already be at end of list after n-1 iteration
    {
        temp1=temp;    //Start from first position
     for(temp2=temp->Next;(temp2)!=NULL;temp2=temp2->Next)   //i+1 because temp1 initialized to i. Skip comparing with self
     {
    if((temp1->val)>(temp2->val)) 
        {
            temp1=temp2;            //Get the smallest element in array.   
        }
     }
     XCH(temp1->val,temp->val);    //Place it into the end of sorted part.
    }
        }
     else printf("List does not exist. Create a list first\n");
}


void destroy()
{
if(root!=NULL)
    {        
        temp=root;
while(temp->Next!=NULL)
{
 temp1=temp;
 temp=temp->Next;   
 free(temp1);
}
free(temp);//Last element after loop.
root=NULL;
printf("List destroyed\n");
}
    else printf("List does not exist. Create a list first\n");
}    

void search()
{
 if(root!=NULL)
    {        temp=root;i=0;
    printf("Enter the element to search\n");
    scanf("%d",&temp_val);
        while(temp)
        {            
            if(temp->val==temp_val)
            {
             printf("Element %d found at position %d\n",temp_val,i);
             break;
            }
            temp=temp->Next;
            i++;
        }
        if(!temp)
        {
             printf("Element %d was not found\n",temp_val);
        }
    }
     else printf("List does not exist. Create a list first\n");
    
}

void delete()
{
        if(root!=NULL)
    {       
        temp=root;
        printf("Enter the position of the element to delete\n");
        scanf("%d",&pos);
        i=0;
        
        while((temp)&&(i<pos-1))
        {
            temp=temp->Next;    //Sets the temp to position-1 after this loop.
            i++;
        }        
        if((temp)&&(temp->Next))
        {
            if(pos==0){         //If first element.
                root=root->Next;
                free(temp);
            }
            else if(pos>=1)
            {
            temp1=temp->Next;
            temp->Next=(temp->Next)->Next;
            free(temp1);
            }
        }
        else printf("Postion exceeds list length\n");
        printf("\n");        
    }
     else printf("List does not exist. Create a list first\n");
    
}
    
void add()
{
     if(root!=NULL)
    {       
        temp=root;
        printf("Enter the position of the element to add\n");
        scanf("%d",&pos);
        printf("Enter the element to add\n");
        scanf("%d",&temp_val);
        i=0;        
        while((temp)&&(i<pos-1))
        {
            temp=temp->Next;    //Sets the temp to position-1 after this loop.
            i++;
        }        
        if((temp))
        {
            if(pos==0){         //If first element.
                temp1=(Node *)malloc(sizeof(Node)); 
                temp1->Next=root;
                temp1->val=temp_val;
                root=temp1;
            }
            else if(pos>=1)
            {
            temp1=(Node *)malloc(sizeof(Node)); 
            temp1->val=temp_val;
            temp1->Next=temp->Next;//Terminate the list
            temp->Next=temp1;   
            }
        }
        else printf("Postion exceeds list length\n");
        printf("\n");        
    }
     else printf("List does not exist. Create a list first\n");   
    
    
}