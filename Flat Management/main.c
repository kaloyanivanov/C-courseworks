#include <stdio.h>
#include <stdlib.h>
# include "flat.h"
# include <string.h>
#include <time.h>
int main()
{ create_bin();
    entry ** arr=NULL;
    while (1){
      system ("cls");
printf("Welcome to the menu.\n To load data enter 1,\n to add new people to apartment enter 2,\n to calculate tax for apartments enter 3,\n to calculate the best elevator position enter 4,\n to free apartment enter 5,\n To exit the program enter random character.");
int choise;
scanf("%d", &choise);
switch (choise){
    case 1:
       arr=load_data();
      break;

    case 2:
      move_to_apt(arr);
      break;

    case 3:
      tax(arr);
      break;
    case 4:
      lift(arr);
      break;
    case 5:
     free_apt(arr);
      break;
    default:
      exit(0);
      }


    }
    return 0;
}

entry ** load_data(){
    flag=1;
    FILE *fp;
    if((fp=fopen("binary.bin","rb+"))==NULL)  exit(1);
    fread (&floors, sizeof(int), 1, fp );
    fread (&apartments, sizeof(int), 1, fp );
    entry **arr = (entry **)malloc(floors * sizeof(entry *));
    if(arr == NULL)
    {
        printf("\nError!");
        fflush(stdin);
        getchar();
        free(arr);
        return arr;
    }
    int i,j;

        for (i = 0; i < floors; i++){
    arr[i] = (entry *)malloc((apartments/floors) * sizeof(entry));
          if(arr[i]== NULL)
    {
        printf("\nError!");
        fflush(stdin);
        getchar();
        exit(1);
    }

    }


     for (i = 0; i <  floors; i++) {
            for (j = 0; j < (apartments/floors); j++)
         {
           fread (&arr[i][j].apt_num, sizeof(int), 1, fp );
           fread (&arr[i][j].room, sizeof(int), 1, fp );
           fread (&arr[i][j].adults, sizeof(int), 1, fp );
           fread (&arr[i][j].kids, sizeof(int), 1, fp );
           fread (&arr[i][j].size_surname, sizeof(int), 1, fp );
           fread (arr[i][j].surname, 1, arr[i][j].size_surname+1 , fp);
           fread (arr[i][j].date, 1, 11 , fp);
           fread (&arr[i][j].rent, sizeof(float), 1, fp);
           if (arr[i][j].adults==0)clear_data(arr,i,j);
         }

         }

        return arr;
}


void move_to_apt(entry** arr){
    if (arr==NULL) return;
    int floor, apt;
    printf("Enter floor\n");
    scanf("%d", &floor);
    printf("Enter apartment\n");
    scanf("%d", &apt);
    if(floor==0||floor>floors||apt>apartments||apt==0){
    printf("Error non-valid data entered.");
    fflush(stdin);
    getchar();
    return; }
    floor=floor-1;
    int apartment=0;
    while(arr[floor][apartment].apt_num!=apt) apartment++;
    if (arr[floor][apartment].adults==0){
     printf("Enter number of adults:\n");
     scanf("%d", &arr[floor][apartment].adults);
     printf("Enter number of kids:\n");
     scanf("%d", &arr[floor][apartment].kids);
     printf("Enter surname:\n");
     fflush(stdin);
     gets(arr[floor][apartment].surname);
     arr[floor][apartment].size_surname=strlen(arr[floor][apartment].surname);
     get_date(arr, floor, apartment);
     printf("Enter rent:\n");
     scanf("%f",&arr[floor][apartment].rent);
     rewrite_file(arr,floor, apartment);
     return;
    }
    else {printf("Error apartment not empty.");
    fflush(stdin);
    getchar();
    return;
    }
}

void tax(entry** arr){
    if (arr==NULL) return;
    int i,j;
    for (i = 0; i <  floors; i++) {
    for (j = 0; j < (floors/apartments); j++)
        {   int sum;
            if(i<=1) sum=(3*arr[i][j].adults)+arr[i][j].kids;

            else sum=(5*arr[i][j].adults)+(3*arr[i][j].kids);
            printf("Apartment %d's tax is %d lv.\n", arr[i][j].apt_num, sum);

        }
}
fflush(stdin);
getchar();

return;
}


