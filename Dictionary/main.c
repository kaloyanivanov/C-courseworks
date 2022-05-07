#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
void pregled ();
void vavedi ();
void iztrii ();
void clear(char* promenen, char* clean);

char kraen1[1000];
char kraen2[1000];
char kraen3[1000];

int main()

{ menu();

    return 0;
}
void menu(){
     int menu;
   printf("Dobre doshli v menuto!\nZa pregled na rechnika vavedete 1\nZa da dobavite duma vavedete 2\nZa da iztriete duma vavedete 3\n");
   scanf("%d", &menu);
  switch(menu)
  { case 1: pregled();
        break;
    case 2: vavedi();
        break;

    case 3: iztrii();
        break;  }
}
void pregled()
{ system("cls");
extern char kraen1[1000];
extern char kraen2[1000];
extern char kraen3[1000];
int back=1;
int ezik;
int ezik2;
do {
printf("Mozhe da pregledate dumite samo na dva ezika ili na vsichki ednovremenno.\n\tVavedete 1 i 2, ako iskate da pregledate dumite si na parvite dva ezika\n\tVavedete 1 i 3 za parvi i treti ezik\n\tVavedete 2 i 3, za da pregledate dumite si na vtori i treti ezik\n\tZa da pregledate dumite na vsichki ezici vavedete 3\n");
scanf("%d", &ezik);
if(ezik==1||ezik==2){
scanf("%d", &ezik2);
if(ezik==1&&ezik2==2){
puts(kraen1);
puts(kraen2);}
if(ezik==1&&ezik2==3){
puts(kraen1);
puts(kraen3);}
if(ezik==2&&ezik2==3){
puts(kraen2);
puts(kraen3);}
}
else if(ezik==3){
puts(kraen1);
puts(kraen2);
puts(kraen3);}
char izbor[3];
  izbor[3]='\0';
printf("Ako iskate da pregledate dumite na drugi ezici duma napishete da,\nako iskate da se varnete kum menuto vavedete proizvolen tekst.\n");
  scanf("%s", izbor);
  if(!strcmp(izbor,"da")){back=1;}
   else{back=0;}
   }
while(back);
system("cls");
menu();
}

void vavedi ()
{ system("cls");
int back=1, space1, space2, space3;
char ezik1[50];
char ezik2[50];
char ezik3[50];
ezik1[0]= '\0';
ezik2[0]= '\0';
ezik3[0]= '\0';
extern char kraen1[1000];
extern char kraen2[1000];
extern char kraen3[1000];
kraen1[0]='\0';
kraen2[0]='\0';
kraen3[0]='\0';
do {printf("Vavedete dumata na 1 ezik:\n");
 fflush(stdin);
 gets(ezik1);
 space1=strlen(ezik1);
 ezik1[space1]= ' ';
strcat(kraen1,ezik1);
ezik1[0]= '\0';
 printf("Vavedete dumata na 2 ezik:\n");
fflush(stdin);
 gets(ezik2);
 space2=strlen(ezik2);
 ezik2[space2]= ' ';
 strcat(kraen2,ezik2);
 ezik2[0]= '\0';
printf("Vavedete dumata na 3 ezik:\n");
  fflush(stdin);
 gets(ezik3);
 space3=strlen(ezik3);
 ezik3[space3]= ' ';
 strcat(kraen3,ezik3);
 ezik3[0]= '\0';
  char izbor[3];
  izbor[3]='\0';
printf("Ako iskate da vavedete nova duma napishete da, ako iskate da se varnete kum menuto vavedete proizvolen tekst.\n");
  scanf("%s", izbor);
  if(!strcmp(izbor,"da")){back=1;}
  else{back=0;}
  }
  while(back);
system("cls");
menu();

}
void iztrii ()
{ system("cls");
extern char kraen1[1000];
extern char kraen2[1000];
extern char kraen3[1000];
char clean[50];
clean[0]= '\0';
int back=1;
do {printf("Vavedete duma, koiato iskate da iztriete na daden ezik\n");
fflush(stdin);
gets(clean);
if(strstr(kraen1, clean)){
clear(kraen1, clean);}
else if(strstr(kraen2, clean)){
clear(kraen2, clean);}
else if(strstr(kraen3, clean)){
clear(kraen3, clean);}
else(menu());
char izbor[3];
izbor[3]='\0';
printf("Ako iskate da iztriete druga duma napishete da, ako iskate da se varnete kum menuto vavedete proizvolen tekst.\n");
  scanf("%s", izbor);
  if(!strcmp(izbor,"da")){back=1;}
   else{back=0;}}
while(back);
system("cls");
menu();
}

void clear(char* promenen,char* clean){
int i, j = 0, k = 0,n = 0;
int flag = 0;
char vremenen[1000];
for(i=0; promenen[i]!= '\0'; i++){
k = i;
while(promenen[i]==clean[j]){
i++,j++;
if(j==strlen(clean)){
flag=1;
 break;}}
j=0;
if(flag==0){i=k;}
else (flag=0);
vremenen[n++]=promenen[i];}
vremenen[n]= '\0';
memmove(promenen, vremenen, n);
promenen[n]= '\0';
}


