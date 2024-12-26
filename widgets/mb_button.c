#include "./mb_button.h"

/* widget definition */

struct _MbButton
{
	GtkWidget parent_instance;
	gchar *label;
};

G_DEFINE_TYPE(MbButton, mb_button, GTK_TYPE_WIDGET)

enum
{
	PROP_LABEL = 1,
	N_PROPERTIES
};

static GParamSpec *properties[N_PROPERTIES];

/* private declaration */

static void mb_button_init(MbButton *self);
static void mb_button_class_init(MbButtonClass *klass);
static void mb_button_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec);
static void mb_button_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);
static void mb_button_dispose(GObject *object);
static void mb_button_finalize(GObject *object);

/* public implementation */

GtkWidget * mb_button_new(void)
{
	return g_object_new(MB_TYPE_BUTTON, NULL);
}
/* private implementation */

static void mb_button_init(MbButton *self)
{

}

static void mb_button_class_init(MbButtonClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS(klass);

	object_class->dispose = mb_button_dispose;
	object_class->finalize = mb_button_finalize;
	object_class->get_property = mb_button_get_property;
	object_class->set_property = mb_button_set_property;

	GParamFlags default_flags = G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS | G_PARAM_EXPLICIT_NOTIFY;

	properties[PROP_LABEL] = 
		g_param_spec_string("label", "Button label", "Textual label for the button", "Button", default_flags);

	g_object_class_install_properties(object_class, N_PROPERTIES, properties);
}

static void mb_button_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
	MbButton *self = MB_BUTTON(object);

	switch(property_id)
	{
		case PROP_LABEL:
		{
			g_value_set_string(value, self->label);
			break;
		}
		default:
		{
			G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
			break;
		}
	}
}

static void mb_button_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
	MbButton *self = MB_BUTTON(object);

	switch(property_id)
	{
		case PROP_LABEL:
		{
			g_free(self->label);
			self->label = g_strdup(g_value_get_string(value));
			break;
		}
		default:
		{
			G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
			break;
		}
	}
}

static void mb_button_dispose(GObject *object)
{
	G_OBJECT_CLASS(mb_button_parent_class)->dispose(object);

}

static void mb_button_finalize(GObject *object)
{
	G_OBJECT_CLASS(mb_button_parent_class)->finalize(object);
}

