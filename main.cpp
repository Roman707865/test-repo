#include <iostream>
#include "data_structure.h"

int main(int argc, char **argv) {
    
    //Example of how to build a request;
    OSMModuleRequest request{};
    VehiclePose pose1{GeoCoordinates{10.0F,45.0F},90.0}; //The firs point of the GPS at long=10 lat=46 heading at 90
    VehiclePose pose2{GeoCoordinates{10.01F,45.0F},90.0}; //The firs point of the GPS at long=10.01 lat=46 heading at 90
    VehiclePose pose3{GeoCoordinates{10.02F,45.0F},90.0}; //The firs point of the GPS at long=10.02 lat=46 heading at 90
    VehiclePose posebuffer[3];
    posebuffer[0]=pose1;
    posebuffer[1]=pose2;
    posebuffer[2]=pose2;
    request.poses_buf=posebuffer;
    request.poses_bug_sz=3U;
    //Request is ready to be submited
    
    
    OSMModuleRequestResult* result=RequestDataForPath(request);
    std::cout<<"Looking at result"<<std::endl;
    std::cout<<"The result contain"<<result->roadpart_buf_sz<<" RoadPart"<<std::endl;
    std::cout<<"The first road part has "<<result->roadpart_buf[0].lanesection_buf_sz<<" Lane Sections"<<std::endl;
    std::cout<<"The first lane section has "<<result->roadpart_buf[0].lanesection_buf[0].lane_buf_sz<<" Lanes"<<std::endl;
    
    for(size_t i=0 ;i < result->roadpart_buf[0].lanesection_buf[0].lane_buf_sz; ++i)
    {
        Lane* lane=&(result->roadpart_buf[0].lanesection_buf[0].lanes_buf[i]);
        std::cout<<"Characteristics of lane"<<i<<std::endl;
        std::cout<<"width "<<lane->width<<" Offset "<<lane->lateraloffset<<" id "<<lane->id <<std::endl;;       
    }
    std::cout<<"End"<<std::endl;
    return 0;
}
