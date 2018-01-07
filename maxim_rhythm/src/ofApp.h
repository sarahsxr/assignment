#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"

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
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //audio output methods
    void audioOut(float * output, int bufferSize, int nChannels);
    
    //declare variables
    int		bufferSize;
    int		sampleRate;
    
    maxiSample sample, beats, bass, bell, bass2;//five sampleplayers
    maxiOsc myPhasor, myOsc;//two oscillators
    int CurrentCount;
    double  wave, mySample1, mySample2, mySample3, mySample4, mySample5;

};