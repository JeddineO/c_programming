#include <gtk/gtk.h>
#include <libxml/parser.h>
#include <string.h>

/*****!!!!!!!!!!!!les Bouttons Radios ************************/
typedef struct
{
    GtkWidget *button; // le widget du radio bouton
    char label[20];    // le label du radio bouton
    gboolean active;   // l'état actif ou inactif du radio bouton
    gint x, y;         // la position du radio bouton dans la fenêtre
} RadioButton;

RadioButton *init_radio_button(RadioButton *button)
{
    button = (RadioButton *)malloc(sizeof(RadioButton));
    button->button = NULL;
    strcpy(button->label, "");
    button->active = FALSE;
    button->x = 0;
    button->y = 0;
    return button;
}
// layout:Dans la fonction create_radio_button de votre code,
// l'argument layout est une variable qui représente le conteneur dans lequel le bouton
// radio sera ajouté.
void create_radio_button(RadioButton *button, GtkWidget *group)
{
    button->button = gtk_radio_button_new_with_label_from_widget(group, button->label);
    gtk_widget_set_sensitive(button->button, TRUE);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(button->button), button->active);
}

RadioButton *parse_radio_button(xmlNode *node, RadioButton *button)
{
    button = init_radio_button(button);
    for (xmlAttr *attr = node->properties; attr != NULL; attr = attr->next)
    {
        if (strcmp((char *)attr->name, "label") == 0)
        {
            strcpy(button->label, (char *)attr->children->content);
        }
        else if (strcmp((char *)attr->name, "x") == 0)
        {
            button->x = atoi((char *)attr->children->content);
        }
        else if (strcmp((char *)attr->name, "y") == 0)
        {
            button->y = atoi((char *)attr->children->content);
        }
        else if (strcmp((char *)attr->name, "active") == 0)
        {
            if (strcmp((char *)attr->children->content, "yes") == 0)
                button->active = TRUE;
            if (strcmp((char *)attr->children->content, "no") == 0)
                button->active = FALSE;
        }
    }
    return button;
}

/************Check Button********************/
typedef struct
{
    GtkWidget *button; // le widget du check bouton
    char label[20];    // le label du check bouton
    gboolean active;   // l'état actif ou inactif du check bouton
    gint x;
    gint y; // la position du check bouton dans la fenêtre
} CheckButton;

CheckButton *init_check_button(CheckButton *check_button)
{
    check_button = (CheckButton *)malloc(sizeof(CheckButton));
    check_button->button = NULL;
    memset(check_button->label, 0, sizeof(check_button->label));
    check_button->active = FALSE;
    check_button->x = NULL;
    check_button->y = NULL;
    return check_button;
}
void create_check_button(CheckButton *cb)
{
    cb->button = gtk_check_button_new_with_label(cb->label);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cb->button), cb->active);
    gtk_widget_set_size_request(cb->button, cb->x, cb->y);
    gtk_widget_set_halign(cb->button, GTK_ALIGN_START);
    gtk_widget_set_valign(cb->button, GTK_ALIGN_START);
}

CheckButton *parse_check_button(xmlNode *node, CheckButton *check_button)
{
    check_button = init_check_button(check_button);
    for (xmlAttr *attr = node->properties; attr != NULL; attr = attr->next)
    {
        if (strcmp((char *)attr->name, "label") == 0)
        {
            strcpy(check_button->label, (char *)attr->children->content);
        }
        else if (strcmp((char *)attr->name, "x") == 0)
        {
            check_button->x = atoi((char *)attr->children->content);
        }
        else if (strcmp((char *)attr->name, "y") == 0)
        {
            check_button->y = atoi((char *)attr->children->content);
        }
        else if (strcmp((char *)attr->name, "active") == 0)
        {
            if (strcmp((char *)attr->children->content, "yes") == 0)
                check_button->active = TRUE;
            if (strcmp((char *)attr->children->content, "no") == 0)
                check_button->active = FALSE;
        }
    }
    return check_button;
}

/**************Les Bouttons SIMPLES************/
/* La structure des données pour un boutton simple */
typedef struct prButton
{
    GtkWidget *button; // l'objet button
    gchar label[20];   // label du button
    gchar *stock_icon; // button du stock
    gchar *image;
    gint x;
    gint y; // position du button
} prSimpleBut;

prSimpleBut *init_button(prSimpleBut *button)
{
    button = (prSimpleBut *)malloc(sizeof(prSimpleBut));
    button->button = NULL;
    memset(button->label, 0, sizeof(button->label));
    button->stock_icon = NULL;
    button->image = NULL;
    button->x = NULL;
    button->y = NULL;
    return button;
}

