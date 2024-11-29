//
// Created by lenovo on 2024/11/29.
//

#include "RMVB_Player.h"
#include "StandardVideoStream.h"

#include <iostream>
using std::cout;
using std::endl;

RMVB_Player::RMVB_Player(System* _pSystem): VideoPlayer(_pSystem) {}

const StandardVideoStream& RMVB_Player::decode(char* string) {
    cout << "RMVB_Player::decode" << endl;
    return *(new StandardVideoStream);
}