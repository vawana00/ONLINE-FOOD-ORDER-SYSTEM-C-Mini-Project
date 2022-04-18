#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int firstinface(void);
void admin_section(void);
void costumer_section(void);
void aboutus(void);

void cos_login(void);
void costumer_signup(void);
char* validating_number();

void admin_inface(void);
void adlogin(void);
void admin_costum_details(void);
void costumers_details(void);
void seerecords(void);
void orderplaced(void);

void costumerfterlogin_inface(void);
int sbfood(int *);

int sbhotel(void);
int hotel1(int *);
int hotel2(int *);
int hotel3(int *);


struct costumer_login_details
		 {
		 	char id[14] , psd[20];
		 }idpsd;

struct costumer_details
		{
			char name[20] , address[30];
			char ph[10];
		} c;

struct order
		{
		    char cur_time[26],item[25],daddress[50];
			char obname[20],obph[10] ;
            int q , precart;
		}day;

int test;


void main()
{
	printf("\n\n\n\t\t\t\t\t***************************************************************************\n");
	printf("\t\t\t\t\t*               WELCOME TO ONLINE FOOD ORDER SYSTEM                       *\n");
	printf("\t\t\t\t\t***************************************************************************\n");
	printf("\n\n");

	firstinface();
}


int firstinface (void)
{
	int n;
	printf("\n\n\nPlease select One of the following section:\n\n\t1.Admin Section\n\t2.Costumer Section\n\t3.About us\n\t4.Exit\n\n");
	printf("Enter your choice:");
	scanf("%d",&n);

	switch(n)
	{
		case 1:
		admin_inface();
		break;

		case 2:
		costumer_section();
		break;

		case 3:
        aboutus();
        break;

		case 4:
		    system("cls");
		    printf("\n\n\n\t\t\t\t***************************************************\n");
		    printf("\t\t\t\t\t\tTHANK YOU!!\n");
		    printf("\t\t\t\t\tREMEMBER US WHEN YOU ARE FEELING HUNGRY!!\n");
		    printf("\t\t\t\t***************************************************\n");
		    exit(0);
		    break;

		default :
		system("cls");
		printf("\n\nInvalid option!!Please Re-enter the correct option!\n");
		firstinface();
	}

return 0;
}

void costumer_section(void)
{
    system("cls");
	int wait,ncos;
	printf("\n\n\n\t\t\t__________________________________________________________________________\n");
	printf("\t\t\t\t\t\tWelcome to the costumer Page!\n");
	printf("\t\t\t__________________________________________________________________________\n");
	printf("\t\t\t\tIt's always great to welcome our gods.we are ready to serve you. \n");
	printf("\t\t\t__________________________________________________________________________\n");
	printf("\n\n\n_________________________________\n");
	printf("\tPlease select to :\n");
	printf("_________________________________\n\n");
	printf("1. Login\n");
	printf("2. Sign Up\n");
	printf("3. Go Back to Mainmenu\n\n\n");
	printf("If your are new in this system you need to sign up first in our system\n\n");
	printf("Enter your choice:");
	fflush(stdin);
	scanf("%d",&ncos);

	switch(ncos)
	{
		case 1:
            cos_login();	//calling of login function
		    break;

		case 2:
			costumer_signup() ;	//caling of costumer signup function
		    break;

		case 3:
		    system("cls");
            firstinface();
            break;

		default:
		    printf("\n\nInvalid option!!Please Re-enter the correct option\n");
		    for(wait =0 ;  wait<100000 ; wait++ )
			{
				printf("\rLoading.....%d.....",wait/1000);
			}
		    system("cls");
            costumer_section();
	}
}

void cos_login(void)
{
	char uname[20] , psd[20];
	FILE *fp2;
	fp2 = fopen("logindetails.dat", "rb");
			if(fp2 ==NULL)
			{
				printf("\n\nUnable to open the file\n");
				exit(1);
			}
                printf("\nUsername= ");
				scanf("%s",uname);
				strcpy(day.obname,uname);
				printf("\nPassword= ");
				scanf("%s",psd);
				rewind(fp2);

                while(fread(&idpsd , sizeof(idpsd), 1, fp2) == 1)
				{

					if(	strcmp(idpsd.id ,uname)==0 && strcmp(idpsd.psd ,psd)==0 )
						{
                                 printf("\nSuccessively login !\n\t Welcome %s\n\n",uname);
						         costumerfterlogin_inface();
						}

				}
							printf("\n\tSorry %s, You haven't signed-up in our system\n\n",uname);
							int ch ;
							printf("\nPlease select the option\n");
							printf("____________________________\n\n");
                            printf("1.Signup \n2.Back to main menu \n");
							printf("\nEnter your choice:");
							fflush(stdin);
							scanf("%d",&ch);

							switch (ch)
							{
								case 1 :
									system("cls");
									costumer_signup() ;	//signin function
								    break ;

								 default:
									system("cls");
									firstinface();	//mainmenu function

							}

}

