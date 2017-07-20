//
//  particle.cpp
//  final
//
//  Created by Kazuki Sakurada on 2017/07/18.
//
//

#include "particle.hpp"
#include "ofMain.h"

Particle::Particle() {
    xPos = ofRandom(ofGetWidth());
    yPos = ofRandom(ofGetHeight());
    xSpeed = ofRandom(2, 8);
    ySpeed = ofRandom(5, 18);
    colorNum = ofRandom(170, 255);
    color = ofColor(colorNum, colorNum, 255, 110);
    radius = ofRandom(0.5, 10.0);
};

void Particle::update() {
    xPos += xSpeed;
    yPos += ySpeed;
    colorNum = ofRandom(0, 255);
    
    //右端
    if (xPos > ofGetWidth()) {
        xPos = 0;
    }
    //左
    if (xPos < 0 ) {
        xPos = ofGetWidth();
    }
    //下
    if (yPos > ofGetHeight()) {
        yPos = 0;
    }
    //上
    if (yPos < 0) {
        yPos = ofGetHeight();
    }
    
}

void Particle::draw() {
    ofSetColor(color);
    ofDrawCircle(xPos, yPos, radius);
}
