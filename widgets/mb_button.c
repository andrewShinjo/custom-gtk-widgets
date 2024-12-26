#include "./mb_button.h"

struct _MbButton
{
	GtkWidget parent_instance;
};

G_DEFINE_TYPE(MbButton, mb_button, GTK_TYPE_WIDGET)

static void mb_button_init(MbButton *self)
{

}

static void mb_button_class_init(MbButtonClass *klass)
{

}

GtkWidget * mb_button_new(void)
{
	return g_object_new(MB_TYPE_BUTTON, NULL);
}