/*
Entrées:La fonction prend en paramètre un pointeur vers un nœud XML représentant le bouton
Sorties:Elle renvoie une structure prSimpleBut remplie avec les informations du nœud
Rôle: Elle parcourt les attributs du nœud et affecte les valeurs correspondantes dans la structure.
Si les attributs "x" et "y" sont présents, la fonction crée une structure prPos pour stocker les
positions x et y du bouton.
*/
prSimpleBut *parse_button(xmlNode *node, prSimpleBut *button)
{

    button = init_button(button);
    for (xmlAttr *attr = node->properties; attr != NULL; attr = attr->next)
    {
        if (strcmp((char *)attr->name, "label") == 0)
        {
            strcpy(button->label, (char *)attr->children->content);
        }
        else if (xmlGetProp(node, (xmlChar *)"image") != NULL)
        {
            button->image = (char *)xmlGetProp(node, (xmlChar *)"image");
        }
        else if (strcmp((char *)attr->name, "x") == 0)
        {
            button->x = atoi((char *)attr->children->content);
        }
        else if (strcmp((char *)attr->name, "y") == 0)
        {
            button->y = atoi((char *)attr->children->content);
        }
    }

    return button;
}
/*
Entrées:
Sorties:
Rôle:cette fonction crée le bouton en utilisant soit un label, soit un bouton du stock, soit une image,
en fonction des champs de la structure prSimpleBut. Elle configure également différentes propriétés du
bouton en fonction des champs de la structure, tels que le nom, la sensibilité,
la taille, etc. Enfin, elle ajoute le bouton au conteneur spécifié dans la structure prSimpleBut.
*/
void create_button(prSimpleBut *button)
{
    if (button->image != NULL)
    { // création avec une image
        GtkWidget *image = gtk_image_new_from_file(button->image);
        button->button = gtk_button_new();
        gtk_container_add(GTK_CONTAINER(button->button), image);
        gtk_button_set_image_position(GTK_BUTTON(button->button), GTK_POS_TOP);
        gtk_button_set_always_show_image(GTK_BUTTON(button->button), TRUE);
    }
    else
    { // création avec un label
        button->button = gtk_button_new_with_label(button->label);
        gtk_button_set_label(GTK_BUTTON(button->button), button->label);
        gtk_button_set_use_underline(GTK_BUTTON(button->button), TRUE);
    }
    // configuration des propriétés du bouton
    gtk_widget_set_sensitive(button->button, TRUE);
    gtk_button_set_focus_on_click(GTK_BUTTON(button->button), TRUE);
    gtk_widget_set_size_request(button->button, button->x, button->y);
}

typedef struct
{
    GtkWidget *box;
    gchar *orient;
    gint space;
    gint x;
    gint y;
} Box;

Box *initB(Box *box)
{
    box = (Box *)malloc(sizeof(Box));
    return box;
}

Box *initDefaultbox(Box *box)
{

    box = initB(box);
    box->orient = (char *)"vertical";
    box->space = 0;
    box->x = 0;
    box->y = 0;
    return box;
}

void BoxC(Box *box)
{
    if (strcmp(box->orient, "vertical") == 0)
        box->box = gtk_box_new(GTK_ORIENTATION_VERTICAL, box->space);
    else if (strcmp(box->orient, "horizontal") == 0)
        box->box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, box->space);
    gtk_widget_set_size_request(box->box, box->x, box->y);
}

Box *ReadBox(xmlNodePtr node, Box *box)
{
    if (xmlGetProp(node, (xmlChar *)"orientation") != NULL)
    {
        box->orient = (char *)xmlGetProp(node, (xmlChar *)"orientation");
    }
    if (xmlGetProp(node, (xmlChar *)"spacing") != NULL)
    {
        box->space = atoi((char *)xmlGetProp(node, (xmlChar *)"spacing"));
    }
    if (xmlGetProp(node, (xmlChar *)"x") != NULL)
    {
        box->x = atoi((char *)xmlGetProp(node, (xmlChar *)"x"));
    }
    if (xmlGetProp(node, (xmlChar *)"y") != NULL)
    {
        box->y = atoi((char *)xmlGetProp(node, (xmlChar *)"y"));
    }

    return box;
}

typedef struct
{
    GtkWidget *entry;         // widget d'une entrée.
    gint x;                   // la longueur d'entrée.
    gint y;                   // largeur.
    gboolean visible;         // le texte est visible ou pas.
    gchar invisible_car;      // le caractère d'un texte invisible.
    gboolean editable;        // on peut saisir par clavier.
    const gchar *text_to_set; // le texte à saisir.
} Entry;

Entry *init_default_entry(Entry *e)
{
    e = (Entry *)malloc(sizeof(Entry));
    e->visible = TRUE;
    e->text_to_set = strdup("");
    e->invisible_car = '*';
    e->x = 0;
    e->y = 0;
    e->editable = TRUE;
    return e;
}

void CreateEntry(Entry *e)
{
    e->entry = gtk_entry_new();
    gtk_widget_set_size_request(e->entry, e->x, e->y);
    gtk_entry_set_visibility(GTK_ENTRY(e->entry), e->visible);
    if (!e->visible)
        gtk_entry_set_invisible_char(GTK_ENTRY(e->entry), e->invisible_car);
    if (e->text_to_set)
        gtk_entry_set_text(GTK_ENTRY(e->entry), e->text_to_set);
    gtk_editable_set_editable(GTK_EDITABLE(e->entry), e->editable);
}

