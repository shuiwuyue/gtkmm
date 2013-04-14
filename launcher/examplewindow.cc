#include "examplewindow.h"
#include <iostream>
#include <fstream>

ExampleWindow::ExampleWindow()
{
	set_title("Gtk::EntryCompletion");
	//set_decorated(false);
	add(m_Entry);

	Glib::RefPtr<Gtk::EntryCompletion> completion = 
		Gtk::EntryCompletion::create();
	m_Entry.set_completion(completion);

	Glib::RefPtr<Gtk::ListStore> refCompletionModel = 
		Gtk::ListStore::create(m_Columns);
	completion->set_model(refCompletionModel);
	{
		
	std::ifstream ifs("app", std::ifstream::in);
	
	int i = 1;
	
	while(ifs.good())
	{
		
		Gtk::TreeModel::Row row = *(refCompletionModel->append());
		row[m_Columns.m_col_id] = i;
		char ch[80];
		ifs.getline(ch,80);
		Glib::ustring str(ch);
		row[m_Columns.m_col_name] = str;
		i++;

	}
	}
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
	
