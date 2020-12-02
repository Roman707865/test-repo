#include "../data_structure.h"
#include "osm_module.h"

OSMModule osmmodule{};

OSMModuleRequestResult *RequestDataForPath(OSMModuleRequest request) {
  return osmmodule.RequestDataForPath(request);
}
