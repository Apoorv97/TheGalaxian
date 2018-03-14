
/*This File Contains the Code to move every thing.
It is called every-time a new frame is rendered*/

void main_ship_move()
{
    if(ship_left)
    {
        if(ship_x>=(int)UNIT_MOVE)
        {
            ship_x -= UNIT_MOVE;
        }
        else if(ship_x>0)
        {
            ship_x = 0;
        }
    }
    else if(ship_right)
    {
        if(ship_x<=(width-ship_span-UNIT_MOVE))
        {
            ship_x += UNIT_MOVE;
        }
        else if(ship_x<=(width-ship_span))
        {
            ship_x = width-ship_span;
        }
    }
}

void timer_func(int v)
{
    if(game_state == 2)
    {
        
    }
    glutPostRedisplay();
    glutTimerFunc(1000/FPS, timer_func, v);
}
