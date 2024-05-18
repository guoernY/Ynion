#pragma once

#include "Ynion.h"
#include "Panels/SceneHierarchyPanel.h"
#include "Panels/ContentBrowserPanel.h"

#include "Ynion/Renderer/EditorCamera.h"

#include "GameMode.h"

namespace Ynion {
	
	class GameMode;

	class EditorLayer : public Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		virtual void OnUpdate(Timestep ts) override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(Event& e) override;
	public:	// Temp: using friend class makes them private 
		void SetGamePause(bool pause);
		void RestartGame();
		void DrawString(const std::string& string, glm::vec3 offset, glm::vec2 scale, glm::vec4 color);
		void SetMainCamerePos(glm::vec3 transform);
		Ref<Scene> getActiveScene() { return m_ActiveScene; }
	private:
		bool OnKeyPressed(KeyPressedEvent& e);
		bool OnMouseButtonPressed(MouseButtonPressedEvent& e);

		void OnOverlayRender();

		void NewScene();
		void OpenScene();
		void OpenScene(const std::filesystem::path& path);
		void SaveScene();
		void SaveSceneAs();

		void SerializeScene(Ref<Scene> scene, const std::filesystem::path& path);

		void OnScenePlay();
		void OnSceneSimulate();
		void OnSceneStop();
		void OnScenePause();

		void OnDuplicateEntity();

		// UI Panels
		void UI_Toolbar();
	private:
		OrthographicCameraController m_CameraController;

		Ref<Framebuffer> m_Framebuffer;

		Ref<Scene> m_ActiveScene;
		Ref<Scene> m_EditorScene;
		std::filesystem::path m_EditorScenePath;
		Entity m_SquareEntity;
		Entity m_CameraEntity;
		Entity m_SecondCamera;

		Entity m_HoveredEntity;

		bool m_PrimaryCamera = true;

		EditorCamera m_EditorCamera;

		Ref<Texture2D> m_CheckerboardTexture;

		bool m_ViewportFocused = false, m_ViewportHovered = false;
		glm::vec2 m_ViewportSize = { 0.0f, 0.0f };
		glm::vec2 m_ViewportBounds[2];

		glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

		int m_GizmoType = -1;

		bool m_ShowPhysicsColliders = false;

		enum class SceneState
		{
			Edit = 0, Play = 1, Simulate = 2
		};
		SceneState m_SceneState = SceneState::Edit;

		// Panels
		SceneHierarchyPanel m_SceneHierarchyPanel;
		ContentBrowserPanel m_ContentBrowserPanel;

		// Editor resources
		Ref<Texture2D> m_IconPlay, m_IconPause, m_IconStep, m_IconSimulate, m_IconStop;

		// GameMode
		GameMode* m_GameMode = nullptr;
	};

}