Entry *ReadEntry(xmlNodePtr node, Entry *entry)
{
    if (xmlGetProp(node, (xmlChar *)"editable") != NULL)
    {
        if (strcmp((char *)xmlGetProp(node, (xmlChar *)"editable"), "TRUE") == 0)
            entry->editable = TRUE;
        if (strcmp((char *)xmlGetProp(node, (xmlChar *)"editable"), "FALSE") == 0)
            entry->editable = FALSE;
    }
    if (xmlGetProp(node, (xmlChar *)"visible") != NULL)
    {
        if (strcmp((char *)xmlGetProp(node, (xmlChar *)"visible"), "TRUE") == 0)
            entry->visible = TRUE;
        if (strcmp((char *)xmlGetProp(node, (xmlChar *)"visible"), "FALSE") == 0)
            entry->visible = FALSE;
    }
    if (xmlGetProp(node, (xmlChar *)"x") != NULL)
    {
        entry->x = atoi((char *)xmlGetProp(node, (xmlChar *)"x"));
    }
    if (xmlGetProp(node, (xmlChar *)"y") != NULL)
    {
        entry->y = atoi((char *)xmlGetProp(node, (xmlChar *)"y"));
    }
    if (xmlGetProp(node, (xmlChar *)"text") != NULL)
    {
        entry->text_to_set = (char *)xmlGetProp(node, (xmlChar *)"text");
    }
    if (xmlGetProp(node, (xmlChar *)"invisiblechar") != NULL)
    {
        gchar *tmp = (char *)xmlGetProp(node, (xmlChar *)"invisiblechar");
        entry->invisible_car = tmp[0];
    }
    return entry;
}

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
    gchar *scroll;         // titre de la fenêtre

} MaFenetre;

MaFenetre *initF(MaFenetre *wind)
{
    wind = (MaFenetre *)malloc(sizeof(MaFenetre));
    return wind;
}

MaFenetre *Init_default_window_prop(MaFenetre *wind)
{
    wind = initF(wind);
    wind->iconfile = (char *)"prebot.ico";
    // strcpy(wind->iconfile,"prebot.ico");
    wind->wind = NULL;
    wind->isResisable = TRUE; // il est possible de changer la
    // taille de la fenêtre.
    wind->isDecorated = TRUE;   // la fenêtre est décorée.
    wind->isFullscreen = FALSE; // la fenêtre n'occupe pas toute
    // l'écran.
    wind->isDeletable = TRUE;

    wind->Largeur = 450;
    wind->Hauteur = 250;
    wind->title = (char *)"default title";
    wind->scroll = (char *)"";
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
    if (strcmp((char *)wind->scroll, "auto") == 0)
    {
        GtkWidget *scrolled_window;
        scrolled_window = gtk_scrolled_window_new(NULL, NULL);
        gtk_container_add(GTK_CONTAINER(wind->wind), scrolled_window);
        gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window),
                                       GTK_POLICY_AUTOMATIC,
                                       GTK_POLICY_AUTOMATIC);
    }
    if (strcmp((char *)wind->scroll, "always") == 0)
    {
        GtkWidget *scrolled_window;
        scrolled_window = gtk_scrolled_window_new(NULL, NULL);
        gtk_container_add(GTK_CONTAINER(wind->wind), scrolled_window);
        gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window),
                                       GTK_POLICY_ALWAYS, GTK_POLICY_ALWAYS);
    }
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

MaFenetre *ReadWindow(xmlNodePtr node, MaFenetre *wind)
{
    if (xmlGetProp(node, (xmlChar *)"title") != NULL)
    {
        wind->title = (char *)xmlGetProp(node, (xmlChar *)"title");
    }
    if (xmlGetProp(node, (xmlChar *)"icon") != NULL)
    {
        wind->iconfile = (char *)xmlGetProp(node, (xmlChar *)"icon");
    }
    if (xmlGetProp(node, (xmlChar *)"scroll") != NULL)
    {
        wind->scroll = (char *)xmlGetProp(node, (xmlChar *)"scroll");
    }
    if (xmlGetProp(node, (xmlChar *)"height") != NULL)
    {
        wind->Hauteur = atoi((char *)xmlGetProp(node, (xmlChar *)"height"));
    }
    if (xmlGetProp(node, (xmlChar *)"width") != NULL)
    {
        wind->Largeur = atoi((char *)xmlGetProp(node, (xmlChar *)"width"));
    }
    if (xmlGetProp(node, (xmlChar *)"posX") != NULL)
    {
        wind->posX = atoi((char *)xmlGetProp(node, (xmlChar *)"posX"));
    }
    if (xmlGetProp(node, (xmlChar *)"posY") != NULL)
    {
        wind->posY = atoi((char *)xmlGetProp(node, (xmlChar *)"posY"));
    }
    if (xmlGetProp(node, (xmlChar *)"red") != NULL)
    {
        wind->rouge = atoi((char *)xmlGetProp(node, (xmlChar *)"red"));
    }
    if (xmlGetProp(node, (xmlChar *)"green") != NULL)
    {
        wind->vert = atoi((char *)xmlGetProp(node, (xmlChar *)"green"));
    }
    if (xmlGetProp(node, (xmlChar *)"blue") != NULL)
    {
        wind->bleu = atoi((char *)xmlGetProp(node, (xmlChar *)"blue"));
    }
    if (xmlGetProp(node, (xmlChar *)"resizable") != NULL)
    {
        if (strcmp((char *)xmlGetProp(node, (xmlChar *)"resizable"), "TRUE") == 0)
            wind->isResisable = TRUE;
        if (strcmp((char *)xmlGetProp(node, (xmlChar *)"resizable"), "FALSE") == 0)
            wind->isResisable = FALSE;
    }
    if (xmlGetProp(node, (xmlChar *)"fullscreen") != NULL)
    {
        if (strcmp((char *)xmlGetProp(node, (xmlChar *)"fullscreen"), "TRUE") == 0)
            wind->isFullscreen = TRUE;
        if (strcmp((char *)xmlGetProp(node, (xmlChar *)"fullscreen"), "FALSE") == 0)
            wind->isFullscreen = FALSE;
    }
    if (xmlGetProp(node, (xmlChar *)"decorated") != NULL)
    {
        if (strcmp((char *)xmlGetProp(node, (xmlChar *)"decorated"), "TRUE") == 0)
            wind->isDecorated = TRUE;
        if (strcmp((char *)xmlGetProp(node, (xmlChar *)"decorated"), "FALSE") == 0)
            wind->isDecorated = FALSE;
    }
    if (xmlGetProp(node, (xmlChar *)"deletable") != NULL)
    {
        if (strcmp((char *)xmlGetProp(node, (xmlChar *)"deletable"), "TRUE") == 0)
            wind->isDeletable = TRUE;
        if (strcmp((char *)xmlGetProp(node, (xmlChar *)"deletable"), "FALSE") == 0)
            wind->isDeletable = FALSE;
    }
    return wind;
}

