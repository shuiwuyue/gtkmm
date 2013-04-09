#include "buttons.h"
#include <gtkmm/main.h>

int main(int argc, char *argv[])
{
	Gtk::Main kit(argc, argv);
	Buttons buttons;
	Gtk::Main::run(buttons);

	return 0;
}
