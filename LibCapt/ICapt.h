#pragma once

class ICapt{
public:
    ICapt()=default;
    virtual ~ICapt()=default;
    virtual void initPlugin()=0;
    virtual void runProcess()=0;
};
