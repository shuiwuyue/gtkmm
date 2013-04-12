#include "examplewindow.h"
#include <gtkmm/main.h>

int main(int argc, char *argv[])
{
	Gtk::Main kit(argc, argv);
	ExampleWindow examplewindow;
	Gtk::Main::run(examplewindow);

	return 0;
}
