#pragma once

//图片资源 加载类
class Resources
{
private:
    Resources();
public:
    ~Resources();

    Resources(const Resources&) = delete;
    Resources& operator=(const Resources&) = delete;
    static Resources& getInstance();

public:
    std::map<std::pair<int, int>, cv::Mat> MapBlockCache;

public:
    cv::Mat PaimonTemplate;
    cv::Mat MinimapCailbTemplate;
    cv::Mat StarTemplate;
    cv::Mat UID;
    cv::Mat UIDnumber[10];

    // 天理坐标映射关系参数 地图中心
    // 地图中天理坐标中心的像素坐标
    const cv::Point2d map_relative_center = { 5292, 3015 }; // 天理坐标中点
    // 地图中图片像素与天理坐标系的比例
    const double map_relative_scale = 2.557; // 天理坐标缩放
public:
    void install();
    void release();
public:
    //void get_map_keypoint_cache();
    bool map_is_embedded();
private:
    bool is_installed = false;
};

bool load_map_keypoint_cache(std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors);

bool get_map_keypoint(std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors);