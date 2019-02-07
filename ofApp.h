#pragma once

#include "ofMain.h"
#include "ofxGui.h"
//this is the maximum number of columns and rows the grid will hold
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
    //updated grid
    int next[COLS][ROWS];
    int neighbours=0;
    int columns;
    int rows;
    //gui control
    ofxFloatSlider zoom;
    ofxPanel gui;
    
    ofTrueTypeFont title, title2;
    
    int state;
    
    int counter=1;
    int counter2;
    
    bool flashing = false;
};

