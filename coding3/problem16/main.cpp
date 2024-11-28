#include <iostream>
#include "Missile.h"
#include "SeaLaunch.h"
#include "AirLaunch.h"
#include "LandLaunch.h"
#include "SubSonicFly.h"
#include "SuperSonicFly.h"

int main() {
    Missile chinaA("ChinaA", new SeaLaunch, new SubSonicFly);
    Missile redBirdB("RedBirdB", new AirLaunch, new SubSonicFly);
    Missile springC("SpringC", new LandLaunch, new SuperSonicFly);
    Missile expeditionD("ExpeditionD", new SeaLaunch, new SuperSonicFly);
    chinaA.simulate();
    redBirdB.simulate();
    springC.simulate();
    expeditionD.simulate();
}
