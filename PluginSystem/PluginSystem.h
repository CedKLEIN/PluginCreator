#pragma once

#include <vector>
#include <string>

struct IPluginSystem{
    virtual ~IPluginSystem()=default;
    virtual void* openPlugin(const std::string& pluginName)=0;
    virtual void* loadFunction(void* plugin, const std::string& functionName)=0;
};

class PluginSystem: public IPluginSystem{
public:
    ~PluginSystem() override;
    void* openPlugin(const std::string& pluginName) override;
    void* loadFunction(void* plugin, const std::string& functionName) override;

private:
    void closePlugins();
    std::vector<void*> m_libraries;
};
