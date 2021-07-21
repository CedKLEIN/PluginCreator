#include "Gps.h"

extern "C"{
    Gps* createPlugin()
    {
        return new Gps();
    }
}
