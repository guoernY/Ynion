#include "ynpch.h"
#include "OrthographicCameraController.h"

#include "Ynion/Core/Input.h"
#include "Ynion/Core/KeyCodes.h"

namespace Ynion {

	OrthographicCameraController::OrthographicCameraController(float aspectRatio, bool rotation)
		: m_AspectRatio(aspectRatio), m_Camera(-m_AspectRatio * m_ZoomLevel, m_AspectRatio* m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel), m_Rotation(rotation)
	{
	}

	void OrthographicCameraController::OnUpdate(Timestep ts)
	{
		if (Ynion::Input::IsKeyPressed(YN_KEY_A))
			m_CameraPosition.x -= m_CameraTranslationSpeed * ts;
		else if (Ynion::Input::IsKeyPressed(YN_KEY_D))
			m_CameraPosition.x += m_CameraTranslationSpeed * ts;
		if (Ynion::Input::IsKeyPressed(YN_KEY_W))
			m_CameraPosition.y += m_CameraTranslationSpeed * ts;
		else if (Ynion::Input::IsKeyPressed(YN_KEY_S))
			m_CameraPosition.y -= m_CameraTranslationSpeed * ts;
		
		m_Camera.SetPosition(m_CameraPosition);

		if (m_Rotation)
		{
			if (Ynion::Input::IsKeyPressed(YN_KEY_Q))
				m_CameraRotation += m_CameraRotationSpeed * ts;
			else if (Ynion::Input::IsKeyPressed(YN_KEY_E))
				m_CameraRotation -= m_CameraRotationSpeed * ts;

			m_Camera.SetRotation(m_CameraRotation);
		}
		
		m_CameraTranslationSpeed = m_ZoomLevel;
	}

	void OrthographicCameraController::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseScrolledEvent>(YN_BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
		dispatcher.Dispatch<WindowResizeEvent>(YN_BIND_EVENT_FN(OrthographicCameraController::OnWindowResized));
	}

	void OrthographicCameraController::OnResize(float width, float height)
	{
		m_AspectRatio = width / height;
		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
	}

	bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& e)
	{
		m_ZoomLevel -= e.GetYOffset() * 0.25f;
		m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);

		return false;
	}

	bool OrthographicCameraController::OnWindowResized(WindowResizeEvent& e)
	{
		OnResize((float)e.GetWidth(), (float)e.GetHeight());

		return false;
	}

}