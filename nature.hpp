//
//  nature.hpp
//  final
//
//  Created by Kazuki Sakurada on 2017/07/02.
//
//

#ifndef nature_hpp
#define nature_hpp

#define NUM_BILLBOARDS 150000

#include <stdio.h>
#include <iostream>
#include "ofMain.h"
#include "ofVbo.h"

class Nature {
public:
    //constructor
    Nature();
    //member
    ofVbo vbo;
    ofShader shader;
    ofImage texture;
    ofVec2f pos[NUM_BILLBOARDS];
    ofVec2f vel[NUM_BILLBOARDS];
    ofVec2f home[NUM_BILLBOARDS];
    float pointSizes[NUM_BILLBOARDS];
    float rotations[NUM_BILLBOARDS];
    //method
    void changeNature();
    void setup();
    void update();
    void draw();
};

#endif /* nature_hpp */
