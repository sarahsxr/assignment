/*Simple Example Project #2 
 
 This is an example playing with five samples includes:
 
 - play back samples using the "frequency" approach
 - change the pitch and end positions of the samples
 - use a phasor to create algorithmic rhythm
 
 */

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);

    /* This is stuff you always need.*/
    sampleRate 	= 44100; //Sampling Rate
    bufferSize	= 512; //Buffer Size
    
    ofxMaxiSettings::setup(sampleRate, 2, bufferSize);
    
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    
    //Sample loading
    sample.load(ofToDataPath("cello.wav"));
    beats.load(ofToDataPath("beats.wav"));
    bass.load(ofToDataPath("bass_01.wav"));
    bell.load(ofToDataPath("Kantilan_1.wav"));
    bass2.load(ofToDataPath("bass_02.wav"));

    ofSoundStreamSetup(2,2,this, sampleRate, bufferSize, 4); //it switches on the DAC
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels) {
    
    for (int i = 0; i < bufferSize; i++){
        CurrentCount = myPhasor.phasor(0.125, 1, 7);//setup a metronome that ticks 7 times every 8 seconds

        if (CurrentCount==1) {
            mySample5 = beats.playOnce()*0.5;//play the sample once, no looping, with half the original amplitude
        }
        
        if (CurrentCount== 3){
            mySample1 = sample.play(20,0,sample.length/2)*0.05;//the original amplitude is multiplied by 0.05, play the sample 20 times a sec, end at half the sample length
            mySample3 = bass2.playOnce();//no looping
        }else{
            mySample3 = bass2.play(8, 0, bass2.length);//play back 8 times a sec
       }
        
        if (CurrentCount== 6){
            mySample4 = bell.play(2,0,bell.length)*0.5;//half the original amplitude, play back twice a sec
        }else{
            mySample4 = bell.play(1,0,bell.length/2)*0.25;//play half of the sample length with 1/4 the original amplitude
        }
        
        if (CurrentCount== 7){//reset the playback position of the samples to 0 (the beginning)
            sample.trigger();
            bass2.trigger();
            bell.trigger();
            bass.trigger();
            beats.trigger();
        }

        mySample2 = bass.play(0.5, 0, bass.length)*2;//linear interpolation play with frequency input(0.5hz), which slow the sample half the speed. twice as large as the original amplitude

        wave = mySample1 + mySample2 + mySample3 + mySample4 + mySample5;
       
        output[i*nChannels    ] = wave;//left channel
        output[i*nChannels + 1] = wave;//right channel
        
    }

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
    
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}