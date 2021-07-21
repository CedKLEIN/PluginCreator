#include "CaptFactory.h"
#include "ICapt.h"
#include "PluginSystem.h"

#include <iostream>

using namespace std;
 
int main()
{
    PluginSystem pluginSystem;

    CaptPluginFactory factory{pluginSystem};
    factory.loadListCaptPlugins({"CaptSurvey","CaptGps"});

    factory.getListCaptPlugins()["CaptSurvey"]->runProcess();
    factory.getListCaptPlugins()["CaptGps"]->runProcess();

    return 0;
}
