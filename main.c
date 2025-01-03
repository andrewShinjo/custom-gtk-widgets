#include <gtk/gtk.h>
#include "./widgets/mb_button.h"

static void activate (GtkApplication* app, gpointer user_data)
{
  GtkWidget *window = gtk_application_window_new (app);
	GtkWidget *button = mb_button_new();

	g_object_set(button, "label", "My button", NULL);

  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 400, 400);
	gtk_window_set_child(GTK_WINDOW(window), button);
  gtk_window_present (GTK_WINDOW (window));
}

int main(int argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
