


#ifndef WINDOW_MANAGER_HPP
#define WINDOW_MANAGER_HPP

extern "C" {
#include <X11/Xlib.h>
}
#include <memory>
#include <string>
#include <unordered_map>
#include "util.hpp"

class WindowManager {
public:
    static WindowManager* getWindowManager();
    ~WindowManager();
    void Run();

private:
    WindowManager();
    static WindowManager* windowManager;

    // Handle to the underlying Xlib Display struct.
    Display* display_;
    // Handle to root window.
    const Window root_;
    // Maps top-level windows to their frame windows.
    std::unordered_map<Window, Window> clients_;
    
    // Frames a top-level window.
    void Frame(Window w, bool was_created_before_window_manager);
    // Unframes a client window.
    void Unframe(Window w);

    /* Event Handler Methods */ 
    void OnCreateNotify(const XCreateWindowEvent& e);
    void OnDestroyNotify(const XDestroyWindowEvent& e);
    void OnReparentNotify(const XReparentEvent& e);
    void OnMapNotify(const XMapEvent& e);
    void OnUnmapNotify(const XUnmapEvent& e);
    void OnConfigureNotify(const XConfigureEvent& e);
    void OnMapRequest(const XMapRequestEvent& e);
    void OnConfigureRequest(const XConfigureRequestEvent& e);
    void OnButtonPress(const XButtonEvent& e);
    void OnButtonRelease(const XButtonEvent& e);
    void OnMotionNotify(const XMotionEvent& e);
    void OnKeyPress(const XKeyEvent& e);
    void OnKeyRelease(const XKeyEvent& e);


    static int OnXError(Display* display, XErrorEvent* e);
    static int OnWMDetected(Display* display, XErrorEvent* e);
    static bool wm_detected_;


    // The cursor position at the start of a window move/resize.
    Position<int> drag_start_pos_;
    // The position of the affected window at the start of a window
    // move/resize.
    Position<int> drag_start_frame_pos_;
    // The size of the affected window at the start of a window move/resize.
    Size<int> drag_start_frame_size_;

    // Atom constants.
    const Atom WM_PROTOCOLS;
    const Atom WM_DELETE_WINDOW;
};

#endif
