#include "ynpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Ynion {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}