void costumer_signup()
{
		    FILE *fp_cosdetails ,*fp1 ;
		    int wait;
			fflush(stdin) ;
			printf("\n\n____________________________________________________\n");
			printf("\tFill up the details for signing up\n");
			printf("____________________________________________________\n\n");
			printf("Name=");
			scanf("%[^\n]s",c.name);
			strcpy(c.ph,validating_number());
			printf("Address= ");
			fflush(stdin);
			scanf("%[^\n]s",c.address);

			fp_cosdetails = fopen( "costumerdetails.dat","ab");
			if (fp_cosdetails == NULL)
			{
				printf("File cannot be opened");
				exit(1);
			}
			else
			{
			fwrite(&c , sizeof(c) ,1,fp_cosdetails);
			}
			fclose(fp_cosdetails);

	    fp1 = fopen("logindetails.dat","ab+");
		if(fp1 ==NULL)
			{
				printf("Unable to open the file\n");
				exit(1);
			}
		else
			{
			printf("Username= ");
			scanf("%s",idpsd.id);
			fflush(stdin);
			printf("Password= ");
			scanf("%s",idpsd.psd);
			fwrite(&idpsd ,sizeof(idpsd),1,fp1);
			}
			fclose(fp1);
			printf("\n\npress any key to go back to costumer section\n");
			if(getch())
			for(wait =0 ;  wait<100000 ; wait++ )
			{
				printf("\rLoading.....%d.....",wait/1000);
			}
			costumer_section();
}

char* validating_number()
{
        int i;
        char ch;
		static char ph[10] ;
		printf("\nEnter phone number = +977");
        fflush(stdin);
		scanf("%s",ph);
		for(i=0;i<10;i++)
        {
            ch = ph[i];
            if(	(ch >='0' && ch<='9')!=1)
                {
                     printf("Number must contain only digits!! Correct format is 9XXXXXXXXX\n");
                      validating_number();
                }

        }

            if((strlen(ph))==10)
                {
                    if(ph[0] != '9')
                    {
                            printf("\nInValid format !!! Correct format is 9XXXXXXXXX\n\n");
                          validating_number();
                    }
                    else
                    {
                             return ph;
                    }
                }
            else
                {
                    printf("\nInvalid format!!!!Valid format is of 10 digits!!!\nCorrect format is 9XXXXXXXXX\n\n");
                    validating_number();
                }
}



void costumerfterlogin_inface(void)
{
			int wait,s=0;
			for(wait =0 ;  wait<100000 ; wait++ )
			{
				printf("\rLoading.....%d.....",wait/1000);
			}
		system("cls") ;
		int choice ;

		printf("\n\n\n\t\t\t_______________________________________________________________\n");
		printf("\t\t\t\t\tWhat do you want to order:\n");
		printf("\t\t\t_______________________________________________________________\n");
		printf("\t\t\t\t\tOrdering is Possible in two ways:\n");
		printf("\t\t\t_______________________________________________________________\n");
		printf("\n\n\t1.Search By Hotel\n");
		printf("\t2.Search By food\n");
		printf("\t3.Go to Mainmenu\n\n\n");
        printf("\nEnter your choice:");
        fflush(stdin);
		scanf("%d",&choice);
		system("cls");

			switch(choice)
				{
					case 1:
						sbhotel();
					break;

					case 2:
						sbfood(&s);
					break;

                    case 3:
                     system("cls");
                     firstinface();

                    default:
                        printf("\nInvalid option!!Please Re-enter the correct option");
                           for(wait =0 ;  wait<100000 ; wait++)
                            {
				               printf("\rLoading.....%d.....",wait/1000);
			                }
			                system("cls");
                            costumerfterlogin_inface();
				}
}

