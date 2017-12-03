#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cat.load("cat.jpg");
    dog.load("dog.jpg");
    
    cat.setImageType(OF_IMAGE_GRAYSCALE);
    dog.setImageType(OF_IMAGE_GRAYSCALE);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(100);
    map < int, ofColor > locations;
    float time = ofGetElapsedTimef();
    float time_since_last_update = ofGetElapsedTimef() - update_time;
    if (time_since_last_update > delay){
        update_time = ofGetElapsedTimef();
        if (show_cat == true) {
            show_cat = false;
        } else {
            show_cat = true;
        }
    }
    
    //cout << time_since_last_update << endl;
    
    unsigned char * data_cat = cat.getPixels().getData();
    unsigned char * data_dog = dog.getPixels().getData();
    
//    for (int i = 0; i < cat.getWidth(); i+=5){
//        for (int j = 0; j < cat.getHeight(); j+=5){
//            int index = j*cat.getWidth() + i;
//            int average = 0;
//            for (int k = 0; k<5;k++) {
//                int index2 = (j+k)*cat.getWidth()+i+k;
//                average += data[index2];
//                cout << average << " " << data[index] << " " << data[index2] << endl;
//            }
//            locations[index] = average;
//        }
//    }

    for (int i = 0; i < cat.getWidth(); i+=5){
        for (int j = 0; j < cat.getHeight(); j+=5){
            float fade;
            
            if (time_since_last_update < 5) {
                fade = abs(ofMap(time_since_last_update, 0, 5, 0, 1.0));
            } else {
                fade = abs(ofMap(time_since_last_update, 5, 10, 1.0, 0));
            }
            // y * w + x;
            int index;
            int brightness;
            if (show_cat) {
                index = j * cat.getWidth() + i;
                brightness = data_cat[index];
            } else {
                index = j * dog.getWidth() + i;
                brightness = data_dog[index];
            }
            //int brightness2 = locations[index];
            cout << fade << endl;
            float radius = fade*ofMap(brightness, 0, 255, 0, 5);
            ofDrawCircle(i*2, j*2, radius);
        }
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
