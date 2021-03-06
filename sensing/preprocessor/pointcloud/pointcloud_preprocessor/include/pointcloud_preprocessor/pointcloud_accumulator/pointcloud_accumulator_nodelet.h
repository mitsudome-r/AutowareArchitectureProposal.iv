/*
 * Copyright 2020 Tier IV, Inc. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <boost/circular_buffer.hpp>
#include "pointcloud_preprocessor/PointcloudAccumulatorConfig.h"
#include "pointcloud_preprocessor/filter.h"

namespace pointcloud_preprocessor
{
class PointcloudAccumulatorNodelet : public pointcloud_preprocessor::Filter
{
protected:
  boost::shared_ptr<
    dynamic_reconfigure::Server<pointcloud_preprocessor::PointcloudAccumulatorConfig> >
    srv_;
  virtual void filter(
    const PointCloud2::ConstPtr & input, const IndicesPtr & indices, PointCloud2 & output);
  virtual void subscribe();
  virtual void unsubscribe();

  bool child_init(ros::NodeHandle & nh, bool & has_service);
  void config_callback(
    pointcloud_preprocessor::PointcloudAccumulatorConfig & config, uint32_t level);

private:
  double accumulation_time_sec_;
  boost::circular_buffer<PointCloud2::ConstPtr> pointcloud_buffer_;

public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};
}  // namespace pointcloud_preprocessor