int sbhotel()
	{
		char ch;
		int sbhnum;
		FILE *fpsbh,*fph1,*fph2,*fph3;
        int wait,s=0;
		printf("\n\n________________________________________________\n");
		printf("\t You can order from following hotel\n");
		printf("________________________________________________\n");
		do
        {
           fpsbh = fopen ("searchbyhotel.txt" , "r");
		if (fpsbh==NULL)
		{
			printf("File cannot be opened!!!");
			exit(1);
		}
		else
		{
			while (ch != EOF)
				{
					ch = fgetc(fpsbh);
					printf("%c",ch);
				}
		}
		fclose(fpsbh);

		printf("\n\n________________________________________________\n");
		printf("\tFood available in Kamana Hotel\n");
		printf("________________________________________________\n");
        fph1=fopen("hotel1.txt","r");
        if(fph1==NULL)
        {
            printf("\nFile can not be opened!\n");
            exit(1);
        }
        while((ch=fgetc(fph1))!=EOF)
        {
            printf("%c",ch);
        }
		fclose(fph1);

		printf("\n\n__________________________________________________________\n");
        printf("\tFood available in The restro-New age, New taste\n");
        printf("__________________________________________________________\n");
        fph2=fopen("hotel2.txt","r");
        if(fph2==NULL)
        {
            printf("\nFile can not be opened!\n");
            exit(1);
        }
        while((ch=fgetc(fph2))!=EOF)
        {
            printf("%c",ch);
        }
		fclose(fph2);

        printf("\n\n___________________________________________________________\n");
        printf("\tFood available in Aagan Swadistha Mithai Pasal\n");
        printf("___________________________________________________________\n");
        fph3=fopen("hotel3.txt","r");
        if(fph3==NULL)
        {
            printf("\nFile can not be opened!\n");
            exit(1);
        }
        while((ch=fgetc(fph3))!=EOF)
        {
            printf("%c",ch);
        }
		fclose(fph3);

        printf("\n\n\nEnter your Hotel choice=");
        fflush(stdin);
        scanf("%d",&sbhnum);
		switch(sbhnum)
		{

			case 1:
			   hotel1(&s);//function calling of hotel 1
			   break;

			case 2:
				hotel2(&s);	//function calling of hotel 2
			    break;

			case 3:
                hotel3(&s);	//	function calling of hotel 3
			    break;
			default:
                printf("\nInvalid option!!Please Re-enter the correct option!!\n");
                sbhotel();
		}
		printf("\nDo you want to order from other hotels(Y/N): ");
		fflush(stdin);
		ch = getche();
		printf("\n\n\n");
	} while (ch == 'Y' || ch == 'y');

	if(s!=0)

	{
    strcpy(day.obph,validating_number());
    printf("\nEnter your location for delivery of food:");
	fflush(stdin);
	scanf("%[^\n]s",day.daddress);
    FILE *fp;
    printf("\n");
    fp = fopen("orderplaced.dat", "ab+");
	if(fp == NULL)
	{
	    printf("file cannot be opened\n");
	    exit(1);
    }
	else
    {
       fwrite(&day, sizeof(day) , 1, fp);
    }
    fclose(fp);
	printf("\nThe total price is =%d\n", s);
    printf("\n\n\n\t\t\t*********************************************************************\n");
    printf("\t\t\t\t\tTHANK YOU FOR ORDERING!!\n");
    printf("\t\t\t\tYOUR ORDER WILL BE AT YOUR DOOR IN 30 MINUTES\n");
    printf("\t\t\t\t\tHAVE A GREAT DAY AHEAD!!\n");
    printf("\t\t\t*********************************************************************\n\n\n");
	}
    printf("PRESS ANY KEY TO GO BACK TO MAIN MENU");
    fflush(stdin);
    ch=getch();
    system("cls");
    firstinface();


		return 0;
	}

	int hotel1(int *cart)
	{
	    char confirm;
	    FILE *fptr;
	    time_t curtime;
	    time(&curtime);
	    strcpy(day.cur_time,ctime(&curtime));
	    char ch;
	    int choice;
	    int price[3]={75 , 40 , 150};
        printf("\n\n\nEnter your choice:");
        fflush(stdin);
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the quantity:");
                scanf("%d",&day.q);
                strcpy(day.item, "Pasta");
                break;

            case 2:
                printf("\nEnter the quantity:");
                scanf("%d",&day.q);
                strcpy(day.item, "Thuppa");
                break;

            case 3:
                 printf("\nEnter the quantity:");
                 scanf("%d",&day.q);
                 strcpy(day.item, "Thakali Khana");
                 break;

            default:
                printf("\n\nSorry!we don't have the food you requested!\n");
                hotel1(cart);
        }
            printf("\n\nDo you want to confirm the order? You won't be able to cancel order hereafter.\n");
            printf("Enter your choice(Y/N)-->");
            fflush(stdin);
            scanf("%c",&confirm);

            if(confirm=='Y'|| confirm=='y')
            {
                day.precart=(day.q*price[choice-1]);
               *cart =  *cart + day.precart;

                FILE *fp;
				printf("\n");
				fp = fopen("Transactionofday.dat", "ab+");
				if(fp == NULL)
					{
					    printf("file cannot be opened\n");
					    exit(1);
                    }
				else
                {
                  fwrite(&day, sizeof(day) , 1, fp);
                }
                fclose(fp);
            }

                printf("\nDo you want to order more-(Y/N)-->");
				fflush(stdin);
				ch = getchar();
					if (ch == 'Y' || ch == 'y')
						{
						    printf("\n\n");
                            hotel1(cart);
						}
	}


  int hotel2(int *cart)
	{
	    FILE *fptr;
	    char ch,confirm;
	    int choice;
	    int price[4]={70 , 100 , 120, 100};
	    time_t curtime;
	    time(&curtime);
	    strcpy(day.cur_time,ctime(&curtime));

        printf("\n\n\nEnter your choice:");
        fflush(stdin);
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the quantity:");
                scanf("%d",&day.q);
                strcpy(day.item, "Leg Piece");
                break;

            case 2:
                printf("\nEnter the quantity:");
                scanf("%d",&day.q);
                strcpy(day.item, "Chicken Roast");
                break;

            case 3:
                 printf("\nEnter the quantity:");
                 scanf("%d",&day.q);
                 strcpy(day.item, "Sausage");
                 break;

            case 4:
                 printf("\nEnter the quantity:");
                 scanf("%d",&day.q);
                 strcpy(day.item, "Chicken Biryani");
                 break;

            default:
                printf("\n\nSorry!we don't have the food you requested!\n");
                hotel2(cart);
        }
            printf("\n\nDo you want to confirm the order? You won't be able to cancel order hereafter.\n");
            printf("Enter your choice(Y/N)-->");
            fflush(stdin);
            scanf("%c",&confirm);
            if(confirm=='Y'|| confirm=='y')
            {
                day.precart=(day.q*price[choice-1]);
               *cart =  *cart + day.precart;

                FILE *fp;
				printf("\n");
				fp = fopen("Transactionofday.dat", "ab+");
				if(fp == NULL)
					{
					    printf("file cannot be opened\n");
					    exit(1);
                    }
				else
                {
                  fwrite(&day, sizeof(day) , 1, fp);
                }
                fclose(fp);
            }
				printf("\nDo you want to order more-(Y/N)-->");
				fflush(stdin);
				ch = getchar();
					if (ch == 'Y' || ch == 'y')
						{
						    printf("\n\n");
                            hotel2(cart);
						}
	}


	int hotel3(int *cart)
	{
	    FILE *fptr;
	    char ch,confirm;
	    int choice;
	    int price[4]={10, 15, 20, 15};
	    time_t curtime;
	    time(&curtime);
	    strcpy(day.cur_time,ctime(&curtime));
        printf("\n\n\nEnter your choice:");
        fflush(stdin);
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the quantity:");
                scanf("%d",&day.q);
                strcpy(day.item, "Peda");
                break;

            case 2:
                printf("\nEnter the quantity:");
                scanf("%d",&day.q);
                strcpy(day.item, "Laddu");
                break;

            case 3:
                 printf("\nEnter the quantity:");
                 scanf("%d",&day.q);
                 strcpy(day.item, "Julebi");
                 break;

            case 4:
                 printf("\nEnter the quantity:");
                 scanf("%d",&day.q);
                 strcpy(day.item, "Batare");
                 break;

            default:
                printf("\n\nSorry!we don't have the food you requested!\n");
                hotel3(cart);
        }
            printf("\n\nDo you want to confirm the order? You won't be able to cancel order hereafter.\n");
            printf("Enter your choice(Y/N)-->");
            fflush(stdin);
            scanf("%c",&confirm);

            if(confirm=='Y'|| confirm=='y')
            {
                day.precart=(day.q*price[choice-1]);
               *cart =  *cart + day.precart;

                FILE *fp;
				printf("\n");
				fp = fopen("Transactionofday.dat", "ab+");
				if(fp == NULL)
					{
					    printf("file cannot be opened\n");
					    exit(1);
                    }
				else
                {
                  fwrite(&day, sizeof(day) , 1, fp);
                }
                fclose(fp);
            }
				printf("\nDo you want to order more-(Y/N)-->");
				fflush(stdin);
				ch = getchar();
					if (ch == 'Y' || ch == 'y')
						{
						    printf("\n\n");
                            hotel3(cart);
						}
	}

