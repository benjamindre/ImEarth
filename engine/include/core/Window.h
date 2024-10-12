#pragma once

namespace ImEarth {

class Window 
{
public:
    Window();

    void Render();
private:
    int m_WinodwFlags = 0;
};

}   // namespace ImEarth