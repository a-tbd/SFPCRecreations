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
    x = 0;
    y = 0;
    
    time = ofGetElapsedTimef();
}

void Wave::update(){
    for (int i=0;i<200;i++) {
        float currentTime = ofGetElapsedTimef();
        x = (float)-10.0 + i*(currentTime-time)*5;
        y = (float)300.0 + 250 * sin(i*.05-PI/2);
    }
}

void Wave::draw(){
    ofDrawCircle(x, y, 10);
}
