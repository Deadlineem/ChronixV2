#include "Onboarding.hpp"
#include "GUI.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/BoolCommand.hpp"
#include "game/backend/AnticheatBypass.hpp"
#include "game/pointers/Pointers.hpp"
#include <shellapi.h>

namespace YimMenu
{
	static BoolCommand _OnboardingComplete{"$onboardingcomplete", "", ""};

	void ProcessOnboarding()
{
		if (_OnboardingComplete.GetState())
			return;

		static bool ensure_popup_open = [] {
			ImGui::OpenPopup("Welcome to ChronixV2");
			GUI::SetOnboarding(true);
			return true;
		}();

		const ImVec2 window_size     = { 700, 520 };
		const ImVec2 window_position = { (*Pointers.ScreenResX - window_size.x) / 2, (*Pointers.ScreenResY - window_size.y) / 2 };

		ImGui::SetNextWindowSize(window_size, ImGuiCond_Always);
		ImGui::SetNextWindowPos(window_position, ImGuiCond_Always);

		if (ImGui::BeginPopupModal("Welcome to ChronixV2", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings))
		{
			ImGui::TextColored(ImVec4(0.3f, 0.7f, 1.0f, 1.0f), "Welcome to ChronixV2!");
			ImGui::Spacing();
			ImGui::TextWrapped("ChronixV2 brings powerful modding tools and features to your game. Before you begin, please take a moment to understand some important notes about BattlEye and multiplayer behavior.");
			ImGui::Spacing();
			
			ImGui::SeparatorText("Important Notice About BattlEye");
			ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.6f, 0.0f, 1.0f));
			ImGui::TextWrapped("Due to BattlEye's protections, joining regular public sessions may result in temporary blacklisting (up to 48 hours). You may also be kicked within 3 minutes.");
			ImGui::PopStyleColor();
			ImGui::Spacing();

			ImGui::SeparatorText("Session Mode Configuration");
			static int sessionChoice = 0;
			ImGui::RadioButton("Join only ChronixV2 users", &sessionChoice, 0);
			ImGui::SameLine();
			ImGui::RadioButton("Join public BattlEye sessions (Not Recommended)", &sessionChoice, 1);

			ImGui::Spacing();
			ImGui::TextWrapped("You can change this later in the menu via:");
			ImGui::BulletText("Network > Spoofing > Join YimMenu-only Sessions"); 

			ImGui::Spacing();
			ImGui::SeparatorText("Useful Links");

			ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
			if (ImGui::Button("Open ChronixV2 GitHub", ImVec2(250, 0)))
				ShellExecuteA(NULL, "open", "https://github.com/DeadlineEm/ChronixV2", NULL, NULL, SW_SHOWNORMAL);

			ImGui::SameLine();

			if (ImGui::Button("Join Discord Server", ImVec2(250, 0)))
				ShellExecuteA(NULL, "open", "https://discord.gg/ZcC3NP3sAT", NULL, NULL, SW_SHOWNORMAL);

			ImGui::Spacing();
			ImGui::SeparatorText("Final Tip");
			ImGui::TextWrapped("We release **nightly updates**. Check for updates regularly for the latest features, improvements, and fixes.");
			ImGui::Spacing();

			ImGui::Spacing();
			ImGui::SetCursorPosX((ImGui::GetWindowWidth() - 120) / 2);
			if (ImGui::Button("Get Started", ImVec2(120, 0)))
			{
				Commands::GetCommand<BoolCommand>("cheaterpool"_J)->SetState(!sessionChoice);
				_OnboardingComplete.SetState(true);
				GUI::SetOnboarding(false);
				ImGui::CloseCurrentPopup();
			}

			ImGui::EndPopup();
		}
	}
}