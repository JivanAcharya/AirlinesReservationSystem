#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void gotoxy(int,int);
void fullscreen();
void screenshot();
void login_user ();
void registration ();
void login_options ();
void newflight();
void showticket();
void admin();
void login();
void show_details();
void about();


COORD coord = {0,0};

void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void fullscreen()
{
keybd_event(VK_MENU,0x38,0,0);
keybd_event(VK_RETURN,0x1c,0,0);
keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}
void screenshot()
{
keybd_event(VK_LWIN,0x5B,0,0);
keybd_event(VK_SNAPSHOT,0x2C,0,0);
keybd_event(VK_SNAPSHOT,0x2C,KEYEVENTF_KEYUP,0);
keybd_event(VK_LWIN,0x5B,KEYEVENTF_KEYUP,0);
}

struct date
{
    int dd;
    int mm;
    int yyyy;
};

//structure for adding new passenger
struct passenger
{
    char name[30];
    char address[50];
    char email[100];
    char gender;
    char username[50];
    char password[50];
};


struct newflight
{
    char uname[20];
    char destination[20];
    char location[20];
    char nationality[20];
    int no;
    float price;
    float total;
    struct date d1;
};

//global declarations
char user[5];
char pw[5];
struct newflight f;

void welcome_screen()
{
	system("cls");
	int j;
	char ch,sh[50]={"      WELCOME TO AIRLINES RESERVATION SYSTEM     "};
gotoxy(0,3);
for(j=0;j<211;j++)
{
 usleep(0.001);
 printf("_");
}
gotoxy(60,4);
for(j=0;j<20;j++)
{
Sleep(5);
printf("\4");
}
for(j=0;j<50;j++)
{
Sleep(25);
printf("%c",sh[j]);
}
for(j=0;j<20;j++)
{
Sleep(5);
printf("\4");
}
printf("\n");

gotoxy(0,5);
for(j=0;j<211;j++)
{
 usleep(0.001);
 printf("_");
}
int   sp=39;
   char ca;
   gotoxy(81,15);
   printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2   MAIN MENU  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
   gotoxy(81,18);
   printf("\xAF\xAF 1. Passenger Login / Sign up \n");
   gotoxy(81,21);
   printf("\xAF\xAF 2. Admin Login\n");
   gotoxy(81,24);
   printf("\xAF\xAF 3. About Program \n");
   gotoxy(81,27);
   printf("\xAF\xAF 4. Exit\n");
   gotoxy(81,29);
   printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
   for(j=15;j<30;j++)
   {
       gotoxy(125,j);
       printf("\xB2\xB2");
   }
   for(j=16;j<30;j++)
   {
       if(j!=18&&j!=21&&j!=24&&j!=27)
       {
          gotoxy(81,j);
          printf("\xB2\xB2");
       }
   }
   gotoxy(0,35);
   printf("\xAF\xAF\xAF Enter your choice : \n");

   while(1){
        gotoxy(28,35);
   ca=tolower(getche());
	switch(ca)
	{
	   case '1':
	       login_options();
	       break;
	   case '2':
	       admin();
	       break;
      case '3':about();
      case '4':
          exit(0);
      default:gotoxy(55,sp++);
               printf("\aIncorrect Input!!!!! please press proper keys... ");
	}
}
}



void login_options (void)
{
    ShowWindow( GetConsoleWindow() , SW_MAXIMIZE);
    system("cls");
    int option;
    gotoxy(75, 10);
    printf("1.) Register\n");
    gotoxy(75, 13);
    printf("2.) Login\n");
    gotoxy(75,16);
    printf("3.) Return to menu");
    gotoxy(75, 19);
    printf("Press 1 or 2 or  3\t");
    scanf("%d",&option);

    getche();

    if(option == 1)
        {
            system("CLS");
            registration();
        }

    else if(option == 2)
        {
            system("CLS");
            login_user();
        }
        else
        {
            system("cls");
            welcome_screen();
        }
}

//function to login by an existing passenger
void login_user (void)
{
    char username[30],password[20],ch;
    FILE *log;

    log = fopen("passenger.txt","r");
      if (log == NULL)
    {
        printf("File cant't be opened or created");
        exit(0);
    }

    struct passenger p1;

    system("cls");
    gotoxy(85, 12);
    printf("||   PASSENGER LOGIN   ||");
    gotoxy(77, 17);
    printf("Username: ");
    scanf("%s",&username);
    gotoxy(77, 20);
    printf("Password: ");
    scanf("%s",&password);
//    int integer=0;
while(fread(&p1,sizeof(p1),1,log))
        {
//            printf("\n%d",integer);
//      integer++;
        if(strcmp(username,p1.username)==0 && strcmp(password,p1.password)==0)

            {
                gotoxy(77, 23);
                printf("-_-_- Successful Login -_-_-");
                getch();
                newflight();
                break;
            }
        }

          if(strcmp(username,p1.username)!=0 && strcmp(password,p1.password)!=0)
            {
                gotoxy(77, 23);
                printf("**  Incorrect Login Details  ***  Please enter the correct credentials  **");
                gotoxy(77, 25);
                printf("Do you want to retry? (y/n):");
                gotoxy(110, 25);
                fflush(stdin);
                scanf("%c", &ch);
                if (ch == 'y' || ch == 'Y')
                {
                    login_user();
                }
                else if(ch=='n' || ch=='N' )
                {
                    exit(0);
                }
            }



            fflush(stdin);
            fflush(log);
            fseek(stdin,0,SEEK_END);

    fclose(log);
}

