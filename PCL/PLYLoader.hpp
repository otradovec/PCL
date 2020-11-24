
#pragma warning(disable:4996)
#pragma once


#define _CRT_SECURE_NO_WARNINGS
#define BOOST_ALL_NO_LIB
#define BOOST_USE_WINDOWS_H
#define NOMINMAX


#include <stdio.h>
#include <pcl/point_types.h>
#include <pcl/io/ply_io.h>

class PLYLoader {
public:
    PLYLoader();
    pcl::PointCloud<pcl::PointXYZ>::Ptr loadCloud(std::string filename);
};

