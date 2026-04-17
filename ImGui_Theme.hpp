#pragma once
#include "Fucking ImGui/imgui.h"
#include <cmath>

namespace OW {
	namespace ImGuiTheme {

		// Énumération des thèmes disponibles
		enum class Theme {
			Dark,
			Light,
			Classic,
			Purple,
			Blue,
			Green,
			Red,
			Orange,
			Cyberpunk
		};

		// ===== Thème Dark (Sombre) =====
		inline void ApplyDarkTheme() {
			ImGuiStyle& style = ImGui::GetStyle();
			ImVec4* colors = style.Colors;

			colors[ImGuiCol_WindowBg] = ImVec4(0.09f, 0.09f, 0.09f, 1.00f);
			colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
			colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
			colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			colors[ImGuiCol_FrameBg] = ImVec4(0.16f, 0.16f, 0.16f, 0.54f);
			colors[ImGuiCol_FrameBgHovered] = ImVec4(0.26f, 0.26f, 0.26f, 0.40f);
			colors[ImGuiCol_FrameBgActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
			colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
			colors[ImGuiCol_TitleBgActive] = ImVec4(0.16f, 0.29f, 0.48f, 1.00f);
			colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
			colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
			colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
			colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
			colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
			colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
			colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
			colors[ImGuiCol_SliderGrab] = ImVec4(0.24f, 0.52f, 0.88f, 1.00f);
			colors[ImGuiCol_SliderGrabActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
			colors[ImGuiCol_Button] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
			colors[ImGuiCol_ButtonHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
			colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
			colors[ImGuiCol_Header] = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
			colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
			colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
			colors[ImGuiCol_Separator] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
			colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
			colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
			colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.20f);
			colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
			colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
			colors[ImGuiCol_Tab] = ImVec4(0.18f, 0.35f, 0.58f, 0.86f);
			colors[ImGuiCol_TabHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
			colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.41f, 0.68f, 1.00f);
			colors[ImGuiCol_TabUnfocused] = ImVec4(0.07f, 0.10f, 0.15f, 0.97f);
			colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.26f, 0.42f, 1.00f);
			colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
			colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
			colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
			colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.45f, 0.00f, 1.00f);
			colors[ImGuiCol_TableHeaderBg] = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
			colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
			colors[ImGuiCol_TableBorderLight] = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
			colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
			colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
			colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
			colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
			colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
			colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
			colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);

			// Style
			style.WindowPadding = ImVec2(8.00f, 8.00f);
			style.FramePadding = ImVec2(5.00f, 2.00f);
			style.CellPadding = ImVec2(6.00f, 6.00f);
			style.ItemSpacing = ImVec2(6.00f, 6.00f);
			style.ItemInnerSpacing = ImVec2(6.00f, 6.00f);
			style.TouchExtraPadding = ImVec2(0.00f, 0.00f);
			style.IndentSpacing = 25.0f;
			style.ScrollbarSize = 15.0f;
			style.GrabMinSize = 10.0f;
			style.WindowBorderSize = 1.0f;
			style.ChildBorderSize = 1.0f;
			style.PopupBorderSize = 1.0f;
			style.FrameBorderSize = 1.0f;
			style.TabBorderSize = 1.0f;
			style.WindowRounding = 7.0f;
			style.ChildRounding = 4.0f;
			style.FrameRounding = 3.0f;
			style.PopupRounding = 4.0f;
			style.ScrollbarRounding = 9.0f;
			style.GrabRounding = 3.0f;
			style.TabRounding = 4.0f;
		}

