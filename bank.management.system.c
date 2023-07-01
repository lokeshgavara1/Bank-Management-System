
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct acct{
	int acct_no,pwds;
	char name[100];
	float balance;
} account;

account ac[100];
int accCount = 0;
FILE *fp;

//FUNCTION DECLARATION
void acc();	//CREATE ACCOUNT
void dp();	//DEPOSIT MONEY
void wd();	//WITHDRAW MONEY
void ad();	//ACCOUNT DETAILS
void cd();	//CHANGE DETAILS
int searchForAccount(int acNo); //FOR SEARCH ACCOUNT 

//MAIN FUNCTION
void main(){
	int opt;
	while(1){
		printf("Menu\n");
		printf("1. Create account\n");
		printf("2. Deposite\n");
		printf("3. Withdraw\n");
		printf("4. Account details\n");
		printf("5. Change details\n");
	    printf("6. Exit\n");
		printf("Enter your option :");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				acc();
				break;
			case 2:
				dp();
				break;
			case 3:
				wd();
				break;
			case 4:
				ad();
				break;
			case 5:
				cd();
				break;
			case 6:
				exit(0);
				fclose(fp);
			default:
				printf("Enter a valid option ");
		}
	}
}

//FUNCTION DEFINITIONS
//CREATING ACCOUNT
void acc(){
	fp=fopen("bank.c","w");
	if(accCount < 100){
		printf("Enter your name :");
		scanf("%s",&ac[accCount].name);
		printf("Enter your account number :");
		scanf("%d",&ac[accCount].acct_no);
		printf("Enter four digit password :");
		scanf("%d",&ac[accCount].pwds);
		printf("Enter amount :");
		scanf("%f",&ac[accCount].balance);
		printf("YOUR ACCOUNT CREATED SUCCESSFULLY\n");
		accCount++;
		fprintf(fp,"%d",ac[accCount].acct_no);
		fprintf(fp,"%s",ac[accCount].name);
		fprintf(fp,"%d",ac[accCount].pwds);
		fprintf(fp,"%f",ac[accCount].balance);
	}else
		printf("Max account count reached. \nYou cannot open new accounts.\n");
}

//DEPOSIT ACCOUNT
void dp(){
	float amt;
	int acNo, acPwd, loc;
	account dpAc;
	printf("\n===STARTING DEPOSIT TRASACTION===\nEnter your account number");
	scanf("%d",&acNo);
	printf("Enter your password");
	scanf("%d",&acPwd);
	loc = searchForAccount(acNo);
	if(loc > -1)
		dpAc = ac[loc];
	else{
		printf("***Account not found.\nRecheck the a/c number.\n");
		return;
	}

	if(dpAc.pwds == acPwd){
		printf("Enter amount to deposit:");
		scanf("%f",&amt);
		dpAc.balance += amt;
		printf("===YOUR TRANSACTION SUCCESSFULLY COMPLETED===\n");
		printf("your balance = %f",dpAc.balance);
	}else
		printf("\n***Passwords do not Match.\n");

}

//ACCOUNT SEARCHING FUNCTION
int searchForAccount(int acno){
	int i = 0;
	account retAct;
	if(accCount != 0)
		for(i = 0; i < accCount; i++)
			if(ac[i].acct_no == acno){
				retAct = ac[i];
				break;
			}
	if (i < accCount )
		return i;
	else
		return -1;
}

//WITHDRAWAL FUNCTION
void wd(){
	float amt;
	int acNo, acPwd, loc;
	account dpAc;
	printf("\n===STARTING WITHDRAWAL TRASACTION===\nEnter your account number");
	scanf("%d",&acNo);
	printf("Enter your password");
	scanf("%d",&acPwd);
	loc = searchForAccount(acNo);
	if(loc > -1)
		dpAc = ac[loc];
	else{
		printf("***Account not found.\nRecheck the a/c number.\n");
		return;
	}	
	if(dpAc.pwds == acPwd){
		printf("Enter amount to withdraw:");
		scanf("%f",&amt);
		dpAc.balance -= amt;
		printf("===YOUR TRANSACTION SUCCESSFULLY COMPLETED===\n");
		printf("your balance = %f",dpAc.balance);
	}else
		printf("\n***Passwords do not Match.\n");
}

//DISPLAY ACCOUNT DETAILS
void ad(){
	int accNo, loc;
	fp=fopen("bank.c","r");
	account dpAc;
	printf("\n===STARTING ACCOUNT DETAIL DISPLAY TRASACTION===\nEnter your account number :");
	scanf("%d",&accNo);
	loc = searchForAccount(accNo);
	if(loc > -1)
		dpAc = ac[loc];
	else{
		printf("***Account not found.\nRecheck the a/c number.\n");
		return;
	}

	printf("NAME          :%s\n",dpAc.name);
	printf("ACCOUNT NUMBER:%d\n",dpAc.acct_no);
	printf("BALANCE       :%f\n",dpAc.balance);
	printf("===YOUR TRANSACTION SUCCESSFULLY COMPLETED===\n");

}

void cd(){
	int opt2,accNo, loc;
	int pwd;
	account dpAc;
	printf("MENU\n");
	printf("1.To change name\n");
	printf("2.To change password\n");
	printf("Enter your option :");
	scanf("%d",&opt2);
	switch(opt2){
		case 1:  
			    printf("Enter your account number :");
				scanf("%d",&accNo);
				loc = searchForAccount(accNo);
				if(loc > -1)
					dpAc = ac[loc];
				else{
					printf("***Account not found.\nRecheck the a/c number.\n");
					return;
				}

				printf("Enter your password :");
				scanf("%d",&pwd);
				if(dpAc.pwds == pwd){
			    	printf("Enter new name :");
					scanf("%s",&dpAc.name);
					printf("YOUR NAME IS SUCCESSFULLY UPDATED");
				}
				else
				   printf("Password Do not Match.\n");
			 	break;
		case 2:
		   		printf("Enter your account number :");
				scanf("%d",&accNo);
				loc = searchForAccount(accNo);
				if(loc > -1)
					dpAc = ac[loc];
				else{
					printf("***Account not found.\nRecheck the a/c number.\n");
					return;
				}

				printf("Enter your old password :");
				scanf("%d",&pwd);
				if(dpAc.pwds == pwd){
			     	printf("Enter new password:");
					scanf("%d",&dpAc.pwds);
					printf("YOUR PASSWORD IS SUCCESSFULLY UPDATED");
				}
				else
				   printf("Password Do not Match.\n");
			    
                break;
		   
		default:
	    	printf("Enter a valid option ");
           
	}   
}