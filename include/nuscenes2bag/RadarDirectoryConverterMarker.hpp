#pragma once

#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include <jsk_recognition_msgs/BoundingBox.h>
#include <jsk_recognition_msgs/BoundingBoxArray.h>
#include "nuscenes2bag/PclRadarObject.hpp"
#include "nuscenes2bag/Filesystem.hpp"

namespace nuscenes2bag {

boost::optional<visualization_msgs::MarkerArray> readRadarFileMarker(const fs::path& filePath);

}
