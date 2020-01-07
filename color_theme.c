#include "stdio.h"

static const char *atom[] = {
    "#000000",
    "#fc5ef0",
    "#87c38a",
    "#ffd7b1",
    "#85befd",
    "#b9b5fc",
    "#85befd",
    "#dfdfdf",
    "#000000",
    "#fc5ef0",
    "#94f936",
    "#f5ffa7",
    "#96cbfe",
    "#b9b5fc",
    "#85befd",
    "#dfdfdf",

	[255] = 0,

	/* more colors can be added after 255 to use with DefaultXX */
	"#cccccc",
	"#555555",
    "#c5c8c6",
    "#161718",
};

static const char * solarized_dark[] = {
	/* solarized dark */
	"#073642",  /*  0: black    */
	"#dc322f",  /*  1: red      */
	"#859900",  /*  2: green    */
	"#b58900",  /*  3: yellow   */
	"#268bd2",  /*  4: blue     */
	"#d33682",  /*  5: magenta  */
	"#2aa198",  /*  6: cyan     */
	"#eee8d5",  /*  7: white    */
	"#002b36",  /*  8: brblack  */
	"#cb4b16",  /*  9: brred    */
	"#586e75",  /* 10: brgreen  */
	"#657b83",  /* 11: bryellow */
	"#839496",  /* 12: brblue   */
	"#6c71c4",  /* 13: brmagenta*/
	"#93a1a1",  /* 14: brcyan   */
	"#fdf6e3",  /* 15: brwhite  */

	[255] = 0,

	/* more colors can be added after 255 to use with DefaultXX */
	"#93a1a1",  /* 14: brcyan   */
	"#fdf6e3",  /* 15: brwhite  */
	"#839496",  /* 12: brblue   */
	"#002b36",  /*  8: brblack  */
};

static const char * solarized_light[] = {
	/* solarized light */
	"#eee8d5",  /*  0: black    */
	"#dc322f",  /*  1: red      */
	"#859900",  /*  2: green    */
	"#b58900",  /*  3: yellow   */
	"#268bd2",  /*  4: blue     */
	"#d33682",  /*  5: magenta  */
	"#2aa198",  /*  6: cyan     */
	"#073642",  /*  7: white    */
	"#fdf6e3",  /*  8: brblack  */
	"#cb4b16",  /*  9: brred    */
	"#93a1a1",  /* 10: brgreen  */
	"#839496",  /* 11: bryellow */
	"#657b83",  /* 12: brblue   */
	"#6c71c4",  /* 13: brmagenta*/
	"#586e75",  /* 14: brcyan   */
	"#002b36",  /* 15: brwhite  */
	[255] = 0,

	/* more colors can be added after 255 to use with DefaultXX */
	"#586e75",  /* 14: brcyan   */
	"#002b36",  /* 15: brwhite  */
	"#657b83",  /* 12: brblue   */
	"#fdf6e3",  /*  8: brblack  */
};

static const char * sunburn[] = {
    "#373338",
    "#bf7f80",
    "#6c8f6b",
    "#d8c58d",
    "#7370a4",
    "#a3779d",
    "#636181",
    "#d6d4e8",
    "#544f55",
    "#d29193",
    "#7da47c",
    "#ebd89f",
    "#8481b7",
    "#ad7ea7",
    "#757395",
    "#ededec",

	[255] = 0,

	/* more colors can be added after 255 to use with DefaultXX */
	"#cccccc",
	"#555555",
    "#d6d4e8",
    "#373338",
};

static const char * zenburn[] = {
    "#3f3f3f",
    "#bf7f80",
    "#60b48a",
    "#dfaf8f",
    "#506070",
    "#dc8cc3",
    "#8cd0d3",
    "#DCDCCC",

    "#709080",
    "#cc9393",
    "#7f9f7f",
    "#f0dfaf",
    "#94bff3",
    "#ec93d3",
    "#93e0e3",
    "#ffffff",

	[255] = 0,

	/* more colors can be added after 255 to use with DefaultXX */
	"#cccccc",
	"#555555",
    "#DCDCCC",
    "#3f3f3f",
};

static const char * dracula[] = {
    /* 8 normal colors */
    [0] = "#000000", /* black   */
    [1] = "#ff5555", /* red     */
    [2] = "#50fa7b", /* green   */
    [3] = "#f1fa8c", /* yellow  */
    [4] = "#bd93f9", /* blue    */
    [5] = "#ff79c6", /* magenta */
    [6] = "#8be9fd", /* cyan    */
    [7] = "#bbbbbb", /* white   */

    /* 8 bright colors */
    [8]  = "#44475a", /* black   */
    [9]  = "#ff5555", /* red     */
    [10] = "#50fa7b", /* green   */
    [11] = "#f1fa8c", /* yellow  */
    [12] = "#bd93f9", /* blue    */
    [13] = "#ff79c6", /* magenta */
    [14] = "#8be9fd", /* cyan    */
    [15] = "#ffffff", /* white   */

 	[255] = 0,

    /* special colors */
    [256] = "#f8f8f2", /* foreground */
    [257] = "#f8f8f2", /* foreground */
    [258] = "#f8f8f2", /* foreground */
    [259] = "#282a36", /* background */
};

static const char * nord[] = {
	"#3b4252", /* black   */
	"#bf616a", /* red     */
	"#a3be8c", /* green   */
	"#ebcb8b", /* yellow  */
	"#81a1c1", /* blue    */
	"#b48ead", /* magenta */
	"#88c0d0", /* cyan    */
	"#e5e9f0", /* white   */

	"#4c566a", /* black   */
	"#bf616a", /* red     */
	"#a3be8c", /* green   */
	"#ebcb8b", /* yellow  */
	"#81a1c1", /* blue    */
	"#b48ead", /* magenta */
	"#8fbcbb", /* cyan    */
	"#eceff4", /* white   */

 	[255] = 0,

    [256] = "#d8dee9", /* cs */
	[257] = "#2e3440", /* rcs */
	[258] = "#d8dee9", /* foreground */
    [259] = "#2e3440", /* background */
};

int color_index = 5;

static const char ** color_themes[] = {
    0,
    atom,
    solarized_dark,
    solarized_light,
    sunburn,
    zenburn,
    dracula,
    nord,
};

static const int color_theme_count = sizeof(color_themes) / sizeof(const char **);

const char * get_colorname(int i, const char ** default_colorname) {
    if (color_index >= color_theme_count || color_index == 0 || color_themes[color_index] == 0)
        return default_colorname[i];

    return color_themes[color_index][i];
}

int next_color(int col_index) {
    col_index++;

    if (col_index >= color_theme_count)
        col_index = 0;

    return col_index;
}
