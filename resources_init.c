#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/Xresource.h>

/* Xresources preferences */
enum resource_type {
	STRING = 0,
	INTEGER = 1,
	FLOAT = 2
};

typedef struct {
	char *name;
	enum resource_type type;
	void *dst;
} ResourcePref;

static char * font;
static int borderpx = 2;
static const char * colorname[512] = {0};
static char * termname;
static char * shell;
static float cwscale = 1.0;
static float chscale = 1.0;
static unsigned int xfps = 120;
static unsigned int actionfps = 30;
static char * opt_name;
static char * opt_class;

/*
 * blinking timeout (set to 0 to disable blinking) for the terminal blinking
 * attribute.
 */
static unsigned int blinktimeout = 800;

/*
 * thickness of underline and bar cursors
 */
static unsigned int cursorthickness = 2;

/*
 * bell volume. It must be a value between -100 and 100. Use 0 for disabling
 * it
 */
static int bellvolume = 0;
unsigned int tabspaces = 8;

ResourcePref resources[] = {
    { "font",         STRING,  &font },
    { "color0",       STRING,  &colorname[0] },
    { "color1",       STRING,  &colorname[1] },
    { "color2",       STRING,  &colorname[2] },
    { "color3",       STRING,  &colorname[3] },
    { "color4",       STRING,  &colorname[4] },
    { "color5",       STRING,  &colorname[5] },
    { "color6",       STRING,  &colorname[6] },
    { "color7",       STRING,  &colorname[7] },
    { "color8",       STRING,  &colorname[8] },
    { "color9",       STRING,  &colorname[9] },
    { "color10",      STRING,  &colorname[10] },
    { "color11",      STRING,  &colorname[11] },
    { "color12",      STRING,  &colorname[12] },
    { "color13",      STRING,  &colorname[13] },
    { "color14",      STRING,  &colorname[14] },
    { "color15",      STRING,  &colorname[15] },
    { "background",   STRING,  &colorname[256] },
    { "foreground",   STRING,  &colorname[257] },
    { "cursorColor",  STRING,  &colorname[258] },
    { "termname",     STRING,  &termname },
    { "shell",        STRING,  &shell },
    { "xfps",         INTEGER, &xfps },
    { "actionfps",    INTEGER, &actionfps },
    { "blinktimeout", INTEGER, &blinktimeout },
    { "bellvolume",   INTEGER, &bellvolume },
    { "tabspaces",    INTEGER, &tabspaces },
    { "borderpx",     INTEGER, &borderpx },
    { "cwscale",      FLOAT,   &cwscale },
    { "chscale",      FLOAT,   &chscale },
};

int
resource_load(XrmDatabase db, char *name, enum resource_type rtype, void *dst)
{
	char **sdst = dst;
	int *idst = dst;
	float *fdst = dst;

	char fullname[256];
	char fullclass[256];
	char *type;
	XrmValue ret;

	snprintf(fullname, sizeof(fullname), "%s.%s",
             opt_name ? opt_name : "st", name);
	snprintf(fullclass, sizeof(fullclass), "%s.%s",
             opt_class ? opt_class : "St", name);
	fullname[sizeof(fullname) - 1] = fullclass[sizeof(fullclass) - 1] = '\0';

	XrmGetResource(db, fullname, fullclass, &type, &ret);
	if (ret.addr == NULL || strncmp("String", type, 64))
		return 1;

	switch (rtype) {
	case STRING:
		*sdst = ret.addr;
		break;
	case INTEGER:
		*idst = strtoul(ret.addr, NULL, 10);
		break;
	case FLOAT:
		*fdst = strtof(ret.addr, NULL);
		break;
	}
	return 0;
}

void
config_init(void)
{
	char *resm;
	XrmDatabase db;
	ResourcePref *p;

	XrmInitialize();
	resm = XResourceManagerString(xw.dpy);
	if (!resm)
		return;

	db = XrmGetStringDatabase(resm);
	for (p = resources; p < resources + LEN(resources); p++)
		resource_load(db, p->name, p->type, p->dst);
}
