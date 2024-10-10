#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "core/Window.h"

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
    Application();
    Application(const ProgramInfo& programInfo);
    ~Application();

    GLFWwindow& GetGLFWWindow() { return *m_GLFWWindow; }

    void Run();

    static void SetDarkThemeColors();
private:
    void Init();
    void ShuntDown();

    static void ViewportResizeCallback(GLFWwindow* window, int width, int height);
private:
    ProgramInfo m_ProgramInfo;
    GLFWwindow* m_GLFWWindow = nullptr;
    Window m_Window;
};

}   // namespace ImEarth