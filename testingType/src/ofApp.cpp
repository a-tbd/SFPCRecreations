#include "ofApp.h"
#include <typeinfo>

//--------------------------------------------------------------
void ofApp::setup(){
    myFont.load("lg.otf", 150, true, true, true);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    
    //myFont.drawString("hello", 250, 250);
    vector < ofPolyline > lines;
    vector < ofPolyline > red_lines;
    vector < ofPolyline > white_lines;
    
    vector < ofPath > characters = myFont.getStringAsPoints("hello");
    
    // for each character in my string
    for (int i=0; i<characters.size();i++){
        // for each path within the character
        for (int j=0;j<characters[i].getOutline().size();j++){
            //vector < ofPoint > red_points;
            //vector < ofPoint > white_points;
            // store the path as a temporary polyline
            ofPolyline temp = characters[i].getOutline()[j];
            ofPolyline temp_red;
            ofPolyline temp_white;
            // for each point in the temporary polyline
            for (int k=0; k<temp.size();k++){
                // get the x and y values
                float temp_x = temp[k].x;
                float temp_y = temp[k].y;
                cout << temp_y << typeid(temp_y).name() << endl;
                
                // if the y value is greater than 100, add point white vector
                // also add a point along the separation line to the red vector
                if (temp_y < -80.0) {
                    temp_white.addVertex(ofVec2f(temp_x, temp_y));
                    temp_red.addVertex(ofVec2f(temp_x, -80));
                    cout << "white" << temp_y << typeid(temp_y).name() << endl;
                } else if (temp_y >= -80.0) {
                    temp_white.addVertex(ofVec2f(temp_x, -80));
                    temp_red.addVertex(ofVec2f(temp_x, temp_y));
                    cout << "red" << temp_y << endl;
                }
            }
            temp_red.close();
            temp_white.close();
            red_lines.push_back(temp_red);
            white_lines.push_back(temp_white);
            lines.push_back(temp);
        }
    }
    
    ofSetColor(255);
    for (int i=0;i<white_lines.size();i++){
        white_lines[i].draw();
    }
    
    ofSetColor(155,0,0);
    for (int i=0;i<red_lines.size();i++){
        red_lines[i].draw();
    }
    
    
//    for (int i=0;i<red_lines.size()-1;i++){
//        for (int j=0;j<)
//        ofSetColor(150, 0,0);
//        ofdr
//    }
//    
//    for (int i=0; i<white_lines.size()-1; i++) {
//        ofSetColor(255);
//        ofPoint a = white_lines[i];
//        ofPoint b = white_lines[i+1];
//        ofLine(a,b);
//    }


    
    
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
