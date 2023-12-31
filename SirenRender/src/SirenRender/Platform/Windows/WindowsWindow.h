#pragma once
#include <glad/glad.h>
#include "SirenRender/Core/Window.h"
#include "SirenRender/Render/GraphicsContext.h"
#include <glfw3.h>

namespace SirenRender
{
	class SIREN_API WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		unsigned int GetWidth() const override {return m_Data.Width;}
		unsigned int GetHeight() const override {return m_Data.Height;}

		void SetEventCallBack(const EventCallBack& callback) override { m_Data.Callback = callback; }
		void SetVSync(bool enable) override;
		bool IsVSync() const override;

		virtual void* GetNativeWindow() const {return m_Window;}
	private:		
		
		virtual void Init(const WindowProps& props);
		virtual void Shutdown(); 
		
		GLFWwindow* m_Window;
		GraphicsContext* m_Context;
		 
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallBack Callback;
		};

		WindowData m_Data;
	};
}