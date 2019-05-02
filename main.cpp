#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
using namespace sf;
int main() {
    int mines = 0;
    int width = 32;
    srand(time(0));
    int board[25][16];
    int gboard[25][16];
    int bombs = 50;
    int flags = 50;
    int open[25][16];
    int hasflag[25][16];
    bool debuger = false;
    int debugger[25][16];
    int debugboard[25][16];
    int origionalBoard[25][16];
    int boardMines[25][16];
    bool gamewin = false;
    bool gamelose = false;
    int tilecount;

    for (int i = 0; i < 25; i++)
        for (int j = 0; j < 15; j++) {
            debugger[i][j] = 1;
        }

    for (int i = 0; i < 25; i++)
        for (int j = 0; j < 15; j++) {
            hasflag[i][j] = 1;
        }


    for (int i = 0; i < 25; i++)
        for (int j = 0; j < 15; j++) {
            open[i][j] = 1;
        }

    RenderWindow window(sf::VideoMode(800, 600), "Minesweeper");

    Texture hidden;
    hidden.loadFromFile("images/tile_hidden.png");
    Sprite sprite(hidden);

    Texture revealed;
    revealed.loadFromFile("images/tile_revealed.png");
    Sprite reveale(revealed);
    Sprite reveale1(revealed);
    Sprite reveale2(revealed);
    Sprite reveale3(revealed);
    Sprite reveale4(revealed);
    Sprite reveale5(revealed);
    Sprite reveale6(revealed);
    Sprite reveale7(revealed);
    Sprite reveale8(revealed);

    Texture mine;
    mine.loadFromFile("images/mine.png");
    Sprite min(mine);

    Texture flag;
    flag.loadFromFile("images/flag.png");
    Sprite flg(flag);

    Texture one;
    one.loadFromFile("images/number_1.png");
    Sprite on(one);

    Texture two;
    two.loadFromFile("images/number_2.png");
    Sprite tw(two);

    Texture three;
    three.loadFromFile("images/number_3.png");
    Sprite thre(three);

    Texture four;
    four.loadFromFile("images/number_4.png");
    Sprite fou(four);

    Texture five;
    five.loadFromFile("images/number_5.png");
    Sprite fiv(five);

    Texture six;
    six.loadFromFile("images/number_6.png");
    Sprite sx(six);

    Texture seven;
    seven.loadFromFile("images/number_7.png");
    Sprite svn(seven);

    Texture eight;
    eight.loadFromFile("images/number_8.png");
    Sprite et(eight);

    Texture happy;
    happy.loadFromFile("images/face_happy.png");
    Sprite hapy(happy);

    Texture testone;
    testone.loadFromFile("images/test_1.png");
    Sprite testo(testone);

    Texture testtwo;
    testtwo.loadFromFile("images/test_2.png");
    Sprite testtw(testtwo);

    Texture debug;
    debug.loadFromFile("images/debug.png");
    Sprite bug(debug);

    Texture digits;
    digits.loadFromFile("images/digits.png");
    Sprite dig(digits);

    Sprite dig2(digits);

    Texture sad;
    sad.loadFromFile("images/face_lose.png");
    Sprite sd(sad);

    Texture cool;
    cool.loadFromFile("images/face_win.png");

    Sprite removedFlag(hidden);


    for (int i = 0; i <= 24; i++)
        for (int j = 0; j <= 15; j++) {
            gboard[i][j] = 10;
            if (rand() % 6 == 0 && bombs > 0) {
                board[i][j] = 9;
                bombs = bombs - 1;
            } else {
                board[i][j] = 0;
            }
            if (board[i][j] == 9) {
                mines = mines + 1;
            }

        }

    for (int i = 0; i < 1; i++)
        for (int j = 0; j < 1; j++) {
            int n = 0;
            if (board[i][j] == 9) continue;
            if (board[i + 1][j] == 9) n++;
            if (board[i][j + 1] == 9) n++;
            if (board[i + 1][j + 1] == 9) n++;
            board[i][j] = n;
        }

    for (int i = 24; i < 25; i++)
        for (int j = 0; j < 1; j++) {
            int n = 0;
            if (board[i][j] == 9) continue;
            if (board[i][j + 1] == 9) n++;
            if (board[i - 1][j + 1] == 9) n++;
            if (board[i - 1][j] == 9) n++;
            board[i][j] = n;
        }

    for (int i = 0; i < 1; i++)
        for (int j = 15; j < 16; j++) {
            int n = 0;
            if (board[i][j] == 9) continue;
            if (board[i][j - 1] == 9) n++;
            if (board[i + 1][j - 1] == 9) n++;
            if (board[i + 1][j] == 9) n++;
            board[i][j] = n;
        }

    for (int i = 24; i < 25; i++)
        for (int j = 15; j < 16; j++) {
            int n = 0;
            if (board[i][j] == 9) continue;
            if (board[i - 1][j] == 9) n++;
            if (board[i][j - 1] == 9) n++;
            if (board[i - 1][j - 1] == 9) n++;
            board[i][j] = n;
        }


    for (int j = 0; j < 1; j++)
        for (int i = 1; i < 23; i++) {
            int n = 0;
            if (board[i][j] == 9) continue;
            if (board[i + 1][j] == 9) n++;
            if (board[i][j + 1] == 9) n++;
            if (board[i - 1][j] == 9) n++;
            if (board[i - 1][j + 1] == 9) n++;
            if (board[i + 1][j + 1] == 9) n++;
            board[i][j] = n;
        }

    for (int j = 15; j < 16; j++)
        for (int i = 1; i < 25; i++) {
            int n = 0;
            if (board[i][j] == 9) continue;
            if (board[i][j - 1] == 9) n++;
            if (board[i + 1][j] == 9) n++;
            if (board[i - 1][j] == 9) n++;
            if (board[i - 1][j - 1] == 9) n++;
            if (board[i + 1][j - 1] == 9) n++;
            board[i][j] = n;
        }

    for (int i = 0; i < 1; i++)
        for (int j = 1; j < 15; j++) {
            int n = 0;
            if (board[i][j] == 9) continue;
            if (board[i + 1][j] == 9) n++;
            if (board[i][j - 1] == 9) n++;
            if (board[i][j + 1] == 9) n++;
            if (board[i + 1][j + 1] == 9) n++;
            if (board[i + 1][j - 1] == 9) n++;
            board[i][j] = n;
        }

    for (int i = 24; i < 25; i++)
        for (int j = 1; j < 15; j++) {
            int n = 0;
            if (board[i][j] == 9) continue;
            if (board[i][j + 1] == 9) n++;
            if (board[i][j - 1] == 9) n++;
            if (board[i - 1][j] == 9) n++;
            if (board[i - 1][j + 1] == 9) n++;
            if (board[i - 1][j - 1] == 9) n++;
            board[i][j] = n;
        }

    for (int i = 1; i <= 23; i++)
        for (int j = 1; j <= 14; j++) {
            int n = 0;
            if (board[i][j] == 9) continue;
            if (board[i + 1][j] == 9) n++;
            if (board[i][j + 1] == 9) n++;
            if (board[i - 1][j] == 9) n++;
            if (board[i][j - 1] == 9) n++;
            if (board[i + 1][j + 1] == 9) n++;
            if (board[i - 1][j - 1] == 9) n++;
            if (board[i - 1][j + 1] == 9) n++;
            if (board[i + 1][j - 1] == 9) n++;
            board[i][j] = n;
        }

    for (int i = 0; i < 25; i++)
        for (int j = 0; j < 16; j++) {
            if(board[i][j] == 9)
                boardMines[i][j] = 69;
        }


    while (window.isOpen()) {
        Vector2i pos = Mouse::getPosition(window);
        int x = pos.x / width;
        int y = pos.y / width;

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed)
                if (event.key.code == Mouse::Right) {
                    if (hasflag[x][y] == 2 && gamelose == false && gamewin == false) {
                        gboard[x][y] = 15;
                        flags = flags + 1;
                        hasflag[x][y] = 1;
                        break;
                    }

                    if (open[x][y] != 2 && gamelose == false && gamewin == false) {
                        gboard[x][y] = 11;
                        flags = flags - 1;
                    }

                } else if (event.key.code == Mouse::Left) {

                    if (bug.getGlobalBounds().contains(x * width, y * width) && debuger == false && gamelose == false && gamewin == false) {
                        for (int i = 0; i < 25; i++)
                            for (int j = 0; j < 16; j++) {
                                if(board[i][j] == 9){
                                    gboard[i][j] = boardMines[i][j];
                                }}
                        gamelose == false;
                        debuger = true;

                    }
                    else if (bug.getGlobalBounds().contains(x * width, y * width) && debuger == true && gamelose == false && gamewin == false) {

                        for (int i = 0; i < 25; i++)
                            for (int j = 0; j < 16; j++) {
                                debugboard[i][j] = 15;
                            }

                        for (int i = 0; i < 25; i++)
                            for (int j = 0; j < 16; j++) {
                                debugger[i][j] = 2;
                            }
                        for (int i = 0; i <= 24; i++)
                            for (int j = 0; j <= 15; j++) {
                                if (debugger[i][j] == 2) {
                                    for (int i = 0; i < 25; i++)
                                        for (int j = 0; j < 16; j++) {
                                            if(open[i][j] == 2){
                                                gboard[i][j] = board[i][j];
                                            }else if(gboard[i][j] == 11){
                                                gboard[i][j] = 11;
                                            }
                                            else{
                                                gboard[i][j] = debugboard[i][j];
                                            }}
                                    gamelose == false;
                                    debuger = false;
                                }

                            }
                    }
                    if (bug.getGlobalBounds().contains(x * width, y * width)) {
//                        gboard[x][y] = gboard[x][y];
//                    }
//                    else if (testo.getGlobalBounds().contains(x * width, y * width)) {
//                        gboard[x][y] = gboard[x][y];
//                    }
//                    else if (testtw.getGlobalBounds().contains(x * width, y * width)) {
//                        gboard[x][y] = gboard[x][y];
//                    }
//                    else if (gboard[x][y] == 11) {
//                        gboard[x][y] = 11;
//                    }
//                    else if(board[x][y] == 0 && gboard[x][y] == 10 && open[x][y] == 1){
//                            int i = 0;
//                            while(board[x+i][y] == 0 && i < 25){
//                                gboard[x + i][y] = 0;
//                                i = i + 1;
//                        }
//                        if(board[x+i][y] > 0 && board[x+i][y] != 9){
//                                gboard[x+i][y] = board[x + i][y];
//                            }
//                        int q = 0;
//                        while(board[x-q][y] == 0 && q < 25){
//                            gboard[x - q][y] = 0;
//                            q = q + 1;
//                        }
//                        if(board[x-q][y] > 0 && board[x-q][y] != 9){
//                            gboard[x-q][y] = board[x-q][y];
//                        }
//                        int z = 0;
//                        while(board[x][y+z] == 0 && z < 25){
//                            gboard[x][y + z] = 0;
//                            z = z + 1;
//                        }
//                        if(board[x][y+z] > 0 && board[x][y+z] != 9){
//                            gboard[x][y + z] = board[x][y+z];
//                        }
//                        int r = 0;
//                        while(board[x][y-r] == 0 && r < 25){
//                            gboard[x][y - r] = board[x][y-r];
//                            r = r + 1;
//                        }
//                        if(board[x][y-r] > 0 && board[x][y-r] != 9){
//                            gboard[x][y -r] = board[x][y-r];
//                        }


                        gboard[x][y] = board[x][y];
                    }
//                    if(board[x][y] == 0 && gboard[x][y] == 10){
//                        for (int i = 0; i <= 24; i++)
//                            for (int j = 0; j <= 15; j++) {
//                                if(board[x+i][y] == 0){
//                                    gboard[x+i][y] = board[x+i][y];
//                                }
//                                else if(board[x+i][y] != 0 && board[x+i][y] != 9){
//                                    gboard[x+i][y] = board[x+i][y];
//                                    break;
//                                }
//
//                        }
//                        for (int i = 0; i <= 24; i++)
//                            for (int j = 0; j <= 15; j++) {
//                               if (board[x][y + j] == 0) {
//                                    gboard[x][y + j] = board[x][y + j];
//                                } else if (board[x][y + j] != 0 && board[x+i][y] != 9) {
//                                   gboard[x][y + j] = board[x][y + j];
//                                   break;
//                                }
//                            }
//                            for (int i = 0; i <= 24; i++)
//                                for (int j = 0; j <= 15; j++) {
//                                    if(board[x-i][y] == 0){
//                                        gboard[x-i][y] = board[x-i][y];
//                                    }
//                                    else if(board[x-i][y] != 0 && board[x-i][y] != 9){
//                                        gboard[x-i][y] = board[x-i][y];
//                                        break;
//                                    }
//
//                                }
//                            for (int i = 0; i <= 24; i++)
//                                for (int j = 0; j <= 15; j++) {
//                                    if(board[x-i][y] == 0){
//                                        gboard[x-i][y] = board[x-i][y];
//                                    }
//                                    else if(board[x+i][y] != 0 && board[x+i][y] != 9){
//                                        gboard[x-i][y] = board[x-i][y];
//                                        break;
//                                    }
//
//                                }
//                            for (int i = 0; i <= 24; i++)
//                                for (int j = 0; j <= 15; j++) {
//                                    if(board[x][y-j] == 0){
//                                        gboard[x][y-j] = board[x][y-j];
//                                    }
//                                    else if(board[x][y-j] != 0 && board[x][y-j] != 9){
//                                        gboard[x][y-j] = board[x][y-j];
//                                        break;
//                                    }
//
//                                }
//                        for (int i = 0; i <= 24; i++)
//                            for (int j = 0; j <= 15; j++) {
//                                if(board[x+i][y-j] == 0){
//                                    gboard[x+i][y-j] = board[x+i][y-j];
//                                }
//                                else if(board[x+i][y-j] != 0 && board[x+i][y-j] != 9){
//                                    gboard[x+i][y-j] = board[x+i][y-j];
//                                    break;
//                                }
//
//                            }
//                        for (int i = 0; i <= 24; i++)
//                            for (int j = 0; j <= 15; j++) {
//                                if(board[x-i][y-j] == 0){
//                                    gboard[x-i][y-j] = board[x+i][y-j];
//                                }
//                                else if(board[x-i][y-j] != 0 && board[x-i][y-j] != 9){
//                                    gboard[x-i][y-j] = board[x+i][y-j];
//                                    break;
//                                }
//
//                            }
//                        for (int i = 0; i <= 24; i++)
//                            for (int j = 0; j <= 15; j++) {
//                                if(board[x+i][y+j] == 0){
//                                    gboard[x+i][y+j] = board[x+i][y+j];
//                                }
//                                else if(board[x+i][y+j] != 0 && board[x+i][y+j] != 9){
//                                    gboard[x+i][y+j] = board[x+i][y+j];
//                                    break;
//                                }
//
//                            }
//                        for (int i = 0; i <= 24; i++)
//                            for (int j = 0; j <= 15; j++) {
//                                if(board[x-i][y+j] == 0){
//                                    gboard[x-i][y+j] = board[x-i][y+j];
//                                }
//                                else if(board[x-i][y+j] != 0 && board[x-i][y+j] != 9){
//                                    gboard[x-i][y+j] = board[x-i][y+j];
//                                    break;
//                                }
//
//                            }
//                            }
                        if(board[x][y] > 0){

                        gboard[x][y] = board[x][y];

                    }

                    if(hapy.getGlobalBounds().contains(x * width, y * width)){
                        bombs = 50;
                        mines = 0;
                        gamelose = false;
                        gamewin = false;
                        flags = 50;
                        hapy.setTexture(happy);
                        window.draw(hapy);
                        for (int i = 0; i <= 24; i++)
                            for (int j = 0; j <= 15; j++) {
                                gboard[i][j] = 10;
                                if (rand() % 6 == 0 && bombs > 0) {
                                    board[i][j] = 9;
                                    bombs = bombs - 1;
                                } else {
                                    board[i][j] = 0;
                                }
                                if (board[i][j] == 9) {
                                    mines = mines + 1;
                                }
                            }

                        tilecount = 400 - mines;


                        for (int i = 0; i < 1; i++)
                            for (int j = 0; j < 1; j++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i + 1][j] == 9) n++;
                                if (board[i][j + 1] == 9) n++;
                                if (board[i + 1][j + 1] == 9) n++;
                                board[i][j] = n;
                            }

                        for (int i = 24; i < 25; i++)
                            for (int j = 0; j < 1; j++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i][j + 1] == 9) n++;
                                if (board[i - 1][j + 1] == 9) n++;
                                if (board[i - 1][j] == 9) n++;
                                board[i][j] = n;
                            }

                        for (int i = 0; i < 1; i++)
                            for (int j = 15; j < 16; j++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i][j - 1] == 9) n++;
                                if (board[i + 1][j - 1] == 9) n++;
                                if (board[i + 1][j] == 9) n++;
                                board[i][j] = n;
                            }

                        for (int i = 24; i < 25; i++)
                            for (int j = 15; j < 16; j++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i - 1][j] == 9) n++;
                                if (board[i][j - 1] == 9) n++;
                                if (board[i - 1][j - 1] == 9) n++;
                                board[i][j] = n;
                            }


                        for (int j = 0; j < 1; j++)
                            for (int i = 1; i < 23; i++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i + 1][j] == 9) n++;
                                if (board[i][j + 1] == 9) n++;
                                if (board[i - 1][j] == 9) n++;
                                if (board[i - 1][j + 1] == 9) n++;
                                if (board[i + 1][j + 1] == 9) n++;
                                board[i][j] = n;
                            }

                        for (int j = 15; j < 16; j++)
                            for (int i = 1; i < 25; i++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i][j - 1] == 9) n++;
                                if (board[i + 1][j] == 9) n++;
                                if (board[i - 1][j] == 9) n++;
                                if (board[i - 1][j - 1] == 9) n++;
                                if (board[i + 1][j - 1] == 9) n++;
                                board[i][j] = n;
                            }

                        for (int i = 0; i < 1; i++)
                            for (int j = 1; j < 15; j++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i + 1][j] == 9) n++;
                                if (board[i][j - 1] == 9) n++;
                                if (board[i][j + 1] == 9) n++;
                                if (board[i + 1][j + 1] == 9) n++;
                                if (board[i + 1][j - 1] == 9) n++;
                                board[i][j] = n;
                            }

                        for (int i = 24; i < 25; i++)
                            for (int j = 1; j < 15; j++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i][j + 1] == 9) n++;
                                if (board[i][j - 1] == 9) n++;
                                if (board[i - 1][j] == 9) n++;
                                if (board[i - 1][j + 1] == 9) n++;
                                if (board[i - 1][j - 1] == 9) n++;
                                board[i][j] = n;
                            }

                        for (int i = 1; i <= 23; i++)
                            for (int j = 1; j <= 14; j++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i + 1][j] == 9) n++;
                                if (board[i][j + 1] == 9) n++;
                                if (board[i - 1][j] == 9) n++;
                                if (board[i][j - 1] == 9) n++;
                                if (board[i + 1][j + 1] == 9) n++;
                                if (board[i - 1][j - 1] == 9) n++;
                                if (board[i - 1][j + 1] == 9) n++;
                                if (board[i + 1][j - 1] == 9) n++;
                                board[i][j] = n;
                            }
                        for (int i = 0; i < 25; i++)
                            for (int j = 0; j < 15; j++) {
                                hasflag[i][j] = 1;
                            }


                        for (int i = 0; i < 25; i++)
                            for (int j = 0; j < 15; j++) {
                                open[i][j] = 1;
                            }

                        for (int i = 0; i < 25; i++)
                            for (int j = 0; j < 16; j++) {
                                if(board[i][j] == 9)
                                    boardMines[i][j] = 69;
                            }



                    }
                    if(testo.getGlobalBounds().contains(x * width, y * width) && gamelose == false && gamewin == false){
                        ifstream inFile;
                        inFile.open("boards/testboard.brd",ios::in);
                        string line;
                        int count = 0;
                        if(inFile.is_open()){
                            getline (inFile,line);
                            while ( getline (inFile,line) )
                            {
                                count++;
                            }
                            inFile.close();
                        }
                        count = count +0;
                        inFile.open("boards/testboard.brd",ios::in);
                        string lines;
                        int numberOfLines = count;
                        if(inFile.is_open()){
                            for (int i = 0; i <= numberOfLines; ++i) {
                                getline(inFile, lines);
                                char * tab2 = new char [lines.length()+1];
                                strcpy (tab2, lines.c_str());
                                for (int j = 0; j < 25; ++j) {
                                    if(tab2[j] == '1'){
                                        board[j][i] = 9;
                                    }else{
                                        board[j][i] = 0;
                                    }
                                }
                            }
                        }

                        bombs = 50;
                        mines = 0;
                        gamelose = false;
                        gamewin = false;


                        for (int i = 0; i < 25; i++)
                            for (int j = 0; j < 16; j++) {
                                gboard[i][j] = 10;
                                if(board[i][j] == 9){
                                    mines = mines + 1;
                                }
                            }
                        hapy.setTexture(happy);
                        window.draw(hapy);

                        tilecount = 400 - mines;

                        flags = mines;

                        for (int i = 0; i < 1; i++)
                            for (int j = 0; j < 1; j++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i + 1][j] == 9) n++;
                                if (board[i][j + 1] == 9) n++;
                                if (board[i + 1][j + 1] == 9) n++;
                                board[i][j] = n;
                            }

                        for (int i = 24; i < 25; i++)
                            for (int j = 0; j < 1; j++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i][j + 1] == 9) n++;
                                if (board[i - 1][j + 1] == 9) n++;
                                if (board[i - 1][j] == 9) n++;
                                board[i][j] = n;
                            }

                        for (int i = 0; i < 1; i++)
                            for (int j = 15; j < 16; j++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i][j - 1] == 9) n++;
                                if (board[i + 1][j - 1] == 9) n++;
                                if (board[i + 1][j] == 9) n++;
                                board[i][j] = n;
                            }

                        for (int i = 24; i < 25; i++)
                            for (int j = 15; j < 16; j++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i - 1][j] == 9) n++;
                                if (board[i][j - 1] == 9) n++;
                                if (board[i - 1][j - 1] == 9) n++;
                                board[i][j] = n;
                            }


                        for (int j = 0; j < 1; j++)
                            for (int i = 1; i < 23; i++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i + 1][j] == 9) n++;
                                if (board[i][j + 1] == 9) n++;
                                if (board[i - 1][j] == 9) n++;
                                if (board[i - 1][j + 1] == 9) n++;
                                if (board[i + 1][j + 1] == 9) n++;
                                board[i][j] = n;
                            }

                        for (int j = 15; j < 16; j++)
                            for (int i = 1; i < 25; i++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i][j - 1] == 9) n++;
                                if (board[i + 1][j] == 9) n++;
                                if (board[i - 1][j] == 9) n++;
                                if (board[i - 1][j - 1] == 9) n++;
                                if (board[i + 1][j - 1] == 9) n++;
                                board[i][j] = n;
                            }

                        for (int i = 0; i < 1; i++)
                            for (int j = 1; j < 15; j++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i + 1][j] == 9) n++;
                                if (board[i][j - 1] == 9) n++;
                                if (board[i][j + 1] == 9) n++;
                                if (board[i + 1][j + 1] == 9) n++;
                                if (board[i + 1][j - 1] == 9) n++;
                                board[i][j] = n;
                            }

                        for (int i = 24; i < 25; i++)
                            for (int j = 1; j < 15; j++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i][j + 1] == 9) n++;
                                if (board[i][j - 1] == 9) n++;
                                if (board[i - 1][j] == 9) n++;
                                if (board[i - 1][j + 1] == 9) n++;
                                if (board[i - 1][j - 1] == 9) n++;
                                board[i][j] = n;
                            }

                        for (int i = 1; i <= 23; i++)
                            for (int j = 1; j <= 14; j++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i + 1][j] == 9) n++;
                                if (board[i][j + 1] == 9) n++;
                                if (board[i - 1][j] == 9) n++;
                                if (board[i][j - 1] == 9) n++;
                                if (board[i + 1][j + 1] == 9) n++;
                                if (board[i - 1][j - 1] == 9) n++;
                                if (board[i - 1][j + 1] == 9) n++;
                                if (board[i + 1][j - 1] == 9) n++;
                                board[i][j] = n;
                            }
                        for (int i = 0; i < 25; i++)
                            for (int j = 0; j < 15; j++) {
                                hasflag[i][j] = 1;
                            }


                        for (int i = 0; i < 25; i++)
                            for (int j = 0; j < 15; j++) {
                                open[i][j] = 1;
                            }

                        for (int i = 0; i < 25; i++)
                            for (int j = 0; j < 16; j++) {
                                if(board[i][j] == 9)
                                    boardMines[i][j] = 69;
                            }




                    }
                    if(testtw.getGlobalBounds().contains(x * width, y * width) && gamelose == false && gamewin == false){
                        ifstream newFile;
                        newFile.open("boards/testboard2.brd",ios::in);
                        string line;
                        int count = 0;
                        if(newFile.is_open()){
                            getline (newFile,line);
                            while ( getline (newFile,line) )
                            {
                                count++;
                            }
                            newFile.close();
                        }
                        count = count +0;
                        newFile.open("boards/testboard2.brd",ios::in);
                        string lines;
                        int numberOfLines = count;
                        if(newFile.is_open()){
                            for (int i = 0; i <= numberOfLines; ++i) {
                                getline(newFile, lines);
                                char * tab2 = new char [lines.length()+1];
                                strcpy (tab2, lines.c_str());
                                for (int j = 0; j < 25; ++j) {
                                    if(tab2[j] == '1'){
                                        board[j][i] = 9;
                                    }else{
                                        board[j][i] = 0;
                                    }
                                }
                            }
                        }
                        bombs = 50;
                        mines = 0;
                        gamelose = false;
                        gamewin = false;


                        for (int i = 0; i < 25; i++)
                            for (int j = 0; j < 16; j++) {
                                gboard[i][j] = 10;
                                if(board[i][j] == 9){
                                    mines = mines + 1;
                                }
                            }
                        hapy.setTexture(happy);
                        window.draw(hapy);

                        tilecount = 400 - mines;

                        flags = mines;

                        for (int i = 0; i < 1; i++)
                            for (int j = 0; j < 1; j++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i + 1][j] == 9) n++;
                                if (board[i][j + 1] == 9) n++;
                                if (board[i + 1][j + 1] == 9) n++;
                                board[i][j] = n;
                            }

                        for (int i = 24; i < 25; i++)
                            for (int j = 0; j < 1; j++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i][j + 1] == 9) n++;
                                if (board[i - 1][j + 1] == 9) n++;
                                if (board[i - 1][j] == 9) n++;
                                board[i][j] = n;
                            }

                        for (int i = 0; i < 1; i++)
                            for (int j = 15; j < 16; j++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i][j - 1] == 9) n++;
                                if (board[i + 1][j - 1] == 9) n++;
                                if (board[i + 1][j] == 9) n++;
                                board[i][j] = n;
                            }

                        for (int i = 24; i < 25; i++)
                            for (int j = 15; j < 16; j++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i - 1][j] == 9) n++;
                                if (board[i][j - 1] == 9) n++;
                                if (board[i - 1][j - 1] == 9) n++;
                                board[i][j] = n;
                            }


                        for (int j = 0; j < 1; j++)
                            for (int i = 1; i < 23; i++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i + 1][j] == 9) n++;
                                if (board[i][j + 1] == 9) n++;
                                if (board[i - 1][j] == 9) n++;
                                if (board[i - 1][j + 1] == 9) n++;
                                if (board[i + 1][j + 1] == 9) n++;
                                board[i][j] = n;
                            }

                        for (int j = 15; j < 16; j++)
                            for (int i = 1; i < 25; i++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i][j - 1] == 9) n++;
                                if (board[i + 1][j] == 9) n++;
                                if (board[i - 1][j] == 9) n++;
                                if (board[i - 1][j - 1] == 9) n++;
                                if (board[i + 1][j - 1] == 9) n++;
                                board[i][j] = n;
                            }

                        for (int i = 0; i < 1; i++)
                            for (int j = 1; j < 15; j++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i + 1][j] == 9) n++;
                                if (board[i][j - 1] == 9) n++;
                                if (board[i][j + 1] == 9) n++;
                                if (board[i + 1][j + 1] == 9) n++;
                                if (board[i + 1][j - 1] == 9) n++;
                                board[i][j] = n;
                            }

                        for (int i = 24; i < 25; i++)
                            for (int j = 1; j < 15; j++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i][j + 1] == 9) n++;
                                if (board[i][j - 1] == 9) n++;
                                if (board[i - 1][j] == 9) n++;
                                if (board[i - 1][j + 1] == 9) n++;
                                if (board[i - 1][j - 1] == 9) n++;
                                board[i][j] = n;
                            }

                        for (int i = 1; i <= 23; i++)
                            for (int j = 1; j <= 14; j++) {
                                int n = 0;
                                if (board[i][j] == 9) continue;
                                if (board[i + 1][j] == 9) n++;
                                if (board[i][j + 1] == 9) n++;
                                if (board[i - 1][j] == 9) n++;
                                if (board[i][j - 1] == 9) n++;
                                if (board[i + 1][j + 1] == 9) n++;
                                if (board[i - 1][j - 1] == 9) n++;
                                if (board[i - 1][j + 1] == 9) n++;
                                if (board[i + 1][j - 1] == 9) n++;
                                board[i][j] = n;
                            }
                        for (int i = 0; i < 25; i++)
                            for (int j = 0; j < 15; j++) {
                                hasflag[i][j] = 1;
                            }


                        for (int i = 0; i < 25; i++)
                            for (int j = 0; j < 15; j++) {
                                open[i][j] = 1;
                            }

                        for (int i = 0; i < 25; i++)
                            for (int j = 0; j < 16; j++) {
                                if(board[i][j] == 9)
                                    boardMines[i][j] = 69;
                            }



                    }




                }
        }

        window.clear(Color::White);
        tilecount = 400 - mines;
        for (int i = 0; i <= 24; i++)
            for (int j = 0; j <= 15; j++) {
                sprite.setPosition(i * width, j * width);
                window.draw(sprite);}

        testo.setPosition(18 * width, 16 * width);
        window.draw(testo);

        testtw.setPosition(20 * width, 16 * width);
        window.draw(testtw);

        bug.setPosition(16 * width, 16 * width);
        window.draw(bug);

        dig2.setPosition(21, 16*width);
        dig2.setTextureRect(IntRect(21*((flags%10)), 0, 21*1, width));
        dig.setTextureRect(IntRect(21*((flags/10)), 0, 21*1, width));
        dig.setPosition(0, 16 * width);
        window.draw(dig2);
        window.draw(dig);

        hapy.setPosition(10 * width, 16 * width);
        window.draw(hapy);


        if(gamelose == false){

            for (int i = 0; i <= 24; i++)
                for (int j = 0; j <= 15; j++) {

                    if (gboard[i][j] == 9) {
                        open[i][j] = 3;
                        min.setPosition(i * width, j * width);
                        window.draw(min);
                        hapy.setTexture(sad);
                        window.draw(hapy);
                        for (int i = 0; i <= 24; i++)
                            for (int j = 0; j <= 15; j++) {
                                if(board[i][j] == 9){
                                    gboard[i][j] =board[i][j];
                                }
                            }
                        gamelose = true;

                    } else if (gboard[i][j] == 0) {
                        open[i][j] = 2;
                        tilecount = tilecount - 1;
                        reveale.setPosition(i * width, j * width);
                        window.draw(reveale);

                    } else if (gboard[i][j] == 11) {
                        hasflag[i][j] = 2;
                        flg.setPosition(i * width, j * width);
                        window.draw(flg);
                    } else if (gboard[i][j] == 1) {
                        open[i][j] = 2;
                        tilecount = tilecount - 1;
                        reveale.setPosition(i * width, j * width);
                        window.draw(reveale);
                        on.setPosition(i * width, j * width);
                        window.draw(on);
                    } else if (gboard[i][j] == 2) {
                        open[i][j] = 2;
                        tilecount = tilecount - 1;
                        reveale.setPosition(i * width, j * width);
                        window.draw(reveale);
                        tw.setPosition(i * width, j * width);
                        window.draw(tw);
                    } else if (gboard[i][j] == 3) {
                        open[i][j] = 2;
                        tilecount = tilecount - 1;
                        reveale.setPosition(i * width, j * width);
                        window.draw(reveale);
                        thre.setPosition(i * width, j * width);
                        window.draw(thre);
                    } else if (gboard[i][j] == 4) {
                        open[i][j] = 2;
                        tilecount = tilecount - 1;
                        reveale.setPosition(i * width, j * width);
                        window.draw(reveale);
                        fou.setPosition(i * width, j * width);
                        window.draw(fou);
                    } else if (gboard[i][j] == 5) {
                        open[i][j] = 2;
                        tilecount = tilecount - 1;
                        reveale.setPosition(i * width, j * width);
                        window.draw(reveale);
                        fiv.setPosition(i * width, j * width);
                        window.draw(fiv);
                    } else if (gboard[i][j] == 6) {
                        open[i][j] = 2;
                        tilecount = tilecount - 1;
                        reveale.setPosition(i * width, j * width);
                        window.draw(reveale);
                        sx.setPosition(i * width, j * width);
                        window.draw(sx);
                    } else if (gboard[i][j] == 7) {
                        open[i][j] = 2;
                        tilecount = tilecount - 1;
                        reveale.setPosition(i * width, j * width);
                        window.draw(reveale);
                        svn.setPosition(i * width, j * width);
                        window.draw(svn);
                    } else if (gboard[i][j] == 8) {
                        open[i][j] = 2;
                        tilecount = tilecount - 1;
                        reveale.setPosition(i * width, j * width);
                        window.draw(reveale);
                        et.setPosition(i * width, j * width);
                        window.draw(et);
                    } else if (gboard[i][j] == 15) {
                        sprite.setPosition(i * width, j * width);
                        window.draw(sprite);
                    } else if (gboard[i][j] == 69) {
                        min.setPosition(i * width, j * width);
                        window.draw(min);
                    }
                }
            if(tilecount == 0){
                for (int i = 0; i <= 24; i++)
                    for (int j = 0; j <= 15; j++) {
                        if(board[i][j] == 9) {
                            gboard[i][j] =11;
                        }
                    }
                hapy.setTexture(cool);
                flags = 0;
                window.draw(hapy);
                gamewin = true;
            }
        }
        else if(gamelose == true){
            for (int i = 0; i <= 24; i++)
                for (int j = 0; j <= 15; j++) {
                    if(board[i][j] == 9) {
                        gboard[i][j] = board[i][j];
                        min.setPosition(i * width, j * width);
                        window.draw(min);
                        hapy.setTexture(sad);
                        window.draw(hapy);
                    }
                    if(open[i][j] == 2 || hasflag[i][j] == 2){
                        if (gboard[i][j] == 0) {
                            reveale.setPosition(i * width, j * width);
                            window.draw(reveale);
                        } else if (gboard[i][j] == 11) {
                            flg.setPosition(i * width, j * width);
                            window.draw(flg);
                        } else if (gboard[i][j] == 1) {
                            reveale.setPosition(i * width, j * width);
                            window.draw(reveale);
                            on.setPosition(i * width, j * width);
                            window.draw(on);
                        } else if (gboard[i][j] == 2) {
                            reveale.setPosition(i * width, j * width);
                            window.draw(reveale);
                            tw.setPosition(i * width, j * width);
                            window.draw(tw);
                        } else if (gboard[i][j] == 3) {
                            reveale.setPosition(i * width, j * width);
                            window.draw(reveale);
                            thre.setPosition(i * width, j * width);
                            window.draw(thre);
                        } else if (gboard[i][j] == 4) {
                            reveale.setPosition(i * width, j * width);
                            window.draw(reveale);
                            fou.setPosition(i * width, j * width);
                            window.draw(fou);
                        } else if (gboard[i][j] == 5) {
                            reveale.setPosition(i * width, j * width);
                            window.draw(reveale);
                            fiv.setPosition(i * width, j * width);
                            window.draw(fiv);
                        } else if (gboard[i][j] == 6) {
                            reveale.setPosition(i * width, j * width);
                            window.draw(reveale);
                            sx.setPosition(i * width, j * width);
                            window.draw(sx);
                        } else if (gboard[i][j] == 7) {
                            reveale.setPosition(i * width, j * width);
                            window.draw(reveale);
                            svn.setPosition(i * width, j * width);
                            window.draw(svn);
                        } else if (gboard[i][j] == 8) {
                            reveale.setPosition(i * width, j * width);
                            window.draw(reveale);
                            et.setPosition(i * width, j * width);
                            window.draw(et);
                        } else if (gboard[i][j] == 15) {
                            sprite.setPosition(i * width, j * width);
                            window.draw(sprite);
                        } else if (gboard[i][j] == 69) {
                            min.setPosition(i * width, j * width);
                            window.draw(min);
                        }
                    }
                }
        }






        window.display();
    }


}



