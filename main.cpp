/* This is the main file of the Project */
#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#ifdef __WIN64
    #include <windows.h>  //for Sleep() only
    #include<GL/glut.h>
#elif __WIN32
    #include <windows.h>  //for Sleep() only
    #include<GL/glut.h>
#elif __APPLE_CC__
    #include <GLUT/glut.h>
#elif __linux
    #include<GL/glut.h>
#elif __unix
    #include<GL/glut.h>
#endif
#include<limits.h>
#include<unistd.h>
#include<time.h>
#include<math.h>
#include<cstring>
#include<iostream>
#include<vector>

struct bullet{
    int x,y;
};
#include "declaration.cpp"
#include "utility.cpp"
#include "draw.cpp"
#include "move.cpp"
#include "callback.cpp"

GLdouble width = 1200, height = 800;
double seg_len;
int game_state;
//Game State Values 1 = Start Menu 2 = In Action 3 = Pause MenuS 4 = Quit 5 = Exit- ThankYou Screen

//Main Ship Variables
bool ship_left, ship_right;
int ship_x = (width/2) - VARA - (VARB/2.0), ship_y = PADDING_BELOW;
unsigned int ship_span = VARA + VARA + VARB, FPS = 60, UNIT_MOVE;

//Bomb Variables
 unsigned int MAX_BOMB;


//Bullets Variable

//Score Variables
long long int curr_score,high_score;

//Background Stars
int star_pos[STARS_MAX][2], num_stars, k;
float star_size[STARS_MAX];
unsigned int BACKGROUND_REFRESH_DELAY;

//Mouse Hover Variables
bool quit_mouse_hover_yes, quit_mouse_hover_no;
bool pause_mouse_hover_resume, pause_mouse_hover_quit;
bool start_mouse_hover_start, start_mouse_hover_quit;
int left_bound_quit_yes, right_bound_quit_yes, left_bound_quit_no, right_bound_quit_no, up_bound_quit, down_bound_quit;
int left_bound_pause_quit, right_bound_pause_quit, left_bound_pause_resume, right_bound_pause_resume, up_bound_pause, down_bound_pause;
int left_bound_start, right_bound_start, up_bound_start_quit, down_bound_start_quit, up_bound_start_start, down_bound_start_start;

void myinit()
{
    set_settings();
    unsigned int i,seg_len = width/MAX_BOMB;
    
    curr_score = 0;
    ship_left = false, ship_right = false, game_state = 1;

}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize((int) width, (int) height);
    glutCreateWindow("Galaxian");
    glutFullScreen();
    myinit();
    glutReshapeFunc(reshape);
    glutDisplayFunc(maindisp);
    glutKeyboardFunc(normal_key);

    glutMouseFunc(mouse_func);
    glutTimerFunc(100, timer_func, 0);
    glutMainLoop();
    return 0;
}
