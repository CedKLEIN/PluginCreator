#pragma once

#include "ICapt.h"

class PluginSurvey : ICapt{
public:
    PluginSurvey();
    void initPlugin() override;
    void runProcess() override;
};
