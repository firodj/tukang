#pragma once

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <unordered_map>

class Application {
public:
  void Init();
  void Finish();
  void Run();

  void MakeContextCurrent();
  static void CheckGLError(const char *file, int line);

  static void OnErrorCallback(int error, const char* description);
  static void OnKeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
  static void OnFramebufferSizeCallback(GLFWwindow* window, int width, int height);
  
  static Application* Get();

  GLFWwindow* window() { return window_; }

  bool LockGL(int ms);
  void UnlockGL();

private:
  GLFWwindow *window_;

  int window_width_, window_height_;
  int screen_width_, screen_height_;
};
