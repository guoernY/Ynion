#include "ynpch.h"
#include "Buffer.h"

#include "Renderer.h"

#include "Ynion/Platform/OpenGL/OpenGLBuffer.h"

namespace Ynion {

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None:		YN_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::OpenGL:	return new OpenGLVertexBuffer(vertices, size);
		}

		YN_CORE_ASSERT(false, "Unkown RendererAPI!");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None:		YN_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::OpenGL:	return new OpenGLIndexBuffer(indices, size);
		}

		YN_CORE_ASSERT(false, "Unkown RendererAPI!");
		return nullptr;
	}

}