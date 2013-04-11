#include "radiobutton.h"

RadioButtons::RadioButtons()
	: m_rb1("button1"),
	  m_rb2("button2"),
	  m_rb3("button3"),
	  m_Box1(false, 10),
          m_Box2(false, 10),
	  m_Button_Close("Close")
{
	set_title("radiobutton example");
	set_border_width(0);

	Gtk::RadioButton::Group group = m_rb1.get_group();
	m_rb2.set_group(group);
	m_rb3.set_group(group);

	add(m_Box_Top);

	m_Box_Top.pack_start(m_Box1);
	m_Box_Top.pack_start(m_Separator);
	m_Box_Top.pack_start(m_Box2);

	m_Box2.set_border_width(10);
	m_Box1.set_border_width(10);

	m_Box1.pack_start(m_rb1);
	m_Box1.pack_start(m_rb2);
	m_Box1.pack_start(m_rb3);

	m_rb2.set_active();


	m_Box2.pack_start(m_Button_Close);

	m_Button_Close.set_can_default();
	m_Button_Close.grab_default();

	m_Button_Close.signal_clicked().connect(sigc::mem_fun(*this,
				&RadioButtons::on_button_clicked) );

	show_all_children();
}

RadioButtons::~RadioButtons()
{
}

void RadioButtons::on_button_clicked()
{
	hide();
}
