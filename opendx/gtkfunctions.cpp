/*
    SDLDX - A wrapper, which provides DirectX functionality on top of the SDL library
    Copyright (C) 2004	Rene Rössler <rene@freshx.de>
						
						
    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA


    SDLDX is a wrapper, which provides DirectX functionality on top of the 
    Simple Direct Media Layer (SDL) library. Using SDLDX enables you to easily 
    port DirectX applications (for example games) to any platform supported 
    by the SDL library.
	
*/

/*	gtkfunctions.cpp

	dialogboxes for the winapi, build with gtk
*/

#include <gtk/gtk.h>

int MessageBox(int a, char *dialog_text, char *dialog_title, int b)
{
    /* our gtk widgets:*/
    GtkWidget *window;
    GtkWidget *table;
    GtkWidget *ok_button;
    GtkWidget *text;
   
    /* create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    
    /* set the window title */
    gtk_window_set_title (GTK_WINDOW (window), dialog_title);
    
    /* wets the border width of the window */
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    
    /* create a 2x1 table */
    table = gtk_table_new (2, 1, TRUE);

    /* add the box to the gtk container */
    gtk_container_add (GTK_CONTAINER (window), table);
    
    /* create a text label */
    text = gtk_label_new (dialog_text);
    
    /* add the label to the table on row 0-1 and colum 0-1 */
    gtk_table_attach_defaults (GTK_TABLE (table), text, 0, 1, 0, 1);
    
    /* create a ok button */
    ok_button = gtk_button_new_with_label ("OK");
    
    /* close the window when the button is clicked */
    g_signal_connect_swapped (G_OBJECT (ok_button), "clicked",
			      G_CALLBACK (gtk_main_quit),
                              G_OBJECT (window));

    /* and when the windowmanager wants to close the window: */
    g_signal_connect (G_OBJECT (window), "destroy",
			      G_CALLBACK (gtk_main_quit), NULL);
    
    /* add the button to the table on row 1-2 and colum 0-1 */
    gtk_table_attach_defaults (GTK_TABLE (table), ok_button, 0, 1, 1, 2);
    
    /* display the invisible box ;) */
    gtk_widget_show (table);
    
    /* display the text, */
    gtk_widget_show (text);

    /* the button */
    gtk_widget_show (ok_button);
    
    /* ...and the window */
    gtk_widget_show (window);
    
    /* wait for an event */
    gtk_main ();

    return 0;
}
