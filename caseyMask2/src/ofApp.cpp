#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // create two fbos for color and type
    color_fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA, 4);
    text_fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA, 4);
    
    // load small and large size font (is there a way to change font
    // size without laoding separately?
    myFont_last.setLetterSpacing(.9);
    myFont_small.setLetterSpacing(.9);
    myFont_small.load("lg.otf", 110, true, true, true);
    text_first = "JACQUELINE";
    myFont_last.load("lg.otf", 200, true, true, true);
    text_last = "CASEY";
    rect_first = myFont_small.getStringBoundingBox(text_first, 1, 1);
    rect_last = myFont_last.getStringBoundingBox(text_last, 1, 1);
    
    // set parameters
    panel.setup();
    group.add(radius.set("radius", 150, 0, 200));
    group.add(color.set("green", 0, 0, 1.5));
    group.add(color2.set("pink",0,0,1.5));
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
    
    for (int i = 0; i < 700; i++){
                ofSetColor( 255 - 255 * sin(i * color+0.01),
                            127 * sin(i * color+0.011),
                           127 * sin(i * color2+0.012));
        ofDrawCircle(200 + i*2, yPos + xAmp * sin(i*0.03 + time*1.4), radius);
        
    }
    color_fbo.end();
    
    // set the alpha layer as text
    text_fbo.begin();
    ofClear(0,0,0,255);
    ofSetColor(255);
    myFont_small.setLineHeight(rect_first.y-2);
    myFont_small.drawString(text_first, (ofGetWidth()-rect_first.width)/2, (ofGetHeight()-(rect_first.height+rect_last.height))/2+rect_first.height);
    
    myFont_last.setLineHeight(rect_last.y-2);
    myFont_last.drawString(text_last, (ofGetWidth()-rect_first.width)/2, (ofGetHeight()-(rect_first.height+rect_last.height))/2+rect_first.height+rect_last.height);
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
