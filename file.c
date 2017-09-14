#include <stdio.h>
#include <string.h>

void main(){

  FILE *fp;
  FILE *fd;
  int i,j,k,l;
  typedef struct node{
   int id;
   char book_name[25];
   char book_id[10];
   int count;  
   int book_lent;
   int book_pending;
  }NODE;
   typedef struct lib{
   int id;
   char book_nam[25];
   char book_id[10];
   char dat[10];
   char uid[10];
   char f_nam[25];
   char l_nam[25];
   char lend_time[10];
   char return_time[10];
   char status;  
  }LIB;
  NODE bok[25];
  LIB ret[25];
  int cmp,cnt;
  fp=fopen("book.txt","r");
  i=0;
  while(fscanf(fp,"%d %s %s %d\n",&bok[i].id,bok[i].book_name,bok[i].book_id,&bok[i].count) != EOF){
    i++;
  }
  fclose(fp);
  
  fd=fopen("library.txt","r");
  
  while(fscanf(fd," %s %s %s %s %s %s %s %c",ret[k].book_nam,ret[k].book_id,ret[k].uid,ret[k].f_nam,ret[k].l_nam,ret[k].lend_time,ret[k].return_time,&ret[k].status)!=EOF){
    k++;
  }
  
  j=0;l=0;
  printf("S.NO Book_name     Book_id Book_Count Book_lend\n"); 
  for(j=0;j<i;j++){
    cnt=0;
    for(l=0;l<k;l++){ 
     cmp=strcmp(bok[j].book_name,ret[l].book_nam);
     if(cmp==0 && ret[l].status=='a'){ 
        cnt++;
     }
    }
    bok[j].book_lent=cnt;
   printf(" %d   %s  %s %d %d\n",bok[j].id,bok[j].book_name,bok[j].book_id,bok[j].count,bok[j].book_lent);   
  }  

}