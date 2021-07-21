#pragma once

#include "ICaptFactory.h"

#include <string>
#include <vector>
#include <iostream>

class PluginSystem;

class CaptPluginFactory: public ICaptFactory{
public:
    CaptPluginFactory(PluginSystem&);
    ~CaptPluginFactory() override;
    bool loadListCaptPlugins(const std::vector<std::string>& pluginList) override;

private:
    ICapt* loadCaptPlugin(const std::string& pluginName);
    void cleanPlugins();
    PluginSystem& m_pluginSystem;
};
