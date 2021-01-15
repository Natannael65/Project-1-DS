#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    //register
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