#include <iostream>
#include "App.h"
#include "AnimatedRect.h"
#include "Rect.h"
#include <stdlib.h>   

float x1 = .01 * (rand() % 80 + 1);
float x2 = -.01 * (rand() % 100 + 1);
float x3 = .01 * (rand() % 80 + 1);
float x4 = -.01 * (rand() % 100 + 1);
float x5 = .01 * (rand() % 80 + 1);
float x6 = -.01 * (rand() % 100 + 1);
float x7 = .01 * (rand() % 80 + 1);
float x8 = -.01 * (rand() % 100 + 1);
float x9 = .01 * (rand() % 80 + 1);
bool contains = true;

App::App(int argc, char** argv): GlutApp(argc, argv){

    bg1 = new AnimatedRect("images.jpg", 1, 1, 100, -1, 1, 2, 2);	// (frame, frame, refresh rate, x position, y position, width, height)

	plat1 = new AnimatedRect("platform.png", 1, 1, 100, x1, 0.0, 0.3, 0.05);
    plat2 = new AnimatedRect("platform.png", 1, 1, 100, x2, 0.4, 0.3, 0.05);
    plat3 = new AnimatedRect("platform.png", 1, 1, 100, x3, 0.6, 0.3, 0.05);
    plat4 = new AnimatedRect("platform.png", 1, 1, 100, x4, 0.8, 0.3, 0.05);
    plat5 = new AnimatedRect("platform.png", 1, 1, 100, x5, 1.0, 0.3, 0.05);
    plat6 = new AnimatedRect("platform.png", 1, 1, 100, x6, 1.2, 0.3, 0.05);
    plat7 = new AnimatedRect("platform.png", 1, 1, 100, x7, 1.4, 0.3, 0.05);
    plat8 = new AnimatedRect("platform.png", 1, 1, 100, x8, 1.6, 0.3, 0.05);
    plat9 = new AnimatedRect("platform.png", 1, 1, 100, x9, 1.8, 0.3, 0.05);
    
    //endgame = new AnimatedRect("endgame.jpg", 1, 1, 100, -1, 1, 2, 2);
	doodle = new AnimatedRect("doodle.png", 1, 1, 100, -0.1, -0.4, 0.2, 0.2);


}
//push this

void App::draw() {

    bg1->draw(0.05);
    //endgame->draw(.04);
    plat1->draw(.1);
    plat2->draw(.1);
    plat3->draw(.1);
    plat4->draw(.1);
    plat5->draw(.1);
    plat6->draw(.1);
    plat7->draw(.1);
    plat8->draw(.1);
    plat9->draw(.1);

	doodle->draw(.1);
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
    if(key == 'w'){
        plat1->jump();
        plat2->jump();
        plat3->jump();
        plat4->jump();
        plat5->jump();
        plat6->jump();
        plat7->jump();
        plat8->jump();
        plat9->jump();
    }

    if(key == 'd'){
        if(doodle->x + doodle->w <= 1){
            doodle->moveRight();
        }
        

    }
        if(key == 'a'){
            if(doodle->x >= -1){
                 doodle->moveLeft();
            }

    }


     glutPostRedisplay();
}

