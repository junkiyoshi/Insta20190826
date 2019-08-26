#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(2);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	auto len = 300;
	auto depth = 10;
	for (auto z = len * -1 ; z <= len; z += depth) {

		auto param_start = ofMap(ofNoise(z * 0.005, ofGetFrameNum() * 0.005), 0, 1, 0, 200);
		for (auto param = param_start; param < param_start + 30; param++) {

			ofBeginShape();
			ofVertex(glm::vec3(this->make_point(len, param), z + depth * 0.5));
			ofVertex(glm::vec3(this->make_point(len, param + 1), z + depth * 0.5));
			ofVertex(glm::vec3(this->make_point(len, param + 1), z + depth * -0.5));
			ofVertex(glm::vec3(this->make_point(len, param), z + depth * -0.5));
			ofEndShape(true);
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
glm::vec2 ofApp::make_point(int len, int param) {

	param = param % 100;
	if (param < 25) {

		return glm::vec2(ofMap(param, 0, 25, -len * 0.5, len * 0.5), -len * 0.5);
	}
	else if (param < 50) {

		return glm::vec2(len * 0.5, ofMap(param, 25, 50, -len * 0.5, len * 0.5));
	}
	else if (param < 75) {

		return glm::vec2(ofMap(param, 50, 75, len * 0.5, -len * 0.5), len * 0.5);
	}
	else {

		return glm::vec2(-len * 0.5, ofMap(param, 75, 100, len * 0.5, -len * 0.5));
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}