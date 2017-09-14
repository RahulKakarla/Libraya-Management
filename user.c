/*
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
*/
#include "all.h"

int check_count(char b_name[25]);
void book_search();

char time_lend[15];
char time_return[15];
char bookid[10];
int cnt,cmpl;


void time_find(){
   struct tm date = {0} ;
   time_t timer;
   char d[2],m[2],y[4];
   char d1[2],m1[2],y1[4];
   char tim[10]="\0";
   char tim1[10]="\0";
   timer=time(NULL);
   date = *gmtime( &timer ) ;
   //printf("%s",asctime(localtime(&timer)));
   sprintf(d,"%d",date.tm_mday);
   sprintf(m,"%d",date.tm_mon+1);
   sprintf(y,"%d",date.tm_year+1900);
   strcat(tim,m);
   strcat(tim,"/");
   strcat(tim,d);
   strcat(tim,"/");
   strcat(tim,y);
   //printf("%s\n",tim);

   date.tm_year = date.tm_year;
   date.tm_mon = date.tm_mon;
   date.tm_mday = date.tm_mday + 30;
   timer = mktime( &date ) ;
   date = *gmtime( &timer ) ;
   sprintf(d1,"%d",date.tm_mday-1);
   sprintf(m1,"%d",date.tm_mon+1);
   sprintf(y1,"%d",date.tm_year+1900);
   strcat(tim1,m1);
   strcat(tim1,"/");
   strcat(tim1,d1);
   strcat(tim1,"/");
   strcat(tim1,y1);
   //printf("%s\n",tim1);
   strcpy(time_lend,tim);
   strcpy(time_return,tim1);   
   
}

void lend_book(){
  
  FILE *fp;
  char book_nam[25];
  char book_id[10];
  char dat[10];
  char uid[10];
  char f_nam[25];
  char l_nam[25];
  char lend_time[10];
  char return_time[10];
  printf("Lend a book");
  printf("\nEnter the name of book:");
  scanf("%s",book_nam);
  book_search(book_nam);
  if(cmpl==1 && cnt > 0){
   printf("\nBook ID is:%s\n",bookid);
   strcpy(book_id,bookid);
   printf("No of books available:%d",cnt);
   
   printf("\nEnter 991:");
   scanf("%s",uid);
   printf("\nEnter the first name:");
   scanf("%s",f_nam);
   printf("\nEnter the last name:");
   scanf("%s",l_nam);
   time_find();
   strcpy(lend_time,time_lend);
   strcpy(return_time,time_return);
   printf("\nlend date:%s\n",lend_time);
   printf("return date:%s\n",return_time);
   fp=fopen("library.txt","a");
   fprintf(fp,"%s %s %s %s %s %s %s a\n",book_nam,book_id,uid,f_nam,l_nam,lend_time,return_time);
   fclose(fp);
   printf("Record successfully inserted!!\n");
  }
  
  else if(cmpl==1 && cnt > 0){
   printf("No stock left!!");
  }
  else{
   printf("book does not exists");
  }
  
  user();
}

void return_book(){
  FILE *fp;
  FILE *fd;
  typedef struct node{
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
  }NODE;
   char book_name[25];
   int i=0,j=0,k=0,chk,chk1,chk2;

  NODE ret[25];
  NODE ret1[25];
  fd=fopen("library.txt","r");
    
  printf("Enter the book name:\n");
  scanf("%s",book_name);

  while(fscanf(fd," %s %s %s %s %s %s %s %c",ret[i].book_nam,ret[i].book_id,ret[i].uid,ret[i].f_nam,ret[i].l_nam,ret[i].lend_time,ret[i].return_time,&ret[i].status)!=EOF){
    ret[i].id=i;
    chk=strcmp(ret[i].book_nam,book_name);
       
    if(chk==0 && ret[i].status=='a'){
       strcpy(ret1[j].book_nam,ret[i].book_nam);
       strcpy(ret1[j].book_id,ret[i].book_id);
       strcpy(ret1[j].uid,ret[i].uid);
       strcpy(ret1[j].f_nam,ret[i].f_nam);
       strcpy(ret1[j].l_nam,ret[i].l_nam);
       strcpy(ret1[j].lend_time,ret[i].lend_time);
       strcpy(ret1[j].return_time,ret[i].return_time);
       ret1[j].status=ret1[j].status;
       ret1[j].id=ret[i].id;
       j++;
    }
    i++;
  }
  fclose(fd);
  if(j==0){
   printf("Book was not in records!!\n");
   user();
  }
 
  for (k=0;k<j;k++){
   printf("%d %s %s %s %s %s %s %s %c\n",k+1,ret1[k].book_nam,ret1[k].book_id,ret1[k].uid,ret1[k].f_nam,ret1[k].l_nam,ret1[k].lend_time,ret1[k].return_time,ret1[k].status);
  }

  printf("Enter the choice of book you are taking back:");
  scanf("%d",&chk1);
   chk2=ret1[chk1-1].id;
   ret[chk2].status='r';

  k=0;
  fp=fopen("library.txt","w");
  for(k=0;k<i;k++){
    fprintf(fp,"%s %s %s %s %s %s %s %c\n",ret[k].book_nam,ret[k].book_id,ret[k].uid,ret[k].f_nam,ret[k].l_nam,ret[k].lend_time,ret[k].return_time,ret[k].status);
  }
  fclose(fp);
  user();
}


void search(){
  int ch;
  printf("What you want to search?");
  printf("1.the books to be returned today");
  printf("2.search by 991");
  printf("3.Search by first name");
  printf("4.Search by lend date");
  printf("5.Search by return date");
  scanf("%d",&ch);

  if(ch == 1){
    today_search();
  }
  else if(ch == 2){
    id_search();
  }
  else if(ch == 3){
    fname_search();
  }  
  else if(ch == 4){
    ldate_search(); 
  }
  else{
    rdate_search();
  }

  
}

void today_search(){

}


void id_search(){
}
void fname_search(){
}
void ldate_search(){
}
void rdate_search(){
}
void book_search(char b_name[25]){
   FILE *fp;
   int i=0;
   int id;
   char book_name[25];
   char book_id[10];
   int count=0,cnt1=0,cnt2=0;
   int cmp=1,ch1=0;
   cmpl=0,cnt=0;
   fp=fopen("book.txt","r");
   while(fscanf(fp,"%d %s %s %d\n",&id,book_name,book_id,&count) != EOF){

      cmp=strcmp(b_name,book_name);
     if(cmp==0){
       cmpl=1;
       strcpy(bookid,book_id);
       cnt1=check_count(b_name);
       cnt=count-cnt1;
       
     }          
   }
   fclose(fp);
}

int check_count(char b_name[25]){
   FILE *fp;
   int i=0;
   int id;
   char book_name[25];
   char book_id[10];
   char uid[10];
   char fname[25]; 
   char lname[25];
   char ldate[12];
   char rdate[12];
   char status;
   int count=0;
   
   int cmp=1,ch1=0;
   
   fp=fopen("library.txt","r");
   while(fscanf(fp,"%s %s %s %s %s %s %s %c\n",book_name,book_id,uid,fname,lname,ldate,rdate,&status) != EOF){
     cmp=strcmp(b_name,book_name);
   
     if(cmp==0 && status=='a'){
      
       count++;
     }        
     
   }
   fclose(fp);

   
  return count;

}




