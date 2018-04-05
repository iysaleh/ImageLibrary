#include <gtk/gtk.h>
#include <gtkmm.h>
#include <gio/gio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <sigc++/sigc++.h>
#include <png.h>

#include "imlib.h"
//API Reference:
//https://developer.gnome.org/gtkmm-tutorial/stable/index.html.en
//https://developer.gnome.org/gtkmm/stable/classGtk_1_1Image.html

//Global Variables
Gtk::Image* left_image = 0;
Gtk::Image* right_image = 0;
Glib::RefPtr<Gdk::Pixbuf> left_image_pix;
Glib::RefPtr<Gdk::Pixbuf> right_image_pix;

void accept_transformation_clicked()
{
	std::cout << "Button Clicked!" << std::endl;
}

void on_quit_clicked()
{
	exit(0);
}

void on_draw_left_image()
{
	
}

void on_draw_right_image()
{
	
}

void on_open_clicked()
{
	Gtk::FileChooserDialog dialog("Please choose a file", Gtk::FILE_CHOOSER_ACTION_OPEN);
	dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
	dialog.add_button("_Open", Gtk::RESPONSE_OK);
	
	//Show the dialog and wait for a user response:
	int result = dialog.run();
	
	//Handle the response:
	switch(result)
	{
		case(Gtk::RESPONSE_OK):
		{
			//Notice that this is a std::string, not a Glib::ustring.
			std::string filename = dialog.get_filename();
			std::cout << filename << std::endl;
			left_image_pix = Gdk::Pixbuf::create_from_file(filename);
			right_image_pix = Gdk::Pixbuf::create_from_file(filename);
			left_image->set(left_image_pix);
			right_image->set(right_image_pix);
			
			//std::cout << *left_image_pix << std::endl;
			//for (int row=0; r < sizeof(left_image_pix); 
			//left_image->gtk_image_set_from_file(filename);
			//right_image->gtk_image_set_from_file(filename);
			break;
		}
		case(Gtk::RESPONSE_CANCEL):
		{
			break;
		}
		default:
		{
			break;
		}
	}
}

int main(int argc, char* argv[])
{
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc,argv,"org.gtkmm.ImageLibraryGUI");
	Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("ImageLibraryGUI.glade");

	Gtk::Window* window = 0;
	builder->get_widget("ImageLibraryGUI",window);
	
	//Set Image widgets
	builder->get_widget("LeftImage",left_image);
	builder->get_widget("RightImage",right_image);
	
	Gtk::MenuItem* open_menu;
	builder->get_widget("OpenMenu",open_menu);
	open_menu->signal_activate().connect(sigc::ptr_fun(on_open_clicked));
	
	Gtk::MenuItem* quit_menu;
	builder->get_widget("QuitMenu",quit_menu);
	quit_menu->signal_activate().connect(sigc::ptr_fun(on_quit_clicked));

	Gtk::Button* accept_transformation_button = 0;
	builder->get_widget("AcceptTransformation",accept_transformation_button);

	accept_transformation_button->signal_clicked().connect(sigc::ptr_fun(accept_transformation_clicked));

	//app->add_window(*window);

	app->run(*window);

	//Gtk::Application::run(*window);
	return 0;
}
