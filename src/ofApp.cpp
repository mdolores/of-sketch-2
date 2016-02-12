#include "ofApp.h"

int circleX, circleY, radius;
int r, g, b;
const int X_INIT = 200;
const int Y_INIT = 300;
const int RADIUS_INIT = 10;
const int RADIUS_DELTA = 5;
const int MOVE_DELTA = 10;
const int COLOR_DELTA = 5;
const int KEY_SHIFT = 2305;
const int KEY_PLUS = 43;
const int KEY_MINUS = 45;
const int KEY_R = 114;
const int KEY_SHIFT_R = 82;
const int KEY_G = 103;
const int KEY_SHIFT_G = 71;
const int KEY_B = 98;
const int KEY_SHIFT_B = 66;
const int KEY_LEFT = 356;
const int KEY_RIGHT = 358;
const int KEY_UP = 357;
const int KEY_DOWN = 359;

bool pressed = false;
int pressedKey = 0;

void ofApp::setup(){
    circleX = X_INIT;
    circleY = Y_INIT;
    radius = RADIUS_INIT;
    r = g = b = 0;
}

void ofApp::draw(){
    // Print legend
    ofSetColor(0,0,0);
    ofDrawBitmapString("Key Pressed: " + ofToString(pressedKey), 10, 15);
    ofDrawBitmapString("Radius: " + ofToString(radius), 10, 30);
    ofDrawBitmapString("R: " + ofToString(r) + " G: " + ofToString(g) + " B: " + ofToString(b), 10, 45);
    // Print colored circle
    ofSetColor(r, g, b);
    ofDrawCircle(circleX, circleY, radius);
}

void ofApp::keyPressed(int key){
    pressedKey = key;
    pressed = true;
    switch(pressedKey) {
    case KEY_PLUS:
        radius += RADIUS_DELTA;
        break;
    case KEY_LEFT:
        circleX -= MOVE_DELTA;
        break;
    case KEY_RIGHT:
        circleX += MOVE_DELTA;
        break;
    case KEY_DOWN:
        circleY += MOVE_DELTA;
        break;
    case KEY_UP:
        circleY -= MOVE_DELTA;
        break;
    case KEY_MINUS:
        if (radius > 0) {
            radius -= RADIUS_DELTA;
        }
        break;
    case KEY_R:
        if (r < 255) {
            r += COLOR_DELTA;
            if (r > 255) {
                r = 255;
            }
        }
        break;
    case KEY_SHIFT_R:
        if (r > 0) {
            r -= COLOR_DELTA;
            if (r < 0) {
                r = 0;
            }
        }
        break;
    case KEY_G:
        if (g < 255) {
            g += COLOR_DELTA;
            if (g > 255) {
                g = 255;
            }
        }
        break;
    case KEY_SHIFT_G:
        if (g > 0) {
            g -= COLOR_DELTA;
            if (g < 0) {
                g = 0;
            }
        }
        break;
    case KEY_B:
        if (b < 255) {
            b += COLOR_DELTA;
            if (b > 255) {
                b = 255;
            }
        }
        break;
    case KEY_SHIFT_B:
        if (b > 0) {
            b -= COLOR_DELTA;
            if (b < 0) {
                b = 0;
            }
        }
        break;
    }
}

void ofApp::keyReleased(int key){
    pressed = false;
    pressedKey = 0;
}
