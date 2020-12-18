#include "EagleClaw/Core/Application.h"

#include "Preheader.h"

namespace EagleClaw {
Application::Application() {}

Application::~Application() {}

void Application::Run() {
  while (true)
    ;
}

}  // namespace EagleClaw

//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//
//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <string>
//
//#include "imgui/imgui.h"
//#include "imgui/imgui_impl_opengl3.h"
//#include "imgui/imgui_impl_glfw.h"
//
//#include "glm/glm.hpp"
//#include "glm/gtc/matrix_transform.hpp"
//#include "tests/TestClearColor.h"
//#include "tests/TestTexture2D.h"

// int main(void)
//{
//	GLFWwindow* window;
//
//	/* Initialize the library */
//	if (!glfwInit())
//		return -1;
//
//	/* Create a windowed mode window and its OpenGL context */
//	window = glfwCreateWindow(1920.0f, 1080.0f, "Hello World", NULL, NULL);
//	if (!window)
//	{
//		glfwTerminate();
//		return -1;
//	}
//
//	/* Make the window's context current */
//	glfwMakeContextCurrent(window);
//
//	if (glewInit() != GLEW_OK)
//		std::cout << "error!" << std::endl;
//
//	std::cout << glGetString(GL_VERSION) << std::endl;
//	// scope
//	{
//		GLCALL(glEnable(GL_BLEND));
//		GLCALL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_DST_ALPHA));
//
//		Renderer renderer;
//
//		ImGui::CreateContext();
//		ImGui::StyleColorsDark();
//		ImGui_ImplGlfw_InitForOpenGL(window, true);
//		ImGui_ImplOpenGL3_Init("#version 330");
//
//		auto& io = ImGui::GetIO();
//		io.FontGlobalScale = 2;
//
//		test::Test* currentTest = nullptr;
//		std::unique_ptr<test::TestMenu> testMenu =
// std::make_unique<test::TestMenu>(currentTest); 		currentTest =
// testMenu.get();
// testMenu->RegisterTest<test::TestClearColor>("Clear Color");
//		testMenu->RegisterTest<test::TestTexture2D>("Texture 2D");
//
//		while (!glfwWindowShouldClose(window))
//		{
//			renderer.Clear();
//			ImGui_ImplOpenGL3_NewFrame();
//			ImGui_ImplGlfw_NewFrame();
//			ImGui::NewFrame();
//
//			if (currentTest)
//			{
//				currentTest->OnUpdate(0.0f);
//				currentTest->OnRender();
//				ImGui::Begin("Test");
//				if (currentTest != testMenu.get() &&
// ImGui::Button("<-"))
//				{
//					delete currentTest;
//					currentTest = testMenu.get();
//				}
//				currentTest->OnImGuiRender();
//				ImGui::End();
//			}
//
//
//			ImGui::Render();
//			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
//
//			glfwSwapBuffers(window);
//			glfwPollEvents();
//		}
//		if (currentTest != testMenu.get())
//			delete currentTest;
//	}
//	ImGui_ImplOpenGL3_Shutdown();
//	ImGui_ImplGlfw_Shutdown();
//	ImGui::DestroyContext();
//	glfwTerminate();
//	return 0;
//}
//