#include "beer_song.h"

void recite(uint8_t start_bottles, uint8_t take_down, char **song)
{
	uint8_t bottles = start_bottles;
	uint16_t line = 0;
	char *line_one = "%s of beer on the wall, %s of beer.";
	char *line_two = "Take %s down and pass it around, %s of beer on the wall.";
	char formatted[17];

	for (uint8_t i = 0; i < take_down; i++) {
		switch (bottles) {
			case 0:
				sprintf(song[line], line_one, "No more bottles", "no more bottles");
				bottles = 100;
				line++;
				break;
			case 1:
				sprintf(formatted, "%d bottle", bottles);
				sprintf(song[line], line_one, formatted, formatted);
				bottles--;
				line++;
				break;
			default:
				sprintf(formatted, "%d bottles", bottles);
				sprintf(song[line], line_one, formatted, formatted);
				bottles--;
				line++;
				break;
		}
		switch (bottles) {
			case 0:
				sprintf(song[line], line_two, "it", "no more bottles");
				line++;
				if (take_down > 1) line++;
				break;
			case 1:
				sprintf(formatted, "%d bottle", bottles);
				sprintf(song[line], line_two, "one", formatted);
				line++;
				if (take_down > 1) line++;
				break;
			case 100:
				sprintf(song[line], "Go to the store and buy some more, 99 bottles of beer on the wall.");
				bottles = 99;
				line++;
				break;
			default:
				sprintf(formatted, "%d bottles", bottles);
				sprintf(song[line], line_two, "one", formatted);
				line++;
				if (take_down > 1) line++;
				break;
		}
	}
}
