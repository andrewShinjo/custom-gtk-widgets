#pragma once

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define MB_TYPE_BUTTON mb_button_get_type()
G_DECLARE_FINAL_TYPE(MbButton, mb_button, MB, BUTTON, GtkWidget)

GtkWidget * mb_button_new(void);

G_END_DECLS
