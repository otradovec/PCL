//  Created by Jaromír Landa on 11/11/2020.

#pragma warning(disable:4996)
#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define BOOST_ALL_NO_LIB
#define BOOST_USE_WINDOWS_H
#define NOMINMAX


#include <stdio.h>

#include <pcl/point_types.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/segmentation/progressive_morphological_filter.h>


class GroundExtractor{
public:
    GroundExtractor();
    void extractGround(pcl::PointCloud<pcl::PointXYZ>::Ptr inputCloud);
    pcl::PointCloud<pcl::PointXYZ>::Ptr getGround();
    pcl::PointCloud<pcl::PointXYZ>::Ptr getEverythingElse();
    
private:
    pcl::PointCloud<pcl::PointXYZ>::Ptr ground;
    pcl::PointCloud<pcl::PointXYZ>::Ptr everyrhingElse;
    
    
    
};


