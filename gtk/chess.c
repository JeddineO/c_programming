#include <gtk/gtk.h>
#include "checkers.h"
int Game_Ended = 0;
#define TITLE_MOVE_ONE "Move: Player White"
#define TITLE_MOVE_TWO "Move: Player Black"
#define TITLE_TAKE_ONE "Take: Player White"
#define TITLE_TAKE_TWO "Take: Player Black"
#define TITLE_WON_ONE "Player White has won!"
#define TITLE_WON_TWO "Player Black has won!"

typedef enum
{
    OWNER_NONE,
    OWNER_WHITE,
    OWNER_BLACK,
} Owner;

typedef enum
{
    STATUS_NONE,
    STATUS_MOVE,
    STATUS_JUMP_AGAIN,
} Status;
typedef struct field
{

    GtkWidget *button;

    View *view;

    Owner owner;
    gboolean is_queen;
    gint col;
    gint row;
} Field;
struct field;

typedef struct view
{

    GtkWidget *grid;

    GtkWidget *hbar;

    struct field *field[8][8];
    struct field *last;

    Status status;
    gint round;
    gint pieces_one;
    gint pieces_two;
} View;

/*
static void load_style_context(void)
{

        GtkCssProvider *css_prov;
       // Création d'un nouvel objet GtkCssProvider
        css_prov = gtk_css_provider_new();
         // Chargement des données CSS à partir de la variable CSS_DATA dans le GtkCssProvider
        gtk_css_provider_load_from_data(css_prov, CSS_DATA, -1, NULL);
        // Ajout du GtkCssProvider au contexte de style de l'écran par défaut
        gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                                                  GTK_STYLE_PROVIDER(css_prov),
                                                  GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}
*/

/*

Explication ligne par ligne :

gint col, row; : Déclaration des variables locales col et
row de type gint (alias pour int).

col = field->col; et row = field->row; : Récupération des
coordonnées du champ à partir de la structure Field passée en paramètre.

Les tableaux statiques white_x, white_y, black_x et black_y
contiennent les coordonnées des pions blancs et noirs respectivement.
Les indices [3][4] indiquent les lignes et les colonnes correspondantes.

Les boucles for sont utilisées pour parcourir les tableaux
de coordonnées et vérifier si les coordonnées du champ correspondent
à celles d'un pion blanc ou noir. Si une correspondance est trouvée,
la fonction retourne le propriétaire correspondant
(OWNER_WHITE pour blanc ou OWNER_BLACK pour noir).

Si aucune correspondance n'est trouvée, la fonction retourne
OWNER_NONE, indiquant que le champ n'appartient à aucun propriétaire.

Cette fonction est utilisée pour déterminer le propriétaire
d'un champ (Field) en fonction de ses coordonnées (col et row).

*/

Owner fieldGetOwner(Field *field)
{
    gint col, row;
    gint i, k;

    // Récupération des coordonnées du champ

    col = field->col;
    row = field->row;
    // Tableaux statiques contenant les coordonnées des pions blancs et noirs

    static gint white_x[3][4] = {
        {0, 2, 4, 6},
        {1, 3, 5, 7},
        {0, 2, 4, 6},
    };

    static gint white_y[3][4] = {
        {7, 7, 7, 7},
        {6, 6, 6, 6},
        {5, 5, 5, 5},
    };

    static gint black_x[3][4] = {
        {1, 3, 5, 7},
        {0, 2, 4, 6},
        {1, 3, 5, 7},
    };

    static gint black_y[3][4] = {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {2, 2, 2, 2},
    };

    for (i = 0; i < 3; i++)
    {
        for (k = 0; k < 4; k++)
        {
            if (col == white_x[i][k] &&
                row == white_y[i][k])
                return OWNER_WHITE;

            if (col == black_x[i][k] &&
                row == black_y[i][k])
                return OWNER_BLACK;
        }
    }

    return OWNER_NONE;
}

