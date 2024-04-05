#include"ball.h"
#include"cube.h"
#include"material.h"
#include"draw.h"
#include"GLinclude.h"
#include"object.h"

#include <iostream>

std::vector<object *> objs;

int width = 800, height = 600;
glm::vec3 cameraPos = glm::vec3(0, 0, 0);
glm::vec3 frontPos = glm::vec3(0, 0, 10);

void reshape(GLFWwindow *window, int w, int h){
    width = w;
    height = h;
    display(window, w, h, 0, 0, cameraPos, frontPos, objs);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    if(!glfwInit()){
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(width, height, "Collide", nullptr, nullptr);
    if(!window){
        glfwTerminate();
        return -1;
    }


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, keyboard);
    glfwSetWindowSizeCallback(window, reshape);
    glfwSetCursorPosCallback(window, nullptr);
    glfwSetMouseButtonCallback(window, nullptr);
    GLenum err = glewInit();

    if(GLEW_OK != err){
        std::cout << "error: " << glewGetErrorString(err) << std::endl;
        exit(-1);
    }
    glInit();
    initObjects(objs);

    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    float lastTimePhy = glfwGetTime();
    float lastTimeFps = glfwGetTime();
    int cntFps = 0;
    int fps = 0;
    while(!glfwWindowShouldClose(window)){
        double currentTime = glfwGetTime();
        float dt = currentTime - lastTimePhy;
        cntFps++;
        if(dt > 0.001){
            updatePhysics(dt, objs);
            lastTimePhy = currentTime;
        }
        if(currentTime - lastTimeFps > 0.1){
            fps = cntFps / (currentTime - lastTimeFps);
            cntFps = 0;
            lastTimeFps = currentTime;
        }
        update(frontPos, cameraPos);
        display(window, width, height, dt, fps, cameraPos, frontPos, objs);

        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}