#ifndef FLAT_H_INCLUDED
#define FLAT_H_INCLUDED

typedef struct data{
int apt_num;
int room;
int adults;
int kids;
int size_surname;
char surname [50];
char date[11];
float rent;

}entry;

int floors, apartments,flag;

entry ** load_data ();
void move_to_apt(entry ** arr);
void tax(entry** arr);
void lift(entry** arr);
void free_apt(entry** arr);
void create_bin();
void clear_data(entry ** arr, int i, int j);
void get_date(entry ** arr, int i, int j);
void rewrite_file(entry ** arr, int i, int j);
#endif // FLAT_H_INCLUDED
