//
//  background.cpp
//  final
//
//  Created by Kazuki Sakurada on 2017/07/02.
//
//

#include "background.hpp"
#include "ofMain.h"
#include "ofApp.h"

Background::Background()
{
    pointX = ofRandom(ofGetWidth());
    pointY = ofRandom(ofGetHeight());
};

void Background::setup()
{
    ofEnableAlphaBlending();
    ofSetCircleResolution(100);
    
    width = 1200;
    height = 800;
    
    // Initial Allocation
    fluid.allocate(width, height, 0.3);
    
    // Seting the gravity set up & injecting the background image
    fluid.dissipation = 0.99;
    fluid.velocityDissipation = 0.99;
    
    fluid.setGravity(ofVec2f(0.0,0.0));
    
    //  Set obstacle
    fluid.begin();
    ofSetColor(0,0);
    ofSetColor(255);
    ofCircle(width, height, 200);
    fluid.end();
    fluid.setUseObstacles(false);
    
    // Adding constant forces
    //fluid.addConstantForce(ofPoint(width,height), ofPoint(0,-2), ofFloatColor(0.5,0.1,0.0), 10.f);
    
    ofSetWindowShape(width, height);
};

void Background::update()
{
    pointX = ofRandom(ofGetWidth());
    pointY = ofRandom(ofGetHeight());
    ofPoint m = ofPoint(pointX,pointY);
    ofPoint d = (m - oldM)*10.0;
    oldM = m;
    ofPoint c = ofPoint(640*0.5, 480*0.5) - m;
    c.normalize();
    fluid.addTemporalForce(m, d, ofFloatColor(c.x,c.y,0.5)*sin(ofGetElapsedTimef()),3.0f);
    
    fluid.update();
};

void Background::draw()
{
    ofBackgroundGradient(ofColor::gray, ofColor::black, OF_GRADIENT_LINEAR);
    fluid.draw();
};