typedef struct
{
    GtkWidget *label;
    gchar *text;
    gchar *justify;
    gint x;
    gint y;

} Label;

Label *initLabel(Label *label)
{
    label = (Label *)malloc(sizeof(Label));
    label->label = NULL;
    label->text = (char *)"";
    label->justify = (char *)"left";
    label->x = NULL;
    label->y = NULL;
    return label;
}

void CreateLabel(Label *label)
{
    label->label = gtk_label_new(label->text);
    if (strcmp(label->justify, "left") == 0)
        gtk_label_set_justify(label->label, GTK_JUSTIFY_LEFT);
    if (strcmp(label->justify, "right") == 0)
        gtk_label_set_justify(label->label, GTK_JUSTIFY_RIGHT);
    if (strcmp(label->justify, "center") == 0)
        gtk_label_set_justify(label->label, GTK_JUSTIFY_CENTER);
    if (strcmp(label->justify, "fill") == 0)
        gtk_label_set_justify(label->label, GTK_JUSTIFY_FILL);
    gtk_widget_set_size_request(label->label, label->x, label->y);
}

Label *Readlabel(xmlNodePtr node, Label *label)
{
    if (xmlGetProp(node, (xmlChar *)"justify") != NULL)
    {
        label->justify = (char *)xmlGetProp(node, (xmlChar *)"justify");
    }
    if (xmlGetProp(node, (xmlChar *)"text") != NULL)
    {
        label->text = (char *)xmlGetProp(node, (xmlChar *)"text");
    }
    if (xmlGetProp(node, (xmlChar *)"y") != NULL)
    {
        label->y = atoi((char *)xmlGetProp(node, (xmlChar *)"y"));
    }
    if (xmlGetProp(node, (xmlChar *)"x") != NULL)
    {
        label->x = atoi((char *)xmlGetProp(node, (xmlChar *)"x"));
    }
    return label;
}

typedef struct
{
    GtkWidget *textview;
    GtkTextBuffer *buffer;
    GtkTextIter iter; /// le buffer associé au textview.
    gchar *text;
    gchar *foreground;
    gchar *background;
    gint left_margin;
    gchar *style;  /// italic,oblique,normal
    gchar *weight; /// normal,gras,light,ultrabold
    gint size;
} TextView;

TextView *init_format_textbuf(TextView *txt)
{
    txt = (TextView *)malloc(sizeof(TextView));
    txt->buffer = NULL;
    txt->textview = NULL;
    txt->background = (char *)"black";
    txt->foreground = (char *)"red";
    txt->style = (char *)"italic";
    txt->weight = (char *)"gras";
    txt->text = (char *)"Bonjour tout le monde";
    txt->left_margin = 30;
    txt->size = 30;
    return txt;
}

TextView *ReadTextview(xmlNodePtr node, TextView *txt)
{

    if (xmlGetProp(node, (xmlChar *)"style") != NULL)
    {
        txt->style = (char *)xmlGetProp(node, (xmlChar *)"style");
    }
    if (xmlGetProp(node, (xmlChar *)"weight") != NULL)
    {
        txt->weight = (char *)xmlGetProp(node, (xmlChar *)"weight");
    }
    if (xmlGetProp(node, (xmlChar *)"background") != NULL)
    {
        txt->background = (char *)xmlGetProp(node, (xmlChar *)"background");
    }
    if (xmlGetProp(node, (xmlChar *)"foreground") != NULL)
    {
        txt->foreground = (char *)xmlGetProp(node, (xmlChar *)"foreground");
    }
    if (xmlGetProp(node, (xmlChar *)"text") != NULL)
    {
        txt->text = (char *)xmlGetProp(node, (xmlChar *)"text");
    }
    if (xmlGetProp(node, (xmlChar *)"size") != NULL)
    {
        txt->size = atoi((char *)xmlGetProp(node, (xmlChar *)"size"));
    }
    if (xmlGetProp(node, (xmlChar *)"left_margin") != NULL)
    {
        txt->left_margin = atoi((char *)xmlGetProp(node, (xmlChar *)"left_margin"));
    }

    return txt;
}

