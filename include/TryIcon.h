#ifndef SYNCFILESDAEMON_TRYICON_H
#define SYNCFILESDAEMON_TRYICON_H
#include <iostream>
#include <gtk-3.0>

void tray_icon_on_click(GtkStatusIcon *status_icon,
                        gpointer user_data)
{
    printf("Clicked on tray icon\n");
}

void tray_icon_on_menu(GtkStatusIcon *status_icon, guint button,
                       guint activate_time, gpointer user_data)
{
    printf("Popup menu\n");
}

static GtkStatusIcon *create_tray_icon() {
    GtkStatusIcon *tray_icon;

    tray_icon = gtk_status_icon_new();
    g_signal_connect(G_OBJECT(tray_icon), "activate",
                     G_CALLBACK(tray_icon_on_click), NULL);
    g_signal_connect(G_OBJECT(tray_icon),
                     "popup-menu",
                     G_CALLBACK(tray_icon_on_menu), NULL);
    gtk_status_icon_set_from_icon_name(tray_icon,
                                       GTK_STOCK_MEDIA_STOP);
    gtk_status_icon_set_tooltip(tray_icon,
                                "Example Tray Icon");
    gtk_status_icon_set_visible(tray_icon, TRUE);

    return tray_icon;
}
#endif //SYNCFILESDAEMON_TRYICON_H
