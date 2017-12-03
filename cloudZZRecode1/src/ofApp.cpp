#include "ofApp.h"
#include "emoji.hpp"
#include <algorithm>

//--------------------------------------------------------------
void ofApp::setup(){
    cookie.load("cookie.png");
    cupcake.load("cupcake.png");
    donut.load("donut.png");
    popsicle.load("popsicle.png");
    strawberry.load("strawberry.png");
    
    icons[0] = cookie;
    icons[1] = cupcake;
    icons[2] = donut;
    icons[3] = popsicle;
    icons[4] = strawberry;
    
    panel.setup();
    group.add(cloud_size.set("cloud size", 200, 50, 700));
    group.add(emojiSpeed.set("emoji speed", 4, 1, 10));
    group.add(jiggle.set("jiggle", .05, .05, .25));
    panel.add(group);
    
    time = 0;
    y_fall = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0;i<my_emojis.size();i++){
        my_emojis[i].emojiSpeed = emojiSpeed;
        my_emojis[i].emojiSize = ofMap(cloud_size, 50, 700, 20, 100);
        my_emojis[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255, 163, 224);
    // cloud variables
    int cloud_width = cloud_size;
    int cloud_height = cloud_width*.72;
    
    float center_x = ofGetWidth()/2;
    float center_y = cloud_height/2*1.3;
    
    int x_wiggle_low = -cloud_width*.06;
    int x_wiggle_hi = cloud_width*.06;
    
    int y_wiggle_low = -cloud_height*.03;
    int y_wiggle_hi = cloud_height*.03;
    
    // verticle bounce
    time += jiggle;
    ofSetCircleResolution(100);
    int y_off = center_y;
    y_off += cloud_height*.1*sin(ofGetElapsedTimef());
    
    // check if new emoji should be created
    float timeSinceLastEmoji = ofGetElapsedTimef() - lastCreationTime;
    
    if (timeSinceLastEmoji > creationDelay){
        total_emojis += 1;
        Emoji temp;
        int index = ofRandom(0,5);
        temp.setup(center_x+ofRandom(-cloud_width/2*.9,cloud_width/2*.6), center_y, icons[index]);
        temp.emojiSize = ofMap(cloud_size, 50, 700, 20, 100);
        my_emojis.push_back(temp);
        lastCreationTime = ofGetElapsedTimef();
    }
    
    for (int i=0;i<my_emojis.size();i++){
        my_emojis[i].draw();
    }
    
    // draw the cloud
    ofDrawCircle(center_x - cloud_width*.075+ofMap(ofNoise(10+time*.8), 0, 1, x_wiggle_low, x_wiggle_hi),
                 y_off - cloud_height*.206+ofMap(ofNoise(10+time*.8), 0, 1, y_wiggle_low, y_wiggle_hi),
                 cloud_width*.23);
    ofDrawCircle(center_x - cloud_width*.313+ofMap(ofNoise(20+time*.8), 0, 1, x_wiggle_low, x_wiggle_hi),
                 y_off - cloud_height*.041+ofMap(ofNoise(20+time*.8), 0, 1, y_wiggle_low, y_wiggle_hi),
                 cloud_width*.16);
    ofDrawCircle(center_x - cloud_width*.096+ofMap(ofNoise(30+time*.8), 0, 1, x_wiggle_low, x_wiggle_hi),
                 y_off + cloud_height*.212+ofMap(ofNoise(30+time*.8), 0, 1, y_wiggle_low, y_wiggle_hi),
                 cloud_width*.18);
    ofDrawCircle(center_x + cloud_width*.194+ofMap(ofNoise(40+time*.8), 0, 1, x_wiggle_low, x_wiggle_hi),
                 y_off - cloud_height*.162+ofMap(ofNoise(40+time*.8), 0, 1, y_wiggle_low, y_wiggle_hi),
                 cloud_width*.15);
    ofDrawCircle(center_x + cloud_width*.309+ofMap(ofNoise(50+time*.8), 0, 1, x_wiggle_low, x_wiggle_hi),
                 y_off + cloud_height*.056+ofMap(ofNoise(50+time*.8), 0, 1, y_wiggle_low, y_wiggle_hi),
                 cloud_width*.17);
    ofDrawCircle(center_x + cloud_width*.127+ofMap(ofNoise(60+time*.8), 0, 1, x_wiggle_low, x_wiggle_hi),
                 y_off + cloud_height*.132+ofMap(ofNoise(60+time*.8), 0, 1, y_wiggle_low, y_wiggle_hi),
                 cloud_width*.15);
    ofDrawCircle(center_x + cloud_width*.138+ofMap(ofNoise(70+time*.8), 0, 1, x_wiggle_low, x_wiggle_hi),
                 y_off + cloud_height*.206+ofMap(ofNoise(70+time*.8), 0, 1, y_wiggle_low, y_wiggle_hi),
                 cloud_width*.13);
    
    // remove emojis that fall below the display
    std::remove_if (my_emojis.begin(), my_emojis.end(), emoji_out_of_range);
    
    panel.draw();
}

// check whether emoji should be removed
bool emoji_out_of_range(Emoji emoji) {
    if (emoji.y_val > ofGetHeight()){
        return true;
    } else {
        return false;
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
