#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    panel.setup();
    panel.add(addRepeat.set("Repeats", 0.,0.,20.));
    panel.add(xPos.set("Horizontal stretch",10.,10.,50.));
    panel.add(yPos.set("Vertical stretch",10.,10.,50.));
    
    panel.loadFromFile("settings.xml");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSeedRandom(0);
    
    // draw background
    ofBackground(226,223,232);
    
    ofSetLineWidth(1);
    
    
    ofSetColor(0);
    ofNoFill();
    
    ofColor myColors[6];
    
    //red
    myColors[0] = ofColor(88,0,0, 150);
    myColors[1] = ofColor(88,0,0, 150);
    
    //blue
    myColors[2] = ofColor(0,0,58,150);
    myColors[3] = ofColor(0,0,58,150);
    myColors[4] = ofColor(0,0,58,150);
    
    //orange
    myColors[5] = ofColor(179,74,36,150);
    
    for (int i=0; i<col;i++){
        for (int j=0;j<row;j++){
            // calculate number of rectangles to draw in each column
            int repeat;
            
            if (i<3){
                repeat = 1+i*i;
            } else if (i == 3) {
                repeat = 40;
            } else {
                int val = col-i;
                float f = val*val;
                repeat = static_cast<int>(f);
            }
            // draw rectangles
            int random_color;
            if (i == row) {
                random_color = ofRandom(1,row);
            } else {
                random_color = ofRandom(0,row);
            }
            repeat += addRepeat;
            
            ofSetColor( myColors[ (int) ofRandom(0,row)]);
            for (int k=0;k<repeat;k++){
                square(i,j);
            }
        }
    }
    // draw the GUI
    panel.draw();
}

void ofApp::square(int a, int b) {
    int padding_w = ofGetWidth() *.1;
    int inner_width = ofGetWidth() - padding_w * 2;
    
    int padding_h = ofGetHeight() *.2;
    int inner_height = ofGetHeight() - padding_h * 2;
    
    int square_w = inner_width / col * 0.6;
    
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofBeginShape();
    
    int start_x = padding_w+a*inner_width/col+ofRandom(-xPos,xPos);
    int start_y = padding_h+b*inner_height/row+ofRandom(-yPos,yPos);
    ofVertex(start_x, start_y);
    ofVertex(start_x+ofRandom(-xPos,xPos), start_y+square_w+ofRandom(-yPos,yPos));
    ofVertex(start_x+square_w+ofRandom(-xPos,xPos), start_y+square_w);
    ofVertex(start_x+square_w, start_y+ofRandom(-yPos,yPos));
    ofEndShape(true);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
