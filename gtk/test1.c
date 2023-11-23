#include <gtk/gtk.h>
#include <string.h>

typedef struct
{
    GtkWidget *wind;
    gchar *title; // titre de la fenêtre
    gint posX;
    gint posY;
    gint rouge;
    gint vert;
    gint bleu;
    gint Hauteur;          // Hauteur
    gint Largeur;          // Largeur
    gboolean isResisable;  // si on peut la redimensionner
    gchar *iconfile;       // l'icône
    gboolean isFullscreen; // si elle est en mode fullscreen
    gboolean isDecorated;  // si elle a des décorations
    gboolean isDeletable;  // s’il est possible de la fermer
} MaFenetre;

MaFenetre *initF(MaFenetre *wind)
{
    wind = (MaFenetre *)malloc(sizeof(MaFenetre));
    return wind;
}

MaFenetre *Init_default_window_prop(MaFenetre *wind)
{
    wind = initF(wind);
    wind->iconfile = (char *)"icon.png";
    // strcpy(wind->iconfile,"icon.png");
    wind->isResisable = TRUE; // il est possible de changer la
    // taille de la fenêtre.
    wind->isDecorated = TRUE;   // la fenêtre est décorée.
    wind->isFullscreen = FALSE; // la fenêtre n'occupe pas toute
    // l'écran.
    wind->isDeletable = TRUE;

    wind->Largeur = 450;
    wind->Hauteur = 250;
    wind->title = (char *)"default title";
    // strcpy(wind->title,"default title");
    wind->posX = 0;
    wind->posY = 0;
    wind->rouge = 65535;
    wind->bleu = 65535;
    wind->vert = 65535;

    return wind;
} // fin de la fonction Init_default_window_prop.

void fenetre(MaFenetre *wind)
{
    wind->wind = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(wind->wind), wind->title);

    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(window), scrolled_window);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window),
                                   GTK_POLICY_ALWAYS, GTK_POLICY_ALWAYS);

    gtk_window_set_icon_from_file(wind->wind, wind->iconfile, NULL);
    gtk_widget_modify_bg(wind->wind, GTK_STATE_NORMAL, &(GdkColor){1, wind->rouge, wind->vert, wind->bleu});

    if (wind->isFullscreen)
        gtk_window_fullscreen(wind->wind);

    if (!wind->isDecorated)
        gtk_window_set_decorated(wind->wind, FALSE);
    if (!wind->isDeletable)
        gtk_window_set_deletable(wind->wind, FALSE);
    gtk_window_set_resizable(wind->wind, wind->isResisable);
    gtk_widget_set_size_request(wind->wind, wind->Largeur, wind->Hauteur);

    gtk_window_move(wind->wind, wind->posX, wind->posY);
}
int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    MaFenetre *F;
    F = Init_default_window_prop(F);
    fenetre(F);
    printf("a");
    gtk_widget_show_all(F->wind);
    printf("a");
    gtk_main();
    return 0;
}