
#include "all.h"
#define max_num 25



int main()
{
main_menu();

    return 0;
}

void main_menu(){
FILE *fp;
    int c1,c2;
    int i=0,login=0,k=0;
    char u_name[25];
    char password[50];
    char us_name[max_num][max_num],pas[max_num][max_num];
    int log[max_num];



    printf("Enter choice:\n");
    printf("1.library operation\n");
    printf("2.games\n");
    printf("3.exit\n");
    scanf("%d",&c1);
    if(c1==1){ 
            do{
	    printf("Welcome to library!!\n");
		printf("Please login!!\n");
		printf("Enter User Name:");
		scanf("%s",u_name);
		printf("Enter Password:");
                 
		scanf("%s",&password);
                fp=fopen("user.txt","r");
             i=0;
	    while(fscanf(fp,"%s %s %d\n",us_name[i],pas[i],&log[i]) != EOF){
			if((strcmp(u_name,us_name[i])==0)){
			  if((strcmp(password,pas[i])==0)){
			    printf("Logged in as %s\n",u_name);
				login=log[i];
                                k=1;
			  }
			  else{
			    printf("Wrong Password!!");
			  }
			
		  }
		}fclose(fp);
              }while(k==0);
                
		if(login==1){
		  admin();
		}else if(login==2){
		  user(); 
		}
		else{
		  printf("User does not exists\n");
		}
                

        
    }
    else if(c1==2){
        printf("Welcome to gaming center!!\n");
        printf("sorry for inconvinience still under construction\n");
        
    }
    else{
        exit(0);
    }
    


}

