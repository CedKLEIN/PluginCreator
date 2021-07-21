#pragma once

#include "ICapt.h"

#include <map>
#include <string>
#include <vector>

class ICaptFactory{
public:
    ICaptFactory()=default;
    virtual ~ICaptFactory()=default;
    virtual bool loadListCaptPlugins(const std::vector<std::string>& pluginList)=0;
    std::map<std::string, ICapt*> getListCaptPlugins() const{
        return m_listCaptPlugins;
    }

protected:
    std::map<std::string,ICapt*> m_listCaptPlugins;
};
