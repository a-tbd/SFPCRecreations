//
//  emoji.cpp
//  cloudZZRecode1
//
//  Created by Ann Kidder on 11/13/17.
//
//

#include "emoji.hpp"

Emoji::Emoji(){
}

void Emoji::setup(int x, int y, ofImage icon){
    x_start = x;
    img = icon;
    emojiSpeed = 1;
    emojiSize = img.getWidth();
    y_val = y;
    creation_time = ofGetElapsedTimef();
}

void Emoji::update(){
    y_val += emojiSpeed;
}

void Emoji::draw(){
    //img.resize(emojiSize, emojiSize);
    float time = ofGetElapsedTimef();
    float time_diff = time - creation_time;
    ofSetRectMode(OF_RECTMODE_CENTER);
    float w = ofGetMouseX();
    img.draw(x_start, y_val,  emojiSize,  emojiSize);

    ofSetRectMode(OF_RECTMODE_CORNER);
}
