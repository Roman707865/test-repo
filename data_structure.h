#ifndef OSMMODULEIO
#define OSMMODULEIO
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif
struct GeoCoordinates {
  double longitude;
  double lattitude;
};
struct VehiclePose {
  GeoCoordinates coordinates;
  double heading;
};
struct OSMModuleRequest {
  VehiclePose *poses_buf;
  size_t poses_bug_sz;
};
enum DrivingDirection { POSITIVE, NEGATIVE, BOTH };
enum RoadMarking { NONE, CONTINUOUS, DASHED, DOUBLE };
enum RoadMarkingColor { WHITE, YELLOW, RED, GREEN, BLUE };
struct Lane {
  int id;
  int next_id;
  int previous_id;
  int speedlimit;
  double width;
  double lateraloffset;
  DrivingDirection driving_direction;
  RoadMarking left_marking;
  RoadMarking right_marking;
  RoadMarkingColor left_marking_color;
  RoadMarkingColor right_marking_color;
};
struct LaneSection {
  Lane *lanes_buf;
  size_t lane_buf_sz;
  GeoCoordinates *chord_coordinates_buf;
  size_t chord_coordinates_buffer_buf_sz;
};
struct RoadPart {
  LaneSection *lanesection_buf;
  size_t lanesection_buf_sz;
};
enum RequestStatus { SUCCESS, FAILED, NOTFOUND };
struct OSMModuleRequestResult {
  RequestStatus request_status;
  RoadPart *roadpart_buf;
  size_t roadpart_buf_sz;
  char country[256];
};
OSMModuleRequestResult *RequestDataForPath(OSMModuleRequest request);
#ifdef __cplusplus
}
#endif
#endif // OSMMODULEIO
