#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // create two fbos for color and type
    color_fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA, 4);
    text_fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA, 4);
    
    img.load("casey.jpg");
    
    // set parameters
    panel.setup();
    group.add(radius.set("radius", 150, 0, 200));
    group.add(partyMode.set("party mode",0,0,1));
    group.add(yPos.set("y-position", ofGetHeight()*.7, 0, ofGetHeight()));
    
    panel.add(group);
    
    panel.loadFromFile("settings.xml");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    text_fbo.getTexture().setAlphaMask(color_fbo.getTexture());
    
    float time = ofGetElapsedTimef();
    int xAmp = 50;
    
    color_fbo.begin();
    ofBackground(255);
    
    ofSetCircleResolution(100);
    int partyStart = 0;
    if (partyMode > 0) {
        partyStart = 127;
    }
    
    for (int i = 0; i < 700; i++){
                ofSetColor( 255 - abs( 255*sin(partyMode*i * 0.1)),
                            partyStart + partyStart * sin(partyMode*i * 0.11),
                           partyStart + partyStart * sin(partyMode*i * 0.12));
        ofDrawCircle(200 + i*2, yPos + xAmp * sin(i*0.03 + time*1.4), radius);
        
    }
    color_fbo.end();
    
    // set the alpha layer as text
    text_fbo.begin();
    ofClear(0,0,0,255);

    img.draw((ofGetWidth() - img.getWidth())/2., (ofGetHeight() - img.getHeight())/2.);
    text_fbo.end();
    
    color_fbo.draw(0,0);
    text_fbo.draw(0,0);
    
    // draw the GUI
    panel.draw();
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
