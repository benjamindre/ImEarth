#include "pch.h"
#include "core/Window.h"

#include <imgui.h>

namespace ImEarth {

Window::Window() 
{
    m_WinodwFlags |= ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
    m_WinodwFlags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
}    

void Window::Render() 
{
    static bool shwoDemoWindow = false;

    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);
    ImGui::SetNextWindowViewport(viewport->ID);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    ImGui::Begin("DockSpace", nullptr, m_WinodwFlags);
    ImGuiID dockspace_id = ImGui::GetID("ImEarthDockspace");
    ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_None);

    if (ImGui::BeginMenuBar()) 
    {   
        if (ImGui::BeginMenu("Options"))
        {   
            ImGui::MenuItem("Show Demo Window", "Ctrl+o", &shwoDemoWindow);
            ImGui::EndMenu();
        }
        

        ImGui::EndMenuBar();
    }

    if (shwoDemoWindow)
    {
        ImGui::ShowDemoWindow();
    }
    

    ImGui::PopStyleVar(3);
    ImGui::End();
}

}   // namespace ImEarth