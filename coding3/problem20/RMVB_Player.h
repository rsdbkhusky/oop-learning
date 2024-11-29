//
// Created by lenovo on 2024/11/29.
//

#ifndef PROBLEM20_RMVB_PLAYER_H
#define PROBLEM20_RMVB_PLAYER_H

#include "VideoPlayer.h"
class System;

class RMVB_Player: public VideoPlayer {
public:
    RMVB_Player(System* _pSystem);
    virtual const StandardVideoStream& decode(char *string) override;
};


#endif //PROBLEM20_RMVB_PLAYER_H
