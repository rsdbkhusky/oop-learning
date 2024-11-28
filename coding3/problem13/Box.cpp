//
// Created by lenovo on 2024/11/28.
//

#include <cassert>
#include "Box.h"
#include "Role.h"
#include "Solider.h"
#include "Mage.h"

void Box::beOpened(Role& role) {
    if (dynamic_cast<Solider*>(&role)) {
        beOpenedBySolider((Solider&)role);
    } else if (dynamic_cast<Mage*>(&role)) {
        beOpenedByMage((Mage&)role);
    } else {
        assert(!"Type Error");
    }
}
