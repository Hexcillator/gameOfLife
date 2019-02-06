#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#define COLS 1024
#define ROWS 768

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);

    
    int size;
    
    int board[COLS][ROWS];
    int next[COLS][ROWS];
    int neighbours=0;
    int columns;
    int rows;
    
    ofxFloatSlider zoom;
    ofxPanel gui;
    
    ofTrueTypeFont title, title2;
    
    int state;
    
    int counter=1;
    int counter2;
    
    bool flashing = false;
};

