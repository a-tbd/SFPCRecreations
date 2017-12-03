#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    myImg.allocate(500,500, OF_IMAGE_COLOR);
    
//    for (int i=0;i<500;i++) {
//        for (int j=0;j<500;j++) {
//            myImg.setColor(i,j,ofColor(ofRandom(0,255)));
//        }
//    }
    myImg.update();
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0;i<500;i++) {
        for (int j=0;j<500;j++) {
            float dist = ofDist(mouseX, mouseY, i, j);
            if (dist < 100) {
                myImg.setColor(i,j,ofColor(127+127*sin(dist*.1), i, j));
            } else {
                myImg.setColor(i,j,ofColor(127-127*sin(dist*.1), i, j));
            }
            //myImg.setColor(i,j,ofColor(i*j, 255-j,0));
        }
    }
    myImg.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    myImg.draw(0,0);
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
