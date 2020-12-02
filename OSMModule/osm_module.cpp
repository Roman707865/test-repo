#include "osm_module.h"

OSMModuleRequestResult *
OSMModule::RequestDataForPath(OSMModuleRequest request) {
  for (size_t i = 0; i < request.poses_bug_sz; ++i) {
    std::cout << "Proceeding vehicle pos " << i << " long "
              << request.poses_buf[i].coordinates.longitude << " lat "
              << request.poses_buf[i].coordinates.lattitude << std::endl;
  }
  // Do some actual processing

  /*Example of how to populate the result: Build a road that has three lane two
  in positive and negative direction
  _________________________________________

          <-------- Negative Direction width=3.75m              negative lane one id=0
  _________________________________________

          ------------> Positive direction width=3.75m          positive lane one id=1

  --  -- -- -- -- -- -- -- -- -- -- -- --

          ------------> Positive direction width=4.0m           negative lane two id=2

  ________________________________________

  */
  constexpr int kNumberOfLanes = 3;
  Lane negativelane{0, -1, -1, 50, 3.75F, 0.0F, DrivingDirection::NEGATIVE};
  Lane positivelaneone{0, -1, -1, 50, 3.75F, 0.0F, DrivingDirection::NEGATIVE};
  Lane positivelanetwo{0, -1, -1, 50, 4.0F, 3.75F, DrivingDirection::NEGATIVE};
  positivelaneone.left_marking=RoadMarking::CONTINUOUS;
  positivelaneone.right_marking=RoadMarking::DASHED;
  negativelane.id=0;
  positivelaneone.id=1;
  positivelanetwo.id=2;
  RoadPart *roadpart = new RoadPart;
  roadpart->lanesection_buf_sz = 1;
  roadpart->lanesection_buf = (LaneSection *)std::malloc(
      roadpart->lanesection_buf_sz * sizeof(LaneSection));
  roadpart->lanesection_buf[0].lane_buf_sz = kNumberOfLanes;
  roadpart->lanesection_buf[0].lanes_buf =
      (Lane *)std::malloc(kNumberOfLanes * sizeof(Lane));
  roadpart->lanesection_buf[0].lanes_buf[0] = negativelane;
  roadpart->lanesection_buf[0].lanes_buf[1] = positivelaneone;
  roadpart->lanesection_buf[0].lanes_buf[2] = positivelanetwo;

  
  OSMModuleRequestResult *result = new OSMModuleRequestResult;
  result->roadpart_buf = roadpart;
  result->roadpart_buf_sz = 1;
  result->request_status = RequestStatus::SUCCESS;
  return result;
}