//function to add new passenger
void registration(void)
{
    char ch;
     struct date d;
    FILE *log;

    log=fopen("passenger.txt","a+");
    if (log == NULL)
    {
        printf("File cant't be opened or created");
        exit(0);
    }

    struct passenger p;

        system("cls");
        fflush(stdin);
        gotoxy(85, 8);
        printf("||   PASSENGER REGISTRATION   ||");
        gotoxy(65, 13);
        printf("Name:");
        gotoxy(65, 16);
        printf("Address:");
        gotoxy(65, 19);
        printf("Gender (M/F):");
        gotoxy(65, 22);
        printf("Email:");
        gotoxy(65, 25);
        printf("Date of Birth(dd/mm/yyyy):");
        gotoxy(65, 28);
        printf("Username:");
        gotoxy(65, 31);
        printf("Password:");
        gotoxy(99, 13);
        scanf(" %[^\n]s", p.name);
        gotoxy(99, 16);
        scanf(" %[^\n]s", p.address);
        gotoxy(99, 19);
        scanf(" %c", &p.gender);
        gotoxy(99, 22);
        scanf(" %[^\n]s", p.email);
        gotoxy(99, 25);
        scanf("%d/%d/%d", &d.dd, &d.mm, &d.yyyy);
        gotoxy(99, 28);
        scanf("%s", p.username);
        gotoxy(99, 31);
        scanf("%s", p.password);


    fwrite(&p,sizeof(p),1,log);
    fclose(log);

    printf("\nRegistration Successful!\n");
    printf("Press any key to continue...");
        getche();
    system("CLS");
    login_user();
}


void newflight()
{


    char c,ch;

    f.price=2000;

    FILE *fptr;
    selection:

    system("cls");

    gotoxy(2,3);
    printf("\n\n\tDear User \n\n\n\tFill up the details for the flight");

    fptr=fopen("destination.txt","a+");
    gotoxy(65, 13);
    printf("Name :");
    gotoxy(65, 16);
    printf("Destination : ");
    gotoxy(65, 19);
    printf("Current Location : ");
    gotoxy(65, 22);
    printf("Date of departure : ");
    gotoxy(65, 25);
    printf("No of Passengers : ");
    gotoxy(65,28);
    printf("Nationality : ");
    fflush(stdin);
    gotoxy(99, 13);
    scanf(" %[^\n]s",f.uname);
    gotoxy(99, 16);
    scanf(" %[^\n]s", f.destination);
    gotoxy(99, 19);
    scanf(" %[^\n]s", f.location);
    gotoxy(99, 22);
    scanf(" %d/%d/%d", &f.d1.dd, &f.d1.mm, &f.d1.yyyy);
    gotoxy(99, 25);
    scanf("%d",&f.no);
    gotoxy(99,28);
    scanf("%s",f.nationality);
    f.total=f.no*f.price;
    gotoxy(50, 30);
    printf("Your total amount for %d seats is Rs.%.2f ",f.no,f.total);
    gotoxy(50, 33);
    fflush(stdin);
    printf("Do you want to confirm your flight ( Y / N )  ?");
    c=tolower(getchar());
    if(c=='y')
    {
         fwrite(&f,sizeof(f),1,fptr);
    }
    else
    {
        gotoxy(50,35);
        printf("Redirecting");
        for(int i=0;i<3;i++)
        {
            Sleep(1000);
            gotoxy(63+i,35);
            printf(".");
        }
        goto selection;
    }
    fclose(fptr);
    fptr=fopen("destination.txt","r");
    fseek(fptr,0,SEEK_END);
    fread(&f,sizeof(f),1,fptr);
    label1:
    system("cls");
    gotoxy(65, 13);
    printf("Name :");
    gotoxy(65, 16);
    printf("Destination : ");
    gotoxy(65, 19);
    printf("Current Location : ");
    gotoxy(65, 22);
    printf("Date of departure : ");
    gotoxy(65, 25);
    printf("No of Passengers : ");
    gotoxy(65,28);
    printf("Nationality : ");
    gotoxy(65,31);
    printf("Total price");
    gotoxy(99, 13);
    printf("%s",f.uname);
    fflush(stdin);
    gotoxy(99, 16);
    printf(" %s", f.destination);
    gotoxy(99, 19);
    printf(" %s", f.location);
    gotoxy(99, 22);
    printf(" %d/%d/%d", f.d1.dd, f.d1.mm, f.d1.yyyy);
    gotoxy(99, 25);
    printf("%d",f.no);
    gotoxy(99,28);
    printf("%s",f.nationality);
    gotoxy(99,31);
    printf("%.2f",f.total);
    fclose(fptr);
    gotoxy(20,35);
    printf("Press S to take screenshot");
    gotoxy(20,37);
    printf("Press R to return to menu");
    gotoxy(20,39);
    printf("Press E to exit");
    gotoxy(30,39);
    ch=tolower(getche());
    switch(ch)
    {
    case 's':
        screenshot();
        goto label1;
    case 'r':
        welcome_screen();
        break;
    case 'e':
        exit(0);

    }
    welcome_screen();
}


