#ifndef WINDOW_RAYLIB_H__
#define WINDOW_RAYLIB_H__

#include "Window.h"

class WindowRaylib : public Window {
public:
    WindowRaylib();
    ~WindowRaylib();
    void createWindow(int width, int height) override;
    void clear() override;
    void display() override;
    void pollEvents() override;
    bool isRunning() override;
    void close() override;
};

#endif // WINDOW_RAYLIB_H__