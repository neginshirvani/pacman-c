

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
//#include <ncurses.h>



clock_t start ;

char arr[1000][1000] ;
int info[1000];
int length,width,timer,food_number,counter=0;
int x1_pos = 0;
int y1_pos = 0;
int x2_pos = 0;
int y2_pos = 0;
int ch;
char tele_pos1[2];
char tele_pos2[2];
char p1[1000],p2[1000];
int player1_score=0,player2_score=0;
int barrier(int x , int y){
    if(arr[x][y] == ' ') {
        arr[x][y] = 'B';
    }


}

void block_maker()  {
    int i = 0 , j = 0;
    while(i <= counter) {
        j = i + 1;
        barrier(info[j], info[i]);
        i += 2;
    }
}

int teleport() {
    int i = 0;
    int random_x = 0;
    int random_y = 0;

    while(i < 1) {
        random_x = rand() % length;
        random_y = rand() % width;
        if(arr[random_y][random_x] == ' ') {
            arr[random_y][random_x] = 'T';
            tele_pos1[0] = random_y;
            tele_pos1[1] = random_x;
            ++i;
        }
    }
    i = 0;
    while(i < 1) {
        random_x = rand() % length;
        random_y = rand() % width;
        if(arr[random_y][random_x] == ' ') {
            arr[random_y][random_x] = 'T';
            tele_pos2[0] = random_y;
            tele_pos2[1] = random_x;
            ++i;
        }
    }
}

int big_food() {
    int i = 0;
    int random_x = 0;
    int random_y = 0;

    while(i < 1) {
        random_x = rand() % length;
        random_y = rand() % width;
        if(arr[random_y][random_x] == ' ') {
            arr[random_y][random_x] = 'F';
            ++i;
        }
    }
}

int random_food(int n){
    int i  = 0 ;
    int random_x = 0 ;
    int random_y = 0 ;

    while(i < n){
        random_x = rand() % length;
        random_y = rand() % width;
        if(arr[random_y][random_x] == ' '){
            arr[random_y][random_x] = '.' ;

            ++i;
        }
    }


}

int x1_change = 0;
int y1_change = 0;
int x2_change = 0;
int y2_change = 0;

void ai() {

    while(kbhit()){
        int key = getch();
        switch(key) {
                case 'w':
                    x1_change = 0;
                    y1_change = -1;
                    break;
                case 's':
                    x1_change = 0;
                    y1_change = 1;
                    break;
                case 'a':
                    x1_change = -1;
                    y1_change = 0;
                    break;
                case 'd':
                    x1_change = 1;
                    y1_change = 0;
                    break;

            }
    }
        int move_toward = rand() % 4;
        if (arr[y2_pos+1][x1_pos]=='.')//||arr[y2_pos][x1_pos+2]=='.'||arr[y2_pos][x1_pos+3]=='.')
            move_toward=1;
        else if (arr[y2_pos][x1_pos+1]=='.')//||arr[y2_pos][x1_pos+2]=='.'||arr[y2_pos][x1_pos+3]=='.')
            move_toward=3;
        else if (arr[y2_pos-1][x1_pos]=='.')//||arr[y2_pos-2][x1_pos]=='.'||arr[y2_pos-3][x1_pos]=='.')
            move_toward=0;
        else if (arr[y2_pos][x1_pos-1]=='.')//||arr[y2_pos][x1_pos-2]=='.'||arr[y2_pos][x1_pos-3]=='.')
            move_toward=2;
        switch(move_toward) {
            case 0:
                x2_change = 0;
                y2_change = -1;
                break;
            case 1:
                x2_change = 0;
                y2_change = 1;
                break;
            case 2:
                x2_change = -1;
                y2_change = 0;
                break;
            case 3:
                x2_change = 1;
                y2_change = 0;
                break;
        }
}



void movement_1(){
    while(kbhit()) {
        int key = getch();
        switch(key) {
            case '8':
                x2_change = 0;
                y2_change = -1;
                break;
            case '2':
                x2_change = 0;
                y2_change = 1;
                break;
            case '4':
                x2_change = -1;
                y2_change = 0;
                break;
            case '6':
                x2_change = 1;
                y2_change = 0;
                break;
            case 'w':
                x1_change = 0;
                y1_change = -1;
                break;
            case 's':
                x1_change = 0;
                y1_change = 1;
                break;
            case 'a':
                x1_change = -1;
                y1_change = 0;
                break;
            case 'd':
                x1_change = 1;
                y1_change = 0;
                break;

        }

    }
}

