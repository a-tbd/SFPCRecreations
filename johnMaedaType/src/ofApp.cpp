#include "ofApp.h"
#include <iostream>
#include <cmath>

//--------------------------------------------------------------
void ofApp::setup(){
    myFont.load("Shumi.otf", 300, true, true, true);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofSetColor(0);
    
    // store text as string and get bounding box
    string text = "HELLO";
    ofRectangle rect = myFont.getStringBoundingBox(text, 0, 0);
    
//    // working example of shrinking rectangles
//    float draw_height = 0;
//    
//    for (int i=0; i<100; i++) {
//        float box_width = ofGetWidth() * powf(.8333, i);
//        float draw_width = (ofGetWidth() - box_width) / 2;
//        
//        float box_height = (ofGetHeight() - draw_height) / 6;
//
//        // add color change to rectangles
//        ofSetColor(255-(i+1)*10, 0,0);
//        ofDrawRectangle(draw_width, draw_height, box_width, box_height);
//        
//        draw_height += box_height;
//    }
    
    // need to scale the part that gets added to the draw_height...it needs to be scaled too
    float draw_height = 0;
    
    for (int i=0; i<100; i++) {
        float box_width = ofGetWidth() * powf(.8333, i);
        float draw_width = (ofGetWidth() - box_width) / 2;
        
        float box_height = (ofGetHeight() - draw_height) / 6;
        
        float scale_w = ofMap(box_width, 0, ofGetWidth(), 0, 1); // why do I need to multiply these by two?
        float scale_h = ofMap(box_height, 0, ofGetHeight()/3, 0, 1);
        
        ofPushMatrix();
        ofTranslate(draw_width, draw_height);
        ofScale(scale_w, scale_h, 1);
        
        //ofSetColor(255 -(i+1)*10, 0,0);
        
        //ofDrawRectangle(0, 0, box_width, box_height);
        myFont.drawString(text, 1, 1);
        
        draw_height += box_height;
        ofPopMatrix();
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