void lift(entry** arr){
    if (arr==NULL) return;
    int i,j, sum=0,max=0,floor, tot_people[floors];
    if (floors==1||floors==2) return;
    for (i = 0; i < floors; i++)
    {
        for (j = 0; j < (floors/apartments); j++)
        {
            sum=sum+arr[i][j].adults+arr[i][j].kids;

        }
        tot_people[i]=sum;
        sum=0;
    }
    for (i = 1; i < floors-1; i++){
        sum=tot_people[i-1]+tot_people[i]+tot_people[i+1];
        if(sum>max) {
        max=sum;
        floor=i+1;
        }
    }
    printf("The elevator must stay at floor %d.", floor);
    fflush(stdin);
    getchar();
    return;
}


void free_apt(entry** arr){
    if (arr==NULL) return;
   flag=2;
    int apt,i,j;
    printf("Enter apartment number to free:\n");
    scanf("%d",&apt);
    if(apt==0||apt>apartments){
    printf("Error non-valid data entered.");
    fflush(stdin);
    getchar();
    return; }
    for (i = 0; i < floors; i++)
        {
            for (j = 0; j < (apartments/floors); j++)
            {
                if (arr[i][j].apt_num==apt) break;
            }
    if (arr[i][j].apt_num==apt) break;
        }
    clear_data(arr, i, j);
    rewrite_file(arr, i, j);
    return;
}


void create_bin(){
 FILE *fp;
    if((fp=fopen("binary.bin","wb"))==NULL)  exit(1);
    int floors=4;
    apartments=4;
    int apt_num=1;
    int room=3;
    int adults=0;
    int kids=1;
    int size_surname=9;
    char surname [50]="some name";
    char date[11]="11.11.1111";
    float rent=500;

    fwrite (&floors, sizeof(int), 1, fp);
    fwrite (&apartments, sizeof(int), 1, fp);
    int i;
    for(i = 0;i < apartments; i++){

    fwrite (&apt_num, sizeof(int), 1, fp);
    fwrite (&room, sizeof(int), 1, fp);
    fwrite (&adults, sizeof(int), 1, fp);
    fwrite (&kids, sizeof(int), 1, fp);
    fwrite (&size_surname, sizeof(int), 1, fp);
    fwrite (surname, 1, size_surname+1, fp);
    fwrite (date, 1, 11, fp);
    fwrite (&rent, sizeof(float), 1, fp);
    apt_num++;
    adults++;
    }
    fclose(fp);
    return;
}


void clear_data(entry ** arr, int i, int j){
    arr[i][j].adults=0;
    arr[i][j].kids=0;
    arr[i][j].size_surname=5;
    strcpy(arr[i][j].surname,"none");
    if(flag==2) get_date(arr, i, j);
    arr[i][j].rent=0;


}

void get_date(entry ** arr, int i, int j){
    time_t t = time(NULL);
    struct tm tm= *localtime(&t);
    char buffer1[11],buffer2[4],buffer3[6];
    tm.tm_year=tm.tm_year + 1900;
    tm.tm_mon=tm.tm_mon + 1;
    itoa (tm.tm_mday,buffer1,10);
    itoa (tm.tm_mon,buffer2,10);
    itoa (tm.tm_year,buffer3,10);
    buffer1[3]=buffer1[1];
    buffer1[1]=buffer1[0];
    buffer1[0]='0';
    buffer1[2]='.';
    buffer2[3]=buffer2[1];
    buffer2[1]=buffer2[0];
    buffer2[0]='0';
    buffer2[2]='.';
    strcat(buffer1,buffer2);
    strcat(buffer1,buffer3);
    strcpy(arr[i][j].date, buffer1);
    }


void rewrite_file(entry ** arr, int i, int j){
     char choise;
     printf("Want to save changes to file Y/N?");
     fflush(stdin);
     scanf("%c", &choise);
     if(choise!='Y') return;
     FILE *fp;
        if((fp=fopen("binary.bin","wb"))==NULL)  exit(1);
    fwrite (&floors, sizeof(int), 1, fp);
    fwrite (&apartments, sizeof(int), 1, fp);

 for (i = 0; i < floors; i++)
        {
            for (j = 0; j < (apartments/floors); j++)
            {
    fwrite (&arr[i][j].apt_num, sizeof(int), 1, fp);
    fwrite (&arr[i][j].room, sizeof(int), 1, fp);
    fwrite (&arr[i][j].adults, sizeof(int), 1, fp);
    fwrite (&arr[i][j].kids, sizeof(int), 1, fp);
    fwrite (&arr[i][j].size_surname, sizeof(int), 1, fp);
    fwrite (arr[i][j].surname, 1, arr[i][j].size_surname+1, fp);
    fwrite (arr[i][j].date, 1, 11, fp);
    fwrite (&arr[i][j].rent, sizeof(float), 1, fp);

            }

        }



fclose(fp);

 }

