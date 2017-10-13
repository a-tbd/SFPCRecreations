#include "ofApp.h"
#include <typeinfo>

//--------------------------------------------------------------
void ofApp::setup(){
    myFont.load("lg.otf", 150, true, true, true);
    text = "drink\nblood";
    rect = myFont.getStringBoundingBox(text, 1, 1);
    myFont.setLineHeight(rect.y-2);
    myFont.setLetterSpacing(.82);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofTranslate(ofGetWidth()/2-100, ofGetHeight()/2+rect.y*.5);
    cout << rect.x << endl; // why is the width 8?
    
    vector < ofPolyline > lines;
    ofPath red_lines;
    ofPath white_lines;
    
    vector < ofPath > characters = myFont.getStringAsPoints(text);
    
    // for each character in my string
    for (int i=0; i<characters.size();i++){
        // for each path within the character
        for (int j=0;j<characters[i].getOutline().size();j++){
            // store the path as a temporary polyline
            ofPolyline temp = characters[i].getOutline()[j];
            
            // create new subpaths for each path within the original character
            red_lines.newSubPath();
            white_lines.newSubPath();
            
            // for each point in the temporary polyline
            for (int k=0; k<temp.size();k++){
                if (k==temp.size()) {
                    red_lines.close();
                    white_lines.close();
                }
                float time = ofGetElapsedTimef();
                // get the x and y values
                float temp_x = temp[k].x;
                float temp_y = temp[k].y;
                
                // animate letter division w/ sine wave?
                //float y_wave = rect.y/2 + sin(circle_freq);
                //float circle_freq = ofMap(k, 0, temp.size(), 0, 2*PI);
                
                float y_wave = rect.y + time*10;
                
                // if the y value is greater than half the height, add point white path
                // also add a point along the separation line to the red path
                if (temp_y < rect.y / 2) {
                    if (k==0) {
                        white_lines.moveTo(temp_x, temp_y);
                        red_lines.moveTo(temp_x, y_wave);
                    } else {
                        white_lines.lineTo(temp_x, temp_y);
                        red_lines.lineTo(temp_x, y_wave);
                    }
                // if the y value is less than half the height, add to red path
                } else if (temp_y >= rect.y / 2) {
                    if (k==0) {
                        white_lines.moveTo(temp_x, y_wave);
                        red_lines.moveTo(temp_x, temp_y);
                    } else {
                        white_lines.lineTo(temp_x, y_wave);
                        red_lines.lineTo(temp_x, temp_y);
                    }
                }
            }
            // close the subpath for each new half character
            lines.push_back(temp);
        }
    }
    
    red_lines.simplify();
    white_lines.simplify();
    
    ofColor white(255,255,255);
    white_lines.setFillColor(white);
    white_lines.draw();
    
    ofColor red(214, 8, 59);
    red_lines.setFillColor(red);
    red_lines.draw();
    
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
