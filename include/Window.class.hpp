#ifndef WINDOW_HPP
#define WINDOW_HPP

# include "Bomberman.class.hpp"
# include "Sound.class.hpp"
# include "WindowKeyEvents.class.hpp"

class Window{
    public:
        Sound *_sound;
        Window();
        ~Window();

        void runGame();
        void initiateSystems();
        void terminateSystems();
        void key_events_handle(GLFWwindow *win, Sound *sound);

    private:
        int _width;
        int _height;
        GLFWwindow* _window;
        WindowKeyEvents *_keyEvents;
};

#endif