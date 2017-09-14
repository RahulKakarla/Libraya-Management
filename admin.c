#include "all.h"

void add_user(){
   char user_name[25];
   char u_name[25],pas[25];
   int log,i,j;
   int check;
   FILE *fp;
   FILE *fd;
 
   printf("Please enter the user name:");
   scanf("%s",user_name);
   check=2;
   do{
      if(check==1){
        printf("User exists!!\nPlease re-enter the user name:");
        scanf("%s",user_name);
        }
        fd=fopen("user.txt","r");
      while( fscanf(fd,"%s %s %d",u_name,pas,&log)!= EOF){
      i=strcmp(user_name,u_name);
      if(i==0){
        check=1;
        break;
       }
      else{
        check=0;

       }
      }
      fclose(fd);
    }while(check==1);
    if(check==0){
      fp=fopen("user.txt","a");
      fprintf(fp,"%s password 2\n",user_name);
      fclose(fp);
      printf("\nUser successfully inserted!!");
    }
     admin();
//gcc min.c admin.c login.c user.c -o mk
}


void add_book(){
   FILE *fp;
   FILE *fd;
   int i=0,j=0;
   int id1;
   char book_name1[25];
   char book_id1[10];
   int count1;
   int id[max_book];
   char book_name[max_book][25];
   char book_id[max_book][10];
   int count[max_book];
   int cnt,n_cnt,inc;
   char b_name[25];
   int cmp=1,ch1=0,ch2=0;
   int lmt,us1=0;

   fp=fopen("book.txt","r");

   i=0;
   while(fscanf(fp,"%d %s %s %d\n",&id[i],book_name[i],book_id[i],&count[i]) != EOF){
      i++;         
   }
   
   fclose(fp);
   printf("Enter book name:");
   scanf("%s",b_name);
 
   j=0;
   for(j=0;j<i;j++){
     cmp=strcmp(b_name,book_name[j]);
     if(cmp==0){
      ch1=1; 
      us1=j;
     }
   } 
     
   if(ch1==1){
    printf("book already exists with book id: %s and %d available !!\n",book_id[us1],count[us1]) ;
    printf("Enter choice:\n");
    printf("1.Increase available books\n");
    printf("2.Go to main menu\n"); 
    scanf("%d",&ch2);
    if(ch2==1){
     printf("How many more you want to add:\n");
     scanf("%d",&inc);
      n_cnt=count[us1]+inc;
      count[us1]=n_cnt;
      j=0;
       fd=fopen("book.txt","w");
      for(j=0;j<i;j++){
       fprintf(fd,"%d %s %s %d\n",id[j],book_name[j],book_id[j],count[j]);
     }fclose(fd);
      printf("books successfully incremented!!\n");
    }
    else{
     admin();
    }
    
   }
   else if(ch1==0){
    fd=fopen("book.txt","a");
    printf("Please enter the number of book:\n");
    scanf("%d",&cnt);
    id1=id[i-1]+1;//b_name
    fprintf(fd,"%d %s bk_%d %d\n",id1,b_name,id1,cnt);
    fclose(fd);
    printf("Book added Successfully!!\n");
   }
    admin();
}

void book_log(){

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

int file_line(char f_name[20]){
  FILE *fd;
  char c; 
  fd=fopen(f_name,"r");
  int line_num=0;
  while ((c =fgetc(fd))!=EOF){  
  
    if(c=='\n'){    
      line_num++;
      }
    }
    fclose(fd); 
   return line_num;
}




