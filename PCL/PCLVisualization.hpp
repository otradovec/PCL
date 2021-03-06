#pragma once
#pragma warning(disable:4996)

#define _CRT_SECURE_NO_WARNINGS
#define BOOST_ALL_NO_LIB
#define BOOST_USE_WINDOWS_H
#define NOMINMAX

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Color.hpp"
#include <vector>

#include <boost/thread/thread.hpp>
#include <pcl/common/common_headers.h>
#include <pcl/features/normal_3d.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/console/parse.h>
#include <pcl/surface/gp3.h>
#include <Eigen/src/Core/Array.h>

class PCVisualization
{

private:
    pcl::PointCloud<pcl::PointXYZI>::Ptr m_cloud;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> m_viewer;
    int m_numberOfClouds;

public:

    PCVisualization();
    void runVisualization();
    void addCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud, Color pointsColor);
    void initializeVisualization();


};