int mapp(int y , int x){

    int i = 0 ;
    int j = 0 ;
    int z = 0 ;
    int k = 0 ;
    system("cls") ;


    for(i = 0 ; i < x + 1 ; ++i){
        arr[z][i] = '!' ;
    }
    z += 1 ;

    for (z = 1 ; z < y + 1 ; ++z) {
        arr[z][0] = '!' ;
        for(k = 1 ; k < x - 1 ; ++k){
                arr[z][k] = ' ' ;
        }
        arr[z][x - 1] = '!' ;
    }

    for(i = 0 ; i < x + 1 ; ++i){
        arr[z - 2][i] = '!' ;
    }

    random_food(food_number);
    big_food();
    teleport();
    player();
    block_maker();


}

int show_mapp(int y , int x){
    system("cls") ;
    int i, j;
    for (j=0;j<y;++j){
        for (i=0;i<x;++i){
            putchar(arr[j][i]);
        }
        putchar('\n') ;
    }

    if (ch=='2') {
        ai();
    }
    if(ch=='1') {
        movement_1();
    }
    printf("%s : %d \n%s : %d",p1,player1_score,p2,player2_score);
}
int write_file() {
    FILE* fp;
    int i;

    fp = fopen("e:\\c\\pacman_na\\score.txt", "w");
    fprintf(fp,"%s's score: %d\n%s's score: %d",p1,player1_score,p2,player2_score);

    fclose(fp);
}

int player(){
    int i = 0;


    while(i < 1) {
        x1_pos = rand() % length;
        y1_pos = rand() % width;
        if(arr[y1_pos][x1_pos] == ' ') {
            arr[y1_pos][x1_pos] = 'X';
            ++i;
        }
    }
    i = 0 ;
    while(i < 1) {
        x2_pos = rand() % length;
        y2_pos = rand() % width;
        if(arr[y2_pos][x2_pos] == ' ') {
            arr[y2_pos][x2_pos] = 'O';
            ++i;
        }
    }
}


int game_time(float seconde){
    while(seconde  > 0){
        fflush(stdout) ;
        if(clock() - start > 500){
            if(arr[y1_pos + y1_change][x1_pos + x1_change] == 'B' || arr[y1_pos + y1_change][x1_pos + x1_change] == '!' || (y1_change == 0 && x1_change == 0) || arr[y1_pos + y1_change][x1_pos + x1_change] == 'O')
                arr[y1_pos][x1_pos]  = 'X';
            else if(arr[y1_pos + y1_change][x1_pos + x1_change] == '.') {
                y1_pos += y1_change;
                x1_pos += x1_change;
                arr[y1_pos][x1_pos]  = 'X';
                arr[y1_pos - y1_change][x1_pos - x1_change]  = ' ';
                ++player1_score;
                random_food(1);
            }
            else if(arr[y1_pos + y1_change][x1_pos + x1_change] == 'F') {
                y1_pos += y1_change;
                x1_pos += x1_change;
                arr[y1_pos][x1_pos]  = 'X';
                arr[y1_pos - y1_change][x1_pos - x1_change]  = ' ';
                player1_score+=5;
                big_food();
            }
            else if((y1_pos + y1_change)==tele_pos1[0]&&(x1_pos + x1_change) == tele_pos1[1]) {
                arr[tele_pos2[0]][tele_pos2[1]] = ' ';
                arr[tele_pos1[0]][tele_pos1[1]] = ' ';
                arr[y1_pos][x1_pos]  = ' ';
                y1_pos=tele_pos2[0];
                x1_pos=tele_pos2[1];

                teleport();

            }
            else if((y1_pos + y1_change)==tele_pos2[0]&&(x1_pos + x1_change) == tele_pos2[1]) {
                arr[tele_pos1[0]][tele_pos1[1]] = ' ';
                arr[tele_pos2[0]][tele_pos2[1]] = ' ';
                arr[y1_pos][x1_pos]  = ' ';
                y1_pos=tele_pos1[0];
                x1_pos=tele_pos1[1];

                teleport();
            }
            else {
                y1_pos += y1_change;
                x1_pos += x1_change;
                arr[y1_pos][x1_pos]  = 'X';
                arr[y1_pos - y1_change][x1_pos - x1_change]  = ' ';
            }

            if(arr[y2_pos + y2_change][x2_pos + x2_change] == 'B' || arr[y2_pos + y2_change][x2_pos + x2_change] == '!' || (y2_change == 0 && x2_change == 0) || arr[y2_pos + y2_change][x2_pos + x2_change] == 'X')
                arr[y2_pos][x2_pos]  = 'O';
            else if(arr[y2_pos + y2_change][x2_pos + x2_change] == '.') {
                y2_pos += y2_change;
                x2_pos += x2_change;
                arr[y2_pos][x2_pos]  = 'O';
                arr[y2_pos - y2_change][x2_pos - x2_change]  = ' ';
                ++player2_score;
                random_food(1);
            }
            else if(arr[y2_pos + y2_change][x2_pos + x2_change] == 'F') {
                y2_pos += y2_change;
                x2_pos += x2_change;
                arr[y2_pos][x2_pos]  = 'O';
                arr[y2_pos - y2_change][x2_pos - x2_change]  = ' ';
                player2_score+=5;
                big_food();
            }
            else if((y2_pos + y2_change)==tele_pos1[0]&&(x2_pos + x2_change) == tele_pos1[1]) {
                arr[tele_pos2[0]][tele_pos2[1]] = ' ';
                arr[tele_pos1[0]][tele_pos1[1]] = ' ';
                arr[y2_pos][x2_pos]  = ' ';
                y2_pos=tele_pos2[0];
                x2_pos=tele_pos2[1];

                teleport();

            }
            else if((y2_pos + y2_change)==tele_pos2[0]&&(x2_pos + x2_change) == tele_pos2[1]) {
                arr[tele_pos1[0]][tele_pos1[1]] = ' ';
                arr[tele_pos2[0]][tele_pos2[1]] = ' ';
                arr[y2_pos][x2_pos]  = ' ';
                y2_pos=tele_pos1[0];
                x2_pos=tele_pos1[1];

                teleport();
            }
            else {
                y2_pos += y2_change;
                x2_pos += x2_change;
                arr[y2_pos][x2_pos]  = 'O';
                arr[y2_pos - y2_change][x2_pos - x2_change]  = ' ';
            }

            show_mapp(width, length);
            seconde -= 0.2;
            printf("\ntime remaining : %.1f" , seconde);
            start = clock();
        }
    }
}

