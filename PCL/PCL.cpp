#pragma warning(disable:4996)

#define _CRT_SECURE_NO_WARNINGS
#define BOOST_ALL_NO_LIB
#define BOOST_USE_WINDOWS_H
#define NOMINMAX

#include <iostream>
#include <thread>

#include <pcl/console/parse.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/sample_consensus/ransac.h>
#include <pcl/sample_consensus/sac_model_plane.h>
#include <pcl/sample_consensus/sac_model_sphere.h>
#include <pcl/visualization/pcl_visualizer.h>

#include <pcl/filters/voxel_grid.h>

#include "PLYLoader.hpp"
#include "PCLVisualization.hpp"
#include "GroundExtractor.hpp"

#include <pcl/kdtree/kdtree_flann.h>

int
main(int argc, char** argv)
{

    PLYLoader loader;
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud = loader.loadCloud("C:\\School\\LVR\\PCL_VS2019\\PCL\\PCL\\urban_area.ply");

    pcl::PointCloud<pcl::PointXYZ>::Ptr filteredCloud(new pcl::PointCloud<pcl::PointXYZ>);

    pcl::VoxelGrid<pcl::PointXYZ> voxelGrigFilter;
    voxelGrigFilter.setInputCloud(cloud);
    voxelGrigFilter.setLeafSize(1.0f, 1.0f, 1.0f);
    voxelGrigFilter.filter(*filteredCloud);

    std::cout << filteredCloud->points.size() << std::endl;

    GroundExtractor groundExtractor;
    groundExtractor.extractGround(filteredCloud);


    PCVisualization pclVisualization;
    pclVisualization.initializeVisualization();

    //pclVisualization.addCloud(filteredCloud, Color(0, 255, 0));
    pclVisualization.addCloud(groundExtractor.getGround(), Color(255, 0, 0));
    pclVisualization.addCloud(groundExtractor.getEverythingElse(), Color(0, 255, 0));
    pclVisualization.runVisualization();


    return 0;
}
