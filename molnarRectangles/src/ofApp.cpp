#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(232,230,239);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    /*
     Recreation of Vera Molnar piece:
     https://image.invaluable.com/housePhotos/artcurial/23/301023/H1118-L22105038.jpg
     */
    
    ofSeedRandom(mouseX);
    
    // function to draw a square
    int square(int a, int b);
    
    ofSetColor(0);
    ofNoFill();
    
    ofColor myColors[3];
    
    //red
    myColors[0] = ofColor(170,101,10);
    //orange
    myColors[1] = ofColor(79,19,19);
    //blue
    myColors[2] = ofColor(23,50,94);
    
    for (int i=0; i<9;i++){
        for (int j=0;j<6;j++){
            // calculate number of rectangles to draw in each column
            int repeat;
            if (i<3){
                repeat = 1+i*i;
            } else if (i == 3) {
                repeat = 25;
            } else {
                float f = 0.642857*i*i - 9.81429*i + 38.6571;
                repeat = static_cast<int>(f);
            }
            // draw rectangles
            int random_color;
            if (i == 3) {
                random_color = ofRandom(1,3);
            } else {
                random_color = ofRandom(0,3);
            }

            ofSetColor( myColors[ (int) ofRandom(0,3)]);
            for (int k=0;k<repeat;k++){
                square(i,j);
            }
        }
    }
}

int square(int a, int b) {
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofBeginShape();
        int start_x = 100+a*100+ofRandom(-10,10);
        int start_y = 100+b*100+ofRandom(-10,10);
        ofVertex(start_x, start_y);
        ofVertex(start_x+ofRandom(-20,20), start_y+80+ofRandom(-10,10));
        ofVertex(start_x+80+ofRandom(-20,20), start_y+80);
        ofVertex(start_x+80, start_y+ofRandom(-10,10));
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
