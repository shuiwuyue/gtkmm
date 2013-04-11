#ifndef GTKMM_EXAMPLE_BUTTONS_H
#define GTKMM_EXAMPLE_BUTTONS_H

#include <gtkmm/window.h>
#include <gtkmm/checkbutton.h>

class ExampleWindow : public Gtk::Window
{
	public:
		ExampleWindow();
		virtual ~ExampleWindow();

	protected:
		void on_button_clicked();
		Gtk::CheckButton m_button;
};

#endif
