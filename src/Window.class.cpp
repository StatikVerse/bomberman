#include "Window.class.hpp"

//Error checking         :Cradebe
static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

//Key Checking input        :Cradebe
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

void Window::key_events_handle(GLFWwindow *win, Sound *sound)
{
    if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(win, true);    
}

Window::Window(){
    _width  = WIDTH;
    _window = nullptr;
    _height  = HEIGHT;
    _sound = new Sound();
    _keyEvents = new WindowKeyEvents();
}

Window::~Window(){
    delete _sound;
    delete _keyEvents;
}

//Runs Game         :Cradebe
void Window::runGame(){
    _sound->playMusicForvever(MUSIC_BEAR);
    initiateSystems();
}

//Initiates Screen  :Cradebe
void Window::initiateSystems(){

glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    
    _window = glfwCreateWindow(_width, _height, "Bomber Man", NULL, NULL);
    
    if (!_window)
    {
        terminateSystems();
    }
    glfwMakeContextCurrent(_window);
    // glfwSetKeyCallback(_window, key_callback);
    
    //Keeps screen open
    while (!glfwWindowShouldClose(_window))
    {
        // Set view port size and position every frame of animation,
        // re-submits window dimensions on window resize
		glfwGetFramebufferSize(_window, &_width, &_height);
		glViewport(0, 0, _width, _height); //set viewport in pixels
		glClearColor(0.2, 0.4, 0.6, 1);	//clear window contents
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        _keyEvents->keyEventsWrapper(_window, _sound);
        // [start]:code for drawing
        
        // [end]:code for drawing

        glfwSwapBuffers(_window); //swaps the buffers or windows
        glfwPollEvents();
    }
    glfwTerminate();
    exit(EXIT_SUCCESS);

}

//Terminates initialised system
void Window::terminateSystems(){
    glfwDestroyWindow(_window);    
    glfwTerminate();
    exit(EXIT_FAILURE);
}