//
// Created by lenovo on 2024/11/29.
//

#ifndef PROBLEM20_VIDEOPLAYER_H
#define PROBLEM20_VIDEOPLAYER_H

class System;
class StandardVideoStream;

class VideoPlayer {
public:
    VideoPlayer(System* _pSystem);
    virtual ~VideoPlayer();
    VideoPlayer(const VideoPlayer& rhs);
    VideoPlayer& operator=(const VideoPlayer& rhs);
    virtual const StandardVideoStream& decode(char* string);
    void Play(char* string);
protected:
    System* pSystem;
};


#endif //PROBLEM20_VIDEOPLAYER_H