		// ===== Thème Light (Clair) =====
		inline void ApplyLightTheme() {
			ImGuiStyle& style = ImGui::GetStyle();
			ImVec4* colors = style.Colors;

			colors[ImGuiCol_WindowBg] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
			colors[ImGuiCol_ChildBg] = ImVec4(0.98f, 0.98f, 0.98f, 1.00f);
			colors[ImGuiCol_PopupBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.98f);
			colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.80f, 0.50f);
			colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			colors[ImGuiCol_FrameBg] = ImVec4(0.96f, 0.96f, 0.96f, 1.00f);
			colors[ImGuiCol_FrameBgHovered] = ImVec4(0.91f, 0.91f, 0.91f, 1.00f);
			colors[ImGuiCol_FrameBgActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
			colors[ImGuiCol_TitleBg] = ImVec4(0.96f, 0.96f, 0.96f, 1.00f);
			colors[ImGuiCol_TitleBgActive] = ImVec4(0.82f, 0.82f, 0.82f, 1.00f);
			colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 1.00f, 1.00f, 0.80f);
			colors[ImGuiCol_MenuBarBg] = ImVec4(0.86f, 0.86f, 0.86f, 1.00f);
			colors[ImGuiCol_ScrollbarBg] = ImVec4(0.98f, 0.98f, 0.98f, 0.53f);
			colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.69f, 0.69f, 0.69f, 0.80f);
			colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.49f, 0.49f, 0.49f, 0.80f);
			colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.49f, 0.49f, 0.49f, 1.00f);
			colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
			colors[ImGuiCol_SliderGrab] = ImVec4(0.26f, 0.59f, 0.98f, 0.78f);
			colors[ImGuiCol_SliderGrabActive] = ImVec4(0.46f, 0.54f, 0.80f, 0.60f);
			colors[ImGuiCol_Button] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
			colors[ImGuiCol_ButtonHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
			colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
			colors[ImGuiCol_Header] = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
			colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
			colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
			colors[ImGuiCol_Separator] = ImVec4(0.39f, 0.39f, 0.39f, 0.62f);
			colors[ImGuiCol_SeparatorHovered] = ImVec4(0.14f, 0.44f, 0.80f, 0.78f);
			colors[ImGuiCol_SeparatorActive] = ImVec4(0.14f, 0.44f, 0.80f, 1.00f);
			colors[ImGuiCol_ResizeGrip] = ImVec4(0.35f, 0.35f, 0.35f, 0.17f);
			colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
			colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
			colors[ImGuiCol_Tab] = ImVec4(0.76f, 0.80f, 0.86f, 0.58f);
			colors[ImGuiCol_TabHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
			colors[ImGuiCol_TabActive] = ImVec4(0.60f, 0.73f, 0.88f, 1.00f);
			colors[ImGuiCol_TabUnfocused] = ImVec4(0.92f, 0.93f, 0.94f, 0.99f);
			colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.74f, 0.82f, 0.91f, 1.00f);
			colors[ImGuiCol_PlotLines] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
			colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
			colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
			colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.45f, 0.00f, 1.00f);
			colors[ImGuiCol_TableHeaderBg] = ImVec4(0.78f, 0.87f, 0.98f, 1.00f);
			colors[ImGuiCol_TableBorderStrong] = ImVec4(0.57f, 0.57f, 0.64f, 1.00f);
			colors[ImGuiCol_TableBorderLight] = ImVec4(0.68f, 0.68f, 0.74f, 1.00f);
			colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			colors[ImGuiCol_TableRowBgAlt] = ImVec4(0.30f, 0.30f, 0.30f, 0.09f);
			colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
			colors[ImGuiCol_DragDropTarget] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
			colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
			colors[ImGuiCol_NavWindowingHighlight] = ImVec4(0.70f, 0.70f, 0.70f, 0.70f);
			colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.20f);
			colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);

			// Style
			style.WindowPadding = ImVec2(8.00f, 8.00f);
			style.FramePadding = ImVec2(5.00f, 2.00f);
			style.CellPadding = ImVec2(6.00f, 6.00f);
			style.ItemSpacing = ImVec2(6.00f, 6.00f);
			style.ItemInnerSpacing = ImVec2(6.00f, 6.00f);
			style.TouchExtraPadding = ImVec2(0.00f, 0.00f);
			style.IndentSpacing = 25.0f;
			style.ScrollbarSize = 15.0f;
			style.GrabMinSize = 10.0f;
			style.WindowBorderSize = 1.0f;
			style.ChildBorderSize = 1.0f;
			style.PopupBorderSize = 1.0f;
			style.FrameBorderSize = 1.0f;
			style.TabBorderSize = 1.0f;
			style.WindowRounding = 7.0f;
			style.ChildRounding = 4.0f;
			style.FrameRounding = 3.0f;
			style.PopupRounding = 4.0f;
			style.ScrollbarRounding = 9.0f;
			style.GrabRounding = 3.0f;
			style.TabRounding = 4.0f;
		}

		// ===== Thème Cyberpunk =====
		inline void ApplyCyberpunkTheme() {
			ImGuiStyle& style = ImGui::GetStyle();
			ImVec4* colors = style.Colors;

			// Couleurs cyberpunk: rose/magenta et cyan
			colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.12f, 1.00f);
			colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			colors[ImGuiCol_PopupBg] = ImVec4(0.05f, 0.05f, 0.10f, 0.94f);
			colors[ImGuiCol_Border] = ImVec4(1.00f, 0.00f, 1.00f, 0.30f);
			colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 1.00f, 1.00f, 0.15f);
			colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.10f, 0.20f, 0.54f);
			colors[ImGuiCol_FrameBgHovered] = ImVec4(0.20f, 0.00f, 0.40f, 0.40f);
			colors[ImGuiCol_FrameBgActive] = ImVec4(1.00f, 0.00f, 1.00f, 0.67f);
			colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.08f, 1.00f);
			colors[ImGuiCol_TitleBgActive] = ImVec4(1.00f, 0.00f, 1.00f, 0.80f);
			colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 1.00f, 1.00f, 0.40f);
			colors[ImGuiCol_MenuBarBg] = ImVec4(0.08f, 0.08f, 0.16f, 1.00f);
			colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.05f, 0.53f);
			colors[ImGuiCol_ScrollbarGrab] = ImVec4(1.00f, 0.00f, 1.00f, 0.80f);
			colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(1.00f, 0.00f, 1.00f, 1.00f);
			colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
			colors[ImGuiCol_CheckMark] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
			colors[ImGuiCol_SliderGrab] = ImVec4(1.00f, 0.00f, 1.00f, 0.80f);
			colors[ImGuiCol_SliderGrabActive] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
			colors[ImGuiCol_Button] = ImVec4(1.00f, 0.00f, 1.00f, 0.40f);
			colors[ImGuiCol_ButtonHovered] = ImVec4(1.00f, 0.00f, 1.00f, 1.00f);
			colors[ImGuiCol_ButtonActive] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
			colors[ImGuiCol_Header] = ImVec4(1.00f, 0.00f, 1.00f, 0.31f);
			colors[ImGuiCol_HeaderHovered] = ImVec4(1.00f, 0.00f, 1.00f, 0.80f);
			colors[ImGuiCol_HeaderActive] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
			colors[ImGuiCol_Separator] = ImVec4(1.00f, 0.00f, 1.00f, 0.50f);
			colors[ImGuiCol_SeparatorHovered] = ImVec4(0.00f, 1.00f, 1.00f, 0.78f);
			colors[ImGuiCol_SeparatorActive] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
			colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 0.00f, 1.00f, 0.20f);
			colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.00f, 0.00f, 1.00f, 0.67f);
			colors[ImGuiCol_ResizeGripActive] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
			colors[ImGuiCol_Tab] = ImVec4(1.00f, 0.00f, 1.00f, 0.40f);
			colors[ImGuiCol_TabHovered] = ImVec4(1.00f, 0.00f, 1.00f, 0.80f);
			colors[ImGuiCol_TabActive] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
			colors[ImGuiCol_TabUnfocused] = ImVec4(0.50f, 0.00f, 1.00f, 0.50f);
			colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.00f, 0.50f, 1.00f, 0.70f);
			colors[ImGuiCol_PlotLines] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
			colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.00f, 1.00f, 1.00f);
			colors[ImGuiCol_PlotHistogram] = ImVec4(1.00f, 0.50f, 0.00f, 1.00f);
			colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.00f, 1.00f, 1.00f);
			colors[ImGuiCol_TableHeaderBg] = ImVec4(1.00f, 0.00f, 1.00f, 0.20f);
			colors[ImGuiCol_TableBorderStrong] = ImVec4(0.00f, 1.00f, 1.00f, 0.40f);
			colors[ImGuiCol_TableBorderLight] = ImVec4(1.00f, 0.00f, 1.00f, 0.20f);
			colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 0.00f, 1.00f, 0.10f);
			colors[ImGuiCol_TextSelectedBg] = ImVec4(1.00f, 0.00f, 1.00f, 0.35f);
			colors[ImGuiCol_DragDropTarget] = ImVec4(0.00f, 1.00f, 1.00f, 0.90f);
			colors[ImGuiCol_NavHighlight] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
			colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 0.00f, 1.00f, 0.70f);
			colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.20f);
			colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.35f);

			// Style
			style.WindowPadding = ImVec2(8.00f, 8.00f);
			style.FramePadding = ImVec2(5.00f, 2.00f);
			style.CellPadding = ImVec2(6.00f, 6.00f);
			style.ItemSpacing = ImVec2(6.00f, 6.00f);
			style.ItemInnerSpacing = ImVec2(6.00f, 6.00f);
			style.TouchExtraPadding = ImVec2(0.00f, 0.00f);
			style.IndentSpacing = 25.0f;
			style.ScrollbarSize = 15.0f;
			style.GrabMinSize = 10.0f;
			style.WindowBorderSize = 2.0f;
			style.ChildBorderSize = 1.0f;
			style.PopupBorderSize = 2.0f;
			style.FrameBorderSize = 1.0f;
			style.TabBorderSize = 1.0f;
			style.WindowRounding = 8.0f;
			style.ChildRounding = 4.0f;
			style.FrameRounding = 4.0f;
			style.PopupRounding = 4.0f;
			style.ScrollbarRounding = 9.0f;
			style.GrabRounding = 3.0f;
			style.TabRounding = 4.0f;
		}

		// ===== Thème Purple (Violet) =====
		inline void ApplyPurpleTheme() {
			ImGuiStyle& style = ImGui::GetStyle();
			ImVec4* colors = style.Colors;

			colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.08f, 0.15f, 1.00f);
			colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.12f, 0.94f);
			colors[ImGuiCol_Border] = ImVec4(0.70f, 0.40f, 1.00f, 0.50f);
			colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			colors[ImGuiCol_FrameBg] = ImVec4(0.16f, 0.10f, 0.26f, 0.54f);
			colors[ImGuiCol_FrameBgHovered] = ImVec4(0.26f, 0.16f, 0.36f, 0.40f);
			colors[ImGuiCol_FrameBgActive] = ImVec4(0.80f, 0.40f, 1.00f, 0.67f);
			colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.08f, 1.00f);
			colors[ImGuiCol_TitleBgActive] = ImVec4(0.50f, 0.20f, 0.80f, 1.00f);
			colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.30f, 0.10f, 0.50f, 0.51f);
			colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.10f, 0.20f, 1.00f);
			colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.05f, 0.53f);
			colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.70f, 0.40f, 1.00f, 1.00f);
			colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.80f, 0.50f, 1.00f, 1.00f);
			colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.90f, 0.60f, 1.00f, 1.00f);
			colors[ImGuiCol_CheckMark] = ImVec4(0.80f, 0.40f, 1.00f, 1.00f);
			colors[ImGuiCol_SliderGrab] = ImVec4(0.70f, 0.40f, 1.00f, 1.00f);
			colors[ImGuiCol_SliderGrabActive] = ImVec4(0.80f, 0.50f, 1.00f, 1.00f);
			colors[ImGuiCol_Button] = ImVec4(0.70f, 0.40f, 1.00f, 0.40f);
			colors[ImGuiCol_ButtonHovered] = ImVec4(0.80f, 0.50f, 1.00f, 1.00f);
			colors[ImGuiCol_ButtonActive] = ImVec4(0.90f, 0.60f, 1.00f, 1.00f);
			colors[ImGuiCol_Header] = ImVec4(0.70f, 0.40f, 1.00f, 0.31f);
			colors[ImGuiCol_HeaderHovered] = ImVec4(0.80f, 0.50f, 1.00f, 0.80f);
			colors[ImGuiCol_HeaderActive] = ImVec4(0.90f, 0.60f, 1.00f, 1.00f);
			colors[ImGuiCol_Separator] = ImVec4(0.70f, 0.40f, 1.00f, 0.50f);
			colors[ImGuiCol_SeparatorHovered] = ImVec4(0.80f, 0.50f, 1.00f, 0.78f);
			colors[ImGuiCol_SeparatorActive] = ImVec4(0.90f, 0.60f, 1.00f, 1.00f);
			colors[ImGuiCol_ResizeGrip] = ImVec4(0.70f, 0.40f, 1.00f, 0.20f);
			colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.80f, 0.50f, 1.00f, 0.67f);
			colors[ImGuiCol_ResizeGripActive] = ImVec4(0.90f, 0.60f, 1.00f, 0.95f);
			colors[ImGuiCol_Tab] = ImVec4(0.50f, 0.25f, 0.70f, 0.86f);
			colors[ImGuiCol_TabHovered] = ImVec4(0.70f, 0.40f, 1.00f, 0.80f);
			colors[ImGuiCol_TabActive] = ImVec4(0.60f, 0.35f, 0.80f, 1.00f);
			colors[ImGuiCol_TabUnfocused] = ImVec4(0.25f, 0.15f, 0.40f, 0.97f);
			colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.40f, 0.25f, 0.60f, 1.00f);
			colors[ImGuiCol_PlotLines] = ImVec4(0.80f, 0.40f, 1.00f, 1.00f);
			colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.60f, 1.00f, 1.00f);
			colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
			colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
			colors[ImGuiCol_TableHeaderBg] = ImVec4(0.40f, 0.20f, 0.60f, 1.00f);
			colors[ImGuiCol_TableBorderStrong] = ImVec4(0.70f, 0.40f, 1.00f, 1.00f);
			colors[ImGuiCol_TableBorderLight] = ImVec4(0.60f, 0.30f, 0.80f, 1.00f);
			colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
			colors[ImGuiCol_TextSelectedBg] = ImVec4(0.70f, 0.40f, 1.00f, 0.35f);
			colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
			colors[ImGuiCol_NavHighlight] = ImVec4(0.80f, 0.50f, 1.00f, 1.00f);
			colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
			colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
			colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);

			// Style
			style.WindowPadding = ImVec2(8.00f, 8.00f);
			style.FramePadding = ImVec2(5.00f, 2.00f);
			style.CellPadding = ImVec2(6.00f, 6.00f);
			style.ItemSpacing = ImVec2(6.00f, 6.00f);
			style.ItemInnerSpacing = ImVec2(6.00f, 6.00f);
			style.TouchExtraPadding = ImVec2(0.00f, 0.00f);
			style.IndentSpacing = 25.0f;
			style.ScrollbarSize = 15.0f;
			style.GrabMinSize = 10.0f;
			style.WindowBorderSize = 1.0f;
			style.ChildBorderSize = 1.0f;
			style.PopupBorderSize = 1.0f;
			style.FrameBorderSize = 1.0f;
			style.TabBorderSize = 1.0f;
			style.WindowRounding = 7.0f;
			style.ChildRounding = 4.0f;
			style.FrameRounding = 3.0f;
			style.PopupRounding = 4.0f;
			style.ScrollbarRounding = 9.0f;
			style.GrabRounding = 3.0f;
			style.TabRounding = 4.0f;
		}

		// ===== Thème Blue (Bleu) =====
		inline void ApplyBlueTheme() {
			ImGuiStyle& style = ImGui::GetStyle();
			ImVec4* colors = style.Colors;

			colors[ImGuiCol_WindowBg] = ImVec4(0.08f, 0.10f, 0.16f, 1.00f);
			colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.14f, 0.94f);
			colors[ImGuiCol_Border] = ImVec4(0.40f, 0.60f, 1.00f, 0.50f);
			colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.14f, 0.26f, 0.54f);
			colors[ImGuiCol_FrameBgHovered] = ImVec4(0.16f, 0.22f, 0.36f, 0.40f);
			colors[ImGuiCol_FrameBgActive] = ImVec4(0.40f, 0.70f, 1.00f, 0.67f);
			colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.06f, 0.10f, 1.00f);
			colors[ImGuiCol_TitleBgActive] = ImVec4(0.20f, 0.50f, 1.00f, 1.00f);
			colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.10f, 0.30f, 0.70f, 0.51f);
			colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.12f, 0.18f, 1.00f);
			colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.05f, 0.53f);
			colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.40f, 0.70f, 1.00f, 1.00f);
			colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.50f, 0.80f, 1.00f, 1.00f);
			colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.60f, 0.90f, 1.00f, 1.00f);
			colors[ImGuiCol_CheckMark] = ImVec4(0.40f, 0.80f, 1.00f, 1.00f);
			colors[ImGuiCol_SliderGrab] = ImVec4(0.40f, 0.70f, 1.00f, 1.00f);
			colors[ImGuiCol_SliderGrabActive] = ImVec4(0.50f, 0.80f, 1.00f, 1.00f);
			colors[ImGuiCol_Button] = ImVec4(0.40f, 0.70f, 1.00f, 0.40f);
			colors[ImGuiCol_ButtonHovered] = ImVec4(0.50f, 0.80f, 1.00f, 1.00f);
			colors[ImGuiCol_ButtonActive] = ImVec4(0.60f, 0.90f, 1.00f, 1.00f);
			colors[ImGuiCol_Header] = ImVec4(0.40f, 0.70f, 1.00f, 0.31f);
			colors[ImGuiCol_HeaderHovered] = ImVec4(0.50f, 0.80f, 1.00f, 0.80f);
			colors[ImGuiCol_HeaderActive] = ImVec4(0.60f, 0.90f, 1.00f, 1.00f);
			colors[ImGuiCol_Separator] = ImVec4(0.40f, 0.70f, 1.00f, 0.50f);
			colors[ImGuiCol_SeparatorHovered] = ImVec4(0.50f, 0.80f, 1.00f, 0.78f);
			colors[ImGuiCol_SeparatorActive] = ImVec4(0.60f, 0.90f, 1.00f, 1.00f);
			colors[ImGuiCol_ResizeGrip] = ImVec4(0.40f, 0.70f, 1.00f, 0.20f);
			colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.50f, 0.80f, 1.00f, 0.67f);
			colors[ImGuiCol_ResizeGripActive] = ImVec4(0.60f, 0.90f, 1.00f, 0.95f);
			colors[ImGuiCol_Tab] = ImVec4(0.20f, 0.50f, 0.80f, 0.86f);
			colors[ImGuiCol_TabHovered] = ImVec4(0.40f, 0.70f, 1.00f, 0.80f);
			colors[ImGuiCol_TabActive] = ImVec4(0.30f, 0.60f, 0.90f, 1.00f);
			colors[ImGuiCol_TabUnfocused] = ImVec4(0.07f, 0.15f, 0.30f, 0.97f);
			colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.35f, 0.60f, 1.00f);
			colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.80f, 1.00f, 1.00f);
			colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.60f, 0.90f, 1.00f, 1.00f);
			colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
			colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.80f, 0.00f, 1.00f);
			colors[ImGuiCol_TableHeaderBg] = ImVec4(0.20f, 0.40f, 0.70f, 1.00f);
			colors[ImGuiCol_TableBorderStrong] = ImVec4(0.40f, 0.70f, 1.00f, 1.00f);
			colors[ImGuiCol_TableBorderLight] = ImVec4(0.30f, 0.50f, 0.80f, 1.00f);
			colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
			colors[ImGuiCol_TextSelectedBg] = ImVec4(0.40f, 0.70f, 1.00f, 0.35f);
			colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
			colors[ImGuiCol_NavHighlight] = ImVec4(0.50f, 0.80f, 1.00f, 1.00f);
			colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
			colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
			colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);

			// Style
			style.WindowPadding = ImVec2(8.00f, 8.00f);
			style.FramePadding = ImVec2(5.00f, 2.00f);
			style.CellPadding = ImVec2(6.00f, 6.00f);
			style.ItemSpacing = ImVec2(6.00f, 6.00f);
			style.ItemInnerSpacing = ImVec2(6.00f, 6.00f);
			style.TouchExtraPadding = ImVec2(0.00f, 0.00f);
			style.IndentSpacing = 25.0f;
			style.ScrollbarSize = 15.0f;
			style.GrabMinSize = 10.0f;
			style.WindowBorderSize = 1.0f;
			style.ChildBorderSize = 1.0f;
			style.PopupBorderSize = 1.0f;
			style.FrameBorderSize = 1.0f;
			style.TabBorderSize = 1.0f;
			style.WindowRounding = 7.0f;
			style.ChildRounding = 4.0f;
			style.FrameRounding = 3.0f;
			style.PopupRounding = 4.0f;
			style.ScrollbarRounding = 9.0f;
			style.GrabRounding = 3.0f;
			style.TabRounding = 4.0f;
		}

		// ===== Fonction générique pour appliquer un thème =====
		inline void ApplyTheme(Theme theme) {
			switch (theme) {
				case Theme::Dark:
					ApplyDarkTheme();
					break;
				case Theme::Light:
					ApplyLightTheme();
					break;
				case Theme::Cyberpunk:
					ApplyCyberpunkTheme();
					break;
				case Theme::Purple:
					ApplyPurpleTheme();
					break;
				case Theme::Blue:
					ApplyBlueTheme();
					break;
				default:
					ApplyDarkTheme();
					break;
			}
		}
	}
}
