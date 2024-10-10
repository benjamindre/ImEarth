#include "pch.h"
#include "core/Application.h"

#include <stb_image.h>

#define IMGUI_IMPL_OPENGL_LOADER_GLAD
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <cassert>

static const char* kGlslVersion = "#version 130";

namespace ImEarth {

static void GlfwErrorCallback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}    

Application::Application(const ProgramInfo& programInfo)
    : m_ProgramInfo(programInfo)
{
    Init();
}

void Application::Run() 
{
    std::cout << "Application::Run" << std::endl;
}

void Application::Init() 
{
    glfwSetErrorCallback(GlfwErrorCallback);

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    m_GLFWWindow = glfwCreateWindow(m_ProgramInfo.width, m_ProgramInfo.height, m_ProgramInfo.title.c_str(), nullptr, nullptr);
    if (!m_GLFWWindow)
    {
        assert(false && "glfwCreateWindow failed.");
        glfwTerminate();
    }

    glfwMakeContextCurrent(m_GLFWWindow);
    glfwSwapInterval(1);

    // glfwSetFramebufferSizeCallback(m_GlfWwindow, ViewportResizeCallback);

    // 初始化 glad
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        assert(false && "gladLoadGLLoader failed.");
        glfwTerminate();
    }

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows

    ImGui::StyleColorsDark();

    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }
    ImGui_ImplGlfw_InitForOpenGL(m_GLFWWindow, true);
    ImGui_ImplOpenGL3_Init(kGlslVersion);
}

void Application::ShuntDown()
{

}

}   // namespace ImEarth