#include "examplewindow.h"
#include <iostream>

ExampleWindow::ExampleWindow():
	m_Label("Press a or b to see a list of possible completions."),
	m_Button_Close("Close")
{
	set_title("Gtk::EntryCompletion");
	//set_decorated(false);

	add(m_VBox);
	m_VBox.pack_start(m_Entry, Gtk::PACK_SHRINK);
	m_VBox.pack_start(m_Label, Gtk::PACK_EXPAND_WIDGET);

	m_Button_Close.signal_clicked().connect( sigc::mem_fun(*this,
				&ExampleWindow::on_button_close) );
	m_VBox.pack_start(m_Button_Close, Gtk::PACK_SHRINK);
	m_Button_Close.set_can_default();
	m_Button_Close.grab_default();

	Glib::RefPtr<Gtk::EntryCompletion> completion = 
		Gtk::EntryCompletion::create();
	m_Entry.set_completion(completion);

	Glib::RefPtr<Gtk::ListStore> refCompletionModel = 
		Gtk::ListStore::create(m_Columns);
	completion->set_model(refCompletionModel);

	Gtk::TreeModel::Row row = *(refCompletionModel->append());
	row[m_Columns.m_col_id] = 1;
	row[m_Columns.m_col_name] = "Alan Zebedee";

	row = *(refCompletionModel->append());
	row[m_Columns.m_col_id] = 2;
	row[m_Columns.m_col_name] = "Adrian Boo";

	row = *(refCompletionModel->append());
	row[m_Columns.m_col_id] = 3;
	row[m_Columns.m_col_name] = "Bob McRoberts";

	row = *(refCompletionModel->append());
	row[m_Columns.m_col_id] = 4;
	row[m_Columns.m_col_name] = "Bob McBob";

	completion->set_text_column(m_Columns.m_col_name);

	m_CompletionActions[0] = "Use Wizard";
	m_CompletionActions[1] = "Browse for Filename";

	for(type_actions_map::iterator iter = m_CompletionActions.begin();
			iter != m_CompletionActions.end(); ++iter)
	{
		int position = iter->first;
		Glib::ustring title = iter->second;
		completion->insert_action_text(title, position);
	}

	completion->signal_action_activated().connect( sigc::mem_fun(*this,
				&ExampleWindow::on_completion_action_activated));
	show_all_children();
}

ExampleWindow::~ExampleWindow()
{
}

void ExampleWindow::on_button_close()
{
	hide();
}

bool ExampleWindow::on_completion_match(const Glib::ustring& key, const
		Gtk::TreeModel::const_iterator& iter)
{
	if(iter)
	{
		Gtk::TreeModel::Row row = *iter;
		Glib::ustring::size_type key_length = key.size();
		Glib::ustring filter_string = row[m_Columns.m_col_name];
		
		Glib::ustring filter_string_start = 
			filter_string.substr(0, key_length);
		if(key == filter_string_start)
			return true;
	}

	return false;
}

void ExampleWindow::on_completion_action_activated(int index)
{
	type_actions_map::iterator iter = m_CompletionActions.find(index);
	if(iter != m_CompletionActions.end())
	{
		Glib::ustring title = iter->second;
		std::cout << "Action selected: " << title << std::endl;
	}
}
	
