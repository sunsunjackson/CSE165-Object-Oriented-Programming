#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "AnimatedRect.h"


class App: public GlutApp {

public:
    AnimatedRect* bg1;

    AnimatedRect* plat1;
    AnimatedRect* plat2;
    AnimatedRect* plat3;
    AnimatedRect* plat4;
    AnimatedRect* plat5;
    AnimatedRect* plat6;
    AnimatedRect* plat7;
    AnimatedRect* plat8;
    AnimatedRect* plat9;
    
    //AnimatedRect* endgame;
    AnimatedRect* doodle;
    

    App(int argc, char** argv);
    void draw();
    void idle();
    bool contains;
    
    void keyDown(unsigned char key, float x, float y);
    
    ~App();
    
};

#endif