void file_info(){
    int x;
    FILE *file = fopen("info.txt", "r");
    int i=0;
    fscanf(file, "%d", &length);
    fscanf(file, "%d", &width);
    fscanf(file, "%d", &timer);
    fscanf(file, "%d", &food_number);
    while((fscanf(file, "%d", &x)) !=EOF){
        info[i] = x;
        ++i;
    }
    counter=i;
    fclose(file);

}


void get_name(){
    printf("ENTER PLAYER 1 NAME ...\n");
    scanf("%s",p1);
    while(strcmp(p1,"computer")==0){
        printf("ENTER PLAYER 1 NAME ...\n");
        scanf("%s",p1);
    }
    printf("ENTER PLAYER 2 NAME ...\n");
    scanf("%s",p2);
    if(strcmp(p2,"computer")==0){
        while(strcmp(p2,"computer")==0)
            printf("ENTER PLAYER 1 NAME ...\n");
            scanf("%s",p2);
    }
    while(strcmp(p2,"computer")==0||strcmp(p2,p1)==0){
        printf("ENTER PLAYER 2 NAME ...\n");
        scanf("%s",p2);
    }
}
void one_player(){
    printf("ENTER PLAYER 1 NAME ...\n");
    scanf("%s",p1);
    while(strcmp(p1,"computer")==0){
        printf("ENTER PLAYER 1 NAME ...\n");
        scanf("%s",p1);
    }
    strcpy(p2 , "computer");
    start = clock();
    file_info();
    float seconde = timer ;
    mapp(width , length) ;
    putchar('\n') ;
    game_time(seconde) ;
    //ai();
    write_file();

}
void two_player(){
    get_name();
    start = clock();
    file_info();
    float seconde = timer ;
    mapp(width , length) ;
    putchar('\n') ;
    game_time(seconde) ;
    write_file();
}

int main(){
    srand(time(0));

    printf("GAME MODES : \n1. PLAYER 1 VS PLAYTER 2 \n2. PLAYER 1 VS COMPUTER \nCHOOSE ... \n");
    ch = getchar();
    if (ch=='2'){
        one_player();
        return 0;
    }
    if (ch=='1'){
       two_player();
    }
    /*get_name();
    start = clock();
    file_info();
    float seconde = timer ;
    mapp(width , length) ;
    putchar('\n') ;
    game_time(seconde) ;
    write_file();
    */
}
















