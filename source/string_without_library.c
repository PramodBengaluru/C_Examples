
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str1[50],str2[50],str3[50],flag=0,temp;
    int i=0,str1_length=0,str2_length=0,str3_length=0;
    enum op_type {STRLENGTH=1,FREQ,SORT,ANAG,REV,ENCRYPT,DEL,SUBSEQ,SWAP,CMP,CONCT,SUBSTR} op;
    
    
 printf("Enter the String operation to be performed\n");
printf("1.String length\t2.Character frequency\t3.Lexicographical sort\t4.Check if anagram\t5.Reverse\t6.Encrypt a word(Caesar)\t7.Delete a character\t8.Search subsequence\t9.Swap 2 strings\n10.Compare\t11.Concatenate\t12.Search for substring\n");
scanf("%d",(int *)&op);
printf("Enter string\n");
scanf("%s",str1);



switch(op)
{
    
/***********************************************************************************************************************************************************************/
    case STRLENGTH : for(str1_length=0;str1[str1_length]!='\0';str1_length++);//Find strlength
    printf("The length of the string is %d\n",str1_length);
        break;
/***********************************************************************************************************************************************************************/


    case FREQ:
           for(str2_length=0;str2_length<26;str2_length++)
    {
        str3[str2_length]=0;    //Initializing all array postions upto 25
    }
        for(str1_length=0;str1[str1_length]!='\0';str1_length++) //Alternative: struct having 26 chars, sequentially counting all charcters, Or using dynami mem alloc    
    {
        i=0;                                                                //Using str3 to store the acharacter counts of a to z
        if(str1[str1_length]>96) 
        {
            i=str1[str1_length]-97;                    //if small letters
        }
        else
        {
            i=str1[str1_length]-65;                                        //if capital
        }
        (str3[i])++;            
    }
    for(str2_length=0;str2_length<26;str2_length++)
    {
         if(str3[str2_length])
         {
          printf("The character %c is repeated %d times. The character frequrency is %f\n",(str2_length+65),str3[str2_length],(((float)str3[str2_length]/str1_length)*100));
         }        
    }        
        break;
        

/***********************************************************************************************************************************************************************/
#define XCH(a,b) temp=a;a=b;b=temp;
#define GETBIG(a) (a>96)?(a-0x20):a

    case SORT:  //Start from beginning of string and compare with each character and if lexicographically smaller exchange.after 1st round 1st chracter has lowest.
    for(str1_length=0;str1[str1_length]!='\0';str1_length++)
    {
     for(str2_length=str1_length;str1[str2_length]!='\0';str2_length++)
     {
        if((GETBIG(str1[str1_length]))==(GETBIG(str1[str2_length])))//if a and A or b and B
        {             
            if(str1[str1_length]<str1[str2_length])
            {                
                XCH(str1[str1_length],str1[str2_length]);   //exchange A and a
            }
        } else if((GETBIG(str1[str1_length]))>(GETBIG(str1[str2_length])))  //ignore the small big case and compare.
        {
            XCH(str1[str1_length],str1[str2_length]);  
        }
     }
    }
     printf("The sorted string is %s\n",str1);
        break;
#undef XCH      
#undef GETBIG
/***********************************************************************************************************************************************************************/

    case ANAG: flag=1;    
        printf("Enter the string to check\n");
        scanf("%s",str2);
    for(str1_length=0;str1[str1_length]!='\0';str1_length++);
    for(str2_length=0;str2[str2_length]!='\0';str2_length++);
    if(str2_length!=str1_length)
    {
        printf("Strings are not of same size\n");
        exit(-1);
    }
    //Find character frequencies of string 1 and string 2 and store it in array 3.
               for(str3_length=0;str3_length<52;str3_length++)
    {
        str3[str3_length]=0;    //Initializing all array postions upto 51
    }
    for(str1_length=0;str1[str1_length]!='\0';str1_length++) //Alternative: struct having 26 chars, sequentially counting all charcters, Or using dynami mem alloc    
    {
        /**********************1st string************/
        i=0;                                                                //Using str3 to store the acharacter counts of a to z
        if(str1[str1_length]>96) 
        {
            i=str1[str1_length]-97;                    //if small letters
        }
        else
        {
            i=str1[str1_length]-65;                                        //if capital
        }
        (str3[i])++;  
     /**********************2nd string *****************/       //Store frequency at second part of the array.
         i=26;                                                                //Using str3 to store the acharacter counts of a to z
        if(str2[str1_length]>96) 
        {
            i=str2[str1_length]-97;                    //if small letters
        }
        else
        {
            i=str2[str1_length]-65;                                        //if capital
        }
        (str3[26+i])++;                         //Second part of the array
    }
    flag=1;
    for(str3_length=0;str3_length<26;str3_length++)
    {
         if((str3[str3_length])!=(str3[str3_length+26]))
         {
          flag=0;
          break;
         }        
    }
    if(flag) printf("The 2 strings are anagram of each other\n");
    else printf("The 2 strings are not anagrams of each other\n");        
        break;
    
    
/***********************************************************************************************************************************************************************/
    case REV :for(str1_length=0;str1[str1_length]!='\0';str1_length++);
    for(i=0;i<(str1_length/2);i++)
    {
        flag=str1[i];
        str1[i]=str1[str1_length-i-1];
        str1[str1_length-i-1]=flag;
    }    
    printf("The reversed string is %s\n",str1);
        break;
/***********************************************************************************************************************************************************************/

    case ENCRYPT: 
    {
        printf("Enter the key to be used\n");
        scanf("%d",&i);  //Key
        i%=26;        
        for(str1_length=0;str1[str1_length]!='\0';str1_length++)
               {    
                   if((((str1[str1_length]+i)>90)&&((str1[str1_length])<91))||(((str1[str1_length]+i)>122)&&((str1[str1_length])<123)))
                   {                       
                       str1[str1_length]= (str1[str1_length]-26+i);
                   }
                   else str1[str1_length]=str1[str1_length]+i;
               }
               printf("The Encrypted word is %s\n",str1);
    }
        break;
/***********************************************************************************************************************************************************************/

    case DEL:
    {
        scanf("%c",&flag);  //To consume the new line character left by the last scanf statement
        printf("Enter the character to delete\n");
        scanf("%c",&flag);
        str2_length=0;
        for(str1_length=0;str1[str1_length]!='\0';str1_length++)
    {
     if(flag!=str1[str1_length])
     {
         str2[str2_length]=str1[str1_length];
         str2_length++;
    }
    }
    str2[str2_length]='\0';
    printf("The string after character deletion is %s\n",str2);   
    }
        break;
/***********************************************************************************************************************************************************************/

    case SUBSEQ:
        printf("Enter the sequence to search\n");
        scanf("%s",str2);flag=0; i=0;
        for(str1_length=0;str1[str1_length]!='\0';str1_length++);
        for(str2_length=0;str2[str2_length]!='\0';str2_length++);
        if(str2_length>str1_length) {
            printf("The sequence must be shorter than parent string\n");
            exit(-1);
        }
       
        for(str1_length=0;str1[str1_length]!='\0';str1_length++)
        {
            if(str2[i]==str1[str1_length])
            {          
                str2[i]=str1_length+1;
                i++;                    //Compare with consecutive words of parent string
                if(i==str2_length)      //If entire substring found
                {
                    break;
                }
            }
        }
        if(i==str2_length)
        {
            printf("The sequence was found at following locations of parent string\n");
            for(i=0;i<str2_length;i++)
            {
            printf("%d ",str2[i]);
            }
            printf("\n");
        }
        else printf("The sequence was not found\n");                        
        break;

/***********************************************************************************************************************************************************************/

    case SWAP:
    {               
        printf("Enter the string to Swap\n");
        scanf("%s",str2);
        
    /***************Using a temp char ************************************************************************/
   /*     for(str1_length=0;str1[str1_length]!='\0';str1_length++);   //Get 2 strings length
        for(str2_length=0;str2[str2_length]!='\0';str2_length++);   //End the last character of the 
        (str1_length>str2_length)?(str2[str1_length]='\0'):(str1[str2_length]='\0'); //Put last character as '\0'
        str1_length=(str1_length>str2_length)?str1_length:str2_length; //Get bigger of 2 lengths
        for(i=0;i<str1_length;i++)
        {
        flag=str1[i];
        str1[i]=str2[i];
        str2[i]=flag;        
        }*/
   
   /****************************************Alternative Use a third temp string************************/
   for(str1_length=0;str1[str1_length]!='\0';str1_length++)
   {
       str3[str1_length]=str1[str1_length];
   }
    str3[str1_length]='\0';
   for(str1_length=0;str2[str1_length]!='\0';str1_length++)
   {
       str1[str1_length]=str2[str1_length];
   }
    str1[str1_length]='\0';
   
   for(str1_length=0;str3[str1_length]!='\0';str1_length++)
   {
       str2[str1_length]=str3[str1_length];
   }
   str2[str1_length]='\0';
 /*****************************************************************************************************/  
        printf("The string1 after swapping is %s\n",str1);   
        printf("The string2 after swapping is %s\n",str2);   
    }
        break;
/***********************************************************************************************************************************************************************/

    case CMP:
    {
        printf("Enter the string to Compare\n");
    scanf("%s",str2);flag=1;
for(str1_length=0;(str1[str1_length]!='\0')&&(str1[str1_length]!='\0');str1_length++)
    {
if(str1[str1_length]!=str2[str1_length])
{
    flag=0;
    break;
}
    }
if((flag==1)&&(str1[str1_length]=='\0')&&(str2[str1_length]=='\0'))//Length of both strings equal
    {
    printf("The strings are same\n");
    }
    else printf("The strings are not same\n");
    }       
        break;
/***********************************************************************************************************************************************************************/

    case CONCT:
    {
        printf("Enter the string to append\n");
        scanf("%s",str2);flag=1;
        for(str1_length=0;str1[str1_length]!='\0';str1_length++);
        for(str2_length=0;str2[str2_length]!='\0';str2_length++)
        {
            str1[str1_length+str2_length]=str2[str2_length];
        }
         str1[str1_length+str2_length]='\0';
          printf("The Concatenated string is %s\n",str1);        
    }
        break;
/***********************************************************************************************************************************************************************/

    case SUBSTR:printf("Enter the string to search\n");
        scanf("%s",str2);flag=0; i=0;
        for(str1_length=0;str1[str1_length]!='\0';str1_length++);
        for(str2_length=0;str2[str2_length]!='\0';str2_length++);
        if(str2_length>str1_length) {
            printf("The substring must be shorter than parent string\n");
            exit(-1);
        }
       
        for(str1_length=0;str1[str1_length]!='\0';str1_length++)
        {
            if(str2[i]==str1[str1_length])
            {
                flag=1;                 //Match started
                i++;                    //Compare with consecutive words of parent string
                if(i==str2_length)      //If entire substring found
                {
                    i=str1_length-i+1;  //Starting location of the substring
                    break;
                }
            }
            else
            {
                flag=0;i=0;
            }
        }
        if(flag)
        {
            printf("The string was found starting at location %d of parent string\n",i);
        }
        else printf("The substring was not found\n");                        
        break;
/***********************************************************************************************************************************************************************/
    default:break;    
}
}
