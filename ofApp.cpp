#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    background.setup();
    nature.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    background.update();
    nature.update();
    positionX += 0.1;
    for (int i = 0; i < 1000; i++) {
        particles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    background.draw();
    nature.draw();
    for (int i = 0; i < 1000; i++) {
        particles[i].draw();
    }
    for (int i = 0; i < 1000; i++) {
        Particle tmp = particles[i];
        
        for (int j = 0; j < 1000; j++) {
            float d = sqrt((particles[j].xPos - tmp.xPos) * (particles[j].xPos - tmp.xPos) + (particles[j].yPos - tmp.yPos) * (particles[j].yPos - tmp.yPos));
            if (d < 50) {
                ofDrawLine(tmp.xPos, tmp.yPos, particles[j].xPos, particles[j].yPos);
            }
        }
    }
    for (int j = 0; j < 5000; j++) {
        ofSetColor(int(ofRandom(120)), int(ofRandom(255)), int(ofRandom(255)), ofRandom(40.0, 60.0));
        ofDrawRectangle(ofRandom(340.0, 640.0), ofRandom(230.0, 509.0), 10.0, 10.0);
        ofSetColor(int(ofRandom(160)), int(ofRandom(255)), int(ofRandom(255)), ofRandom(30.0,50.0));
        ofDrawRectangle(ofRandom(154.0, 840.0), ofRandom(130.0, 610.0), 15.0, 15.0);
        ofSetColor(int(ofRandom(255)), int(ofRandom(255)), int(ofRandom(255)), ofRandom(30.0, 40.0));
        ofDrawRectangle(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 20.0, 20.0);
        
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == 'p')
        bPaint = !bPaint;
    if( key == 'o')
        bObstacle = !bObstacle;
    if( key == 'b')
        bBounding = !bBounding;
    if( key == 'c')
        bClear = !bClear;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
