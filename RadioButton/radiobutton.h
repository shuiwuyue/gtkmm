#ifndef GTKMM_EXAMPLE_BUTTON_H
#define GTKMM_EXAMPLE_BUTTON_H

#include <gtkmm/window.h>
#include <gtkmm/radiobutton.h>
#include <gtkmm/box.h>
#include <gtkmm/separator.h>

class RadioButtons : public Gtk::Window
{
	public:
		RadioButtons();
		virtual ~RadioButtons();

	protected:
		void on_button_clicked();

		Gtk::VBox m_Box_Top, m_Box1, m_Box2;
		Gtk::HSeparator m_Separator;
		Gtk::Button m_Button_Close;
		Gtk::RadioButton m_rb1, m_rb2, m_rb3;
};

#endif
