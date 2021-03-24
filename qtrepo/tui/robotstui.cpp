#include "robotstui.h"

RobotsTUI::RobotsTUI()
{
    r = new Robots(10,6);
}

RobotsTUI::RobotsTUI(int ro, int co) {
    r = new Robots(ro, co);
}

RobotsTUI::~RobotsTUI() {
    delete r;
}

void RobotsTUI::draw_screen() {
    // temporary display string for storing the value
    // of the displayed Value object.


    // clear screen return cursor to (0,0)
    clear();
    if(r->win()) {
        mvprintw(0, 15, "You Win!");
    }
    r->isDead();
    r->moveRobots();
    r->updateBoard();

    //print line by line the current board
    int i = 0;
    for(; i < r->getRows(); i++ ) {
        std::string display;
        for(int j = 0; j < r->getCols(); j++) {
            display += r->get(i, j);
        }
        mvprintw(i, 0, display.c_str());
        //printw(display.c_str());
        //move(i, 0);
    }
    std::string s = "Score: ";
    s += std::to_string(r->score);
    mvprintw(i, 4, s.c_str());
}

void RobotsTUI::run() {
    // initialize the screen
    initscr();

    // hide the cursor from view (comment this line out for debugging)
    curs_set(0);

    // disables line buffering and erase/kill character-processing
    // (interrupt and flow control characters are unaffected),
    // making characters typed by the  user  immediately
    // available to the program
    cbreak();

    // control whether characters  typed  by  the user  are echoed
    // by getch as they are typed
    noecho();

    // the user can press a function key (such as an arrow key) and
    // getch returns a single value representing the  function  key,
    // as in KEY_LEFT
    keypad(stdscr, TRUE);

    // initialize the interaction loop to run
    bool continue_looping = true;

    // draw the current screen
    //refresh();
    //draw_screen();

    do {

        // draw the new screen
        refresh();
        draw_screen();

        // obtain character from keyboard
        int ch = getch();

        // operate based on input character
        if(!r->win() && !r->playerDead()) {
            switch (ch) {
            case KEY_RIGHT: //move right
                r->movePlayerE();
                break;
            case KEY_LEFT: //move left
                r->movePlayerW();
                break;
            case KEY_UP: //move up
                r->movePlayerN();
                break;
            case KEY_DOWN: //move down
                r->movePlayerS();
                break;
            case '*': //random teleport
                r->randomTeleport();
                break;
            case 'q': //quit
                continue_looping = false;
                break;
            }
            r->moveRobots();
        }
        //game is over and want to refesh
        else {
            switch(ch) {
            case 'q':
                continue_looping = false;
                break;
            case 'p':
                r->resetGame();
                break;
        }
        }
    } while(continue_looping);

        // cleanup the window and return control to bash
        endwin();

        std::cout << "exiting run\n";

}

int RobotsTUI::getScore() {
    return r->score;
}
