//
//  nature.cpp
//  final
//
//  Created by Kazuki Sakurada on 2017/07/02.
//
//

#include "nature.hpp"
#include <stdio.h>
#include <iostream>
#include "ofMain.h"
#include "ofVbo.h"

#define NUM_BILLBOARDS 150000

Nature::Nature()
{
    ofVbo vbo;
    ofShader shader;
    ofImage texture;
    ofVec2f pos[NUM_BILLBOARDS];
    ofVec2f vel[NUM_BILLBOARDS];
    ofVec2f home[NUM_BILLBOARDS];
    float pointSizes[NUM_BILLBOARDS];
    float rotations[NUM_BILLBOARDS];
};

void Nature::setup()
{
    ofBackground(0);
    ofSetVerticalSync(true);
    
    // billboard particles
    for (int i=0; i<NUM_BILLBOARDS; i++) {
        pos[i].x = ofRandomWidth();
        pos[i].y = ofRandomHeight();
        vel[i].x = ofRandomf();
        vel[i].y = ofRandomf();
        home[i] = pos[i];
        pointSizes[i] = ofRandom(2, 40);
        rotations[i] = ofRandom(0, 360);
    }
    
    // set the vertex data
    vbo.setVertexData(pos, NUM_BILLBOARDS, GL_DYNAMIC_DRAW);
    if(ofIsGLProgrammableRenderer()){
        shader.load("shaderGL3/Billboard");
    }else{
        shader.load("shaderGL2/Billboard");
    }
    
    ofDisableArbTex();
    texture.load("snow.png");
    
    // we are getting the location of the point size attribute
    // we then set the pointSizes to the vertex attritbute
    // we then bind and then enable
    shader.begin();
    int pointAttLoc = shader.getAttributeLocation("pointSize");
    vbo.setAttributeData(pointAttLoc, pointSizes, 1, NUM_BILLBOARDS, GL_DYNAMIC_DRAW);
    
    // rotate the snow based on the velocity
    int angleLoc = shader.getAttributeLocation("angle");
    vbo.setAttributeData(angleLoc, rotations, 1, NUM_BILLBOARDS, GL_DYNAMIC_DRAW);
    shader.end();
};

void Nature::update()
{
    ofVec2f mouse(ofGetMouseX(), ofGetMouseY());
    ofVec2f mouseVec(ofGetPreviousMouseX()-ofGetMouseX(), ofGetPreviousMouseY()-ofGetMouseY());
    mouseVec.limit(10.0);
    
    for (int i=0; i<NUM_BILLBOARDS; i++) {
        ofSeedRandom(i);
        if(mouse.distance(pos[i]) < ofRandom(100, 200)) {
            vel[i] -= mouseVec;
        }
        
        pos[i] += vel[i];
        vel[i] *= 0.84f;
        
        if(pos[i].x < 0) pos[i].x = ofGetWidth();
        if(pos[i].x > ofGetWidth()) pos[i].x = 0;
        if(pos[i].y < 0) pos[i].y = ofGetHeight();
        if(pos[i].y > ofGetHeight()) pos[i].y = 0;
        
        ofVec2f center(ofGetWidth()/2, ofGetHeight()/2);
        ofVec2f frc = home[i] - pos[i];
        if(frc.length() > 20.0) {
            frc.normalize();
            frc *= 0.84;
            vel[i] += frc;
        }
        
        // get the 2d heading
        float angle = (float)atan2(-vel[i].y, vel[i].x) + PI;
        rotations[i] = (angle * -1.0);
    }
};

void Nature::draw()
{
    ofEnableAlphaBlending();
    ofSetColor(60, 135, 230);
    
    shader.begin();
    ofEnablePointSprites();
    
    
    texture.getTexture().bind();
    vbo.updateVertexData(pos, NUM_BILLBOARDS);
    
    // rotate the snow based on the velocity
    int angleLoc = shader.getAttributeLocation("angle");
    vbo.updateAttributeData(angleLoc, rotations, NUM_BILLBOARDS);
    
    vbo.draw(GL_POINTS, 0, NUM_BILLBOARDS);
    texture.getTexture().unbind();
    
    ofDisablePointSprites();
    shader.end();
};
