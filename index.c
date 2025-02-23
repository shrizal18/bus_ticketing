#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

int admin();
int client();
int add_bus();
int remove_bus();
int passeneger();


int main (){
    char user[10], pass[10];
    printf("Enter username : ");
    scanf("%s",user);
    printf("Enter password : ");
    scanf("%s",pass);
    if(strcmp(user,"admin")==0 && strcmp(pass,"admin")==0)
        admin();
    else
        client();

}

int admin(){
    char choice;
    FILE* fp;
    char num[10],pick[10],drop[10];
    int seat,time1;
    
    do{
        system("cls");
        fp=fopen("bus.txt","r");
        if((fscanf(fp,"%s%s%s%d%d",&num,&pick,&drop,&seat,&time1))==EOF){
		    printf("  ---NO BUS Available--- ");
            printf("\n To add buses press 'a' :  ");
            choice = getche();
	    }
        else{
            rewind(fp);
            printf("  \t\t\t---Available BUS--- \n\n");
	        printf(" BUS number\tPickup\t\tDrop\t  Available Seats\t Deaprture time");
	        printf("\n_____________________________________________________________________________\n");
	        while((fscanf(fp,"%s\t%s\t%s\t%d\t%d",&num,&pick,&drop,&seat,&time1))!=EOF){
		        printf("   %s  \t%s      %s       %d   \t   \t     %d\n" , num,pick, drop,seat,time1);
                
	        } 
            printf("\n Press 'a' to add , 'r' to remove bus and 'p' to view passenger's details : ");
            choice=getche();
            fclose(fp);
        }
        
}
    while(choice!='a' && choice!='r' && choice!='p' );
    
    if (choice=='a'){
        add_bus();
    }
    else if(choice=='r'){
        remove_bus();
    }
    else{
        passeneger();
    }
}

int add_bus(){

    char num[10],pick[10],drop[10];
    int seat,time1;
    FILE *fp;
    char choice, con, con1;
    char red;
    do{
        system("cls");
        fp=fopen("bus.txt","a");
        printf("Enter bus number : ");
        scanf("%s",num);
        printf("Enter pickup location : ");
        scanf("%s",pick);
        printf("Enter drop location : ");
        scanf("%s",drop);
        printf("Enter no of seats : ");
        scanf("%d",&seat);
        printf("Enter bus depature timing : ");
        scanf("%d",&time1);
        system("cls");
        printf("Bus Number : %s \n PickUp/Drop : %s/%s \n No of seats : %d\n Deaprture time : %d", num,pick,drop,seat,time1);
        printf("\n\nConfirm to add bus of following details :(y for yes n for no ) : ");
        con=getche();
        if (con =='y'){
            fprintf(fp,"\n%s\t%s\t%s\t%d\t%d\n",num,pick,drop,seat,time1);
            printf("\nBus added successfully ");
            fclose(fp);
        }
        else{
            system("cls");
            printf("\nIf you want to edit details press y if not press any keys to rediret to dashboard : ");
            con1=getche();
            if(con1 =='y'){
                    add_bus();
            }
            else{
                admin();
            }
        }
        printf("\nPress 'y' to add more bus : ");
        choice= getche();
    }
    while(choice=='y');
    printf("\nEnter any keys to go to the dashboard  ") ; 
    getch();
    admin();
}




int remove_bus(){
    system("cls");
    char bus_num[10];
    char num[10],pick[10],drop[10];
    int seat,time1;
    FILE *fp;
    FILE *fp1;
    int count=0;
    printf("Enter the Bus no to remove : ");
    scanf("%s",bus_num);
    fp=fopen("bus.txt","r");
     while((fscanf(fp,"%s\n",&num))!=EOF){
        if(strcmp(bus_num,num)==0){
            count++;
        }       
	}
    fclose(fp);
    fp=fopen("bus.txt","r");
    if(count==1){
        fp1=fopen("buscha.txt","w");
        while((fscanf(fp,"%s\t%s\t%s\t%d\t%d\n",&num,&pick,&drop,&seat,&time1))!=EOF){
            if(strcmp(bus_num,num)!=0){
                fprintf(fp1,"%s\t%s\t%s\t%d\t%d\n",num,pick,drop,seat,time1);
            }       
	    }
        fclose(fp);
        fclose(fp1);
        remove("bus.txt");
        rename("buscha.txt","bus.txt"); 
        printf("\nBus removed Successsfully ");
        printf("\nEnter any key to redirect to dashboard ");
        getch();
        admin();
    }
    else{
        system("cls");
        printf(" Bus not found  ");
        printf("\n Press any key to see dashboard ");
        getch();
        admin();
    }
}

int passeneger(){

    char choice[10];
    FILE* fp;
    FILE *fp1;
    char num[10],pick[10],drop[10];
    char name[10];
    int seat,time1;
        system("cls");
        fp=fopen("bus.txt","r");
            rewind(fp);
            printf("  \t\t\t---Available BUS--- \n\n");
	        printf(" BUS number\tPickup\t\tDrop\t  Available Seats\t Deaprture time");
	        printf("\n_____________________________________________________________________________\n");
	        while((fscanf(fp,"%s\t%s\t%s\t%d\t%d",&num,&pick,&drop,&seat,&time1))!=EOF){
		        printf("   %s  \t%s      %s       %d   \t   \t     %d\n" , num,pick, drop,seat,time1);
                
	        } 
            fclose(fp);
            printf("\n Press bus number to see passenger details : ");
            scanf("%s",choice);
            fp=fopen("bus.txt","r");
            while((fscanf(fp,"%s\t%s\t%s\t%d\t%d",&num,&pick,&drop,&seat,&time1))!=EOF){ 
            if(strcmp(choice, num) == 0){
                fp1=fopen(choice, "r");
                if(fp1 == NULL){
                    system("cls");
                printf("\n\n\n");
                printf("  \t\t\t---NO PASSENGERs IN THE BUS--- \n\n");
                getch();
                }
                else{
                    rewind(fp1);
                    system("cls");
                    printf("  \t\t\t---PASSENGERS--- \n\n");
	                printf(" Name\tPickup\t\tDrop\t  Seat Numebr");
	                printf("\n_____________________________________________________________________________\n");
	                while((fscanf(fp1,"%s\t%s\t%s\t%d",&name,&pick,&drop,&seat))!=EOF){
		                printf("   %s  \t%s      %s       %d   \t   \t     \n" , name,pick, drop,seat);
                    }
	        } 
            fclose(fp1);
            }
            else{
                printf("Bus not found");
                }
            }
            
            
        
    
}

int client(){

    printf("CLINET HERE");
}
