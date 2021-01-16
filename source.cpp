#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "auth.cpp"


struct User {   //doubly linked list buat data user
    char name[255];
    char pass[255];
    User *prev, *next;
} *head, *tail;

User *createUser(const char *name, const char *pass) {
    User *newUser = (User*)malloc(sizeof(User));
    strcpy(newUser->name, name);
    strcpy(newUser->pass, pass);
     newUser->prev = NULL;
    newUser->next = NULL;
    return newUser;

}

void pushHead(const char *name,const char *pass) {
    User *temp = createUser(name,pass);
    

    if (!head) {
        head = tail = temp;
    }else {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
   
}

void printListNameMenu() {
    User *curr = head;
    int nomor = 1;
    while(curr) {
        printf("%d.\t%s\n",nomor,curr->name);
        curr = curr-> next;
        nomor++;
    }
    printf("NULL\n");
}


void mainMenu() {
    printf("Oo=====================================oO\n");
    printf("               STUDY NETWORK                \n");
    printf("Oo=====================================oO\n");
    printf("\n");
    printf("[All User]\n");
    printf("No.   Username\n");
    printListNameMenu();    //data user
    printf("-----------------------------------------\n");
    printf("[1] Register\n");
    printf("[2] Login\n");
    printf("[3] Exit\n");
    printf("-----------------------------------------\n");
    printf(" Press 0 and enter to abort an operation\n");
    printf("-----------------------------------------\n");
    printf(">> ");
}

void registermenu(){
    char namaUser[255];
    char passUser[255];
    printf("-----------------------------------------\n");
    printf("Please type in your username [lowercase||1..24]:");
    scanf("%s",namaUser);
    getchar();
    printf("Please type in your password [lowercase||1..24]:");
    scanf("%s",passUser);
    getchar();
    
    pushHead(namaUser,passUser);
    printf("---Registration Successfull---\n");
    printf("Press enter to continue\n");
    
    getchar();
}


    
   void loginmenu() {
    char inputUser[255];    //inputan username
    char inputPass[255];    //inputan password

    printf("-----------------------------------------\n");
    printf("Username: ");
    scanf("%[^\n]",inputUser);
    getchar();
   

    puts("Password: ");
    scanf("%[^\n]",inputPass);
    getchar();
    bool accepted = false;     //kalo berhasil pass sama user sama
    
    User *curr = head;
    while(curr){
        if(strcmp(curr->name,inputUser)==0 && strcmp(curr->pass,inputPass)==0){
            accepted =  true;
            break;
        }else if(strcmp(curr->name,inputUser)!=0 && strcmp(curr->pass,inputPass)==0){
            accepted=false;
            break;
        }else if(strcmp(curr->name,inputUser)==0 && strcmp(curr->pass,inputPass)!=0){
            accepted = false;
            break;
        }else{
            accepted = false;
            break;
        }
    }
    if (accepted == true) {
         printf("--- Login Successfull ---\n");
         printf("Press enter to continue\n");
        getchar();
        return;
    }else if(accepted == false) {
        printf("--- Data Not Registered ---\n");
        printf("Press enter to continue\n");
        getchar();
        return;
    }
    
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
        scanf("%d",&menus);getchar();
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