void *create_textView(TextView *view)
{
    GtkTextIter *iter;
    view->buffer = gtk_text_buffer_new(NULL);
    view->textview = gtk_text_view_new_with_buffer(view->buffer);
    gtk_text_buffer_create_tag(view->buffer, "lmarg", "left_margin", view->left_margin, NULL);
    ///***choix du style**
    if (!strcmp(view->style, "italic"))
        gtk_text_buffer_create_tag(view->buffer, "style", "style", PANGO_STYLE_ITALIC, NULL);
    if (!strcmp(view->style, "oblique"))
        gtk_text_buffer_create_tag(view->buffer, "style", "style", PANGO_STYLE_OBLIQUE, NULL);
    if (!strcmp(view->style, "normal"))
        gtk_text_buffer_create_tag(view->buffer, "style", "style", PANGO_STYLE_NORMAL, NULL);
    ///***choix du weight***
    if (!strcmp(view->weight, "gras"))
        gtk_text_buffer_create_tag(view->buffer, "weight", "weight", PANGO_WEIGHT_BOLD, NULL);
    if (!strcmp(view->weight, "light"))
        gtk_text_buffer_create_tag(view->buffer, "weight", "weight", PANGO_WEIGHT_LIGHT, NULL);
    if (!strcmp(view->weight, "normal"))
        gtk_text_buffer_create_tag(view->buffer, "weight", "weight", PANGO_WEIGHT_NORMAL, NULL);
    if (!strcmp(view->weight, "ultrabold"))
        gtk_text_buffer_create_tag(view->buffer, "weight", "weight", PANGO_WEIGHT_ULTRABOLD, NULL);
    ///****size*****
    gtk_text_buffer_create_tag(view->buffer, "size", "size", view->size, NULL);
    ///**color*******
    gtk_text_buffer_create_tag(view->buffer, "foreground", "foreground", view->foreground, NULL);
    ///***background******
    gtk_text_buffer_create_tag(view->buffer, "background", "background", view->background, NULL);
    gtk_text_buffer_get_iter_at_offset(view->buffer, &view->iter, 0);
    gtk_text_buffer_insert_with_tags_by_name(view->buffer, &view->iter, view->text, -1, "background", "foreground", "weight", "style", "lmarg", NULL, NULL);
}

typedef struct
{
    GtkWidget *scale;
    gint min_value;
    gint max_value;
    gint step_increment;
    gint page_increment;
    gint value;
    gint digits;
    gboolean draw_value;
    GtkOrientation orientation;
} ScaleProperties;

ScaleProperties *init_scale(ScaleProperties *scale)
{
    scale = (ScaleProperties *)malloc(sizeof(ScaleProperties));
    scale->min_value = 0.0;
    scale->max_value = 100.0;
    scale->step_increment = 1.0;
    scale->page_increment = 10.0;
    scale->value = 50.0;
    scale->digits = 1;
    scale->draw_value = TRUE;
    scale->orientation = GTK_ORIENTATION_HORIZONTAL;
    return ((ScaleProperties *)scale);
}
void Create_scale(ScaleProperties *scale)
{
    scale->scale = gtk_scale_new_with_range(scale->orientation, scale->min_value, scale->max_value, scale->step_increment);
    gtk_scale_set_digits(GTK_SCALE(scale->scale), scale->digits);
    gtk_scale_set_draw_value(GTK_SCALE(scale->scale), scale->draw_value);
    gtk_range_set_increments(GTK_RANGE(scale->scale), scale->step_increment, scale->page_increment);
    gtk_range_set_value(GTK_RANGE(scale->scale), scale->value);
}

