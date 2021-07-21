#include "PluginSurvey.h"

#include <iostream>

PluginSurvey::PluginSurvey(){
    std::cout << "PluginSurvey::PluginSurvey()" << std::endl;
}

void PluginSurvey::initPlugin(){
    std::cout << "PluginSurvey::initPlugin()" << std::endl;
}

void PluginSurvey::runProcess(){
    std::cout << "PluginSurvey::runProcess()" << std::endl;
}
