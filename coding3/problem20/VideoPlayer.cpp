//
// Created by lenovo on 2024/11/29.
//

#include <algorithm>
#include "VideoPlayer.h"
#include "System.h"
#include "StandardVideoStream.h"
using std::swap;

#include <iostream>
using std::cout;
using std::endl;

VideoPlayer::VideoPlayer(System* _pSystem): pSystem(_pSystem) {}

VideoPlayer::~VideoPlayer() {
    delete pSystem;
}

VideoPlayer::VideoPlayer(const VideoPlayer& rhs) {
    pSystem = new System(*rhs.pSystem);
}

VideoPlayer& VideoPlayer::operator=(const VideoPlayer& rhs) {
    VideoPlayer temp(rhs);
    swap(pSystem, temp.pSystem);
    return *this;
}

const StandardVideoStream& VideoPlayer::decode(char* string) {
    cout << "VideoPlayer::decode" << endl;
    return *(new StandardVideoStream);
}

void VideoPlayer::Play(char* string) {
    pSystem->playStandardVideoStream(decode(string));
}