#pragma once

#include "ofMain.h"
#include "ofxPanel.h"

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
    
    ofFbo color_fbo;
    ofFbo text_fbo;
    
    ofImage img;
    
    ofxPanel panel;
    ofParameterGroup group;
    ofParameter < float > radius;
    ofParameter < float > partyMode;
    ofParameter < float > yPos;
		
};
