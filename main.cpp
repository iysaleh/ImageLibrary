#include <gtk/gtk.h>
#include <gtkmm.h>

int main(int argc, char* argv[])
{
	//GtkBuilder *builder;
	//GtkWidget *window;

	Gtk::Main kit(argc, argv);

	Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("ImageLibraryGUI.glade");

	Gtk::Window *window1 = 0;
	builder->get_widget("ImageLibraryGUI",window1);

	Gtk::Button *acceptTransformationButton = 0;
	builder->get_widget("AcceptTransformation",acceptTransformationButton);

	Gtk::Main::run(*window1);

	return 0;
}