static void field_init(Field *field)
{
    // Création d'un bouton GtkButton
    field->button = gtk_button_new();
    // Initialisation des autres membres de la structure Field
    field->view = NULL;
    field->owner = fieldGetOwner(field);
    field->is_queen = FALSE;

    // Ajout de style au bouton
    gtk_container_set_border_width(GTK_CONTAINER(field->button), 8);
    GtkStyleContext *context = gtk_widget_get_style_context(field->button);
    gtk_style_context_add_class(context, "field");
    // Ajout de classes de style en fonction du propriétaire du champ
    switch (field->owner)
    {
    case OWNER_NONE:
        break;
    case OWNER_BLACK:
        gtk_style_context_add_class(context, "black");
        break;
    case OWNER_WHITE:
        gtk_style_context_add_class(context, "white");
        break;
    }
}

/**
 * Accessors
 */
GtkWidget *field_get_button(Field *field)
{
    return field->button;
}

View *field_get_view(Field *field)
{
    return field->view;
}

void field_set_view(Field *field, View *view)
{
    field->view = view;
}

Owner field_get_owner(Field *field)
{
    return field->owner;
}

void field_set_owner(Field *field, Owner owner)
{
    field->owner = owner;

    GtkStyleContext *context;

    context = gtk_widget_get_style_context(field->button);

    switch (owner)
    {
    case OWNER_NONE:
        gtk_style_context_remove_class(context, "black");
        gtk_style_context_remove_class(context, "white");
        gtk_style_context_remove_class(context, "queen");
        break;
    case OWNER_BLACK:
        gtk_style_context_remove_class(context, "blackpre");
        gtk_style_context_add_class(context, "black");
        break;
    case OWNER_WHITE:
        gtk_style_context_remove_class(context, "whitepre");
        gtk_style_context_add_class(context, "white");
        break;
    }
}

gboolean field_get_is_queen(Field *field)
{
    return field->is_queen;
}

void field_set_preowner(Field *field,
                        Owner owner)
{
    GtkStyleContext *context;

    context = gtk_widget_get_style_context(field->button);

    switch (owner)
    {
    case OWNER_NONE:
        gtk_style_context_remove_class(context, "blackpre");
        gtk_style_context_remove_class(context, "whitepre");
        break;
    case OWNER_BLACK:
        gtk_style_context_add_class(context, "blackpre");
        break;
    case OWNER_WHITE:
        gtk_style_context_add_class(context, "whitepre");
        break;
    }
}

void field_set_is_queen(Field *field,
                        gboolean is_queen)
{
    field->is_queen = is_queen;
    if (is_queen)
    {
        GtkStyleContext *context = gtk_widget_get_style_context(field->button);
        gtk_style_context_add_class(context, "queen");
    }
}

gint field_get_col(Field *field)
{
    return field->col;
}

gint field_get_row(Field *field)
{
    return field->row;
}

Field *init_field_inPos(gint col,
                        gint row)
{
    Field *field;

    field = g_malloc(sizeof(Field));

    field->col = col;
    field->row = row;

    field_init(field);

    return field;
}

////////////////////////////////////////////////////
/////////////////////////////////////////////////////
////////////////////////////////////////////////

static void view_set_status(View *view, Status status)
{
    view->status = status;

    GtkHeaderBar *hbar;
    const gchar *title;

    switch (status)
    {
    case STATUS_NONE:
        title = (view->round % 2 == 0) ? TITLE_WON_ONE : TITLE_WON_TWO;
        break;
    case STATUS_MOVE:
        title = (view->round % 2 == 0) ? TITLE_MOVE_ONE : TITLE_MOVE_TWO;
        break;
    case STATUS_JUMP_AGAIN:
        title = (view->round % 2 == 0) ? TITLE_TAKE_ONE : TITLE_TAKE_TWO;
        break;
    }

    gtk_header_bar_set_title(GTK_HEADER_BAR(view->hbar), title);
}

