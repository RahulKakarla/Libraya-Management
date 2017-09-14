#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define max_book 25

void main_menu();

void admin();
void user();

void lend_book();
void return_book();
void search();

void add_book();
void add_user();
void book_log();

void today_search();
void id_search();
void fname_search();
void ldate_search(); 
void rdate_search();


int file_line(char f_name[20]); 