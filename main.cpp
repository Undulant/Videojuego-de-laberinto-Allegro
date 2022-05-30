#include <iostream>
#include <allegro.h>

using namespace std;

    BITMAP *buffer;
    BITMAP *roca;
    BITMAP *necobmp;
    BITMAP *neco;
    BITMAP *limon;
    BITMAP *Menu;
    BITMAP *MenuC;
    BITMAP *MenuS;
    BITMAP *cursor;
    BITMAP *MenuCre;
    BITMAP *Creditos;
    BITMAP *CreditosA;

    int dir=0;
    int px=30, py=30;
    int numero_de_nivel = 1;

    int mapa1[19][30] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                         1,0,0,1,0,0,0,0,1,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1,0,0,0,0,1,1,
                         1,1,0,1,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,1,1,1,1,0,1,1,
                         1,1,0,0,0,0,1,0,1,1,1,0,1,0,1,1,0,1,1,1,0,1,0,0,0,0,0,0,1,1,
                         1,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,1,0,1,0,1,1,
                         1,1,0,0,1,0,0,0,1,0,1,0,1,1,1,0,0,1,0,0,0,0,0,1,0,0,1,0,1,1,
                         1,1,0,1,1,0,1,0,0,0,1,0,1,2,1,0,1,1,1,1,1,1,0,1,0,0,1,0,1,1,
                         1,1,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,1,1,
                         1,1,1,0,1,0,1,0,1,1,0,1,1,0,1,1,1,1,0,1,1,1,1,1,1,0,1,0,1,1,
                         1,1,1,0,0,0,0,0,0,1,0,1,0,0,1,0,0,1,0,0,0,1,0,1,0,0,1,0,1,1,
                         1,1,1,1,0,1,0,1,1,1,1,1,0,0,1,1,0,1,1,1,1,1,0,0,0,1,0,0,1,1,
                         1,1,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,1,0,1,0,1,1,1,1,1,
                         1,1,0,0,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,0,0,1,1,
                         1,1,0,1,0,1,0,1,0,0,0,1,1,0,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,
                         1,1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,0,1,0,1,0,1,1,
                         1,1,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,2,1,
                         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    };

    int mapa2[19][30] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                         1,2,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,2,0,0,1,1,
                         1,1,0,1,0,0,1,0,0,0,0,0,1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,0,1,1,
                         1,1,0,0,0,0,1,0,1,1,1,0,1,0,0,0,0,1,1,1,0,1,1,1,0,0,0,0,1,1,
                         1,1,0,1,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,1,1,1,0,1,0,0,1,0,1,1,
                         1,1,0,1,1,0,0,0,1,0,0,0,1,1,0,1,1,1,0,0,0,0,0,1,1,0,1,0,1,1,
                         1,1,0,1,1,0,1,0,1,0,1,0,0,0,0,0,0,0,1,1,1,1,0,1,1,0,1,0,1,1,
                         1,1,0,0,0,0,1,0,1,0,1,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,1,0,0,1,
                         1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,
                         1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,
                         1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
                         1,0,0,1,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,
                         1,0,0,0,0,1,1,0,0,1,0,0,1,1,1,1,1,1,0,0,0,1,0,1,0,1,0,0,0,1,
                         1,0,1,1,0,1,1,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                         1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,
                         1,0,0,1,1,0,0,1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,
                         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    };

    void dibujar_mapa1(){
    for (int row = 0; row < 19; row++){
        for (int col = 0; col < 30; col++){
            if(mapa1 [row][col]== 1){
                draw_sprite(buffer, roca, col*30, row*30);
            }
            if(mapa1 [row][col] == 2){
                draw_sprite(buffer, limon, col*30, row*30);
                if(py/30 == row && px/30 == col){
                    mapa1[row][col] = ' ';
                }
            }
        }
    }
    }

    void dibujar_mapa2(){
    for (int row = 0; row < 19; row++){
        for (int col = 0; col < 30; col++){
            if(mapa2 [row][col]== 1){
                draw_sprite(buffer, roca, col*30, row*30);
            }
            if(mapa2 [row][col] == 2){
                draw_sprite(buffer, limon, col*30, row*30);
                if(py/30 == row && px/30 == col){
                    mapa2[row][col] = ' ';
                }
            }
        }
    }
    }


    void pantalla(){
    blit(buffer, screen, 0,0,0,0, 900, 600);
    }

    void dibujar_personaje(){
    blit(necobmp,neco, 0,0,0,0, 30, 30);
    draw_sprite(buffer,neco, px, py); //Estrablece el respawn
    }



    bool nivel1(){
        for (int row = 0; row < 19; row++){
                for (int col = 0; col < 30; col++){
                    if(mapa1 [row][col] == 2) return true;
                    numero_de_nivel = 2;
                }
        }
        return false;
    }
    bool nivel2(){
        for (int row = 0; row < 19; row++){
                for (int col = 0; col < 30; col++){
                    if(mapa2 [row][col] == 2)return true;
                }
        }
        return false;
    }