void App::idle() {
        if(doodle->x + doodle->w >= plat1->x && doodle->y >= plat1->y + plat1->h && doodle->x <= plat1->x + plat1->w && doodle->y - doodle->h <= plat1->y){ 
            plat1->pause();
            plat2->pause();
            plat3->pause();
            plat4->pause();
            plat5->pause();
            plat6->pause();
            plat7->pause();
            plat8->pause();
            plat9->pause();
        }
        if(doodle->x + doodle->w >= plat2->x && doodle->y >= plat2->y + plat2->h && doodle->x <= plat2->x + plat2->w && doodle->y - doodle->h <= plat2->y){ 
            plat1->pause();
            plat2->pause();
            plat3->pause();
            plat4->pause();
            plat5->pause();
            plat6->pause();
            plat7->pause();
            plat8->pause();
            plat9->pause();
        }
        if(doodle->x + doodle->w >= plat3->x && doodle->y >= plat3->y + plat3->h && doodle->x <= plat3->x + plat3->w && doodle->y - doodle->h <= plat3->y){ 
            plat1->pause();
            plat2->pause();
            plat3->pause();
            plat4->pause();
            plat5->pause();
            plat6->pause();
            plat7->pause();
            plat8->pause();
            plat9->pause();
        }
        if(doodle->x + doodle->w >= plat4->x && doodle->y >= plat4->y + plat4->h && doodle->x <= plat4->x + plat4->w && doodle->y - doodle->h <= plat4->y){ 
            plat1->pause();
            plat2->pause();
            plat3->pause();
            plat4->pause();
            plat5->pause();
            plat6->pause();
            plat7->pause();
            plat8->pause();
            plat9->pause();
        }
        if(doodle->x + doodle->w >= plat5->x && doodle->y >= plat5->y + plat5->h && doodle->x <= plat5->x + plat5->w && doodle->y - doodle->h <= plat5->y){ 
            plat1->pause();
            plat2->pause();
            plat3->pause();
            plat4->pause();
            plat5->pause();
            plat6->pause();
            plat7->pause();
            plat8->pause();
            plat9->pause();
        }
        if(doodle->x + doodle->w >= plat6->x && doodle->y >= plat6->y + plat6->h && doodle->x <= plat6->x + plat6->w && doodle->y - doodle->h <= plat6->y){ 
            plat1->pause();
            plat2->pause();
            plat3->pause();
            plat4->pause();
            plat5->pause();
            plat6->pause();
            plat7->pause();
            plat8->pause();
            plat9->pause();
        }
        if(doodle->x + doodle->w >= plat7->x && doodle->y >= plat7->y + plat7->h && doodle->x <= plat7->x + plat7->w && doodle->y - doodle->h <= plat7->y){ 
            plat1->pause();
            plat2->pause();
            plat3->pause();
            plat4->pause();
            plat5->pause();
            plat6->pause();
            plat7->pause();
            plat8->pause();
            plat9->pause();
        }
        if(doodle->x + doodle->w >= plat8->x && doodle->y >= plat8->y + plat8->h && doodle->x <= plat8->x + plat8->w && doodle->y - doodle->h <= plat8->y){ 
            plat1->pause();
            plat2->pause();
            plat3->pause();
            plat4->pause();
            plat5->pause();
            plat6->pause();
            plat7->pause();
            plat8->pause();
            plat9->pause();
        }
        if(doodle->x + doodle->w >= plat9->x && doodle->y >= plat9->y + plat9->h && doodle->x <= plat9->x + plat9->w && doodle->y - doodle->h <= plat9->y){ 
            plat1->pause();
            plat2->pause();
            plat3->pause();
            plat4->pause();
            plat5->pause();
            plat6->pause();
            plat7->pause();
            plat8->pause();
            plat9->pause();
        }

        if(plat1->y < -1){
            float x = .01 * (rand() % 80 + 1);
            plat1->y = 1 + plat1->h;
            plat1->x = x;
            plat1->resume();
        }
        if(plat2->y < -1){
            float x = -.01 * (rand() % 100 + 1);
            plat2->y = 1 + plat2->h;
            plat2->x = x;
            plat2->resume();
        }
        if(plat3->y < -1){
            float x = .01 * (rand() % 80 + 1);
            plat3->y = 1 + plat3->h;
            plat3->x = x;
            plat3->resume();
        }
        if(plat4->y < -1){
            float x = -.01 * (rand() % 100 + 1);
            plat4->y = 1 + plat4->h;
            plat4->x = x;
            plat4->resume();
        }
        if(plat5->y < -1){
            float x = .01 * (rand() % 80 + 1);
            plat5->y = 1 + plat5->h;
            plat5->x = x;
            plat5->resume();
        }
        if(plat6->y < -1){
            float x = -.01 * (rand() % 100 + 1);
            plat6->y = 1 + plat6->h;
            plat6->x = x;
            plat6->resume();
        }
        if(plat7->y < -1){
            float x = .01 * (rand() % 80 + 1);
            plat7->y = 1 + plat7->h;
            plat7->x = x;
            plat7->resume();
        }
        if(plat8->y < -1){
            float x = -.01 * (rand() % 100 + 1);
            plat8->y = 1 + plat8->h;
            plat8->x = x;
            plat8->resume();
        }
        if(plat9->y < -1){
            float x = .01 * (rand() % 80 + 1);
            plat9->y = 1 + plat9->h;
            plat9->x = x;
            plat9->resume();
        }

}

App::~App(){
    std::cout << "Exiting..." << std::endl;

    delete bg1;
    //delete endgame;
	delete plat1;
    delete plat2;
    delete plat3;
    delete plat4;
    delete plat5;
    delete plat6;
    delete plat7;
    delete plat8;
    delete plat9;

	delete doodle;
}
