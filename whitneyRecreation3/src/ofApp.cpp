#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for (int i=0;i<NWAVES;i++){
        myWaves[i].setup();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<NWAVES; i++){
        myWaves[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    float time = ofGetElapsedTimef();
    
    float x_1, y_1;
    for (int i=0;i<200;i++) {
        x_1 = (float)ofGetWidth()/2.0 + i*time*5;
        y_1 = 300.0 + 250 * sin(i*.05-PI/2);
        ofDrawCircle(x_1, y_1, 5);
    }
    
    float timeSinceLastCreation = ofGetElapsedTimef() - lastCreationTime;
    float prev_y = 300.0;
    int total_waves = 0;
    
    if (timeSinceLastCreation > creationDelay){
        
        myWaves[total_waves % 20].draw();
        total_waves += 1;
        
        lastCreationTime = ofGetElapsedTimef();
    }
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
