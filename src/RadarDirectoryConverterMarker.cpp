#include "nuscenes2bag/RadarDirectoryConverterMarker.hpp"

#include <pcl_ros/point_cloud.h>

using namespace sensor_msgs;
using namespace std;
using namespace nuscenes2bag;

namespace nuscenes2bag {

boost::optional<visualization_msgs::MarkerArray>
readRadarFileMarker(const fs::path& filePath)
{
  const auto fileName = filePath.string();
  pcl::PointCloud<PclRadarObject>::Ptr cloud(
    new pcl::PointCloud<PclRadarObject>);

  if (pcl::io::loadPCDFile<PclRadarObject>(fileName, *cloud) ==
      -1) //* load the file
  {
    std::string error = "Could not read ";
    error += fileName;
    cout << error << endl;
    // PCL_ERROR(error);

    return boost::none;
  }

  visualization_msgs::MarkerArray radarObjectsMarker;

  for (const auto& pclRadarObject : *cloud) {
    visualization_msgs::Marker objMarker;
    objMarker.type = visualization_msgs::Marker::CUBE;
    objMarker.id = pclRadarObject.id;
    objMarker.scale.x = 0.3;
    objMarker.scale.y = 0.3;
    objMarker.scale.z = 1;
    objMarker.color.r = 0.0;
    objMarker.color.g = 1.0;
    objMarker.color.b = 1.0;
    objMarker.color.a = 0.5;
    objMarker.pose.orientation.x = 0.0;
    objMarker.pose.orientation.y = 0.0;
    objMarker.pose.orientation.z = 0.0;
    objMarker.pose.orientation.w = 1.0;
    objMarker.pose.position.x = pclRadarObject.x;
    objMarker.pose.position.y = pclRadarObject.y;
    objMarker.pose.position.z = pclRadarObject.z;
    radarObjectsMarker.markers.push_back(objMarker);
  }

  return boost::optional<visualization_msgs::MarkerArray>(radarObjectsMarker);
}

}
