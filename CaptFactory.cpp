#include "CaptFactory.h"
#include "ICapt.h"
#include "PluginSystem.h"

#include <dlfcn.h>

using FunctionCreatePlugin = ICapt*(*)();

CaptPluginFactory::CaptPluginFactory(PluginSystem &pluginSystem) : m_pluginSystem{pluginSystem}{}

CaptPluginFactory::~CaptPluginFactory(){
    cleanPlugins();
}

bool CaptPluginFactory::loadListCaptPlugins(const std::vector<std::string> &pluginList){
    if(pluginList.empty())
        return false;

    for(auto plugin: pluginList){
        loadCaptPlugin(plugin);
    }
    return true;
}

ICapt* CaptPluginFactory::loadCaptPlugin(const std::string& pluginName){
    void* plugin{m_pluginSystem.openPlugin(pluginName)};

    if(!plugin){
        std::cout << "loadCaptPlugin : plugin is null" << std::endl;
        return nullptr;
    }

    void* mkr = m_pluginSystem.loadFunction(plugin,"createPlugin");

    if(!mkr){
        std::cerr << "loadCaptPlugin : mkr is null => " << dlerror() << std::endl;
        return nullptr;
    }

    FunctionCreatePlugin pluginCreator = reinterpret_cast<FunctionCreatePlugin>(mkr);

    ICapt* capt=pluginCreator();

    m_listCaptPlugins[pluginName]=capt;

    return capt;
}

void CaptPluginFactory::cleanPlugins(){
    for(auto& plugin: m_listCaptPlugins){
        std::cout << "Delete : " << plugin.first << std::endl;
        delete m_listCaptPlugins[plugin.first];
        m_listCaptPlugins[plugin.first]=nullptr;
    }
    m_listCaptPlugins.clear();
}
