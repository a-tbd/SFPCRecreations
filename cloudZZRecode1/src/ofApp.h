#pragma once

#include "ofMain.h"
#include "emoji.hpp"
#include "ofxPanel.h"

bool emoji_out_of_range(Emoji emoji);

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    // emoji rain
    ofImage cookie;
    ofImage cupcake;
    ofImage donut;
    ofImage popsicle;
    ofImage strawberry;
    
    ofImage icons[5];
    
    int total_emojis = 0;
    
    float lastCreationTime;
    float creationDelay = .5;
    
    vector < Emoji > my_emojis;
    
    ofxPanel panel;
    ofParameterGroup group;
    
    ofParameter < float > cloud_size;
    ofParameter < float > emojiSpeed;
    ofParameter < float > jiggle;
    
    float time;
    float y_fall;
    
		
};
