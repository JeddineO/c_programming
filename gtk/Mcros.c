#include "programme.h"

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    MaFenetre *F;
    F = Init_default_window_prop(F);
    F->title = "Test macro GTK-2022-2023";
    fenetre(F);
    ComboBox *Bx;
    Bx = Init_comobox(Bx);
    add_element(&Bx->items, "a");
    add_element(&Bx->items, "b");
    add_element(&Bx->items, "c");
    add_element(&Bx->items, "d");

    create_combobox(Bx);
    Box Bx1;
    Bx1 = initDefaultbox(Bx1);
    gtk_container_add(GTK_CONTAINER(Bx1->box), Bx->combo);
    BoxC(Bx1);
    gtk_container_add(GTK_CONTAINER(F->wind), Bx1->box);
    gtk_widget_show_all(F->wind);
    gtk_main();
    return 0;
}