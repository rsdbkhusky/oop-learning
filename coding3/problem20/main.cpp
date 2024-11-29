#include "VideoPlayer.h"
#include "RMVB_Player.h"
#include "WinOS.h"

int main() {
    VideoPlayer* vp = new RMVB_Player(new WinOS());
    vp->Play("demo.rmvb");
    delete vp;
    return 0;
}

/*
第二问：
17个类，包括VideoPlayer基类和其10个派生类，以及System基类和其5个派生类
*/