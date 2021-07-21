#include "PluginSurvey.h"

extern "C"{
    PluginSurvey* createPlugin()
    {
        return new PluginSurvey();
    }
}
