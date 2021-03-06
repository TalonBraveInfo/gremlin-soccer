struct {
	int page,x,y,n,off;
	BYTE wid,hgt;
	BYTE prp[43];
	} font_data[]=
	{
	 {
	  0,168,171,11,0,
	  8,5,
	  {
	  5,5,5,5,5,5,5,5,5,5,2,4,5,5,5,2,
	  1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	  5,5,5,5,5,5,5,5,5,5,5,
	  }
	 },
	 {
	  0,96,143,9,0,	
	  8,7,
	  {
	  7,6,7,7,7,7,7,7,7,7,3,4,6,7,6,4,
	  3,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,
	  7,7,7,7,6,7,7,7,7,7,7,
	  }
	 },
	 {
	  0,96,191,10,7,
	  16,13,
	  {
	  11,8,11,11,11,10,11,11,11,11,5,9,11,11,11,7,
	  5,14,11,12,12,9,9,14,12,5,8,13,9,16,13,14,
	  11,14,12,10,11,12,13,16,14,11,13
	  }
	 },
	};


// Sprite 0 is variable, don't use
struct {
	int page,x,y,wid,hgt;
	} spr_data[]=
	{
	 {0,0,0,16,16},
	 {1,0,192,48,240},
	 {0,0,180,24,24},
	 {0,24,180,24,24},
	 {0,48,180,24,24},
	 {0,72,180,24,24},
	 {0,0,204,24,24},
	 {0,24,204,24,24},
	 {0,48,204,24,24},
	 {0,72,204,24,24},
	 {0,0,228,24,24},
	 {0,24,228,24,24},
	 {0,48,228,24,24},
	 {0,72,228,24,24},
	 {0,96,180,24,24},
	 {0,120,180,24,24},
	 {0,144,180,24,24},
	 {0,0,49,39,12},
	 {0,168,192,39,12},
	 {1,0,0,69,79},
	 {1,69,0,69,79},
	 {1,138,0,21,22},
	 {1,191,0,32,9},
	 {1,171,0,9,32},
	 {1,91,81,165,30},
	 {1,0,81,91,30},
	 {1,170,35,57,30},
	 {1,181,0,9,18},
	 {1,159,0,12,18},
	 {1,76,111,52,53},
	 {1,220,111,35,40},
	 {1,220,151,35,40},
	 {1,227,29,11,11},
	 {1,138,23,32,5},
	 {1,250,35,5,32},
	 {1,167,65,83,15},
	 {1,181,19,46,15},
	 {1,137,65,29,15},
	 {1,197,9,4,9},
	 {1,191,9,5,9},
	 {1,228,1,27,27},
	 {1,37,111,39,48},
	 {1,170,34,39,47},
	 {1,210,40,39,41},
	 {1,122,173,70,83},
	 {1,52,173,70,83},
	 {1,176,111,44,77},
	 {1,134,111,21,26},
	 {1,155,133,21,27},
	 {1,155,111,21,22},
	 {1,16,170,36,43},
	 {1,16,213,36,43},
	 {1,15,111,22,41},
	 {0,0,62,23,27},
	 {0,23,62,23,27},
	 {0,46,62,23,27},
	 {0,69,62,23,27},
	 {0,92,62,23,27},
	 {0,115,62,23,27},
	 {0,138,62,23,27},
	 {0,161,62,23,27},
	 {0,184,62,23,27},
	 {0,207,62,23,27},
	 {0,230,62,23,27},
	 {0,69,116,23,27},
	 {0,92,116,23,27},
	 {0,115,116,23,27},
	 {0,138,116,23,27},
	 {0,0,89,23,27},
	 {0,23,89,23,27},
	 {0,46,89,23,27},
	 {0,69,89,23,27},
	 {0,92,89,23,27},
	 {0,115,89,23,27},
	 {0,138,89,23,27},
	 {0,161,89,23,27},
	 {0,184,89,23,27},
	 {0,207,89,23,27},
	 {0,230,89,23,27},
	 {0,161,116,23,27},
	 {0,184,116,23,27},
	 {0,207,116,23,27},
	 {0,230,116,23,27},
	 {1,250,35,5,16},
	 {1,0,111,14,16},
	 {1,0,127,14,16},
	 {1,38,111,18,20},
	 {1,56,111,18,20},
	 {1,129,112,34,46},
	 {1,129,158,4,4},
	 {1,133,158,7,7},
	 {1,140,158,4,4},
	 {1,144,158,7,7},
	 {1,192,192,64,63},	// 93
	 {1,192,192,32,63}, 	// 94
	 {1,192,192,16,63},	// 95
	 {1,192,192,8 ,63},	// 96
	 {1,192,192,4 ,63}, 	// 97
	 {1,192,192,2 ,63},	// 98
	 {1,192,192,64,32},	// 99
	 {1,192,192,32,32},	// 100
	 {1,192,192,16,32}, 	// 101
	 {1,192,192,8 ,32}, 	// 102
	 {1,192,192,4 ,32}, 	// 103
	 {1,192,192,2 ,32}, 	// 104
	 {1,192,192,64,16},	// 105
	 {1,192,192,32,16},	// 106
	 {1,192,192,16,16},	// 107
	 {1,192,192,8 ,16}, 	// 108
	 {1,192,192,4 ,16}, 	// 109
	 {1,192,192,2 ,16}, 	// 110
	 {1,192,192,64,8 }, 	// 111
	 {1,192,192,32,8 }, 	// 112
	 {1,192,192,16,8 }, 	// 113
	 {1,192,192,8 ,8 }, 	// 114
	 {1,192,192,4 ,8 },	// 115
	 {1,192,192,2 ,8 }, 	// 116
	 {1,192,192,64,4 }, 	// 117
	 {1,192,192,32,4 }, 	// 118
	 {1,192,192,16,4 }, 	// 119
	 {1,192,192,8 ,4 }, 	// 120
	 {1,192,192,4 ,4 }, 	// 121
	 {1,192,192,2 ,4 }, 	// 122
	 {1,192,192,64,2 }, 	// 123
	 {1,192,192,32,2 }, 	// 124
	 {1,192,192,16,2 }, 	// 125
	 {1,192,192,8 ,2 }, 	// 126
	 {1,192,192,4 ,2 }, 	// 127
	 {1,192,192,2 ,2 }, 	// 128
	};						 		
