#ifndef LAYOUT_HPP
# define LAYOUT_HPP

	// colors
	# define RED_TERM		"\033[0;38;2;255;0;0m"  
	# define RED 			"\033[0;38;2;210;10;10m"   
	# define ROUILLE 		"\033[0;38;2;205;105;0m"  
	# define GOLD 			"\033[0;38;2;255;215;0m"
	# define YELLOW 		"\033[0;38;2;255;255;0m" 
	# define BRIGHT_GREEN 	"\033[0;38;2;0;255;0m"
	# define GREEN 			"\033[0;38;2;80;200;120m" 
	# define SAPIN 			"\033[0;38;2;0;128;0m"
	# define CYAN 			"\033[0;38;2;0;255;255m"
	# define PURPLE 		"\033[0;38;2;80;80;220m"
	# define DARK_PURPLE	"\033[0;38;2;75;0;130m"
	# define PINK 			"\033[0;38;2;238;130;238m"
	# define MAGENTA 		"\033[0;38;2;255;0;255m"
	# define SAUMON 		"\033[0;38;2;255;192;203m"
	# define GREY1 			"\033[0;38;2;128;128;128m"
	# define GREY2 			"\033[0;38;2;170;170;170m" 
	# define TURQUOISE 		"\033[0;38;2;64;224;208m" 
	# define ORANGE 		"\033[0;38;2;255;127;80m" 
	# define CORAIL			"\033[0;38;2;250;128;114m" 
	# define BONBON 		"\033[0;38;2;221;160;221m"
	# define BLUE_GREEN 	"\033[0;38;2;0;128;128m"
	# define KAKI 			"\033[0;38;2;128;128;0m"
	# define VERT_PASTEL 	"\033[0;38;2;189;252;201m" 
	
	// background colors
	# define BLACK_BG   	"\033[40m"
	# define RED_BG     	"\033[41m"
	# define GREEN_BG   	"\033[42m"
	# define YELLOW_BG  	"\033[43m"
	# define BLUE_BG    	"\033[44m"
	# define MAGENTA_BG 	"\033[45m"
	# define CYAN_BG    	"\033[46m"
	# define WHITE_BG   	"\033[47m"

	// utils
	# define RESET			"\033[0m"
	# define CLRALL 		"\033[2J\033[3J\033[H" 			// supprime l'historique
	# define CLEARTERM 		"\033c"     
	# define CLEARLINE 		"\033[2K"
	
	// effects
	# define BOLD 			"\033[1m"
	# define DIM    		"\033[2m"
	# define ITALIC 		"\033[3m"
	# define UNDERLINE 		"\033[4m"
	# define BLINK 			"\033[5m"
	# define REVERSE		"\033[7m"						// reverse fg and bg
	# define HIDDEN			"\033[8m"
	# define BARRE 			"\033[9m"

#endif