ScaleProperties *ReadScale(xmlNodePtr node, ScaleProperties *scale)
{
    if (xmlGetProp(node, (xmlChar *)"draw_value") != NULL)
    {
        if (strcmp((char *)xmlGetProp(node, (xmlChar *)"draw_value"), "TRUE") == 0)
            scale->draw_value = TRUE;
        if (strcmp((char *)xmlGetProp(node, (xmlChar *)"draw_value"), "FALSE") == 0)
            scale->draw_value = FALSE;
    }
    if (xmlGetProp(node, (xmlChar *)"orientation") != NULL)
    {
        if (strcmp((char *)xmlGetProp(node, (xmlChar *)"orientation"), "vertical") == 0)
            scale->orientation = GTK_ORIENTATION_VERTICAL;
        if (strcmp((char *)xmlGetProp(node, (xmlChar *)"orientation"), "horizontal") == 0)
            scale->orientation = GTK_ORIENTATION_HORIZONTAL;
        g_print("%s", (char *)xmlGetProp(node, (xmlChar *)"orientation"));
    }
    if (xmlGetProp(node, (xmlChar *)"min_value") != NULL)
    {
        scale->min_value = atoi((char *)xmlGetProp(node, (xmlChar *)"min_value"));
    }
    if (xmlGetProp(node, (xmlChar *)"max_value") != NULL)
    {
        scale->max_value = atoi((char *)xmlGetProp(node, (xmlChar *)"max_value"));
    }
    if (xmlGetProp(node, (xmlChar *)"step_increment") != NULL)
    {
        scale->step_increment = atoi((char *)xmlGetProp(node, (xmlChar *)"step_increment"));
    }
    if (xmlGetProp(node, (xmlChar *)"page_increment") != NULL)
    {
        scale->page_increment = atoi((char *)xmlGetProp(node, (xmlChar *)"page_increment"));
    }
    if (xmlGetProp(node, (xmlChar *)"value") != NULL)
    {
        scale->value = atoi((char *)xmlGetProp(node, (xmlChar *)"value"));
    }
    if (xmlGetProp(node, (xmlChar *)"digits") != NULL)
    {
        scale->digits = atoi((char *)xmlGetProp(node, (xmlChar *)"digits"));
    }
    return scale;
}

typedef struct
{
    GtkWidget *image;
    gchar *file;
    gint x;
    gint y;

} Image;

Image *initImage(Image *image)
{
    image = (Image *)malloc(sizeof(Image));
    image->image = NULL;
    image->file = (char *)"";
    image->x = NULL;
    image->y = NULL;
    return image;
}

void CreateImage(Image *image)
{
    image->image = gtk_image_new_from_file(image->file);
    gtk_widget_set_size_request(image->image, image->x, image->y);
}

Image *ReadImage(xmlNodePtr node, Image *image)
{
    if (xmlGetProp(node, (xmlChar *)"file") != NULL)
    {
        image->file = (char *)xmlGetProp(node, (xmlChar *)"file");
    }
    if (xmlGetProp(node, (xmlChar *)"height") != NULL)
    {
        image->y = atoi((char *)xmlGetProp(node, (xmlChar *)"height"));
    }
    if (xmlGetProp(node, (xmlChar *)"width") != NULL)
    {
        image->x = atoi((char *)xmlGetProp(node, (xmlChar *)"width"));
    }
    return image;
}

typedef struct mennu
{
    GtkWidget *menu;
    struct item *fils;
} Menu;

typedef struct item
{
    GtkWidget *item;
    gchar *titre;
    struct mennu *menu;
    struct item *next;
} Item;

Menu *initMenu(Menu *menu)
{
    menu = (Menu *)malloc(sizeof(Menu));
    menu->menu = NULL;
    menu->fils = NULL;
    return menu;
}

Item *initItem(Item *item)
{
    item = (Item *)malloc(sizeof(Item));
    item->item = NULL;
    item->titre = NULL;
    item->menu = NULL;
    item->next = NULL;
    return item;
}

Item *creeItem(Item *item, gchar *titre)
{
    item = initItem(item);
    item->titre = titre;
    item->item = gtk_menu_item_new_with_label(titre);
    return item;
}

Menu *creemenubar(Menu *menu)
{
    menu = initMenu(menu);
    menu->menu = gtk_menu_bar_new();
    return menu;
}

Menu *creemenu(Menu *menu)
{
    menu = initMenu(menu);
    menu->menu = gtk_menu_new();
    return menu;
}

Menu *Ajouteraumenu(Menu *menu, Item *item)
{
    if (menu->fils)
        item->next = menu->fils->next;
    menu->fils = item;
    gtk_menu_shell_append(GTK_MENU_SHELL(menu->menu), menu->fils->item);
    return menu;
}

Item *Creesousmenu(Item *item)
{
    if (!item)
        return NULL;
    item->menu = creemenu(item->menu);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(item->item), item->menu->menu);
    return item;
}

static void create_menu_items(xmlNodePtr node, Menu *menu)
{
    for (xmlNodePtr child = node->children; child != NULL; child = child->next)
    {
        if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "item") == 0)
        {
            Item *item = creeItem(item, (char *)xmlGetProp(child, (xmlChar *)"label"));
            menu = Ajouteraumenu(menu, item);
            if (child->children != NULL)
            {
                item = Creesousmenu(item);
                create_menu_items(child, item->menu);
            }
        }
    }
}

Menu *create_menu_bar_from_xml(xmlNodePtr node)
{
    Menu *menu = creemenubar(menu);
    create_menu_items(node, menu);
    return menu;
}

void linkwidgets(GtkWidget *parent, GtkWidget *child)
{
    if (GTK_IS_WINDOW(parent))
        gtk_container_add(GTK_CONTAINER(parent), child);

    if (GTK_IS_BOX(parent))
        gtk_box_pack_start(GTK_BOX(parent), child, FALSE, FALSE, 0);
}

typedef struct
{
    GtkWidget *grid;
    gboolean column_homogeneous;
    gboolean row_homogeneous;
    gint column_spacing;
    gint row_spacing;
    gint x;
    gint y;
    gint collumn;
    gint row;

} Grid;