int sbfood(int *cart)
{
		int choice;
        int q ;
        int total=0;
        time_t curtime;
 		time(&curtime);
		strcpy(day.cur_time ,ctime(&curtime));

		int price[4] = {100, 120 , 110 , 140};
		char ch;
		printf("\n\n\t\t_________________________________________________\n");
		printf("\t\t\tAvailable foods are:\n");
		printf("\t\t_________________________________________________\n\n");
	    FILE *fpsbf;
	    char confirm;
	    fpsbf=fopen("searchbyfood.txt","r");
	    if(fpsbf==NULL)
        {
            printf("FILE CAN'T BE OPENED!!");
            exit(1);
        }
        else
        {
            while((ch=fgetc(fpsbf))!=EOF)
            {
                printf("%c",ch);
            }
        }
        fclose(fpsbf);
        fflush(stdin);
        printf("\nEnter your choice= ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1 :
				printf("Enter the quantity = ");
				scanf("%d",&day.q);
				strcpy (day.item , "Vegeterian momo");
			break ;
			case  2:
				printf("Enter the quantity = ");
				scanf("%d",&day.q);
				strcpy (day.item , "Chicken Momo");
			break ;
			case 3:
				printf("Enter the quantity = ");
				scanf("%d",&day.q);
				strcpy (day.item , "Vegeterian Chowmin");
			break;

			case 4:
				printf("Enter the quantity = ");
				scanf("%d",&day.q);
				strcpy (day.item , "Chicken Chowmin");
			break ;


			default:
				printf("\nSorry!!! We don't have the food option you requested\n");
				sbfood (&total);
		}
            printf("\n\nDo you want to confirm the order? You won't be able to cancel order hereafter.\n");
            printf("Enter your choice(Y/N)-->");
            fflush(stdin);
            scanf("%c",&confirm);
            if(confirm=='Y'|| confirm=='y')
            {
                day.precart=(day.q*price[choice-1]);
               *cart =  *cart + day.precart;
               total = *cart;

                FILE *fp;
				printf("\n");
				fp = fopen("Transactionofday.dat", "ab+");
				if(fp == NULL)
					{
					    printf("file cannot be opened\n");
					    exit(1);
                    }
				else
                {
                  fwrite(&day, sizeof(day) , 1, fp);
                }
                fclose(fp);
            }
				printf("\nDo you want to order more-(Y/N)");
				fflush(stdin);
				ch = getche();
					if (ch == 'Y' || ch == 'y')
						{
						    printf("\n\n");
                            sbfood(&total);
						}
						else
                        {
                            if(total!=0)
                           {
                            strcpy(day.obph,validating_number());
                            printf("\n\nEnter your location for delivery of food:");
	                        fflush(stdin);
	                        scanf("%[^\n]s",day.daddress);
	                        FILE *fp;
                            printf("\n");
				           fp = fopen("orderplaced.dat", "ab+");
				           if(fp == NULL)
                           {
					          printf("file cannot be opened\n");
					          exit(1);
                           }
				           else
                           {
                              fwrite(&day, sizeof(day) , 1, fp);
                           }
                            fclose(fp);
                            printf("\n\nYour total price is = %d\n\n",total);
                            printf("\n\n\n\t\t\t*********************************************************************\n");
                            printf("\t\t\t\t\tTHANK YOU FOR ORDERING!!\n");
                            printf("\t\t\t\tYOUR ORDER WILL BE AT YOUR DOOR IN 30 MINUTES\n");
                            printf("\t\t\t\t\tHAVE A GREAT DAY AHEAD!!\n");
                            printf("\t\t\t*********************************************************************\n");
                           }
                            printf("\n\n\nPress any key to go back to main menu\n");
                            if(getch())
                            system("cls");
                            firstinface();
                        }

		return 0;
}

