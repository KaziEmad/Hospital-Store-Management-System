//
//  main.c
//  Hospital Store Management System.
//
//  Created by Emad on 12/30/2019.
//  Copyright (c) 2019 Kazi Emad. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

COORD coord = {0,0};


void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void menu()
{
    system("cls");
printf("\t\t**********WELCOME TO MEDICAL STORE MANAGEMENT SYSTEM*************");

printf("\n\n\t\t\t  MENU\t\t\n\n");
printf("\t1.About\n   \t2.Medicine Menu\n   \t3.Supplier Menu\n  \t4.Customer Menu\n \t5.Exit\n");

switch(getch())
{
    case '1':
        about();
    break;
   case '2':
       medicine();
    break;
    case '3':
        supplier();
    break;
    case '4':
        customer();
    break;
    case '5':
        exit(0);
    break;
    default:
                system("cls");
                printf("\nEnter 1 to 5 only");
                printf("\n Enter any key");
                getch();
menu();
}
}

int about()
{
    system("cls");
    printf("This mini project in C Medical Store Management System is a console application without graphic.\nIn this project, you can add, modify and delete records of customers, suppliers and medicines.\nYou can also search for customer or supplier details and medicines added into stock. Search can be done by medicine name, customer name or supplier name.\n");
    printf("\n\npress any key to go back...!!!");
    getch();
    menu();

}
int medicine()
{
    FILE *fp, *ft;
    char another, choice;

    struct medicin
    {
        char name[40];
        char company[20];
        char date[20];
    };

    struct medicin e;

    char medicinename[40];

    long int recsize;

    fp = fopen("MDC.DAT","rb+");
    if(fp == NULL)
    {
        fp = fopen("MDC.DAT","wb+");
        if(fp == NULL)
        {
            printf("Cannot open file");
            exit(1);
        }
    }
    recsize = sizeof(e);

    while(1)
    {

        system("cls");

        printf(" \n  ::::::::::::::::::::::::::  | MEDICINE MENU |  :::::::::::::::::::::::::: \n");
		gotoxy(30,07);
		printf("\n                              =====================\n");
		gotoxy(30,9);
		printf("[1] Add  Medicine");
        gotoxy(30,11);
        printf("[2] Stock List");
        gotoxy(30,13);
        printf("[3] Stock Update");
        gotoxy(30,15);
        printf("[4] Delete Medicine");
        gotoxy(30,17);
        printf("[5] Search Medicine");
        gotoxy(30,19);
        printf("[6] Return Main Menu");
        gotoxy(30,20);
        printf("=====================\n");
        gotoxy(30, 21);
        printf("Your Choice: ");
        fflush(stdin);
        choice  = getche();
        switch(choice)


        {
        case '1':
            system("cls");
            fseek(fp,0,SEEK_END);

            another = 'y';
            while(another == 'y')
            {
                printf("\nEnter Medicine Name : ");
                scanf("%s",e.name);
                printf("\nEnter Medicine Company :");
                scanf("%s",e.company);
                printf("\nEnter Valid Date of the Medicine: ");
                scanf("%s", &e.date);

                fwrite(&e,recsize,1,fp);

                printf("\nAdd another record(y/n) ");
                fflush(stdin);
                another = getche();
            }
            break;
        case '2':
            system("cls");
            printf("Stock List (name, company, date)");
            rewind(fp);
            while(fread(&e,recsize,1,fp)==1)
            {

                printf("\n\n%s \t\t%s \t%s",e.name,e.company,e.date);
            }
            getch();
            break;

        case '3':
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("Enter the medicine name to modify: ");
                scanf("%s", medicinename);
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)
                {
                    if(strcmp(e.name,medicinename) == 0)
                    {
                        printf("\nEnter new name, company, and date: ");
                        scanf("%s%s%s",e.name,&e.company,&e.date);
                        fseek(fp,-recsize,SEEK_CUR);
                        fwrite(&e,recsize,1,fp);
                        break;
                    }
                }
                printf("\nModify another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '4':
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("\nEnter name of the medicine to delete: ");
                scanf("%s",medicinename);
                ft = fopen("Temp.dat","wb");
                rewind(fp);
                while(fread(&e,recsize,1,fp) == 1)
                {
                    if(strcmp(e.name,medicinename) != 0)
                    {
                        fwrite(&e,recsize,1,ft);
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("MDC.DAT");
                rename("Temp.dat","MDC.DAT");
                fp = fopen("MDC.DAT", "rb+");
                printf("Delete another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '5':
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("\nEnter name of the medicine to delete: ");
                scanf("%s",medicinename);
                ft = fopen("Temp.dat","wb");
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)
            {

                printf("\n\n%s \t\t%s \t%s",e.name,e.company,e.date);
            }
            printf("Search another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '6':
            fclose(fp);
            menu();
        }
    }
}
int supplier()
{
    FILE *fp, *ft;
    char another, choice;

    struct supplier
    {
        char name[40];
        int age;
        char address[20];
        float bs;
    };

    struct supplier e;

    char suppliername[40];;

    long int recsize;

    fp = fopen("SPL.DAT","rb+");
    if(fp == NULL)
    {
        fp = fopen("SPL.DAT","wb+");
        if(fp == NULL)
        {
            printf("Cannot open file");
            exit(1);
        }
    }
    recsize = sizeof(e);

    while(1)
    {

        system("cls");

        printf(" \n  ::::::::::::::::::::::::::  | SUPPLIER MENU |  :::::::::::::::::::::::::: \n");
		gotoxy(30,07);
		printf("\n                              =====================\n");
		gotoxy(30,9);
		printf("[1] Supplier Entry");
        gotoxy(30,11);
        printf("[2] Supplier List");
        gotoxy(30,13);
        printf("[3] Supplier Update");
        gotoxy(30,15);
        printf("[4] Supplier Remove");
        gotoxy(30,17);
        printf("[5] Supplier Search");
        gotoxy(30,19);
        printf("[6] Return Main Menu");
        gotoxy(30, 20);
        printf("=====================\n");
        gotoxy(30, 21);
        printf("Your Choice: ");
        fflush(stdin);
        choice  = getche();
        switch(choice)


        {
        case '1':
            system("cls");
            fseek(fp,0,SEEK_END);

            another = 'y';
            while(another == 'y')
            {
                printf("\nEnter name: ");
                scanf("%s",e.name);
                printf("\nEnter age: ");
                scanf("%d", &e.age);
                printf("\nEnter Address:");
                scanf("%s",e.address);
                printf("\nEnter basic salary: ");
                scanf("%f", &e.bs);

                fwrite(&e,recsize,1,fp);

                printf("\nAdd another record(y/n) ");
                fflush(stdin);
                another = getche();
            }
            break;
        case '2':
            system("cls");
            printf("Supplier List (name, age, address, salary)");
            rewind(fp);
            while(fread(&e,recsize,1,fp)==1)
            {

                printf("\n\n%s \t\t%d \t%s \t%.2f",e.name,e.age,e.address,e.bs); /// print the name, age and basic salary
            }
            getch();
            break;

        case '3':
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("Enter the supplier name to modify: ");
                scanf("%s", suppliername);
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)
                {
                    if(strcmp(e.name,suppliername) == 0)
                    {
                        printf("\nEnter new name,age,address and bs: ");
                        scanf("%s%d%s%f",e.name,&e.age,&e.address,&e.bs);
                        fseek(fp,-recsize,SEEK_CUR);
                        fwrite(&e,recsize,1,fp);
                        break;
                    }
                }
                printf("\nModify another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '4':
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("\nEnter name of supplier to delete: ");
                scanf("%s",suppliername);
                ft = fopen("Temp.dat","wb");
                rewind(fp);
                while(fread(&e,recsize,1,fp) == 1)
                {
                    if(strcmp(e.name,suppliername) != 0)
                    {
                        fwrite(&e,recsize,1,ft);
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("SPL.DAT");
                rename("Temp.dat","SPL.DAT");
                fp = fopen("SPL.DAT", "rb+");
                printf("Delete another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '5':
        system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("\nEnter name of the supplier to search: ");
                scanf("%s",suppliername);
                ft = fopen("Temp.dat","wb");
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)
            {

                printf("\n\n%s \t\t%d \t%s \t%.2f",e.name,e.age,e.address,e.bs); /// print the name, age and basic salary
            }
            printf("Search another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '6':
            fclose(fp);
            menu();
        }
    }
}
int customer()
{
    FILE *fp, *ft;
    char another, choice;

    struct customer
    {
        char name[40];
        int age;
        char id[20];
        char address[20];
    };

    struct customer e;

    char customername[40];;

    long int recsize;

    fp = fopen("CST.DAT","rb+");
    if(fp == NULL)
    {
        fp = fopen("CST.DAT","wb+");
        if(fp == NULL)
        {
            printf("Cannot open file");
            exit(1);
        }
    }
    recsize = sizeof(e);

    while(1)
    {

        system("cls");

        printf(" \n  ::::::::::::::::::::::::::  | CUSTOMER MENU |  :::::::::::::::::::::::::: \n");
		gotoxy(30,07);
		printf("\n                              =====================\n");
		gotoxy(30,9);
		printf("[1] Customer Entry");
        gotoxy(30,11);
        printf("[2] Customer List");
        gotoxy(30,13);
        printf("[3] Customer Update");
        gotoxy(30,15);
        printf("[4] Customer Remove");
        gotoxy(30,17);
        printf("[5] Customer Search");
        gotoxy(30,19);
        printf("[6] Return Main Menu");
        gotoxy(30, 20);
        printf("=====================\n");
        gotoxy(30, 21);
        printf("Your Choice: ");
        fflush(stdin);
        choice  = getche();
        switch(choice)


        {
        case '1':
            system("cls");
            fseek(fp,0,SEEK_END);

            another = 'y';
            while(another == 'y')
            {
                printf("\nEnter name: ");
                scanf("%s",e.name);
                printf("\nEnter age: ");
                scanf("%d", &e.age);
                printf("\nEnter ID:");
                scanf("%s",e.id);
                printf("\nEnter address: ");
                scanf("%s", &e.address);

                fwrite(&e,recsize,1,fp);

                printf("\nAdd another record(y/n) ");
                fflush(stdin);
                another = getche();
            }
            break;
        case '2':
            system("cls");
            printf("Customer List (name, age, id, address)");
            rewind(fp);
            while(fread(&e,recsize,1,fp)==1)
            {

                printf("\n\n%s \t\t%d \t%d \t%s",e.name,e.age,e.id,e.address);
            }
            getch();
            break;

        case '3':
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("Enter the customer name to modify: ");
                scanf("%s", customername);
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)
                {
                    if(strcmp(e.name,customername) == 0)
                    {
                        printf("\nEnter new name,age,id and address: ");
                        scanf("%s%d%d%s",e.name,&e.age,&e.id,&e.address);
                        fseek(fp,-recsize,SEEK_CUR);
                        fwrite(&e,recsize,1,fp);
                        break;
                    }
                }
                printf("\nModify another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '4':
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("\nEnter name of customer to delete: ");
                scanf("%s",customername);
                ft = fopen("Temp.dat","wb");
                rewind(fp);
                while(fread(&e,recsize,1,fp) == 1)
                {
                    if(strcmp(e.name,customername) != 0)
                    {
                        fwrite(&e,recsize,1,ft);
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("CST.DAT");
                rename("Temp.dat","CST.DAT");
                fp = fopen("CST.DAT", "rb+");
                printf("Delete another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '5':
        system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("\nEnter name of the customer to search: ");
                scanf("%s",customername);
                ft = fopen("Temp.dat","wb");
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)
            {

                printf("\n\n%s \t\t%d \t%d \t%s",e.name,e.age,e.id,e.address);
            }
            printf("Search another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '6':
            fclose(fp);
            menu();
        }
    }
}

void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="kaziemad";
    char pass[10]="emad123";
    do
{

    printf("\n  ::::::::::::::::::::::::::  LOGIN FORM  ::::::::::::::::::::::::::  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0;
		if(strcmp(uname,"KaziEmad")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       WELCOME TO MEDICAL STORE MANAGEMENT SYSTEM !!!! LOGIN IS SUCCESSFUL");
	    printf("\n LOADING PLEASE WAIT... \n");
    for(i=0; i<3; i++)
    {
        printf(".");
        Sleep(500);
    }
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();
	menu();
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}

int main()
{
    login();
}
