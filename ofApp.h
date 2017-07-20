#pragma once

#include "ofMain.h"
#include "ofxFluid.h"
#include "nature.hpp"
#include "background.hpp"
#include "particle.hpp"

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
    
    ofxFluid fluid;
    
    ofVec2f oldM;
    int width, height;
    bool  bPaint, bObstacle, bBounding, bClear;
    
    Nature nature;
    Background background;
    float positionX;
    Particle particles[1000];
		
};
