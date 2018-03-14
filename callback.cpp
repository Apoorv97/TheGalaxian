/*This File contains all the CallBack Function
for Mouse and Keyboard. */
#include "declaration.cpp"
#include<stdio.h>


void normal_key(unsigned char k, int x, int y)
{
    switch(k)
    {
        case 27:
        case 'q':
        case 'Q':   game_state = 4;
                    break;
        case 'p':
        case 'P':   if(game_state == 2) game_state = 3;
                    else if(game_state == 3) game_state = 2;
                    break;
        case 'R':
        case 'r':   if(game_state == 3) game_state = 2;
                    break;

        case 'Y':
        case 'y':   if(game_state == 4) game_state = 5;
                    break;

        case 'N':
        case 'n':   if(game_state == 4) game_state = 3;
                    break;

        case 'S':
        case 's':   if(game_state == 1) game_state = 2;
                    break;

    }
}

void mouse_func(int button, int state, int x, int y)
{
    switch(game_state)
    {
        case 1: if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
                {
                    if(y>=down_bound_start_start && y<=up_bound_start_start && x>=left_bound_start && x<=right_bound_start) game_state = 2;
                    if(y>=down_bound_start_quit && y<=up_bound_start_quit && x>=left_bound_start && x<=right_bound_start) game_state = 4;
                }
                break;

        case 2: 
                break;

        case 3: if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP) game_state = 2;
                else if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
                {
                    if(y>=down_bound_pause && y<=up_bound_pause && x>=left_bound_pause_quit && x<=right_bound_pause_quit) game_state = 4;
                    if(y>=down_bound_pause && y<=up_bound_pause && x>=left_bound_pause_resume && x<=right_bound_pause_resume) game_state= 2;
                }
                break;

        case 4: if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
                {
                    if(y>=down_bound_quit && y<=up_bound_quit && x>=left_bound_quit_yes && x<=right_bound_quit_yes) game_state = 5;
                    if(y>=down_bound_quit && y<=up_bound_quit && x>=left_bound_quit_no && x<=right_bound_quit_no) game_state= 3;
                }
    }
}

