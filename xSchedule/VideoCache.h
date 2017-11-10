#ifndef VIDEOCACHE_H
#define VIDEOCACHE_H

#include <mutex>

#include <wx/wx.h>
#include <wx/thread.h>

#include <string>
#include <list>
#include <map>
#include "../xLights/JobPool.h"

class VideoReader;
class VideoCacheItem;
class CVRThread;
struct AVFrame;

class CachedVideoReader
{
    std::map<long, wxImage> _cache;
    std::mutex _cacheAccess;
    int _maxItems;
    CVRThread* _thread;
    int _frameTime;
    std::string _videoFile;
    wxSize _size;
    long _lengthMS;

    void PurgeCachePriorTo(long start);

public:
    CachedVideoReader(const std::string& videoFile, long startMillisecond, int frameTime, const wxSize& size, bool keepAspectRatio);
    virtual ~CachedVideoReader();

    static wxImage CreateImageFromFrame(AVFrame* frame, const wxSize& size);

    bool HasFrame(long millisecond);
    void CacheImage(long millisecond, const wxImage& image);
    void SetLengthMS(long lengthMS);

    long GetLengthMS() const { return _lengthMS; };
    wxImage GetNextFrame(long ms);
};

#endif // VIDEOCACHE_H

