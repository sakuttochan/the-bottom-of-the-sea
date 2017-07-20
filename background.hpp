//
//  background.hpp
//  final
//
//  Created by Kazuki Sakurada on 2017/07/02.
//
//

#ifndef background_hpp
#define background_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxFXObject.h"
#include "ofxFluid.h"

class Background
{
public:
    //constructor
    Background();
    //member
    ofxFluid fluid;
    ofVec2f oldM;
    int width, height;
    int pointX, pointY;
    bool  bPaint, bObstacle, bBounding, bClear;
    //method
    void setup();
    void update();
    void draw();
};

#endif /* background_hpp */