void login()
{

    gotoxy(50, 7);
    printf("Please enter the admin username and password below.\n");
    gotoxy(50, 9);
    printf("Username: ");
    scanf("%s", &user);
    gotoxy(50, 10);
    printf("Password: ");
    scanf("%s", &pw);

    if (strcmp(user, "admin") == 0 && strcmp(pw, "admin") == 0)
    {
        gotoxy(65, 12);
        printf("Login successful! :) \n");
        fseek(stdin, 0, SEEK_END);
    }
    else
    {
        system("cls");

        printf("\n");

        printf("\n");

        printf("\t\t\t\t\t\t\t\tWELCOME TO ADMIN LOGIN ");

        printf("\n");

        printf("\n");

        printf("\t\t\t\t\t\t\t\t");
        for (int i = 0; i < 22; i++)
        {
            printf("\xB2");
        }
        printf("\n");

        printf("\n");
        gotoxy(65, 12);
        printf("Invalid credentials.");
        login();
    }
    int choice;
    gotoxy(20,16);
    printf("Select one of the options ");
    gotoxy(22,18);
    printf("1.) Show all user details");
    gotoxy(22,20);
    printf("2.) Return to Menu ");
    gotoxy(22,22);
    printf("3.) Exit");
    gotoxy(22,24);
    scanf("%d",&choice);
    switch(choice)
    {
    case(1):
        show_details();

    case(2):
        welcome_screen();
        break;
    case(3):
        exit(0);
    }

}

void admin()
{
    system("cls");

    printf("\n");

    printf("\n");

    printf("\t\t\t\t\t\t\t\tWELCOME TO ADMIN LOGIN ");


    printf("\n");

    printf("\n");

    printf("\t\t\t\t\t\t\t\t");
    for (int i = 0; i < 22; i++)
    {
        printf("\xB2");
    }
    printf("\n");

    printf("\n");

    login();
}

void show_details()
{
    system("cls");
    FILE *fptr;
    fptr=fopen("destination.txt","r");
    while(fread(&f,sizeof(f),1,fptr))
    {
   printf("\n");

    printf("\nName : %s",f.uname);
    printf("\nDestination : %s", f.destination);
    printf("\nCurrent Location : %s", f.location);
    printf("\nDate of departure : %d/%d/%d", f.d1.dd, f.d1.mm, f.d1.yyyy);
    printf("\nNo of passengers : %d",f.no);
    printf("\nNationality : %s",f.nationality);
    printf("\nTotal Price : %.2f",f.total);
    }
    getch();
    fclose(fptr);
}

void about()
{
    system("cls");
    printf("\n\n\n\tThis program is an Airlines Reservation System that is developed by : \n\t\xF Girban Adhikari\n\t\xF Jivan Acharya\n\t\xF Arjan Sapkota \n\t\xF Subarna Ghimire. ");
    printf("\n\n\t\xAFHere's something about the program: \n\n\t1. The Passenger Login/ Sign up Panel:\n\tAny passenger who already holds a registered account can login via his/her credentials \n\tand book the desired flights or check the summary of his/her booked flights through the passenger \n\tlogin panel. Any person who doesn't hold an account and desires to have one can also sign up pretty easily");
    printf("\n\n\t2: The Admin Login Panel:\n\t The Admin Login Panel gives admins the permission to check out the flights that have been booked\n\t by passengers.");
    printf("\n\n\t3: The About Program Panel:\n\tDisplays the information about the  program.");
    printf("\n\n\t4: The Exit Progaram Panel:\n\tExits the program*/");
    printf("\n\n\n\tPress any key to return to menu\n\n\t");
    getch();
    welcome_screen();
}


   int main()
   {
       system("COLOR F2");
       fullscreen();
       welcome_screen();
      return 0;
   }

