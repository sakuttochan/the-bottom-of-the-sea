//
//  particle.hpp
//  final
//
//  Created by Kazuki Sakurada on 2017/07/18.
//
//

#ifndef particle_hpp
#define particle_hpp

#include <stdio.h>
#include <iostream>
#include "ofMain.h"

class Particle
{
    
public:
    
    //memnber
    float xPos;
    float yPos;
    float xSpeed;
    float ySpeed;
    float radius; // radius of particles;
    int colorNum;
    
    ofColor color;
    //constructor
    Particle();
    
    //method
    void update();
    void draw();
};

#endif /* particle_hpp */
