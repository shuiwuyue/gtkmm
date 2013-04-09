#include "helloworld.h"
#include <gtkmm/main.h>

int main (int argc, char *argv[])
{
	Gtk::Main kit(argc, argv);

	HelloWorld helloworld;

	Gtk::Main::run(helloworld);

	return 0;
}
