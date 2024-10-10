#pragma once

#include "core/Config.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace ImEarth {

struct ProgramInfo 
{
    std::string title = "ImEarth Application";
    int width = 1600;
    int height = 900;
};    

class Application 
{
public:
    Application() = default;
    Application(const ProgramInfo& programInfo);

    GLFWwindow& GetGLFWWindow() { return *m_GLFWWindow; }

    void Run();
private:
    void Init();
    void ShuntDown();

private:
    ProgramInfo m_ProgramInfo;
    GLFWwindow* m_GLFWWindow = nullptr;
};

}   // namespace ImEarth