#include <gtk/gtk.h>



int main (int argc,char *argv[])
{
    GtkWidget *window, *table, *label, *label2,*label3,*label4,*label5, *nom,*prenom,*sexe,*email ,*button,*GroupB1,*box;
    gboolean icon;

    gtk_init (&argc, &argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "Formulaire");
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    icon= gtk_window_set_icon_from_file (window,"C:\\Users\\HP\\Desktop\\x.png",NULL);
    gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &(GdkColor){ 65535, 65535 , 65535 });

    gtk_widget_set_size_request (window, 340, 200);
    table = gtk_table_new (5, 2, TRUE);



    label = gtk_label_new ("Entrez vos informations ...");
    label2 = gtk_label_new ("Nom : ");
    label3 = gtk_label_new ("Prenom : ");
    label4 = gtk_label_new ("Sexe : ");
    label5 = gtk_label_new ("E-mail : ");
    button = gtk_button_new_with_label("Envoyer");


    nom = gtk_entry_new ();
    prenom = gtk_entry_new ();
    sexe = gtk_entry_new ();
    email = gtk_entry_new ();


    gtk_table_attach (GTK_TABLE (table), label, 0, 2, 0, 1,GTK_EXPAND, GTK_SHRINK, 0, 0);

    gtk_table_attach (GTK_TABLE (table), label2, 0, 1, 1, 2,GTK_EXPAND, GTK_SHRINK, 0, 0);
    gtk_table_attach (GTK_TABLE (table), nom, 1, 2, 1, 2,GTK_EXPAND, GTK_SHRINK, 0, 0);

    gtk_table_attach (GTK_TABLE (table), label3, 0, 1, 2, 3,GTK_EXPAND, GTK_SHRINK, 0, 0);
    gtk_table_attach (GTK_TABLE (table), prenom, 1, 2, 2, 3,GTK_EXPAND, GTK_SHRINK, 0, 0);

    gtk_table_attach (GTK_TABLE (table), label4, 0, 1, 3, 4,GTK_EXPAND, GTK_SHRINK, 0, 0);
    gtk_table_attach (GTK_TABLE (table), sexe, 1, 2, 3, 4,GTK_EXPAND, GTK_SHRINK, 0, 0);

    gtk_table_attach (GTK_TABLE (table), label5, 0, 1, 4, 5,GTK_EXPAND, GTK_SHRINK, 0, 0);
    gtk_table_attach (GTK_TABLE (table), email, 1, 2, 4, 5,GTK_EXPAND, GTK_SHRINK, 0, 0);


    gtk_table_attach (GTK_TABLE (table),  button, 0, 2, 5, 6,GTK_EXPAND, GTK_SHRINK, 0, 0);

    gtk_table_set_row_spacings (GTK_TABLE (table), 15);
    gtk_table_set_col_spacings (GTK_TABLE (table), 5);
    gtk_container_add (GTK_CONTAINER (window), table);
    gtk_widget_show_all (window);
    gtk_main ();
    return 0;
}
