#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofBackground(0);
    
    //loads font file and sets size
    title.load("barcade-brawl.ttf",30);
    title2.load("barcade-brawl.ttf",7);
    
    //size of cells
    size = 1;
    
    
    //size of grid
    columns=(int)ofGetWidth()/size;
    rows=(int)ofGetHeight()/size;
    
    
    //slide that controls interactively cells size
    gui.setup();
    gui.add(zoom.setup("Zoom in/out", 10, 1, 30));
    
    
    //produces a random array of live and dead cells as an initial state
    for (int x=1; x<columns; x++) {
        for (int y=1; y<rows; y++) {
            board[x][y] = int(ofRandom(2));
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //counters created to display a flashing title in state 0
    counter++;
    
    if(counter % 5 == 0){
        if(counter2 > 4){
            counter2 = 0;
            
        }else if(counter2 < 4){
            flashing = true;
        }else{
            flashing = false;
        }
        counter2++;
    }
    
    
    //we can replace a fixed size if we don't want the slider
    size=zoom;
    
    //create a 2d grid
    for (int x = 1; x < columns; x++) {
        for (int y = 1; y < rows; y++) {
            
            neighbours = 0;
            //checks each neighbour cell
            for(int i = -1;i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    /*asumming the game is set in an infinite two-dimensional grid all 4 edges are wrapped to create a kind of infinity. For example,
                     cells 0 on the X axis will be neighbour of the cells in the last column, same goes for cells 0 on the Y axis, they automatically are considered neighbours of the last row of the grid.
                     
                     */
                    
                    int col = (x+i+columns) % columns;//The total of columns is also added to avoid negative numbers and join the grid to the left
                    int row = (y+j+rows) % rows;
                    
                    neighbours+=board[col][row];
                }
            }
            
            //subtract main cell from the sum
            neighbours-=board[x][y];
            
            //rules of life where 1 = life and 0 = death
            
            //Underpopulation
            if      ((board[x][y] == 1) && (neighbours <  2)){
                next[x][y] = 0;
                
            }
            //Overcrowding
            else if ((board[x][y] == 1) && (neighbours >  3)){
                
                next[x][y] = 0;
            }
            
            //creation of life
            else if ((board[x][y] == 0) && (neighbours ==  3)){
                next[x][y] = 1;
                
            }
            
            // survival
            else{
                next[x][y] = board[x][y];
            }
        }
        
    }
    //update the grid
    for (int x = 1; x<columns; x++) {
        for (int y = 1; y <rows; y++) {
            board[x][y] = next[x][y];
        }
        
    }
    
    

}

//--------------------------------------------------------------


void ofApp::draw(){
    
    switch(state){
        case 0:
            //welcome screen
            ofSetColor(255, 30, 255);
            title.drawString("Game of Life",ofGetWidth()/4,ofGetHeight()/2);
            if(flashing){
                ofSetColor(0, 130, 255);
                title2.drawString("Press '1' to Start",ofGetWidth()/2-80,410);
                
            }
            break;
            
        case 1:
            //draws the game, control and titles
            gui.draw();
            ofSetColor(255, 30, 255);
            title.drawString("Game of Life",ofGetWidth()/4,50);
            ofSetColor(0, 130, 255);
            title2.drawString("Press 'r' to Restart",ofGetWidth()-250,15);
            title2.drawString("Press 'c' to Clear",ofGetWidth()-250,30);
            title2.drawString("Press 'q' to Quit",ofGetWidth()-250,45);
            
            //translate grid 55 pixels down
            glTranslatef(0,55,0);
            
            //Draw grid
            for (int x = 0; x < columns; x++) {
                for (int y = 0; y< rows; y++) {
                    if(board[x][y] == 1){
                        ofSetColor(10,255,0);
                        ofFill();
                        
                    }else{
                        ofSetColor(0);
                        ofNoFill();
                        
                        /*whenever we zoom out the stroke of the cells stays the original size to the point of not letting us see the cells properly so I decided to map the zoom value to a grayscale to match the background color and create a smoother color transition. */
                        int color;
                        int stroke = ofMap(size, 1, 30, 0, 255);
                        ofSetColor(stroke);
                    }
                    
                    ofDrawRectangle(x*size, y*size, size,size);
                }
            }
            break;
    }
    
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    //keys controlling the game
    
    if(key == '1' ){
        state = 1;
        
    }
    
    if(state==1){
        if( key == 'r'||key == 'R' ){
            for (int x=1; x<columns; x++) {
                for (int y=1; y<rows; y++) {
                    //resets grid to random seeding
                    board[x][y] = int(ofRandom(2));
                }
            }
        }else if( key == 'c'||key == 'C' ){
            for (int x=1; x<columns; x++) {
                for (int y=1; y<rows; y++) {
                    //clears grid
                    board[x][y] = 0;
                }
            }
        }else if( key == 'q'||key == 'Q'){
            state=0;
        }
    }
    
}













