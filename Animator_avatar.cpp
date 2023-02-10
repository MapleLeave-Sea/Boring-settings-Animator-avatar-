#include "pch-il2cpp.h"
#include<cheat/world/ModelChanger.h>

#include <helpers.h>
#include <cheat/events.h>
#include <cheat/game/EntityManager.h>
#include <fmt/ranges.h>
#include <CommCtrl.h>
using namespace app;

namespace cheat::feature
{
    Modelchanger::Modelchanger() : Feature(),
        NF(f_Enabled, "Modelchanger Enabled", "Modelchanger", false),
        NF(f_Hotkey, "Modelchanger HotKey", "Modelchanger", Hotkey(VK_CAPITAL)),
        NF(f_ApplyKey, "cut", "Visuals::AnimationChanger", Hotkey('I')),
        NF(f_ResetKey, "paste", "Visuals::AnimationChanger", Hotkey('Y'))
    {

        events::GameUpdateEvent += MY_METHOD_HANDLER(Modelchanger::OnGameUpdate);
    }

    const FeatureGUIInfo& Modelchanger::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "Modelchanger", "World", true };
        return info;
    }

    void Modelchanger::DrawMain()
    {
        ConfigWidget("Modelchanger Enabled", f_Enabled, "Model game with hotkey");
        if (f_Enabled)
        {
            ConfigWidget("Cut Key", f_ApplyKey, true);
            ConfigWidget("Paste Key", f_ResetKey, true);

        }

    }

    bool Modelchanger::NeedStatusDraw() const
    {
        return f_Enabled;
    }

    void Modelchanger::DrawStatus()
    {
        ImGui::Text("Modelchanger");
    }

    Modelchanger& Modelchanger::GetInstance()
    {
        static Modelchanger instance;
        return instance;
    }






    Avatar* value2;

    void Modelchanger::OnGameUpdate()
    {
        if (f_Enabled){

            auto& manager = game::EntityManager::instance();
            auto avatar = manager.avatar();

            if (f_ApplyKey.value().IsPressed())
            {
                value2 = app::Animator_get_avatar(avatar->animator(), nullptr);
               // app::Animator_set_avatar(avatar->animator(), NULL, nullptr);
                LOG_DEBUG("cut³É¹¦ÁËÄó£¡");
            }
            if (f_ResetKey.value().IsPressed())

                app::Animator_set_avatar(avatar->animator(), value2, nullptr);
        }
    }
}