int main()
{
    allegro_init(); //Inicializa el entorno de allegro
    install_keyboard(); //Permite el uso de teclas dentro del programa
    install_mouse(); //Permite el uso del cursor
    set_color_depth(32); //Establece el formato en 32 bits
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 900, 600, 0, 0); //Define el tamaño de la pantalla del juego

    buffer = create_bitmap(900,600); //Permite pegar la estampa principal y armar el esecenario del juego
    roca = load_bitmap("roca.bmp",NULL);
    necobmp = load_bitmap("neco.bmp",NULL);
    neco = create_bitmap(30,30);
    limon = load_bitmap("limon.bmp",NULL);
    Menu = load_bitmap("Menu.bmp",NULL);
    MenuC = load_bitmap("MenuC.bmp",NULL);
    MenuS = load_bitmap("MenuS.bmp",NULL);
    cursor = load_bitmap("cursor.bmp",NULL);
    MenuCre = load_bitmap ("MenuCreditos.bmp",NULL);
    Creditos = load_bitmap ("Creditos.bmp", NULL);
    CreditosA = load_bitmap ("CreditosA.bmp", NULL);

    int salida = 1;//menu

    while(salida == 1){
            if(mouse_x > 250 && mouse_x < 490 && mouse_y > 290 && mouse_y < 355){
                    blit(MenuC,buffer, 0,0,0,0, 900, 600);
                if(mouse_b & 1){
                    salida = 2;
                }
            }
            else if(mouse_x > 250 && mouse_x < 380 && mouse_y > 405 && mouse_y < 455){
                    blit(MenuS,buffer,0,0,0,0, 900, 600);
                if(mouse_b & 1){
                    salida = 3;
                }
            }
            else if(mouse_x > 780 && mouse_x < 890 && mouse_y > 10 && mouse_y < 45){
                    blit(MenuCre,buffer,0,0,0,0, 900, 600);
                if(mouse_b & 1){
                    salida = 4;
                }
            }
            else blit(Menu,buffer,0,0,0,0, 900, 600);

            masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,15,22);
            blit(buffer,screen,0,0,0,0, 900, 600);

        while(salida == 4){//Creditos
        if(mouse_x > 20 && mouse_x < 140 && mouse_y > 540 && mouse_y < 575){
                blit(CreditosA,buffer, 0,0,0,0, 900, 600);
                if(mouse_b & 1){
                    salida = 1;
                }
            }
        else blit(Creditos,buffer,0,0,0,0, 900, 600);

        masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,15,22);
        blit(buffer,screen,0,0,0,0, 900, 600);
        }
    }


    if(numero_de_nivel == 1){
    while(!key[KEY_ESC] && nivel1() && salida == 2) //Sistema de cerrado del juego
    {
        //Sistema de juego
        if(key[KEY_RIGHT]) dir = 1;{
                if (dir == 1){
                        if(mapa1[py/30][(px+30)/30]!= 1)
                        px +=30;
                        else dir = 5;
                        }
                dir=4;
        }

        if(key[KEY_LEFT]) dir = 0;{
                if (dir == 0){
                        if(mapa1[py/30][(px-30)/30]!= 1)
                        px -=30;
                        else dir = 5;
                        }
                dir=4;
        }

        if(key[KEY_UP]) dir = 2;{
            if (dir == 2){
                if(mapa1[(py-30)/30][px/30]!= 1)
                py -=30;
                else dir = 5;
        }
            dir=4;
        }

        if(key[KEY_DOWN]) dir = 3;{
            if (dir == 3){
                    if(mapa1[(py+30)/30][px/30]!= 1)
                    py +=30;
                    else dir = 5;
        }
            dir=4;
        }


        clear(buffer);
        dibujar_mapa1();
        dibujar_personaje();
        pantalla();
        rest(90);
    }
    }

    if(numero_de_nivel == 2){
    while(!key[KEY_ESC] && nivel2() && salida == 2) //Sistema de cerrado del juego
    {
        //Sistema de juego
        if(key[KEY_RIGHT]) dir = 1;{
                if (dir == 1){
                        if(mapa2[py/30][(px+30)/30]!= 1)
                        px +=30;
                        else dir = 5;
                        }
                dir=4;
        }

        if(key[KEY_LEFT]) dir = 0;{
                if (dir == 0){
                        if(mapa2[py/30][(px-30)/30]!= 1)
                        px -=30;
                        else dir = 5;
                        }
                dir=4;
        }

        if(key[KEY_UP]) dir = 2;{
            if (dir == 2){
                if(mapa2[(py-30)/30][px/30]!= 1)
                py -=30;
                else dir = 5;
        }
            dir=4;
        }

        if(key[KEY_DOWN]) dir = 3;{
            if (dir == 3){
                    if(mapa2[(py+30)/30][px/30]!= 1)
                    py +=30;
                    else dir = 5;
        }
            dir=4;
        }


        clear(buffer);
        dibujar_mapa2();
        dibujar_personaje();
        pantalla();
        rest(90);
    }
    }
    return 0;
}
END_OF_MAIN();


