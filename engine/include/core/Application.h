#pragma once

#include "core/Config.h"

#include <GLFW/glfw3.h>

namespace ImEarth {

struct ProgramInfo 
{
    std::string title = "ImEarth";
    int width = 1280;
    int height = 720;
};    

class Application 
{
public:
    Application(const ProgramInfo& programInfo);

private:
    ProgramInfo m_ProgramInfo;
    GLFWwindow* m_Window = nullptr;
};

}   // namespace ImEarth