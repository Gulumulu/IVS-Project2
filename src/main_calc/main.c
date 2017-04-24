#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include "calculator.h"
#include "callbacks.h"



int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;
 
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade_calc/calculator_gtk.glade", NULL);
 
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
    gtk_builder_connect_signals(builder, NULL);
    

    widg_2 = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "textview2"));
    widg_1 = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "textview1"));

    gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2), "", -1);
 
    g_object_unref(G_OBJECT(builder));
 
    gtk_widget_show(window);
                
    gtk_main();
 
    return 0;
}