Grid *initGrid(Grid *grid)
{
    grid = (Grid *)malloc(sizeof(Grid));
    grid->grid = NULL;
    grid->column_homogeneous = FALSE;
    grid->row_homogeneous = FALSE;
    grid->column_spacing = 0;
    grid->row_spacing = 0;
    grid->x = 0;
    grid->y = 0;
    grid->collumn = -1;
    grid->row = -1;
    return grid;
}

void CreateGrid(Grid *grid)
{
    grid->grid = gtk_grid_new();
    gtk_grid_set_column_homogeneous(grid->grid, grid->column_homogeneous);
    gtk_grid_set_row_homogeneous(grid->grid, grid->row_homogeneous);
    gtk_grid_set_column_spacing(grid->grid, grid->column_spacing);
    gtk_grid_set_row_spacing(grid->grid, grid->row_spacing);
    gtk_widget_set_size_request(grid->grid, grid->x, grid->y);
}

Grid *ReadGrid(xmlNodePtr node, Grid *grid)
{
    if (xmlGetProp(node, (xmlChar *)"column_homogeneous") != NULL)
    {
        if (strcmp((char *)xmlGetProp(node, (xmlChar *)"column_homogeneous"), "TRUE") == 0)
            grid->column_homogeneous = TRUE;
        if (strcmp((char *)xmlGetProp(node, (xmlChar *)"column_homogeneous"), "FALSE") == 0)
            grid->column_homogeneous = FALSE;
    }
    if (xmlGetProp(node, (xmlChar *)"row_homogeneous") != NULL)
    {
        if (strcmp((char *)xmlGetProp(node, (xmlChar *)"row_homogeneous"), "TRUE") == 0)
            grid->row_homogeneous = TRUE;
        if (strcmp((char *)xmlGetProp(node, (xmlChar *)"row_homogeneous"), "FALSE") == 0)
            grid->row_homogeneous = FALSE;
    }
    if (xmlGetProp(node, (xmlChar *)"column_spacing") != NULL)
    {
        grid->column_spacing = atoi((char *)xmlGetProp(node, (xmlChar *)"column_spacing"));
    }
    if (xmlGetProp(node, (xmlChar *)"row_spacing") != NULL)
    {
        grid->row_spacing = atoi((char *)xmlGetProp(node, (xmlChar *)"row_spacing"));
    }
    if (xmlGetProp(node, (xmlChar *)"x") != NULL)
    {
        grid->x = atoi((char *)xmlGetProp(node, (xmlChar *)"x"));
    }
    if (xmlGetProp(node, (xmlChar *)"y") != NULL)
    {
        grid->y = atoi((char *)xmlGetProp(node, (xmlChar *)"y"));
    }
    return grid;
}

void LinktoGrid(Grid *grid, GtkWidget *child)
{
    grid->collumn++;
    gtk_grid_attach(GTK_GRID(grid->grid), child, grid->collumn, grid->row, 1, 1);
}

void create_grid_items(xmlNodePtr node, Grid *grid)
{
    int found = 0;
    for (xmlNodePtr childd = node->children; childd != NULL; childd = childd->next)
    {
        if (childd->type == XML_ELEMENT_NODE && strcmp((char *)childd->name, "row") == 0)
        {
            found = 1;
            grid->row++;
            grid->collumn = -1;
            GtkWidget *fils, *group, *radiobut;
            radiobut = gtk_radio_button_new(NULL);
            MaFenetre *wind;
            Box *box;
            Menu *menu;
            prSimpleBut *buttonsimple;
            CheckButton *buttoncheck;
            RadioButton *buttonradio;
            Image *image;
            Label *label;
            TextView *view;
            ScaleProperties *scale;
            Entry *entry;
            Grid *gridd;
            for (xmlNodePtr child = childd->children; child != NULL; child = child->next)
            {
                if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "menu") == 0)
                {
                    menu = create_menu_bar_from_xml(child);
                    fils = menu->menu;
                }
                if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "box") == 0)
                {

                    box = initDefaultbox(box);
                    box = ReadBox(child, box);
                    BoxC(box);
                    fils = box->box;
                    CreateWidgets(child, box->box);
                }

                if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "window") == 0)
                {
                    wind = Init_default_window_prop(wind);
                    wind = ReadWindow(child, wind);
                    fenetre(wind);
                    fils = wind->wind;
                    CreateWidgets(child, wind->wind);
                }

                if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "simplebutton") == 0)
                {
                    buttonsimple = parse_button(child, buttonsimple);
                    create_button(buttonsimple);
                    // g_print("%s",buttonsimple.stock_icon);
                    fils = buttonsimple->button;
                }

                if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "checkbutton") == 0)
                {
                    buttoncheck = parse_check_button(child, buttoncheck);
                    create_check_button(buttoncheck);

                    fils = buttoncheck->button;
                }

                if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "radiobutton") == 0)
                {
                    buttonradio = parse_radio_button(child, buttonradio);
                    create_radio_button(buttonradio, radiobut);
                    fils = buttonradio->button;
                }

                if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "image") == 0)
                {
                    image = initImage(image);
                    image = ReadImage(child, image);
                    CreateImage(image);
                    fils = image->image;
                }

                if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "label") == 0)
                {
                    label = initLabel(label);
                    label = Readlabel(child, label);
                    CreateLabel(label);
                    fils = label->label;
                }

                if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "textview") == 0)
                {
                    view = init_format_textbuf(view);
                    view = ReadTextview(child, view);
                    create_textView(view);
                    fils = view->textview;
                }

                if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "scale") == 0)
                {
                    scale = init_scale(scale);
                    scale = ReadScale(child, scale);
                    Create_scale(scale);
                    fils = scale->scale;
                }

                if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "entry") == 0)
                {
                    entry = init_default_entry(entry);
                    entry = ReadEntry(child, entry);
                    CreateEntry(entry);
                    fils = entry->entry;
                }

                if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "grid") == 0)
                {
                    gridd = initGrid(gridd);
                    gridd = ReadGrid(child, gridd);
                    CreateGrid(gridd);
                    fils = gridd->grid;
                    create_grid_items(child, gridd);
                }

                if (strcmp((char *)child->name, "text") != 0)
                    LinktoGrid(grid, fils);
            }
        }
    }
    if (!found)
        g_print("\nGrid Row not found!!\n");
}

