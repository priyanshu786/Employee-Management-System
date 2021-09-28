#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
COORD coord = {0,0};
void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int main()
{
    int i;
    char password[40];
    char po[40];
    char j[]="priyanshu";
    char k[]="aman";
    char l[]="janmejay";
    int x,y,z;
    FILE *fp, *ft;
    char another, choice,am ;
    struct emp
    {   long id;
        char name[30],bg[5],email[35],g[7],mar[15],con[15],econ[15];
        int sell,age;
        float bs,hra,da,ta,bonus,ts;
    };
    struct emp e;
    char empname[30];
    long int recsize;
    fp = fopen("EMP.DAT","rb+");
    if(fp == NULL)
    {
        fp = fopen("EMP.DAT","wb+");
        if(fp == NULL)
        {
            printf("Connot open file");
            exit(1);
        }
    }

    recsize = sizeof(e);
    gotoxy(40,7);
    printf("_____________________________________");
    gotoxy(40,8);
    printf("|S.N. INSTITUTE ID  NAME            |");
    gotoxy(40,9);
    printf("|___________________________________|");
    gotoxy(40,10);
	printf("|1.    201851093    PRIYANSHU ASHIYA|");
    gotoxy(40,11);
	printf("|2.    201851016    AMAN SAGAR      |");
	gotoxy(40,12);
	printf("|3.    201851053    JANMEJAY        |");
	gotoxy(40,13);
	printf("|___________________________________|");
	gotoxy(65,16);
    printf("WELCOME TO EMPLOYEE MANAGEMENT SYSTEM");
	gotoxy(35,19);
	printf("press 1 for login");
	gotoxy(35,20);
	printf("YOUR CHOICE : ");
	choice=getch();
	if(choice!='1')
    {
    	system("cls");
       	gotoxy(55,22);
       	printf("THANK YOU FOR USING EMPLOYEE MANAGEMENT SYSTEM");
       	gotoxy(55,23);
       	printf("              HAVE A NICE DAY");
       	getch();
		fclose(fp);
        exit(0);
    }
	do
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\t\t\t\tBACKSPACE WILL WORK BUT NOT SHOWS\n");
    	printf("\t\t\t\tpassword :");
    	int p=0;
        do
	    {
        	po[p]=getch();
        	if(po[p]=='\b')
        	{
				p=p-2;
       		}
        	else
        	{
      			password[p]=po[p];
  			}

        	if(password[p]!='\r')
           	{
		    	printf("*");
           	}
        	p++;
        }while(password[p-1]!='\r');
		password[p-1]='\0';
		x = strcmp(password,j);
		y = strcmp(password,k);
		z = strcmp(password,l);
    }while(!(x==0||y==0||z==0));

    while(1)
    {
        system("cls");
		printf("\nLOGIN SUCCESSFULL\n\n\n");
		gotoxy(30,8);
		if(x==0)
		printf("Hello..!!  PRIYANSHU ASHIYA");
		if(y==0)
		printf("Hello..!!  AMAN SAGAR");
		if(z==0)
		printf("Hello..!!  JANMEJAY");

        gotoxy(30,10);
        printf("______________________________");
        gotoxy(30,12);
        printf("| 1. Add EMPLOYEE Record     |");
        gotoxy(30,13);
        printf("| 2. List EMPLOYEE Records   |");
        gotoxy(30,14);
        printf("| 3. Modify EMPLOYEE Records |");
        gotoxy(30,15);
        printf("| 4. Delete EMPLOYEE Records |");
        gotoxy(30,16);
        printf("| 5. EMPLOYEE Details        |");
        gotoxy(30,17);
        printf("| 6. Exit                    |");
        gotoxy(30,18);
        printf("______________________________");
        gotoxy(30,20);
        printf("Your Choice: ");
        fflush(stdin);
        choice  = getch();
        switch(choice)
        {
			case '1':
			{
				fseek(fp,0,SEEK_END);

				another = 'y';
				while(another == 'y' ||another=='Y')
				{
				    system("cls");
					e.bonus=0;
					printf("\nEnter Employee ID    : ");
					scanf("%ld",&e.id);
					getchar();
					printf("Enter Employee name  : ");
					scanf("\n%[^\n]s",e.name);
					printf("Enter Employee age   : ");
					scanf("%d", &e.age);
					getchar();
					printf("Enter Employee Gender: ");
					scanf("%[^\n]s",e.g);
					getchar();
					printf("Employee Blood Group : ");
					scanf("%[^\n]s",e.bg);
					printf("CONTACT DETAILS --------------------------------------------\n");
					getchar();
					printf("Personal Mobile N.   : ");
					scanf("%[^\n]s",e.con);
					getchar();
					printf("E.mail               : ");
					scanf("%[^\n]s",e.email);
					getchar();
					printf("Emergency Mob. N.    : ");
					scanf("%[^\n]s",e.econ);
					getchar();
					printf("Martial status       : ");
					scanf("%[^\n]s",e.mar);
					printf("Enter basic salary   : ");
					scanf("%f", &e.bs);
					printf("Enter Product sell   : ");
					scanf("%d",&e.sell);
					e.hra=e.bs*0.02;
					e.da=e.bs*0.02;
					e.ta=e.bs*0.02;
					if(e.sell>100)
					{
						e.bonus=e.bs*0.05;
					}
					e.ts=e.bs+e.hra+e.da+e.ta+e.bonus;
					fwrite(&e,recsize,1,fp);
					printf("\n\n\nAdd another record(y/n) : ");
					fflush(stdin);
					another = getche();
				}
				break;
			}
            case '2':
			{
			    system("cls");
				rewind(fp);
				for(i=0;i<110;i++)
				printf("_");
				printf("\n");
				printf("S.N.\tID\t\tNAME\t\t\t Gender \tAGE\tbasic salary\tSell \tTotal salary\n");
				for(i=0;i<110;i++)
				printf("_");
				printf("\n");
				i=1;
				while(fread(&e,recsize,1,fp)==1)
				{
					printf("%3d\t",i);
					printf("%-10ld",e.id);
					printf("%-30s ",e.name);
					printf("%-7s\t",e.g);
					printf("%2d\t",e.age);
					printf("%-16.2f%2d\t",e.bs,e.sell);
					printf("%.2f\n",e.ts);
				    i++;
				}
				for(i=0;i<110;i++)
				printf("_");
				getch();
				break;
			}
            case '3':
			{
				another = 'y';
				while(another == 'y' ||another=='Y')
				{
				    system("cls");
					printf("\nEnter the employee name to modify: ");
					scanf("%[^\n]s", empname);
					rewind(fp);
					while(fread(&e,recsize,1,fp)==1)
					{
						if(strcmp(e.name,empname) ==0)
						{
						    do
						    {

						    printf("what you want to modify\n");
						    printf("A. Employee id");
						    printf("B. Employee name");
						    printf("C. Employee age ");
						    printf("D. Employee Gender ");
						    printf("E. Employee blood group");
						    printf("F. mobile number");
						    printf("G. Employee email ");
						    printf("H. Employee emergency contact ");
						    printf("I. Employee martial status ");
						    printf("J. basic salary");
						    printf("K. product sell");
						    am=getch();



							printf("\nEnter new ");
							e.bonus=0;
							  switch(am)
						    {
                        case 'a':
                        case 'A':
                            printf("\nEnter Employee ID    : ");
							scanf("%ld",&e.id);
							break;
						case 'b':
                        case 'B':
                             printf("Enter Employee name  : ");
							scanf("\n%[^\n]s",e.name);
							break;
                        case 'c':
                        case 'C':
                           printf("Enter Employee age   : ");
							scanf("%d", &e.age);
							break;
                        case 'D':
						
                        case 'd':
                            printf("Enter Employee Gender: ");
							scanf("%[^\n]s",e.g);
							break;

                        case 'e':
                        case 'E':

							printf("Employee Blood Group : ");
							scanf("%[^\n]s",e.bg);
							break;
                        case 'f':
                        case'F':

							//printf(" UPDATE CONTACT DETAILS ------------------------------------\n");

							printf("Personal Mobile N.   : ");
							scanf("%[^\n]s",e.con);
							break;
                        case 'G':
                        case 'g':

							printf("E.mail               : ");
							scanf("%[^\n]s",e.email);
							break;
						case 'h':
                        case 'H':

							printf("Emergency Mob. N.    : ");
							scanf("%[^\n]s",e.econ);
							break;

						case 'I':
                        case 'i':
							printf("Martial status       : ");
							scanf("%[^\n]s",e.mar);
							break;
                        case 'J':
                        case 'j':
							printf("Enter basic salary   : ");
							scanf("%f", &e.bs);
							break;
                        case 'K':
                        case 'k':
							printf("Enter Product sell   : ");
							scanf("%d",&e.sell);
							break;
							}
						    printf("change  any other data(y/n)");
						    am=getch();
							e.hra=e.bs*0.02;
							e.da=e.bs*0.02;
							e.ta=e.bs*0.02;
							if(e.sell>100)
							{
								e.bonus=e.bs*0.05;
							}
							e.ts=e.bs+e.hra+e.da+e.ta+e.bonus;
							fseek(fp,-recsize,SEEK_CUR);
							fwrite(&e,recsize,1,fp);


						    }while(am=='Y'||am=='y');
							break;
						}
					}
					printf("\n\n\nModify another record(y/n)");
					fflush(stdin);
					another = getche();
				}
				break;
			}
			case '4':
			{
				another = 'y';
				while(another == 'y'||another=='Y')
				{
					system("cls");
					printf("\nEnter name of employee to delete: ");
					scanf("%[^\n]s",empname);
					ft = fopen("Temp.dat","wb");
					rewind(fp);
					while(fread(&e,recsize,1,fp) == 1)
					{
						if(strcmp(e.name,empname) != 0)
						{
							fwrite(&e,recsize,1,ft);
						}
					}
					fclose(fp);
					fclose(ft);
					remove("EMP.DAT"); ///
					rename("Temp.dat","EMP.DAT");
					fp = fopen("EMP.DAT", "rb+");
					printf("Delete another record(y/n)");
					fflush(stdin);
					another = getche();
				}
				break;
			}
			case '5':
			{
				another = 'y';
				while(another == 'y' ||another=='Y')
				{
					system("cls");
					printf("\nEnter the employee name to biodata: ");
					scanf("%[^\n]s", empname);
					rewind(fp);
					while(fread(&e,recsize,1,fp)==1)
					{
						if(strcmp(e.name,empname) ==0)
						{
							printf("EMPLOYEE ALL DETAILS\n\n\n");

							printf("ID           :%-10ld\n",e.id);
							printf("NAME         :%-30s \n",e.name);
							printf("AGE          :%d\n",e.age);
							printf("GENDER       :%-7s\n",e.g);
							printf("BLOOD GROUP  :%s\n\n",e.bg);
							printf("CONTACT DETAILS --------------------------------------------\n");
							printf("Personal Mobile N. :%s\n",e.con);
							printf("E.mail             :%s\n",e.email);
							printf("Emergency Mob. N.  :%s\n\n",e.econ);
							printf("Martial status     :%s\n\n",e.mar);
							printf("SALARY DETAILS ---------------------------------------------\n");
							printf("BASIC SALARY           :%-16.2f\n",e.bs);
							printf("SELL                   :%d\n",e.sell );
							printf("House Rent Allowance   :%.2f\n",e.hra);
							printf("Travel Allowance       :%.2f\n",e.ta);
							printf("Dearness Allowance     :%.2f\n",e.da);
							printf("Bonus                  :%.2f\n",e.bonus);
							printf("TOTAL SALARY           :%.2f\n\n\n",e.ts);
							break;
						}
					}
					printf("print other employee data(y/n)");
					fflush(stdin);
					another=getche();
				}
		        break;
			}
            case '6':
			{
				system("cls");
				gotoxy(55,22);
				printf("THANK YOU FOR USING EMPLOYEE MANAGEMENT SYSTEM");
				gotoxy(55,23);
				printf("              HAVE A NICE DAY");
				getch();
				fclose(fp);
				exit(0);
           }
        }
	}
    return 0;
}

