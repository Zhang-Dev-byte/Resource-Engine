#pragma once
#include "Application.h"
#include "Log.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {
	Resource::Log::Init();

	Resource::Application::Start();

    GLFWwindow* window = 0;

    /* Initialize the library */
    if (!glfwInit())
        RS_CORE_ERROR("Failed to initalize GLFW!");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 4);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGL())
    {
        RS_CORE_ERROR("Failed to initalize GLAD!");
    }

    glEnable(GL_MULTISAMPLE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        Resource::Application::Update();

        glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        Resource::Application::Render();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
	RS_CORE_WARN("Initalized Log!");
	Resource::Application::Run();
	while (true);
}