#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct User {   //doubly linked list buat data user
    char name[255];
    char pass[255];
    User *prev, *next;
} *head, *tail;

User *createUser(const char *name, const char *pass) {
    User *newUser = (User*)malloc(sizeof(User));
    strcpy(newUser->name, name);
    strcpy(newUser->pass, pass);
    return newUser;
}

void mainMenu() {
    printf("Oo=====================================oO\n");
    printf("               STUDY NETWORK                \n");
    printf("Oo=====================================oO\n");
    printf("\n");
    printf("[All User]\n");
    printf("No.   Username\n");
    // data user
    printf("-----------------------------------------\n");
    printf("[1] Register\n");
    printf("[2] Login\n");
    printf("[3] Exit\n");
    printf("-----------------------------------------\n");
    printf(" Press 0 and enter to abort an operation\n");
    printf("-----------------------------------------\n");
    printf(">>");
}

void registermenu(){
    printf("-----------------------------------------\n");

    return;
}

void loginmenu() {
    //login
    return;
}
bool exitCommand() {
    return false;
}

int main() {
    // data user tampung di file txt
    // save pas keluar
    int menus;
    bool repeat = true;
    
    while (repeat) {
        system("cls");
        mainMenu();
        scanf("%d",&menus);
        switch(menus) {
            case 0: break;
            case 1: registermenu(); break;
            case 2: loginmenu(); break;
            case 3: repeat = exitCommand(); break;
            default: printf("Menu tidak tersedia\n"); break;
        }
    }
    
    return 0;
}