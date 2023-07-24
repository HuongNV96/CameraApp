#include "RepeaterManager.hpp"

RepeaterManager::RepeaterManager()
{
    streams.append(std::make_shared<StreamRepeater>("http://streams.videolan.org/samples/360VR/180.mp4", "1111"));
}