void CreateWidgets(xmlNodePtr node, GtkWidget *parent)
{
    GtkWidget *fils, *group, *radiobut;
    radiobut = gtk_radio_button_new(NULL);
    MaFenetre *wind;
    Box *box;
    Menu *menu;
    prSimpleBut *buttonsimple;
    CheckButton *buttoncheck;
    RadioButton *buttonradio;
    Image *image;
    Label *label;
    TextView *view;
    ScaleProperties *scale;
    Entry *entry;
    Grid *gridd;
    for (xmlNodePtr child = node->children; child != NULL; child = child->next)
    {
        if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "menu") == 0)
        {
            menu = create_menu_bar_from_xml(child);
            fils = menu->menu;
        }
        if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "box") == 0)
        {

            box = initDefaultbox(box);
            box = ReadBox(child, box);
            BoxC(box);
            fils = box->box;
            CreateWidgets(child, box->box);
        }

        if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "window") == 0)
        {
            wind = Init_default_window_prop(wind);
            wind = ReadWindow(child, wind);
            fenetre(wind);
            fils = wind->wind;
            CreateWidgets(child, wind->wind);
        }

        if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "simplebutton") == 0)
        {
            buttonsimple = parse_button(child, buttonsimple);
            create_button(buttonsimple);
            // g_print("%s",buttonsimple.stock_icon);
            fils = buttonsimple->button;
        }

        if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "checkbutton") == 0)
        {
            buttoncheck = parse_check_button(child, buttoncheck);
            create_check_button(buttoncheck);

            fils = buttoncheck->button;
        }

        if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "radiobutton") == 0)
        {
            buttonradio = parse_radio_button(child, buttonradio);
            create_radio_button(buttonradio, radiobut);
            fils = buttonradio->button;
        }

        if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "image") == 0)
        {
            image = initImage(image);
            image = ReadImage(child, image);
            CreateImage(image);
            fils = image->image;
        }

        if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "label") == 0)
        {
            label = initLabel(label);
            label = Readlabel(child, label);
            CreateLabel(label);
            fils = label->label;
        }

        if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "textview") == 0)
        {
            view = init_format_textbuf(view);
            view = ReadTextview(child, view);
            create_textView(view);
            fils = view->textview;
        }

        if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "scale") == 0)
        {
            scale = init_scale(scale);
            scale = ReadScale(child, scale);
            Create_scale(scale);
            fils = scale->scale;
        }

        if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "entry") == 0)
        {
            entry = init_default_entry(entry);
            entry = ReadEntry(child, entry);
            CreateEntry(entry);
            fils = entry->entry;
        }

        if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "grid") == 0)
        {
            gridd = initGrid(gridd);
            gridd = ReadGrid(child, gridd);
            CreateGrid(gridd);
            fils = gridd->grid;
            create_grid_items(child, gridd);
        }

        // dkchi dyalkom

        if (strcmp((char *)child->name, "text") != 0)
            linkwidgets(parent, fils);
    }
}

void parsefile(const char *filename)
{
    xmlDocPtr doc = xmlParseFile(filename);
    if (doc == NULL)
    {
        g_warning("Failed to parse XML file %s", filename);
        return;
    }
    xmlNodePtr root = xmlDocGetRootElement(doc);
    if (root->type == XML_ELEMENT_NODE && strcmp((char *)root->name, "window") == 0)
    {
        // GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        MaFenetre *wind;
        wind = Init_default_window_prop(wind);
        wind = ReadWindow(root, wind);
        fenetre(wind);
        CreateWidgets(root, wind->wind);
        gtk_widget_show_all(wind->wind);
    }
    else
        g_print("Window not found");
    xmlFreeDoc(doc);
}

int main(int argc, char *argv[])
{

    gtk_init(&argc, &argv);
    parsefile("menu.xml");
    gtk_main();
    return 0;
}