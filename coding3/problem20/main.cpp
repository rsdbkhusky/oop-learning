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

*/