void admin_inface(void)
{
	system("cls");
	char aduname[20] , psd[20];
    printf("\t\t\t___________________________________________________________________________________\n");
	printf("\t\t\t\t\t\tWelcome To the Admin Section\n");
	printf("\t\t\t___________________________________________________________________________________\n");
	printf("\t\t\t\tPlease enter the department login Id to login as management person\n");
	printf("\t\t\t___________________________________________________________________________________\n");
	printf("\n\n");
	adlogin();
}


   void adlogin()
{
	int i , check , wait;
	char aduname[20] , psd[20];
	printf("\tUsername:");
	fflush(stdin);
	scanf("%s",&aduname);
	printf("\tPassword:");
	fflush(stdin);
	scanf("%s",&psd);
	if (strcmp(aduname , "miniproject")!=0 || strcmp(psd ,"bbbs077")!=0)
		{
		    if (strcmp(aduname , "miniproject")!=0 && strcmp(psd ,"bbbs077")!=0)
                {
                    printf("You are not allowed to login:\n");

                    printf("Please wait !! We are transferring you to our homepage:\n\n");
                    for(wait =0 ; wait<=100000; wait++)
                    {
                        printf("\rloading......%d.....",wait/1000);
                    }
                    system("cls");
                    firstinface();  //first interface function calling

                }
            else if (strcmp(aduname , "miniproject")!=0)
                    {
                            check = strcmp(aduname ,"miniproject");
                            system("cls");
                            printf("\n\nNo such Username is registered\n");

                    while (check!=0)
                        {
                            if(test==3)
                            break;

                            printf("You have %d attempts left\n",(3-test++));
                            adlogin();

                        }
                    }
            else
            {
                      check = strcmp(psd ,"bbbs077");
                    system("cls");
                    printf("\n\nIncorrect password\n");

                    while (check!=0)
                        {
                            if(test==3)
                            break;

                            printf("You have %d attempts left\n",(3-test++));
                            adlogin();
                        }
            }
        }
	else
		{
		        printf("\n\nYOU ARE SUCESSFULLY LOGGED IN AS MANAGEMENT PERSON\n");
                admin_section();
		}
}


