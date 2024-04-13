#include <iostream>

using namespace std;

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"

#define ANSI_COLOR_BRIGHT  "\x1b[1m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define ANSI_BG_COLOR_RED "\x1b[41m"
#define ANSI_BG_COLOR_BLUE "\x1b[44m"
#define ANSI_BG_COLOR_RESET "\x1b[40m"

void draw_bord();
void game_start();
int play();
void re_draw_bord();
void win_lose();
void game_clear();


char bord_lable[9] = { '1','2','3','4','5','6','7','8','9' };
char mark;
int player_temp;

bool game_condition = true;


int main()
{ 
    int x = 1;
    while (x) {
        game_clear();
        game_start();
        re_draw_bord();
        win_lose();
        cout << "to exiet priss 0 else press any number : ";
        cin >> x;
    }
}

void game_clear() {
    char a = '1';
    for (int i = 0; i < 9; i++){
        bord_lable[i] = a;
        a++;
    }
}



void win_lose() {
    if (play() == 1)
    {
        if (player_temp == 1)
        {
            cout << ANSI_BG_COLOR_RED;
            cout << "player " << player_temp << " won!!" << endl;
        }
        else {
            cout << ANSI_BG_COLOR_BLUE;
            cout << "player " << player_temp << " won!!" << endl;
        }

        cout << ANSI_BG_COLOR_RESET;
    }
    else {
        cout << "Draw";
    }
}

void game_start() {
    int game = play();
    int player = 1, num;

    while (game == -1) {

        draw_bord();
        if (player % 2 != 0) {
            player = 1;
            player_temp = 1;
            cout << ANSI_COLOR_RED;
        }
        else {
            player = 2;
            player_temp = 2;
            cout << ANSI_COLOR_BLUE;
        }

        if (player == 1)
        {
            mark = 'X';
        }
        else {
            mark = 'O';
        }

        cout << "player " << player << " enter a num : ";
        cin >> num;

        if (num == 1 && bord_lable[0] == '1') {
            bord_lable[0] = mark;
        }
        else if (num == 2 && bord_lable[1] == '2') {
            bord_lable[1] = mark;
        }
        else if (num == 3 && bord_lable[2] == '3') {
            bord_lable[2] = mark;
        }
        else if (num == 4 && bord_lable[3] == '4') {
            bord_lable[3] = mark;
        }
        else if (num == 5 && bord_lable[4] == '5') {
            bord_lable[4] = mark;
        }
        else if (num == 6 && bord_lable[5] == '6') {
            bord_lable[5] = mark;
        }
        else if (num == 7 && bord_lable[6] == '7') {
            bord_lable[6] = mark;
        }
        else if (num == 8 && bord_lable[7] == '8') {
            bord_lable[7] = mark;
        }
        else if (num == 9 && bord_lable[8] == '9') {
            bord_lable[8] = mark;
        }
        else {
            //cout << "invalid location " << endl;
            player--;
        }
        player++;
        cout << ANSI_COLOR_RESET;
        game = play();
    }
}



int play() {
    if (bord_lable[0] == bord_lable[1] && bord_lable[1] == bord_lable[2]) {
        return 1;
    }
    else if (bord_lable[0] == bord_lable[3] && bord_lable[3] == bord_lable[6]) {
        return 1;
    }
    else if (bord_lable[1] == bord_lable[4] && bord_lable[4] == bord_lable[7]) {
        return 1;
    }
    else if (bord_lable[2] == bord_lable[5] && bord_lable[5] == bord_lable[8]) {
        return 1;
    }
    else if (bord_lable[3] == bord_lable[4] && bord_lable[4] == bord_lable[5]) {
        return 1;
    }
    else if (bord_lable[6] == bord_lable[7] && bord_lable[7] == bord_lable[8]) {
        return 1;
    }
    else if (bord_lable[0] == bord_lable[4] && bord_lable[4] == bord_lable[8]) {
        return 1;
    }
    else if (bord_lable[2] == bord_lable[4] && bord_lable[4] == bord_lable[6]) {
        return 1;
    }
    else if (bord_lable[0] != '1' && bord_lable[1] != '2' && bord_lable[2] != '3' && bord_lable[3] != '4' && bord_lable[4] != '5' && bord_lable[5] != '6' && bord_lable[6] != '7' && bord_lable[7] != '8' &&
        bord_lable[8] != '9') {
        return 0;
    }
    else {
        return -1;
    }
}


