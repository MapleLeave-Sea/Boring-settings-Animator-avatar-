#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

namespace cheat::feature
{

    class Modelchanger : public Feature
    {
    public:
        config::Field<config::Toggle<Hotkey>> f_Enabled;
        config::Field<Hotkey> f_Hotkey;

        config::Field<Hotkey> f_ApplyKey;
        config::Field<Hotkey> f_ResetKey;

        static Modelchanger& GetInstance();

        const FeatureGUIInfo& GetGUIInfo() const override;
        void DrawMain() override;

        virtual bool NeedStatusDraw() const override;
        void DrawStatus() override;

        void OnGameUpdate();
    private:
        Modelchanger();
    };
}