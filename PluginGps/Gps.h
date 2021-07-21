#pragma once

#include "ICapt.h"

class Gps : ICapt{
public:
    Gps();
    void initPlugin() override;
    void runProcess() override;
};
