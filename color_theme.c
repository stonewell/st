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

int color_index = 1;

const char * get_colorname(int i, const char ** default_colorname) {
    switch(color_index) {
    case 1:
        return atom[i];
    case 2:
        return solarized_dark[i];
    case 3:
        return solarized_light[i];
    default:
        return default_colorname[i];
    }
}

int next_color(int col_index) {
    col_index++;

    if (col_index > 3)
        col_index = 0;

    return col_index;
}
