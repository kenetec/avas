#pragma once
class GuiWindow {
   protected:
    bool window_active_;

   public:
    virtual void setup(){};
    virtual void draw(){};

	void SetWindowActive(bool active) { window_active_ = active; };
    bool IsWindowActive() { return window_active_; };
};