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
    xUpdate = xStart;
    yUpdate = yStart;
    
    time = ofGetElapsedTimef();
}

void Wave::update(){
}

void Wave::draw(){
    for (int i=0;i<200;i++) {
        xUpdate = (float)i*(ofGetElapsedTimef()-time)*5;
        yUpdate = (float)300.0 + 250 * sin(i*.05-PI/2);
        ofDrawCircle(xUpdate, yUpdate, 5);
    }
}
