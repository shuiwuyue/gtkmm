#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>

class ExampleWindow : public Gtk::Window
{
public:
	ExampleWindow();
	virtual ~ExampleWindow();

protected:
	void on_button_close();
	void on_completion_action_activated(int index);
	bool on_completion_match(const Glib::ustring& key, const
			Gtk::TreeModel::const_iterator& iter);
	class ModelColumns : public Gtk::TreeModel::ColumnRecord
	{
	public:
		ModelColumns()
		{
			add(m_col_id);
			add(m_col_name);
		}

		Gtk::TreeModelColumn<unsigned int> m_col_id;
		Gtk::TreeModelColumn<Glib::ustring> m_col_name;
	};

	ModelColumns m_Columns;

	typedef std::map<int, Glib::ustring> type_actions_map;
	type_actions_map m_CompletionActions;

	Gtk::HBox m_HBox;
	Gtk::VBox m_VBox;
	Gtk::Entry m_Entry;
	Gtk::Label m_Label;
	Gtk::Button m_Button_Close;
};

#endif