static void view_add_fields(View *view, Field *field[8][8])
{
    gint i, k;
    GtkGrid *grid;
    GtkWidget *button;

    grid = GTK_GRID(view->grid);

    for (i = 0; i < 8; i++)
    {
        for (k = 0; k < 8; k++)
        {
            field[i][k] = init_field_inPos(i, k);
            button = field_get_button(field[i][k]);
            field_set_view(field[i][k], view);
            gtk_grid_attach(grid, button, i, k, 1, 1);
            /*g_signal_connect(button, "clicked", G_CALLBACK(chks_field_clicked), field[i][k]);
            g_signal_connect(button, "enter",G_CALLBACK(chks_field_enter),field[i][k]);
            g_signal_connect(button, "leave",G_CALLBACK(chks_field_leave),field[i][k]);*/
        }
    }
}

static void init_view(View *view)
{
    view->grid = gtk_grid_new();
    view->hbar = NULL;
    view->last = NULL;
    view->status = STATUS_MOVE;
    view->round = 0;
    view->pieces_one = 12;
    view->pieces_two = 12;

    /* Grid */
    GtkStyleContext *context = gtk_widget_get_style_context(view->grid);
    gtk_style_context_add_class(context, "tableau");
    gtk_grid_set_column_homogeneous(GTK_GRID(view->grid), TRUE);
    gtk_grid_set_row_homogeneous(GTK_GRID(view->grid), TRUE);
    view_add_fields(view, view->field);
}

/**
 * Accessors
 */
void reset_view(View *view, gint difficulty, gint mode)
{
    gint i, k;
    Owner owner_init;
    Game_Ended = 0;
    for (i = 0; i < 8; i++)
    {
        for (k = 0; k < 8; k++)
        {
            owner_init = fieldGetOwner(view->field[i][k]);
            field_set_owner(view->field[i][k], OWNER_NONE);
            field_set_owner(view->field[i][k], owner_init);
            field_set_is_queen(view->field[i][k], FALSE);
        }
    }

    view->last = NULL;
    view->round = 0;
    view->pieces_one = 12;
    view->pieces_two = 12;
    / GameSettings *settings = (GameSettings)malloc(sizeof(GameSettings));
    settings->view = view;
    settings->difficulty = difficulty;
    settings->mode = mode;
    * /
        view_set_status(view, STATUS_MOVE);
    // g_timeout_add(2000, AIturn, settings);
}

GtkWidget *view_get_grid(View *view)
{
    return view->grid;
}

void view_set_header_bar(View *view,
                         GtkWidget *hbar)
{
    view->hbar = hbar;
}

View *view_new(void)
{
    View *view;

    view = g_malloc(sizeof(View));

    init_view(view);

    return view;
}

gint main(gint argc, gchar *argv[])
{
    gtk_init(&argc, &argv);

    load_style_context();

    GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *hbar = gtk_header_bar_new();
    GtkWidget *btn_new = gtk_button_new_with_label("New Game");
    GtkWidget *difficulty = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX(difficulty), "Easy");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX(difficulty), "Medium");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX(difficulty), "Hard");
    gtk_combo_box_set_active(GTK_COMBO_BOX(difficulty), 0);
    GtkWidget *mode = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX(mode), "Human vs Human");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX(mode), "Ai vs Human");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX(mode), "Ai vs Ai");
    gtk_combo_box_set_active(GTK_COMBO_BOX(mode), 0);

    gtk_style_context_add_class(gtk_widget_get_style_context(win), "fenetre");
    gtk_window_set_default_size(GTK_WINDOW(win), 800, 800);
    gtk_window_set_titlebar(GTK_WINDOW(win), hbar);
    gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(win), FALSE);

    gtk_header_bar_set_title(GTK_HEADER_BAR(hbar), "Checkers");
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(hbar), TRUE);
    gtk_header_bar_pack_end(GTK_HEADER_BAR(hbar), btn_new);
    gtk_header_bar_pack_end(GTK_HEADER_BAR(hbar), difficulty);
    gtk_header_bar_pack_end(GTK_HEADER_BAR(hbar), mode);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    View *view = view_new();
    view_set_header_bar(view, hbar);
    reset_view(view, 0, 0);

    gtk_box_pack_start(GTK_BOX(box), view->grid, TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(win), box);

    gtk_widget_show_all(win);

    gtk_main();
}