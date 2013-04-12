#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H
#include <gtkmm.h>

class ExampleWindow : public Gtk::Window
{
public:
	ExampleWindow();
	virtual ~ExampleWindow();

protected:
	Gtk::Frame m_Frame;
	Gtk::Label m_Label;
};

#endif
