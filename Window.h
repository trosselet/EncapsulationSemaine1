#ifndef WINDOW_H__
#define WINDOW_H__

class Window {
public:
    virtual ~Window() = default;
    virtual void createWindow(int width, int height) = 0;
    virtual void clear() = 0;
    virtual void display() = 0;
    virtual void pollEvents() = 0;
    virtual bool isRunning() = 0;
    virtual void close() = 0;
};

#endif // WINDOW_H__