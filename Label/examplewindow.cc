#include "examplewindow.h"

ExampleWindow::ExampleWindow()
	: m_Frame("This is a Frame title"),
	  m_Label("This is a Label Text.")
{
	set_title("Label");
	set_border_width(5);

	m_Frame.add(m_Label);
	add(m_Frame);

	show_all_children();
}

ExampleWindow::~ExampleWindow()
{
}
