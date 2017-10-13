//
//  wave.cpp
//  whitneyRecreation3
//
//  Created by Ann Kidder on 9/27/17.
//
//

#include "wave.hpp"
Wave::Wave(){
}

void Wave::setup(){
    xUpdate = 0;
    yUpdate = 0;
    
    time = ofGetElapsedTimef();
    
}

void Wave::update(){
}

void Wave::draw(){
    for (int i=0;i<200;i++) {
        float circle_freq = ofMap(i, 0, 200, 0, 2*PI);
        float revolutions = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 3);
        float speed = (float)ofGetWidth()/600.0 * revolutions;
        xUpdate = ofGetWidth()/2 + 250 * sin(circle_freq) + i*(ofGetElapsedTimef()-time)*speed;
        yUpdate = 300.0 -          250 * cos(circle_freq);
        ofDrawCircle((int)xUpdate % ofGetWidth(), yUpdate, 5);
    }
}
