#include "ynpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Ynion {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		:m_WindowHandle(windowHandle)
	{
		YN_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		YN_CORE_ASSERT(status, "Failed to initialize Glad!");

		YN_CORE_INFO("OpenGL Info:");
		YN_CORE_INFO("	Vendor: {0}", (char*)glGetString(GL_VENDOR));
		YN_CORE_INFO("	Renderer: {0}", (char*)glGetString(GL_RENDERER));
		YN_CORE_INFO("	Version: {0}", (char*)glGetString(GL_VERSION));

		#ifdef YN_ENABLE_ASSERTS
			int versionMajor;
			int versionMinor;
			glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
			glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

			YN_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Ynion requires at least OpenGL version 4.5!");
		#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}