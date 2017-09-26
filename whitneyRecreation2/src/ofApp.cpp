#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
}

//--------------------------------------------------------------
void ofApp::update(){

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
    
    float x_2, y_2;
    for (int i=0;i<200;i++) {
        x_2 = (float) + i*time*5;
        y_2 = 350.0 + 250 * sin(i*.05-PI/2);
        ofDrawCircle(x_2, y_2, 5);
    }
    
    float x_3, y_3;
    for (int i=0;i<200;i++) {
        x_3 = (float)-ofGetWidth()/2.0 + i*time*5;
        y_3 = 400.0 + 250 * sin(i*.05-PI/2);
        ofDrawCircle(x_3, y_3, 5);
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
