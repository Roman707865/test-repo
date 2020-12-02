#ifndef OSMMODULE
#define OSMMODULE
#include "../data_structure.h"
#include <iostream>
class OSMModule {
public:
  OSMModuleRequestResult *RequestDataForPath(OSMModuleRequest request);
};
#endif // OSMMODULE
