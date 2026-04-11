#include "Onboarding.hpp"
#include "GUI.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/BoolCommand.hpp"
#include "game/backend/AnticheatBypass.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/frontend/Menu.hpp"
#include "core/frontend/manager/UIManager.hpp"
#include <shellapi.h>

#define ICON_FA_ROCKET "\xef\x84\xb5"             // f135
#define ICON_FA_SHIELD_ALT "\xef\x8f\xad"          // f3ed
#define ICON_FA_USERS "\xef\x8b\x83"               // f0c0
#define ICON_FA_EXCLAMATION_TRIANGLE "\xef\x81\xb1" // f071
#define ICON_FA_GITHUB        "\xef\x84\xa1"
#define ICON_FA_MATRIX        "\xef\x89\xba"
#define ICON_FA_CHECK "\xef\x81\x98"               // f058
#define ICON_FA_LINK "\xef\x83\x81"                // f0c1

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

		const ImVec2 window_size = {700, 520};
		const ImVec2 window_pos = {(*Pointers.ScreenResX - window_size.x) / 2, (*Pointers.ScreenResY - window_size.y) / 2};

		ImGui::SetNextWindowSize(window_size, ImGuiCond_Once);
		ImGui::SetNextWindowPos(window_pos, ImGuiCond_Once);

		if (ImGui::BeginPopupModal("Welcome to ChronixV2", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings))
		{
			static int tab = 0;
			if (ImGui::BeginTabBar("##onboarding_tabs", ImGuiTabBarFlags_None))
			{
				// ───────────────────────────── Intro Tab
				if (ImGui::BeginTabItem("Intro"))
				{
					ImGui::PushTextWrapPos(0.0f);
					ImGui::PushFont(YimMenu::Menu::Font::g_AwesomeFont); ImGui::TextUnformatted(ICON_FA_ROCKET); ImGui::PopFont();
					ImGui::SameLine(); ImGui::Text("Welcome to ChronixV2!");
					
					ImGui::Spacing();
					ImGui::Separator();
					ImGui::Spacing();

					ImGui::TextWrapped("Press INSERT or Ctrl+\\ to open the menu. This tool gives you advanced control over GTA V with a modded experience.");
					ImGui::Spacing();
					ImGui::TextWrapped("ChronixV2 publishes builds every 12 hours and stays updated to the latest commits off of YimMenuV2's repository. Be sure to check GitHub frequently for new updates, experiment, and most importantly — enjoy!");

					ImGui::PopTextWrapPos();
					ImGui::EndTabItem();
				}
				
				// ───────────────────────────── Warning Tab
				if (ImGui::BeginTabItem("Warning & Disclaimer"))
				{
					ImGui::PushTextWrapPos(0.0f);

					// Header: Icon + Title
					ImGui::PushFont(YimMenu::Menu::Font::g_AwesomeFont);
					ImGui::TextUnformatted(ICON_FA_EXCLAMATION_TRIANGLE);
					ImGui::PopFont();
					ImGui::SameLine();
					ImGui::TextColored(ImVec4(1.f, 0.6f, 0.f, 1.f), "Important Notice");

					ImGui::Spacing();
					ImGui::Separator();
					ImGui::Spacing();

					// Modding warning
					ImGui::TextWrapped("Modding *Grand Theft Auto Online* is strictly prohibited by Rockstar Games and Take-Two Interactive. Engaging in modding activity may violate the game's Terms of Service and End User License Agreement (EULA).");

					ImGui::Spacing();
					ImGui::BulletText("Use this software in *private or invite-only* sessions only.");
					ImGui::BulletText("Avoid joining public or Rockstar-hosted sessions.");
					ImGui::BulletText("Do not grief or interfere with non-modding players.");
					ImGui::BulletText("Disconnect immediately if unexpected players join.");
					
					ImGui::Spacing();
					ImGui::TextWrapped("Failure to follow these precautions may result in:");
					ImGui::BulletText("Temporary or permanent account suspension.");
					ImGui::BulletText("Soft or hard bans/blacklisting from GTA Online services.");
					ImGui::BulletText("Social Club account restrictions.");
					ImGui::BulletText("System-level penalties depending on severity.");

					ImGui::Spacing();
					ImGui::Separator();
					ImGui::Spacing();

					// Disclaimer
					ImGui::PushFont(YimMenu::Menu::Font::g_AwesomeFont);
					ImGui::TextUnformatted(ICON_FA_EXCLAMATION_TRIANGLE);
					ImGui::PopFont();
					ImGui::SameLine();
					ImGui::TextColored(ImVec4(0.9f, 0.4f, 0.4f, 1.f), "Disclaimer");

					ImGui::Spacing();
					ImGui::TextWrapped(
						"This tool is provided strictly for educational and developmental purposes. "
						"The developers and contributors of this software assume *no responsibility* for any consequences resulting from its use. "
						"You use this tool entirely at your own risk. No warranties or guarantees are provided, expressed or implied."
					);
					ImGui::PopTextWrapPos();
					ImGui::EndTabItem();
				}

				// ───────────────────────────── Restrictions Tab
				if (ImGui::BeginTabItem("Battleye Restrictions"))
				{
					ImGui::PushTextWrapPos(0.0f);
					ImGui::PushFont(YimMenu::Menu::Font::g_AwesomeFont); ImGui::TextUnformatted(ICON_FA_SHIELD_ALT); ImGui::PopFont();
					ImGui::SameLine(); ImGui::Text("BattlEye Restrictions");
					
					ImGui::Spacing();
					ImGui::Separator();
					ImGui::Spacing();
					
					ImGui::TextWrapped("Due to BattlEye anti-cheat enforcement, joining public sessions is unreliable. You can:");
					ImGui::BulletText("Play only with other Mod/FSL users (safe and stable)");
					ImGui::BulletText("Attempt connecting to Public sessions");
					ImGui::TextWrapped("NOTE: Public sessions are risky; disconnects after ~3 minutes if not host and may cause temporary blacklisting from online / bans.");

					static int choice = 0;
					ImGui::RadioButton("Play with Mod/FSL users", &choice, 0);
					ImGui::SameLine();
					ImGui::RadioButton("Attempt public sessions", &choice, 1);
					ImGui::PopTextWrapPos();
					ImGui::EndTabItem();
				}

				// ───────────────────────────── Community Tab
				if (ImGui::BeginTabItem("Community"))
				{
					ImGui::PushTextWrapPos(0.0f);
					ImGui::PushFont(YimMenu::Menu::Font::g_AwesomeFont); ImGui::TextUnformatted(ICON_FA_USERS); ImGui::PopFont();
					ImGui::SameLine(); ImGui::Text("Stay Connected");

					ImGui::Spacing();
					ImGui::Separator();
					ImGui::Spacing();
					
					ImGui::TextWrapped("We recommend bookmarking our GitHub and joining YimMenu's Matrix space for news, updates, and support:");

					// GitHub Link
					ImGui::Bullet();
					ImGui::SameLine();
					ImGui::PushFont(YimMenu::Menu::Font::g_AwesomeFont); ImGui::TextUnformatted(ICON_FA_GITHUB); ImGui::PopFont();
					ImGui::SameLine(); ImGui::Text("GitHub:");
					ImGui::SameLine();
					ImGui::TextColored(ImVec4(0.2f, 0.6f, 1.0f, 1.0f), "https://github.com/Deadlineem/ChronixV2");
					if (ImGui::IsItemClicked())
					{
						ShellExecuteA(NULL, "open", "https://github.com/Deadlineem/ChronixV2", NULL, NULL, SW_SHOWNORMAL);
					}

					// Matrix Link
					ImGui::Bullet();
					ImGui::SameLine();
					ImGui::PushFont(YimMenu::Menu::Font::g_AwesomeFont); ImGui::TextUnformatted(ICON_FA_MATRIX); ImGui::PopFont();
					ImGui::SameLine(); ImGui::Text("Matrix:");
					ImGui::SameLine();
					ImGui::TextColored(ImVec4(0.2f, 0.6f, 1.0f, 1.0f), "https://matrix.to/#/#yimmenu:matrix.org");
					if (ImGui::IsItemClicked())
					{
						ShellExecuteA(NULL, "open", "https://matrix.to/#/#yimmenu:matrix.org", NULL, NULL, SW_SHOWNORMAL);
					}

					ImGui::Spacing();
					ImGui::TextWrapped("Matrix is a privacy-respecting alternative to Discord. Creating an account is quick and free.  Matrix (Element) is also available on iPhone/Android App store and in the web browser.");
					ImGui::PopTextWrapPos();
					ImGui::EndTabItem();
				}

				ImGui::EndTabBar();
			}

			ImGui::Spacing();
			ImGui::Separator();
			ImGui::Dummy(ImVec2(0.0f, 10.0f)); // Add 20px vertical spacing
			
			ImGui::Text("NOTE: Please review all tabs before pressing 'I Understand' as you will not see this popup again.");
			ImGui::Dummy(ImVec2(0.0f, 10.0f)); // Add 20px vertical spacing
			if (ImGui::Button("I Understand!"))
			{
				Commands::GetCommand<BoolCommand>("cheaterpool"_J)->SetState(tab == 1 ? false : true);
				_OnboardingComplete.SetState(true);
				GUI::SetOnboarding(false);
				ImGui::CloseCurrentPopup();
			}
			
			ImGui::EndPopup();
		}
	}
}
