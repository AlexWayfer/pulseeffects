#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <giomm/settings.h>
#include <gtkmm/application.h>
#include <memory>
#include "presets_manager.hpp"
#include "pulse_manager.hpp"
#include "sink_input_effects.hpp"
#include "source_output_effects.hpp"

class Application : public Gtk::Application {
   public:
    Application();
    ~Application();

    static Glib::RefPtr<Application> create();
    Glib::RefPtr<Gio::Settings> settings;

    std::shared_ptr<PulseManager> pm;
    std::shared_ptr<SinkInputEffects> sie;
    std::shared_ptr<SourceOutputEffects> soe;
    std::shared_ptr<PresetsManager> presets_manager;

   protected:
    int on_command_line(
        const Glib::RefPtr<Gio::ApplicationCommandLine>& command_line) override;

    void on_startup() override;
    void on_activate() override;

   private:
    std::string log_tag = "application: ";

    bool running_as_service;

    void create_appmenu();
};

#endif
