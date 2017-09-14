#include "all.h"


void admin(){
     int c1;
     printf("Enter choice:\n");
     printf("1.Add a book\n");
     printf("2.Add User \n");
     printf("3.Book Log\n");
     printf("4.logout\n");
     scanf("%d",&c1);
     if(c1==1){            
          add_book();
     }
     else if(c1==2){
          add_user();
     }
     else if(c1==3){
          book_log();
     }
     else{
         main_menu();
     }

}

void user(){
     int c2;	
     printf("Enter choice:\n");
     printf("1.lend a book\n");
     printf("2.return book \n");
     //printf("3.search \n");
     printf("4.logout\n");
     scanf("%d",&c2);
     if(c2==1){            
        lend_book();
     }
     else if(c2==2){
        return_book();
     }
     else if(c2==3){
        search();
     }
     else{
        main_menu();
     }

}