void admin_section(void)
{
	int wait,nadm;
	printf("\n\n\tPlease select the option to view:\n\n1.Total Order and Transaction\n2.Costumer Details\n3.Go Back to MainMenu\n");
	printf("\nEnter your choice:");
	fflush(stdin);
	scanf("%d",&nadm);

	switch(nadm)
	{
		char ch;
			case 1:
					for(wait = 0 ; wait <=10000 ; wait ++ )
					printf("\rLoading.....%d......",wait/100);
					system("cls");
					printf("\n\n\t\t____________________________________________________________\n");
					printf("\t\t\tTotal Order and Transaction are:\n");
					printf("\t\t____________________________________________________________\n\n");
					seerecords();	  			//1st output of admin ..fucntion calling
                    break;

			case 2:
					for(wait = 0 ; wait <=10000 ; wait ++ )
					printf("\rLoading.....%d......",wait/100);
					costumers_details();				//2nd output of admin ..fucntion calling
			        break;

			case 3:
			        system("cls");
				    firstinface();
                    break;
            default:
                    printf("\n\nInvalid option!!Please Re-enter the correct option!\n");
                    for(wait = 0 ; wait <=100000 ; wait ++ )
                    {
                      printf("\rLoading.....%d......",wait/1000);
                    }
                    system("cls");
		            admin_section();
	}
	return ;

}


void costumers_details(void)
{
    system("cls");
    char ch;
    FILE *fp;
    fp = fopen("costumerdetails.dat","rb");
	if(fp==NULL)
        {
            printf("\nUnable to open file!!!\n");
            exit(1);
        }
    else
    {
        printf("\n\n\t\t________________________________________\n");
        printf("\t\t\tCostumer Details are:\n");
        printf("\t\t________________________________________\n\n\n");
        printf("___________________________________________________________________________\n");
        printf("%0.20s\t\t %26s \t %s\n","Name" , "Phone Number(+977)" , "Address");
        printf("___________________________________________________________________________\n");
        while (fread(&c , sizeof(c) ,1,fp) == 1)
        {
            printf("%-18s\t  %s\t\t%s\n",c.name , c.ph , c.address);
        }
    }
    printf("\nPRESS ANY KEY TO GO BACK TO ADMIN SECTION");
    fflush(stdin);
    ch = getch();
    system("cls");
	admin_section();
}

