#include "radiobutton.h"
#include <gtkmm/main.h>

int main(int argc, char *argv[])
{
	Gtk::Main kit(argc, argv);

	RadioButtons window;

	Gtk::Main::run(window);

	return 0;
}