void draw_bord() {
    system("cls");
    cout << "_____" << "_" << "_____" << "_" << "_____" << endl;
    cout << "     " << "|" << "     " << "|" << "     " << endl;
    cout << "  " << bord_lable[0] << "  |  " << bord_lable[1] << "  |  " << bord_lable[2] << endl;
    cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
    cout << "     " << "|" << "     " << "|" << "     " << endl;
    cout << "  " << bord_lable[3] << "  |  " << bord_lable[4] << "  |  " << bord_lable[5] << endl;
    cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
    cout << "     " << "|" << "     " << "|" << "     " << endl;
    cout << "  " << bord_lable[6] << "  |  " << bord_lable[7] << "  |  " << bord_lable[8] << endl;
    cout << "_____" << "|" << "_____" << "|" << "_____" << endl;   
}


void re_draw_bord() {
    system("cls");

    //HORIZONTAL
    if (bord_lable[0] == bord_lable[1] && bord_lable[1] == bord_lable[2] && player_temp == 1)
    {
        cout << "_____" << "_" << "_____" << "_" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << ANSI_BG_COLOR_RED;
        cout << "  " << bord_lable[0] << "  |  " << bord_lable[1] << "  |  " << bord_lable[2] << endl;
        cout << ANSI_BG_COLOR_RESET;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[3] << "  |  " << bord_lable[4] << "  |  " << bord_lable[5] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[6] << "  |  " << bord_lable[7] << "  |  " << bord_lable[8] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
    }
    else if (bord_lable[0] == bord_lable[1] && bord_lable[1] == bord_lable[2] && player_temp == 2) {
        cout << "_____" << "_" << "_____" << "_" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << ANSI_BG_COLOR_BLUE;
        cout << "  " << bord_lable[0] << "  |  " << bord_lable[1] << "  |  " << bord_lable[2] << endl;
        cout << ANSI_BG_COLOR_RESET;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[3] << "  |  " << bord_lable[4] << "  |  " << bord_lable[5] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[6] << "  |  " << bord_lable[7] << "  |  " << bord_lable[8] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
    }
    
    else if (bord_lable[3] == bord_lable[4] && bord_lable[4] == bord_lable[5] && player_temp == 1) {
        cout << "_____" << "_" << "_____" << "_" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[0] << "  |  " << bord_lable[1] << "  |  " << bord_lable[2] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << ANSI_BG_COLOR_RED;
        cout << "  " << bord_lable[3] << "  |  " << bord_lable[4] << "  |  " << bord_lable[5] << endl;
        cout << ANSI_BG_COLOR_RESET;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[6] << "  |  " << bord_lable[7] << "  |  " << bord_lable[8] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
    }
    else if (bord_lable[3] == bord_lable[4] && bord_lable[4] == bord_lable[5] && player_temp == 2) {
        cout << "_____" << "_" << "_____" << "_" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[0] << "  |  " << bord_lable[1] << "  |  " << bord_lable[2] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << ANSI_BG_COLOR_BLUE;
        cout << "  " << bord_lable[3] << "  |  " << bord_lable[4] << "  |  " << bord_lable[5] << endl;
        cout << ANSI_BG_COLOR_RESET;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[6] << "  |  " << bord_lable[7] << "  |  " << bord_lable[8] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
    }
    
    else if (bord_lable[6] == bord_lable[7] && bord_lable[7] == bord_lable[8] && player_temp == 1) {
        cout << "_____" << "_" << "_____" << "_" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[0] << "  |  " << bord_lable[1] << "  |  " << bord_lable[2] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[3] << "  |  " << bord_lable[4] << "  |  " << bord_lable[5] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << ANSI_BG_COLOR_RED;
        cout << "  " << bord_lable[6] << "  |  " << bord_lable[7] << "  |  " << bord_lable[8] << endl;
        cout << ANSI_BG_COLOR_RESET;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
    }
    else if (bord_lable[6] == bord_lable[7] && bord_lable[7] == bord_lable[8] && player_temp == 2) {
        cout << "_____" << "_" << "_____" << "_" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[0] << "  |  " << bord_lable[1] << "  |  " << bord_lable[2] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[3] << "  |  " << bord_lable[4] << "  |  " << bord_lable[5] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << ANSI_BG_COLOR_BLUE;
        cout << "  " << bord_lable[6] << "  |  " << bord_lable[7] << "  |  " << bord_lable[8] << endl;
        cout << ANSI_BG_COLOR_RESET;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
    }

    // VERTICAL
    else if (bord_lable[0] == bord_lable[3] && bord_lable[3] == bord_lable[6] && player_temp == 1) {
        cout << "_____" << "_" << "_____" << "_" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << ANSI_BG_COLOR_RED << bord_lable[0] << ANSI_BG_COLOR_RESET << "  |  " << bord_lable[1] << "  |  " << bord_lable[2] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << ANSI_BG_COLOR_RED << bord_lable[3] << ANSI_BG_COLOR_RESET << "  |  " << bord_lable[4] << "  |  " << bord_lable[5] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << ANSI_BG_COLOR_RED << bord_lable[6] << ANSI_BG_COLOR_RESET << "  |  " << bord_lable[7] << "  |  " << bord_lable[8] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
    }
    else if (bord_lable[0] == bord_lable[3] && bord_lable[3] == bord_lable[6] && player_temp == 2) {
        cout << "_____" << "_" << "_____" << "_" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << ANSI_BG_COLOR_BLUE << bord_lable[0] << ANSI_BG_COLOR_RESET << "  |  " << bord_lable[1] << "  |  " << bord_lable[2] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << ANSI_BG_COLOR_BLUE << bord_lable[3] << ANSI_BG_COLOR_RESET << "  |  " << bord_lable[4] << "  |  " << bord_lable[5] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << ANSI_BG_COLOR_BLUE << bord_lable[6] << ANSI_BG_COLOR_RESET << "  |  " << bord_lable[7] << "  |  " << bord_lable[8] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
    }

    else if (bord_lable[1] == bord_lable[4] && bord_lable[4] == bord_lable[7] && player_temp == 1) {
        cout << "_____" << "_" << "_____" << "_" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[0] <<  "  |  " << ANSI_BG_COLOR_RED << bord_lable[1] << ANSI_BG_COLOR_RESET << "  |  " << bord_lable[2] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[3] << "  |  " << ANSI_BG_COLOR_RED << bord_lable[4] << ANSI_BG_COLOR_RESET << "  |  " << bord_lable[5] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[6] << "  |  " << ANSI_BG_COLOR_RED << bord_lable[7] << ANSI_BG_COLOR_RESET << "  |  " << bord_lable[8] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
    }
    else if (bord_lable[1] == bord_lable[4] && bord_lable[4] == bord_lable[7] && player_temp == 2) {
        cout << "_____" << "_" << "_____" << "_" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[0] << "  |  " << ANSI_BG_COLOR_BLUE << bord_lable[1] << ANSI_BG_COLOR_RESET << "  |  " << bord_lable[2] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[3] << "  |  " << ANSI_BG_COLOR_BLUE << bord_lable[4] << ANSI_BG_COLOR_RESET << "  |  " << bord_lable[5] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[6] << "  |  " << ANSI_BG_COLOR_BLUE << bord_lable[7] << ANSI_BG_COLOR_RESET << "  |  " << bord_lable[8] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
    }

    else if (bord_lable[2] == bord_lable[5] && bord_lable[5] == bord_lable[8] && player_temp == 1) {
        cout << "_____" << "_" << "_____" << "_" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[0] << "  |  " << bord_lable[1] << "  |  " << ANSI_BG_COLOR_RED << bord_lable[2] << ANSI_BG_COLOR_RESET << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[3] << "  |  " << bord_lable[4] << "  |  " << ANSI_BG_COLOR_RED << bord_lable[5] << ANSI_BG_COLOR_RESET << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[6] << "  |  " << bord_lable[7] << "  |  " << ANSI_BG_COLOR_RED << bord_lable[8] << ANSI_BG_COLOR_RESET << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
    }
    else if (bord_lable[2] == bord_lable[5] && bord_lable[5] == bord_lable[8] && player_temp == 2) {
        cout << "_____" << "_" << "_____" << "_" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[0] << "  |  " << bord_lable[1] << "  |  " << ANSI_BG_COLOR_BLUE << bord_lable[2] << ANSI_BG_COLOR_RESET << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[3] << "  |  " << bord_lable[4] << "  |  " << ANSI_BG_COLOR_BLUE << bord_lable[5] << ANSI_BG_COLOR_RESET << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[6] << "  |  " << bord_lable[7] << "  |  " << ANSI_BG_COLOR_BLUE << bord_lable[8] << ANSI_BG_COLOR_RESET << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
    }
    
    // DIAGONAL
    else if (bord_lable[0] == bord_lable[4] && bord_lable[4] == bord_lable[8] && player_temp == 1) {
        cout << "_____" << "_" << "_____" << "_" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << ANSI_BG_COLOR_RED << bord_lable[0] << ANSI_BG_COLOR_RESET << "  |  " << bord_lable[1] << "  |  " << bord_lable[2] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[3] << "  |  " << ANSI_BG_COLOR_RED << bord_lable[4] << ANSI_BG_COLOR_RESET << "  |  " << bord_lable[5] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[6] << "  |  " << bord_lable[7] << "  |  " << ANSI_BG_COLOR_RED << bord_lable[8] << ANSI_BG_COLOR_RESET << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
    }
    else if (bord_lable[0] == bord_lable[4] && bord_lable[4] == bord_lable[8] && player_temp == 2) {
        cout << "_____" << "_" << "_____" << "_" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << ANSI_BG_COLOR_BLUE << bord_lable[0] << ANSI_BG_COLOR_RESET << "  |  " << bord_lable[1] << "  |  " << bord_lable[2] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[3] << "  |  " << ANSI_BG_COLOR_BLUE << bord_lable[4] << ANSI_BG_COLOR_RESET << "  |  " << bord_lable[5] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[6] << "  |  " << bord_lable[7] << "  |  " << ANSI_BG_COLOR_BLUE << bord_lable[8] << ANSI_BG_COLOR_RESET << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
    }

    else if (bord_lable[2] == bord_lable[4] && bord_lable[4] == bord_lable[6] && player_temp == 1) {
        cout << "_____" << "_" << "_____" << "_" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[0] << "  |  " << bord_lable[1] << "  |  " << ANSI_BG_COLOR_RED << bord_lable[2] << ANSI_BG_COLOR_RESET << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[3] << "  |  " << ANSI_BG_COLOR_RED << bord_lable[4] << ANSI_BG_COLOR_RESET << "  |  " << bord_lable[5] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << ANSI_BG_COLOR_RED << bord_lable[6] << ANSI_BG_COLOR_RESET << "  |  " << bord_lable[7] << "  |  " << bord_lable[8] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
    }
    else if (bord_lable[2] == bord_lable[4] && bord_lable[4] == bord_lable[6] && player_temp == 2) {
        cout << "_____" << "_" << "_____" << "_" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[0] << "  |  " << bord_lable[1] << "  |  " << ANSI_BG_COLOR_BLUE << bord_lable[2] << ANSI_BG_COLOR_RESET << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << bord_lable[3] << "  |  " << ANSI_BG_COLOR_BLUE << bord_lable[4] << ANSI_BG_COLOR_RESET << "  |  " << bord_lable[5] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
        cout << "     " << "|" << "     " << "|" << "     " << endl;
        cout << "  " << ANSI_BG_COLOR_BLUE << bord_lable[6] << ANSI_BG_COLOR_RESET << "  |  " << bord_lable[7] << "  |  " << bord_lable[8] << endl;
        cout << "_____" << "|" << "_____" << "|" << "_____" << endl;
    }

    //DRAW
    else {
        draw_bord();
    }
    
}