void seerecords(void)
{
		char ch;
		int choice;
		int wait,tot=0,ord=0;
		FILE *fp1, *fp2;
		printf("\nplease select\n");
		fp1 = fopen("Transactionofday.dat","rb");

	    printf("1.To see total transaction\n2.To see order place on system\n3.To go back to admin section\n");
		printf("\n\nEnter your choice:");
		fflush(stdin);
		scanf("%d",&choice);
		switch(choice)
		{
        case 1:
            if(fp1 == NULL)
		{
			printf("File cannot be opened");
		}
		else
		{
            printf("\n\n____________________________________________________________________________________________________\n");
            printf("%25s \t|   %0.8s  \t|\t%s  \t  |%26s\n" , "Item" ,"Quantity","Cost","Time");
            printf("____________________________________________________________________________________________________\n");
		}
		while (fread(&day , sizeof(day),1,fp1)==1)
			{
		         printf("%25s \t|\t%d\t|\tRs.%d\t  |\t%26s\n",day.item , day.q , day.precart , day.cur_time);
                 tot=tot+day.precart;
                 ord= ord+day.q;
			}
        fclose(fp1);
		fflush(stdin);
        printf("\nThe total transaction = %d\n\n",tot);
        printf("\nThe total order = %d\n\n",ord);
        printf("\n\nPRESS ANY KEY TO GO BACK TO ORDER AND TRANSACTION SECTION");
        if(getch())
        system("cls");
		seerecords();
        break;

        case 2:
        fp2 = fopen("orderplaced.dat","rb");
		if(fp2 == NULL)
		{
			printf("File cannot be opened");
		}
		else
		{
            printf("\n\n____________________________________________________________________________________________________________________\n");
            printf("%20s\t|  %18s \t|   %s  \t\t|\t%s \t \n" ,"Ordered By","Phone No(+977)","Delivery Location","Time");
            printf("____________________________________________________________________________________________________________________\n");
		}
		while (fread(&day , sizeof(day),1,fp2)==1)
			{
		         printf("%20s\t|%15s \t|%22s \t|\t\%s\n",day.obname,day.obph,day.daddress, day.cur_time);
			}
        fclose(fp2);
        orderplaced();
        break;

        case 3:
            system("cls");
            admin_section();
            break;

        default:
            printf("\n\nInvalid option!!Please Re-enter the correct option!\n");
            for(wait = 0 ; wait <=100000 ; wait ++ )
            {
              printf("\rLoading.....%d......",wait/1000);
            }
            system("cls");
		    admin_section();
		}
}

void orderplaced(void)
{
    char search_uname[20],ch;
	FILE *fp;
	fp = fopen("Transactionofday.dat","rb");
	printf("Enter the username to see his/her order placed = ");
	fflush(stdin);
	gets(search_uname);
	printf("\nOrder of %s are\n",search_uname);
	printf("%25s | %5s\n","Item","Quantity");
	printf("----------------------------------------------\n");
while(fread(&day,sizeof(day),1,fp)==1)
	{
		if(strcmp(day.obname,search_uname)==0)
		{
			printf("%25s | %5d \n",day.item , day.q);
		}
	}
    printf("\n\nDo you want to see the order of other username(Y/N)-->");
    fflush(stdin);
    ch=getchar();
    if(ch=='Y' || ch=='y')
    {

      orderplaced();
    }
	fclose(fp);
	printf("\n Press any key to go back to see the transaction and order section\n");
	if(getch())
    system("cls");
    seerecords();
}


  void aboutus(void)
    {
        system("cls");
        printf("\n\n\nThis is the project developed as per instructed by our  respected professor and teachers.\nThis project is submitted to Department of Electronics and Computer Engineering for the partial fulfillment of the requirements of the practical course on C-programming [CT 401].");
        printf("\n\n\nThe people behind this project are:\n");
        printf("1. Benzeena Dhakal    -PUL077BME006\n");
        printf("2. Bhawana Dahal      -PUL077BME007\n");
        printf("3. Biswash Khatiwada  -PUL077BME014\n");
        printf("4. Sugal Khatiwada    -PUL077BME041\n");
        printf("Department of Mechanical and Aerospace Engineering\n\n\n");
        printf("PRESS ANY KEY TO GO BACK TO MAINMENU\n\n");
        if(getch())
        system("cls");
        firstinface();
    }


