#include "PluginSystem.h"

#include <dlfcn.h>
#include <iostream>

std::string getNameLibrary(const std::string& pluginName){
    return "./Libs/Plugin"+pluginName+".so";
}

PluginSystem::~PluginSystem(){
    closePlugins();
}

void* PluginSystem::openPlugin(const std::string& pluginName){
    void* plugin{nullptr};

    std::cout << "Load library : "<< pluginName << std::endl;

    if(!pluginName.empty()){
        plugin= dlopen(getNameLibrary(pluginName).c_str(),RTLD_LAZY);
        m_libraries.push_back(plugin);
    }
    return plugin;
}

void* PluginSystem::loadFunction(void* plugin, const std::string& functionName){
    if(plugin){
        return dlsym(plugin,functionName.c_str());
    }
    return nullptr;
}

void PluginSystem::closePlugins(){
    for(auto& library: m_libraries){
        std::cout << "Close lib " << std::endl;
        dlclose(library);
    }
}
