#include "Preheader.h"
#include "EagleClaw/Core/Application.h"

namespace EagleClaw {
Application::Application() {
}

Application::~Application() {
}

void Application::Run() {
    while (true)
        ;
}

}  // namespace EagleClaw

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