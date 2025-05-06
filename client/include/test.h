#include <gtk/gtk.h>

static void on_button_clicked(GtkWidget *widget, gpointer data) {
    g_print("Bouton cliqué !\n");
}

static void activate(GtkApplication *app, gpointer user_data) {
    // Créer la fenêtre principale
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Test GTK4");
    gtk_window_set_default_size(GTK_WINDOW(window), 1200, 900);

    // Créer un bouton
    GtkWidget *button = gtk_button_new_with_label("Cliquez-moi");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);

    // Ajouter le bouton à la fenêtre (méthode GTK4)
    gtk_window_set_child(GTK_WINDOW(window), button);
    
    // Remplacer gtk_widget_show() par:
    gtk_window_present(GTK_WINDOW(window));  // Nouvelle méthode recommandée
}

int main(int argc, char **argv) {
    GtkApplication *app = gtk_application_new("com.example.gtk4-test", 
                                             G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    
    return status;
}


// fichier .c en src et fichier h en include